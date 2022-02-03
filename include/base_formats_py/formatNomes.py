#!/usr/bin/env python3

"""
 @file formatNomes.py

 @brief this file is the base structure of name validation using python 

 @author Aquila Macedo  - 202021800
 @author Talles Marcelo - 200060295

"""

def isValid(msg, n):
    if n < 5 or n > 20:
        return "Nome invalido. Use algo entre 5 e 20 caracteres"

    for i in range(n):
        if not(msg[i].isalpha()) and msg[i] != '.' and msg[i] != ' ':
            return "Nome Invalido. Apenas os caracteres (A-Z ou a-z), ponto(.) ou espaço em branco devem ser utilizados"
        if msg[0] == '.':
            return "Nome Invalido. O primeiro caractere nao pode ser um ponto"
        if msg[i] == '.' and not(msg[i-1].isalpha()):
            return "Nome Invalido. O Caractere precedente nao pertence ao alfabeto(A-Z ou a-z)"
        if (msg[i] == ' ') and (i != n-1) and (msg[i+1] == ' '):
            return "Nome Invalido. Nao pode ter espaco consecutivo"
        if (not(msg[0].isupper()) and msg[0].isalpha()) or (msg[i] == ' ' and msg[i+1].isalpha() and not(msg[i+1].isupper())):
            return "Nome Invalido. Todos os caracteres de um termo devem iniciar com letra maiscula"
    return True 

entrada = input()
tamanho = len(entrada)

print(isValid(entrada,tamanho))
