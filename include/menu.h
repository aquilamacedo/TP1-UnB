#include <ncurses.h>
#include <string>

#ifndef _MENU_H_
#define _MENU_H_
using namespace std;
class Menu
{
public:
  int start_x;
  string text;
  char trigger;
  string *items;
  int num_items;
  int selected_item;

  Menu(string text, char trigger, string *items, int num_items)
  {
    this->text = text;
    this->trigger = trigger;
    this->items = items;
    this->num_items = num_items;
    this->selected_item = 0;
  }

  void selectNextItem()
  {
    selected_item++;
    if (selected_item >= num_items)
    {
      selected_item = 0;
    }
  }

  void selectPrevItem()
  {
    selected_item--;
    if (selected_item < 0)
    {
      selected_item = num_items - 1;
    }
  }
};

class MenuBar
{
public:
  WINDOW *win;
  Menu *menus;
  int num_menus;
  int current_position;
  int selected_menu;
  WINDOW *menuwin;
  int yMax;
  int xMax;
  int yBeg;
  int xBeg;
  int ch;

  MenuBar(WINDOW *win, Menu *menus, int num_menus)
  {
    this->win = win;
    this->menus = menus;
    this->num_menus = num_menus;
    this->current_position = 2;
    this->selected_menu = -1;

    getmaxyx(win, yMax, xMax);
    getbegyx(win, yBeg, xBeg);
    menuwin = newwin(yMax - 2, xMax - 2, yBeg + 1, xBeg + 1);
    keypad(menuwin, true);
    wrefresh(menuwin);

    for (int i = 0; i < num_menus; i++)
    {
      this->menus[i].start_x = current_position;
      current_position += this->menus[i].text.length() + 1;
    }
  }

  void reset()
  {
    for (int i = 0; i < num_menus; i++)
    {
      mvwprintw(win, 0, this->menus[i].start_x, this->menus[i].text.c_str());
    }
    wrefresh(win);
  }

  void draw()
  {
    for (int i = 0; i < num_menus; i++)
    {
      drawMenu(menus[i], selected_menu == i);
    }
    selected_menu = -1;
  }

  void drawMenu(Menu menu, bool is_selected)
  {
    if (is_selected)
    {
      wattron(win, A_STANDOUT);
    }
    mvwprintw(win, 0, menu.start_x, menu.text.c_str());
    wattroff(win, A_STANDOUT);
    wrefresh(win);

    drawMenuItems(menu);
    wrefresh(menuwin);

    while (is_selected && (ch = wgetch(menuwin)))
    {
      switch (ch)
      {
      case KEY_DOWN:
        menu.selectNextItem();
        break;
      case KEY_UP:
        menu.selectPrevItem();
        break;
      case '\r':
      case '\n':
      case KEY_ENTER:
        menu.selectNextItem();
        break;
      default:
        is_selected = false;
        break;
      }
      drawMenuItems(menu);
    }
    werase(menuwin);
    wrefresh(menuwin);
    reset();
  }

  void drawMenuItems(Menu menu)
  {
    int yMax, xMax;
    getmaxyx(menuwin, yMax, xMax);

    for (int i = 0; i < menu.num_items; i++)
    {
      mvwprintw(menuwin, i, 0, menu.items[i].c_str());
      if (menu.selected_item == i)
      {
        mvwchgat(menuwin, i, 0, xMax, A_NORMAL, 1, NULL);
      }
      else
      {
        mvwchgat(menuwin, i, 0, xMax, A_STANDOUT, 0, NULL);
      }
    }
  }

  void handleTrigger(char trigger)
  {
    for (int i = 0; i < num_menus; i++)
    {
      if (trigger == this->menus[i].trigger)
      {
        selected_menu = i;
      }
    }
  }
};

#endif //  _MENU_H_