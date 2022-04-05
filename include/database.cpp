#include "entidades.h"
#include "dominios.h"
#include "sqlite3.h"
#include "database.h"
#include <string>
#include <sstream>

//Atributo estatico container List.

list<ElementoResultado> ComandoSQL::listaResultado;

//---------------------------------------------------------------------------
//Classe ErroPersistencia.

EErroPersistencia::EErroPersistencia(string mensagem)
{
        this->mensagem = mensagem;
}

string EErroPersistencia::what()
{
        return mensagem;
}

//---------------------------------------------------------------------------
//Classe ElementoResultado.

void ElementoResultado::setNomeColuna(const string &nomeColuna)
{
        this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string &valorColuna)
{
        this->valorColuna = valorColuna;
}

//---------------------------------------------------------------------------
//Classe ComandoSQL.

void ComandoSQL::conectar()
{
        rc = sqlite3_open(nomeBancoDados, &bd);
        if (rc != SQLITE_OK)
                throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ComandoSQL::desconectar()
{
        rc = sqlite3_close(bd);
        if (rc != SQLITE_OK)
                throw EErroPersistencia("Erro na desconexao ao banco de dados");
}

void ComandoSQL::executar()
{
        conectar();
        rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);

        if (rc != SQLITE_OK)
        {
                sqlite3_free(mensagem);
                desconectar();
                throw EErroPersistencia("Erro na execucao do comando SQL");
        }

        desconectar();
}

int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna)
{
        NotUsed = 0;
        ElementoResultado elemento;
        int i;
        for (i = 0; i < argc; i++)
        {
                elemento.setNomeColuna(nomeColuna[i]);
                elemento.setValorColuna(valorColuna[i] ? valorColuna[i] : "NULL");
                listaResultado.push_front(elemento);
        }
        return 0;
}

ComandoSenha::ComandoSenha(Email email)
{
        comandoSQL = "SELECT senha FROM usuario WHERE email = '";
        // senha da tabela usuario onde email eh o getemail
        comandoSQL += email.getEmail();
        comandoSQL += "'";
}

string ComandoSenha::getResultado()
{
        ElementoResultado resultado;
        string senha;

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista Vazia.");
        }

        resultado = listaResultado.back();
        listaResultado.pop_back(); // dado que a gente vai excluir

        senha = resultado.getValorColuna();

        return senha;
}

// ---------------------------------------------
// Implementação do comando Cadastrar Usuario
// ---------------------------------------------
ComandoCadastrarUsuario::ComandoCadastrarUsuario(Usuario usuario)
{
        comandoSQL = "INSERT INTO usuario VALUES (";
        comandoSQL += "'" + usuario.getEmail().getEmail() + "', ";
        comandoSQL += "'" + usuario.getNome().getNome() + "', ";
        comandoSQL += "'" + usuario.getSenha().getSenha() + "')";
}

// ---------------------------------------------
// Implementação do comando Descadastrar Usuario
// ---------------------------------------------
ComandoDescadastrarUsuario::ComandoDescadastrarUsuario(Email email)
{
        comandoSQL = "DELETE FROM usuario WHERE email = '";
        comandoSQL += email.getEmail();
        comandoSQL += "'";
}

// ---------------------------------------------
// Implementação do comando Editar Usuário
// ---------------------------------------------

ComandoEditarUsuario::ComandoEditarUsuario(Usuario usuario)
{
        comandoSQL = "UPDATE usuario ";
        comandoSQL += "SET nome = '" + usuario.getNome().getNome();
        comandoSQL += "', senha = '" + usuario.getSenha().getSenha();
        comandoSQL += "' WHERE email = 'lucasbbs@live.fr'"; //+ usuario.getEmail().getEmail();
}

//ComandoPesquisarUsuario::ComandoPesquisarUsuario(Email email) {}

//--------------------------------------------------------------------------------------
//|                                 Excursão                                           |
//--------------------------------------------------------------------------------------

// ------------------------------------------------
// Implementação do comando Cadastrar Excursão
// ------------------------------------------------
ComandoCadastrarExcursao::ComandoCadastrarExcursao(Excursao excursao, Email email)
{
        comandoSQL = "INSERT INTO Excursao VALUES (";
        comandoSQL += "'" + excursao.getCodigo().getCodigo() + "', ";
        comandoSQL += "'" + excursao.getTitulo().getTitulo() + "', ";
        comandoSQL += "'" + to_string(excursao.getNota().getNota()) + "', ";
        comandoSQL += "'" + excursao.getCidade().getCidade() + "', ";
        comandoSQL += "'" + excursao.getDuracao().getDuracao() + "', ";
        comandoSQL += "'" + excursao.getEndereco().getEndereco() + "', ";
        comandoSQL += "'" + excursao.getDescricao().getDescricao() + "', ";
        comandoSQL += "'" + email.getEmail() + "')";
}

NextIdExcursao::NextIdExcursao()
{
        comandoSQL = "SELECT seq + 1 FROM SQLITE_SEQUENCE WHERE name='Excursao'";
}
int NextIdExcursao::getResultado()
{
        ElementoResultado resultado;
        int result;

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista Vazia.");
        }
        resultado = listaResultado.back();
        listaResultado.pop_back();

        result = stoi(resultado.getValorColuna());
        return result;
}

// ------------------------------------------------
// Implementação do comando Descadastrar Excursão
// ------------------------------------------------
ComandoDescadastrarExcursao::ComandoDescadastrarExcursao(Codigo codigo, Email email)
{
        comandoSQL = "DELETE FROM Excursao WHERE (Codigo = '";
        comandoSQL += codigo.getCodigo();
        comandoSQL += "') AND (Guia = '";
        comandoSQL += email.getEmail();
        comandoSQL += "')";
}

// ------------------------------------------------
// Implementação do comando Editar Excursão
// ------------------------------------------------

ComandoEditarExcursao::ComandoEditarExcursao(Excursao excursao, Email email)
{
        comandoSQL = "UPDATE Excursao ";
        comandoSQL += "SET Titulo = '" + excursao.getTitulo().getTitulo();
        comandoSQL += "', Nota = " + to_string(excursao.getNota().getNota());
        comandoSQL += ", Cidade = '" + excursao.getCidade().getCidade();
        comandoSQL += "', Duracao = " + excursao.getDuracao().getDuracao();
        comandoSQL += ", Descricao = '" + excursao.getDescricao().getDescricao();
        comandoSQL += "', Endereco = '" + excursao.getEndereco().getEndereco();
        comandoSQL += "' WHERE (Codigo = '" + excursao.getCodigo().getCodigo();
        comandoSQL += "') AND (Guia = '" + email.getEmail() + "')";
}

// ------------------------------------------------
// Implementação do comando Listar Excursões
// ------------------------------------------------

ComandoListarExcursoes::ComandoListarExcursoes()
{
        comandoSQL = "SELECT * FROM Excursao";
}

//--------------------------------------------------------------------------------------
//|                                   Sessão                                           |
//--------------------------------------------------------------------------------------

// ------------------------------------------------
// Implementação do comando Cadastrar Sessão
// ------------------------------------------------
ComandoCadastrarSessao::ComandoCadastrarSessao(Sessao sessao, Email email, Codigo codigo)
{
        comandoSQL = "INSERT INTO Sessao VALUES (";
        comandoSQL += "'" + sessao.getCodigo().getCodigo() + "', ";
        comandoSQL += "'" + sessao.getData().getData() + "', ";
        comandoSQL += "'" + sessao.getHorario().getHorario() + "', ";
        comandoSQL += "'" + sessao.getIdioma().getIdioma() + "', ";
        comandoSQL += "'" + codigo.getCodigo() + "')";
}

// NextIdExcursao::NextIdExcursao()
// {
//         comandoSQL = "SELECT seq + 1 FROM SQLITE_SEQUENCE WHERE name='Excursao'";
// }
// int NextIdExcursao::getResultado()
// {
//         ElementoResultado resultado;
//         int result;

//         if (listaResultado.empty())
//         {
//                 throw EErroPersistencia("Lista Vazia.");
//         }
//         resultado = listaResultado.back();
//         listaResultado.pop_back();

//         result = stoi(resultado.getValorColuna());
//         return result;
// }

// ------------------------------------------------
// Implementação do comando Descadastrar Sessão
// ------------------------------------------------
ComandoDescadastrarSessao::ComandoDescadastrarSessao(Codigo codigo, Email email)
{
        comandoSQL = "DELETE FROM Sessao WHERE (Codigo = '";
        comandoSQL += codigo.getCodigo();
        comandoSQL += "') AND (Guia = '";
        comandoSQL += email.getEmail();
        comandoSQL += "')";
}

// ------------------------------------------------
// Implementação do comando Editar Sessão
// ------------------------------------------------

ComandoEditarSessao::ComandoEditarSessao(Sessao sessao, Email email)
{
        comandoSQL = "UPDATE Sessao ";
        comandoSQL += "SET Data = '" + sessao.getData().getData();
        comandoSQL += "', Horario = " + sessao.getHorario().getHorario();
        comandoSQL += ", Idioma = '" + sessao.getIdioma().getIdioma();
        comandoSQL += "' WHERE (Codigo = '" + sessao.getCodigo().getCodigo();
        comandoSQL += "') AND (Guia = '" + email.getEmail() + "')";
}

// ------------------------------------------------
// Implementação do comando Listar Sessões
// ------------------------------------------------

ComandoListarSessoes::ComandoListarSessoes() {
        comandoSQL = "SELECT * FROM Sessao";
}

list<Sessao> ComandoListarSessoes::getResultado() {
        list<Sessao> sessoes;
        Codigo codigo;
        Data data;
        Horario horario;
        Idioma idioma;
        ElementoResultado resultado;
        
        while (!listaResultado.empty()) {
                Sessao sessao;
                // Adicionando valores pesquisados dentro dos domínios.
                if (listaResultado.empty()) {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                listaResultado.pop_back();
                if (listaResultado.empty()) {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                idioma.setIdioma(resultado.getValorColuna());
                listaResultado.pop_back();
                if (listaResultado.empty()) {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                horario.setHorario(resultado.getValorColuna());
                listaResultado.pop_back();
                if (listaResultado.empty()) {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                data.setData(resultado.getValorColuna());
                listaResultado.pop_back();
                if (listaResultado.empty()) {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                codigo.setCodigo(resultado.getValorColuna());
                listaResultado.pop_back();

                // Adicionando os domínios adicionados dentro da Sessão
                sessao.setCodigo(codigo);
                sessao.setData(data);
                sessao.setHorario(horario);
                sessao.setIdioma(idioma);
                sessoes.push_back(sessao);
        }
        return sessoes;
}

ComandoListarSessoes::ComandoListarSessoes(Excursao excursao){
        comandoSQL = "SELECT * FROM Sessao WHERE Excursao = ";
        comandoSQL += excursao.getCodigo().getCodigo();

}

// ------------------------------------------------
// Implementação do comando Recuperar Sessao
// ------------------------------------------------
ComandoRecuperarSessao::ComandoRecuperarSessao(Codigo codigo)
{
        comandoSQL = "SELECT * FROM Sessao WHERE Codigo = ";
        comandoSQL += codigo.getCodigo();
}

Sessao ComandoRecuperarSessao::getResultado() {
        Sessao sessao;
        Codigo codigo;
        Data data;
        Horario horario;
        Idioma idioma;
        ElementoResultado resultado;

        // Adicionando valores pesquisados dentro dos domínios.
        if (listaResultado.empty()) {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        listaResultado.pop_back();
        if (listaResultado.empty()) {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        idioma.setIdioma(resultado.getValorColuna());
        listaResultado.pop_back();
        if (listaResultado.empty()) {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        horario.setHorario(resultado.getValorColuna());
        listaResultado.pop_back();
        if (listaResultado.empty()) {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        data.setData(resultado.getValorColuna());
        listaResultado.pop_back();
        if (listaResultado.empty()) {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        codigo.setCodigo(resultado.getValorColuna());
        listaResultado.pop_back();

        // Adicionando os domínios adicionados dentro da Sessão
        sessao.setCodigo(codigo);
        sessao.setData(data);
        sessao.setHorario(horario);
        sessao.setIdioma(idioma);

        return sessao;
}