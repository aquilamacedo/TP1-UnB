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
        comandoSQL = "PRAGMA foreign_keys = ON;";
        comandoSQL += "SELECT senha FROM usuario WHERE email = '";
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
        comandoSQL += "INSERT INTO usuario VALUES (";
        comandoSQL += "'" + usuario.getEmail().getEmail() + "', ";
        comandoSQL += "'" + usuario.getNome().getNome() + "', ";
        comandoSQL += "'" + usuario.getSenha().getSenha() + "')";
}

// ---------------------------------------------
// Implementação do comando Descadastrar Usuario
// ---------------------------------------------
ComandoDescadastrarUsuario::ComandoDescadastrarUsuario(Email email)
{
        comandoSQL = "PRAGMA foreign_keys = ON; DELETE FROM usuario WHERE email = '";
        comandoSQL += email.getEmail();
        comandoSQL += "';";
}

// ---------------------------------------------
// Implementação do comando Editar Usuário
// ---------------------------------------------

ComandoEditarUsuario::ComandoEditarUsuario(Usuario usuario)
{
        comandoSQL = "UPDATE usuario ";
        comandoSQL += "SET nome = '" + usuario.getNome().getNome();
        comandoSQL += "', senha = '" + usuario.getSenha().getSenha();
        comandoSQL += "' WHERE email = '" + usuario.getEmail().getEmail() + "'";
}

// ---------------------------------------------
// Implementação do comando Checar Usuario
// ---------------------------------------------
ComandoChecarUsuario::ComandoChecarUsuario()
{
        comandoSQL = "SELECT Email from usuario";
}

list<string> ComandoChecarUsuario::getResultado()
{
        ElementoResultado resultado;
        list<string> elementos;
        while (!listaResultado.empty())
        {
                resultado = listaResultado.back();
                listaResultado.pop_back();
                elementos.push_back(resultado.getValorColuna());
        }
        return elementos;
}

// ---------------------------------------------
// Implementação do comando Recuperar Usuario
// ---------------------------------------------

ComandoRecuperarUsuario::ComandoRecuperarUsuario(Usuario usuario)
{
        comandoSQL = "SELECT * FROM usuario WHERE Email = '" + usuario.getEmail().getEmail() + "'";
}

Usuario ComandoRecuperarUsuario::getResultado()
{
        Usuario usuario;

        Email email;
        Nome nome;
        Senha senha;
        ElementoResultado resultado;

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        email.setEmail(resultado.getValorColuna());
        listaResultado.pop_back(); //1

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        nome.setNome(resultado.getValorColuna());
        listaResultado.pop_back(); //2

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        senha.setSenha(resultado.getValorColuna());
        listaResultado.pop_back(); //3

        usuario.setEmail(email);
        usuario.setNome(nome);
        usuario.setSenha(senha);

        return usuario;
}
//--------------------------------------------------------------------------------------
//|                                 Excursão                                           |
//--------------------------------------------------------------------------------------

// ------------------------------------------------
// Implementação do comando Cadastrar Excursão
// ------------------------------------------------
ComandoCadastrarExcursao::ComandoCadastrarExcursao(Excursao excursao, Email email, int digito_verificador)
{
        comandoSQL = "PRAGMA foreign_keys = ON;";
        comandoSQL += "INSERT INTO Excursao VALUES (";
        comandoSQL += "NULL, ";
        comandoSQL += "'" + excursao.getTitulo().getTitulo() + "', ";
        comandoSQL += "-1, ";
        comandoSQL += "'" + excursao.getCidade().getCidade() + "', ";
        comandoSQL += "'" + excursao.getDuracao().getDuracao() + "', ";
        comandoSQL += "'" + excursao.getEndereco().getEndereco() + "', ";
        comandoSQL += "'" + excursao.getDescricao().getDescricao() + "', ";
        comandoSQL += "'" + to_string(digito_verificador) + "', ";
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
        string icodigo = codigo.getCodigo();
        icodigo.pop_back();
        comandoSQL = "PRAGMA foreign_keys = ON; DELETE FROM Excursao WHERE (Codigo = '";
        comandoSQL += icodigo;
        comandoSQL += "') AND (Guia = '";
        comandoSQL += email.getEmail();
        comandoSQL += "')";
}

// ------------------------------------------------
// Implementação do comando Listar Excursões
// ------------------------------------------------
ComandoListarExcursoes::ComandoListarExcursoes()
{
        comandoSQL = "SELECT * FROM Excursao";
}
list<Excursao> ComandoListarExcursoes::getResultado()
{
        list<Excursao> excursoes;

        Codigo codigo;
        Titulo titulo;
        Nota nota;
        Cidade cidade;
        Duracao duracao;
        Endereco endereco;
        Descricao descricao;
        Email email;
        int digito_verificador;

        ElementoResultado resultado;

        while (!listaResultado.empty())
        {
                Excursao excursao;

                // Adicionando valores pesquisados dentro dos domínios.
                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                codigo.setCodigo(codigo.getCodigoDigitoVerificador(stoi(resultado.getValorColuna())));
                listaResultado.pop_back(); //1

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                titulo.setTitulo(resultado.getValorColuna());
                listaResultado.pop_back(); //2

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                nota.setNotaMedia(stof(resultado.getValorColuna()));
                listaResultado.pop_back(); //3

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                cidade.setCidade(resultado.getValorColuna());
                listaResultado.pop_back(); //4

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                duracao.setDuracao(resultado.getValorColuna());
                listaResultado.pop_back(); //5

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                endereco.setEndereco(resultado.getValorColuna());
                listaResultado.pop_back(); //6

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                descricao.setDescricao(resultado.getValorColuna());
                listaResultado.pop_back(); //7

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                digito_verificador = stoi(resultado.getValorColuna());
                listaResultado.pop_back(); //8

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                email.setEmail(resultado.getValorColuna());
                listaResultado.pop_back(); //9

                // Adicionando os domínios adicionados dentro da Sessão
                excursao.setCodigo(codigo);
                excursao.setTitulo(titulo);
                excursao.setNota(nota);
                excursao.setCidade(cidade);
                excursao.setDuracao(duracao);
                excursao.setEndereco(endereco);
                excursao.setDescricao(descricao);
                excursao.setEmail(email);
                excursoes.push_back(excursao);
        }
        return excursoes;
}
// ------------------------------------------------
// Implementação do comando Editar Excursão
// ------------------------------------------------

ComandoEditarExcursao::ComandoEditarExcursao(Excursao excursao, Email email)
{
        string icodigo = excursao.getCodigo().getCodigo();
        icodigo.pop_back();
        comandoSQL = "PRAGMA foreign_keys = ON;";
        comandoSQL += "UPDATE Excursao ";
        comandoSQL += "SET Titulo = '" + excursao.getTitulo().getTitulo();
        comandoSQL += "', Cidade = '" + excursao.getCidade().getCidade();
        comandoSQL += "', Duracao = " + excursao.getDuracao().getDuracao();
        comandoSQL += ", Descricao = '" + excursao.getDescricao().getDescricao();
        comandoSQL += "', Endereco = '" + excursao.getEndereco().getEndereco();
        comandoSQL += "' WHERE (Codigo = '" + icodigo;
        comandoSQL += "') AND (Guia = '" + email.getEmail() + "')";
}

// ------------------------------------------------
// Implementação do comando Recuperar Excursao
// ------------------------------------------------
ComandoRecuperarExcursao::ComandoRecuperarExcursao(Codigo codigo)
{
        string icodigo = codigo.getCodigo();
        icodigo.pop_back();

        comandoSQL = "SELECT * FROM Excursao WHERE Codigo = ";
        comandoSQL += icodigo;
}

// -------------------------------------------------------
// Implementação do comando Recuperar Excursao - getResultado
// -------------------------------------------------------
Excursao ComandoRecuperarExcursao::getResultado()
{
        Excursao excursao;
        Codigo codigo;
        Titulo titulo;
        Nota nota;
        Cidade cidade;
        Duracao duracao;
        Endereco endereco;
        Descricao descricao;
        int digito_verificador;
        Email email;

        ElementoResultado resultado;

        // Adicionando valores pesquisados dentro dos domínios.
        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        codigo.setCodigo(codigo.getCodigoDigitoVerificador(stoi(resultado.getValorColuna())));
        listaResultado.pop_back(); //1

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        titulo.setTitulo(resultado.getValorColuna());
        listaResultado.pop_back(); //2

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        nota.setNotaMedia(stof(resultado.getValorColuna()));
        listaResultado.pop_back(); //3

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        cidade.setCidade(resultado.getValorColuna());
        listaResultado.pop_back(); //4

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        duracao.setDuracao(resultado.getValorColuna());
        listaResultado.pop_back(); //5

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        endereco.setEndereco(resultado.getValorColuna());
        listaResultado.pop_back(); //6

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        descricao.setDescricao(resultado.getValorColuna());
        listaResultado.pop_back(); //7

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        digito_verificador = stoi(resultado.getValorColuna());
        listaResultado.pop_back(); //8

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        email.setEmail(resultado.getValorColuna());
        listaResultado.pop_back(); //9

        // Adicionando os domínios adicionados dentro da Sessão
        excursao.setCodigo(codigo);
        excursao.setTitulo(titulo);
        excursao.setNota(nota);
        excursao.setCidade(cidade);
        excursao.setDuracao(duracao);
        excursao.setEndereco(endereco);
        excursao.setDescricao(descricao);
        excursao.setEmail(email);

        return excursao;
}
// ------------------------------------------------
// Implementação do comando Checar Excursão
// ------------------------------------------------
ComandoChecarExcursao::ComandoChecarExcursao(Email email)
{
        comandoSQL = "SELECT Codigo from Excursao where Guia = '";
        comandoSQL += email.getEmail() + "'";
}

list<string> ComandoChecarExcursao::getResultado()
{
        ElementoResultado resultado;
        list<string> elementos;
        while (!listaResultado.empty())
        {
                resultado = listaResultado.back();
                listaResultado.pop_back();
                elementos.push_back(resultado.getValorColuna());
        }
        return elementos;
}

//--------------------------------------------------------------------------------------
//|                                   Sessão                                           |
//--------------------------------------------------------------------------------------

// ------------------------------------------------
// Implementação do comando Cadastrar Sessão
// ------------------------------------------------
ComandoCadastrarSessao::ComandoCadastrarSessao(Sessao sessao, Email email, Codigo codigo, int digito_verificador)
{
        string codigoId = codigo.getCodigo();
        codigoId.pop_back();
        comandoSQL = "PRAGMA foreign_keys = ON;";
        comandoSQL += "INSERT INTO Sessao VALUES (";
        comandoSQL += "NULL, ";
        comandoSQL += "'" + sessao.getData().getData() + "', ";
        comandoSQL += "'" + sessao.getHorario().getHorario() + "', ";
        comandoSQL += "'" + sessao.getIdioma().getIdioma() + "', ";
        comandoSQL += "'" + to_string(digito_verificador) + "', ";
        comandoSQL += "'" + codigoId + "')";
}

NextIdSessao::NextIdSessao()
{
        comandoSQL = "SELECT seq + 1 FROM SQLITE_SEQUENCE WHERE name='Sessao'";
}
int NextIdSessao::getResultado()
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
// Implementação do comando Descadastrar Sessão
// ------------------------------------------------
ComandoDescadastrarSessao::ComandoDescadastrarSessao(Codigo codigo, Email email)
{
        string icodigo = codigo.getCodigo();
        icodigo.pop_back();
        comandoSQL = "PRAGMA foreign_keys = ON; DELETE FROM Sessao WHERE Codigo in ";
        comandoSQL += "(SELECT Sessao.Codigo FROM Sessao LEFT JOIN Excursao ON Excursao.Codigo = Sessao.Excursao ";
        comandoSQL += "WHERE Sessao.Codigo = ";
        comandoSQL += icodigo;
        comandoSQL += " AND Excursao.Guia = '";
        comandoSQL += email.getEmail() + "')";
}

/*
 WHERE Sessao.Codigo = 12 AND Excursao.Guia = "lucasbbs@live.fr")
*/
// ------------------------------------------------
// Implementação do comando Editar Sessão
// ------------------------------------------------

ComandoEditarSessao::ComandoEditarSessao(Sessao sessao, Email email)
{
        string icodigo = sessao.getCodigo().getCodigo();
        icodigo.pop_back();
        comandoSQL = "PRAGMA foreign_keys = ON;";
        comandoSQL += "UPDATE Sessao ";
        comandoSQL += "SET Data = '" + sessao.getData().getData();
        comandoSQL += "', Horario = '" + sessao.getHorario().getHorario();
        comandoSQL += "', Idioma = '" + sessao.getIdioma().getIdioma();
        comandoSQL += "' WHERE Codigo in (SELECT Sessao.Codigo FROM Sessao LEFT JOIN Excursao ON Excursao.Codigo = Sessao.Excursao ";
        comandoSQL += "WHERE Sessao.Codigo = " + icodigo;
        comandoSQL += " AND Excursao.Guia = '" + email.getEmail() + "')";
}

// ------------------------------------------------
// Implementação do comando Listar Sessões
// ------------------------------------------------

ComandoListarSessoes::ComandoListarSessoes()
{
        comandoSQL = "SELECT * FROM Sessao";
}

ComandoListarSessoes::ComandoListarSessoes(Excursao excursao)
{
        string icodigo = excursao.getCodigo().getCodigo();
        icodigo.pop_back();
        comandoSQL = "SELECT * FROM Sessao WHERE Excursao = ";
        comandoSQL += icodigo;
}
// -----------------------------------------------------
// Implementação do comando ListarSessoes getResultado
// -----------------------------------------------------
list<Sessao> ComandoListarSessoes::getResultado()
{
        list<Sessao> sessoes;
        Codigo codigo;
        Codigo codigoExcursao;
        Data data;
        Horario horario;
        Idioma idioma;
        ElementoResultado resultado;
        while (!listaResultado.empty())
        {
                Sessao sessao;
                // Adicionando valores pesquisados dentro dos domínios.
                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                codigo.setCodigo(codigo.getCodigoDigitoVerificador(stoi(resultado.getValorColuna())));
                listaResultado.pop_back(); //1

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                data.setData(resultado.getValorColuna());
                listaResultado.pop_back(); //2

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                horario.setHorario(resultado.getValorColuna());

                listaResultado.pop_back(); //3

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                idioma.setIdioma(resultado.getValorColuna());

                listaResultado.pop_back(); //4

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();

                listaResultado.pop_back(); //5

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                codigoExcursao.setCodigo(codigoExcursao.getCodigoDigitoVerificador(stoi(resultado.getValorColuna())));

                listaResultado.pop_back(); //6

                // Adicionando os domínios adicionados dentro da Sessão
                sessao.setCodigo(codigo);
                sessao.setData(data);
                sessao.setHorario(horario);
                sessao.setIdioma(idioma);
                sessao.setCodigoExcursao(codigoExcursao);
                sessoes.push_back(sessao);
        }

        return sessoes;
}

// ------------------------------------------------
// Implementação do comando Recuperar Sessao
// ------------------------------------------------
ComandoRecuperarSessao::ComandoRecuperarSessao(Codigo codigo)
{
        string icodigo = codigo.getCodigo();
        icodigo.pop_back();
        comandoSQL = "SELECT * FROM Sessao WHERE Codigo = ";
        comandoSQL += icodigo;
}

// -------------------------------------------------------
// Implementação do comando Recuperar Sessao- getResultado
// -------------------------------------------------------
Sessao ComandoRecuperarSessao::getResultado()
{
        Sessao sessao;
        Codigo codigo;
        Data data;
        Horario horario;
        Idioma idioma;
        int digito_verificador;
        Codigo codigoExcursao;
        ElementoResultado resultado;

        // Adicionando valores pesquisados dentro dos domínios.
        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        codigo.setCodigo(codigo.getCodigoDigitoVerificador(stoi(resultado.getValorColuna())));
        listaResultado.pop_back(); //1

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        data.setData(resultado.getValorColuna());
        listaResultado.pop_back(); //2

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        horario.setHorario(resultado.getValorColuna());

        listaResultado.pop_back(); //3

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        idioma.setIdioma(resultado.getValorColuna());

        listaResultado.pop_back(); //4

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();

        listaResultado.pop_back(); //5

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        codigoExcursao.setCodigo(codigoExcursao.getCodigoDigitoVerificador(stoi(resultado.getValorColuna())));

        listaResultado.pop_back(); //6

        // Adicionando os domínios adicionados dentro da Sessão
        sessao.setCodigo(codigo);
        sessao.setData(data);
        sessao.setHorario(horario);
        sessao.setIdioma(idioma);
        sessao.setCodigoExcursao(codigoExcursao);

        return sessao;
}

ComandoChecarSessao::ComandoChecarSessao(Codigo codigo, Email email)
{
        string icodigo = codigo.getCodigo();
        icodigo.pop_back();
        comandoSQL = "SELECT * FROM Sessao WHERE Codigo in ";
        comandoSQL += "(SELECT Sessao.Codigo FROM Sessao LEFT JOIN Excursao ON Excursao.Codigo = Sessao.Excursao ";
        comandoSQL += "WHERE Sessao.Codigo = ";
        comandoSQL += icodigo;
        comandoSQL += " AND Excursao.Guia = '";
        comandoSQL += email.getEmail() + "')";
}

bool ComandoChecarSessao::getResultado()
{
        if (listaResultado.empty())
        {
                return false;
        }
        else
        {
                while (!listaResultado.empty())
                {
                        listaResultado.pop_back();
                }
                return true;
        }
}

//--------------------------------------------------------------------------------------
//|                                  Avaliação                                         |
//--------------------------------------------------------------------------------------

// ------------------------------------------------
// Implementação do comando Cadastrar Avaliação
// ------------------------------------------------
ComandoCadastrarAvaliacao::ComandoCadastrarAvaliacao(Avaliacao avaliacao, Email email, Codigo codigo, int digito_verificador)
{
        string codigoId = codigo.getCodigo();
        codigoId.pop_back();
        comandoSQL = "PRAGMA foreign_keys = ON;";
        comandoSQL += "INSERT INTO Avaliacao VALUES (";
        comandoSQL += "NULL, ";
        comandoSQL += "" + to_string(avaliacao.getNota().getNota()) + ", ";
        comandoSQL += "'" + avaliacao.getDescricao().getDescricao() + "', ";
        comandoSQL += "'" + to_string(digito_verificador) + "', ";
        comandoSQL += "'" + email.getEmail() + "', ";
        comandoSQL += "'" + codigoId + "')";
}

// ------------------------------------------------
// Implementação do comando Recuperar Avaliação
// ------------------------------------------------
ComandoRecuperarAvaliacao::ComandoRecuperarAvaliacao(Codigo codigo)
{
        string icodigo = codigo.getCodigo();
        icodigo.pop_back();
        comandoSQL = "SELECT * FROM Avaliacao WHERE Codigo = ";
        comandoSQL += icodigo;
}

// -------------------------------------------------------
// Implementação do comando Recuperar Avaliação - getResultado
// -------------------------------------------------------

Avaliacao ComandoRecuperarAvaliacao::getResultado()
{
        Avaliacao avaliacao;

        Codigo codigo;
        Nota nota;
        Descricao descricao;
        Email avaliador;
        Codigo codigoExcursao;
        int digito_verificador;

        ElementoResultado resultado;

        // Adicionando valores pesquisados dentro dos domínios.
        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        codigo.setCodigo(codigo.getCodigoDigitoVerificador(stoi(resultado.getValorColuna())));
        listaResultado.pop_back(); //1

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        nota.setNota(stoi(resultado.getValorColuna()));
        listaResultado.pop_back(); //2

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        descricao.setDescricao(resultado.getValorColuna());

        listaResultado.pop_back(); //3

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();

        digito_verificador = stoi(resultado.getValorColuna());

        listaResultado.pop_back(); //4

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        avaliador.setEmail(resultado.getValorColuna());
        listaResultado.pop_back(); //5

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista de resultados vazia!");
        }
        resultado = listaResultado.back();
        codigoExcursao.setCodigo(codigoExcursao.getCodigoDigitoVerificador(stoi(resultado.getValorColuna())));

        listaResultado.pop_back(); //6

        // Adicionando os domínios adicionados dentro da Sessão
        avaliacao.setCodigo(codigo);
        avaliacao.setNota(nota);
        avaliacao.setDescricao(descricao);
        avaliacao.setEmail(avaliador);
        avaliacao.setCodigoExcursao(codigoExcursao);

        return avaliacao;
}

GetNotasAvaliacao::GetNotasAvaliacao(int codigo)
{
        comandoSQL = "SELECT Nota FROM Avaliacao where Excursao = ";
        comandoSQL += to_string(codigo);
}
bool GetNotasAvaliacao::getResultado()
{
        ElementoResultado resultado;

        if (listaResultado.empty())
        {
                return false;
        }
        else
        {
                while (!listaResultado.empty())
                {
                        listaResultado.pop_back();
                }

                return true;
        }
}

GetNotasMediaAvaliacao::GetNotasMediaAvaliacao(int codigo)
{
        this->codigo = codigo;
        comandoSQL = "SELECT avg(Nota) FROM Avaliacao where Excursao = ";
        comandoSQL += to_string(codigo);
}
float GetNotasMediaAvaliacao::getResultado()
{
        ElementoResultado resultado;

        if (listaResultado.empty())
        {
                throw EErroPersistencia("Lista Vazia.");
        }
        resultado = listaResultado.back();
        listaResultado.pop_back();
        GetNotasAvaliacao notas(codigo);
        notas.executar();
        if (notas.getResultado())
        {
                return stof(resultado.getValorColuna());
        }
        else
        {
                return -1;
        }
}

NextIdAvaliacao::NextIdAvaliacao()
{
        comandoSQL = "SELECT seq + 1 FROM SQLITE_SEQUENCE WHERE name='Avaliacao'";
}
int NextIdAvaliacao::getResultado()
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
// Implementação do comando Descadastrar Avaliação
// ------------------------------------------------
ComandoDescadastrarAvaliacao::ComandoDescadastrarAvaliacao(Codigo codigo, Email email)
{
        string icodigo = codigo.getCodigo();
        icodigo.pop_back();
        comandoSQL = "PRAGMA foreign_keys = ON; DELETE FROM Avaliacao WHERE (Codigo = '";
        comandoSQL += icodigo;
        comandoSQL += "') AND (Avaliador = '";
        comandoSQL += email.getEmail();
        comandoSQL += "')";
}

// ------------------------------------------------
// Implementação do comando Editar Avaliação
// ------------------------------------------------

ComandoEditarAvaliacao::ComandoEditarAvaliacao(Avaliacao avaliacao, Email email)
{
        string icodigo = avaliacao.getCodigo().getCodigo();
        icodigo.pop_back();
        comandoSQL = "PRAGMA foreign_keys = ON;";
        comandoSQL += "UPDATE Avaliacao ";
        comandoSQL += "SET Nota = '" + to_string((int)avaliacao.getNota().getNota());
        comandoSQL += "', Descricao = '" + avaliacao.getDescricao().getDescricao();
        comandoSQL += "' WHERE (Codigo = '" + icodigo;
        comandoSQL += "') AND (Avaliador = '" + email.getEmail() + "')";
}

// ------------------------------------------------
// Implementação do comando Atualizar Nonta Excursao
// ------------------------------------------------

ComandoAtualizarNotaExcursao::ComandoAtualizarNotaExcursao(float averageGrade, Email email, Codigo codigo)
{
        string codigoId = codigo.getCodigo();
        codigoId.pop_back();
        comandoSQL = "PRAGMA foreign_keys = ON;";
        comandoSQL += "UPDATE Excursao ";
        comandoSQL += "SET Nota = " + to_string(averageGrade);
        comandoSQL += " WHERE Codigo = " + codigoId;
}
// ------------------------------------------------
// Implementação do comando Checar Avaliação
// ------------------------------------------------
ComandoChecarAvaliacao::ComandoChecarAvaliacao(Email email)
{
        comandoSQL = "SELECT Codigo from Avaliacao where Avaliador = '";
        comandoSQL += email.getEmail() + "'";
}

list<string> ComandoChecarAvaliacao::getResultado()
{
        ElementoResultado resultado;
        list<string> elementos;
        while (!listaResultado.empty())
        {
                resultado = listaResultado.back();
                listaResultado.pop_back();
                elementos.push_back(resultado.getValorColuna());
        }
        return elementos;
}

// ------------------------------------------------
// Implementação do comando Listar Sessões
// ------------------------------------------------

ComandoListarAvaliacoes::ComandoListarAvaliacoes()
{
        comandoSQL = "SELECT * FROM Avaliacao";
}

ComandoListarAvaliacoesExcursao::ComandoListarAvaliacoesExcursao(Excursao excursao)
{
        string icodigo = excursao.getCodigo().getCodigo();
        icodigo.pop_back();
        comandoSQL = "SELECT * FROM Avaliacao WHERE Excursao = ";
        comandoSQL += icodigo;
}
list<Avaliacao> ComandoListarAvaliacoesExcursao::getResultado()
{
        list<Avaliacao> avaliacoes;
        Codigo codigo;
        Nota nota;
        Descricao descricao;
        int digito_verificador;
        Email avaliador;
        Codigo codigoExcursao;

        ElementoResultado resultado;

        while (!listaResultado.empty())
        {
                Avaliacao avaliacao;
                // Adicionando valores pesquisados dentro dos domínios.
                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                codigo.setCodigo(codigo.getCodigoDigitoVerificador(stoi(resultado.getValorColuna())));
                listaResultado.pop_back(); //1

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                nota.setNota(stoi(resultado.getValorColuna()));
                listaResultado.pop_back(); //2

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                descricao.setDescricao(resultado.getValorColuna());

                listaResultado.pop_back(); //3

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                digito_verificador = stoi(resultado.getValorColuna());

                listaResultado.pop_back(); //4

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                avaliador.setEmail(resultado.getValorColuna());
                listaResultado.pop_back(); //5

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                codigoExcursao.setCodigo(codigoExcursao.getCodigoDigitoVerificador(stoi(resultado.getValorColuna())));

                listaResultado.pop_back(); //6

                // Adicionando os domínios adicionados dentro da Sessão
                avaliacao.setCodigo(codigo);
                avaliacao.setNota(nota);
                avaliacao.setDescricao(descricao);
                avaliacao.setEmail(avaliador);
                avaliacao.setCodigoExcursao(codigoExcursao);
                avaliacoes.push_back(avaliacao);
        }

        return avaliacoes;
}

ComandoListarAvaliacoesUsuario::ComandoListarAvaliacoesUsuario(Usuario usuario)
{

        comandoSQL = "SELECT * FROM Avaliacao WHERE Avaliador = '";
        comandoSQL += usuario.getEmail().getEmail() + "'";
}
list<Avaliacao> ComandoListarAvaliacoesUsuario::getResultado()
{
        list<Avaliacao> avaliacoes;
        Codigo codigo;
        Nota nota;
        Descricao descricao;
        int digito_verificador;
        Email avaliador;
        Codigo codigoExcursao;

        ElementoResultado resultado;

        while (!listaResultado.empty())
        {
                Avaliacao avaliacao;
                // Adicionando valores pesquisados dentro dos domínios.
                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                codigo.setCodigo(codigo.getCodigoDigitoVerificador(stoi(resultado.getValorColuna())));
                listaResultado.pop_back(); //1

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                nota.setNota(stoi(resultado.getValorColuna()));
                listaResultado.pop_back(); //2

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                descricao.setDescricao(resultado.getValorColuna());

                listaResultado.pop_back(); //3

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                digito_verificador = stoi(resultado.getValorColuna());

                listaResultado.pop_back(); //4

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                avaliador.setEmail(resultado.getValorColuna());
                listaResultado.pop_back(); //5

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                codigoExcursao.setCodigo(codigoExcursao.getCodigoDigitoVerificador(stoi(resultado.getValorColuna())));

                listaResultado.pop_back(); //6

                // Adicionando os domínios adicionados dentro da Sessão
                avaliacao.setCodigo(codigo);
                avaliacao.setNota(nota);
                avaliacao.setDescricao(descricao);
                avaliacao.setEmail(avaliador);
                avaliacao.setCodigoExcursao(codigoExcursao);
                avaliacoes.push_back(avaliacao);
        }

        return avaliacoes;
}

// -----------------------------------------------------
// Implementação do comando ListarAvaliacoes getResultado
// -----------------------------------------------------
list<Avaliacao> ComandoListarAvaliacoes::getResultado()
{
        list<Avaliacao> avaliacoes;
        Codigo codigo;
        Nota nota;
        Descricao descricao;
        int digito_verificador;
        Email avaliador;
        Codigo codigoExcursao;

        ElementoResultado resultado;

        while (!listaResultado.empty())
        {
                Avaliacao avaliacao;
                // Adicionando valores pesquisados dentro dos domínios.
                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                codigo.setCodigo(codigo.getCodigoDigitoVerificador(stoi(resultado.getValorColuna())));
                listaResultado.pop_back(); //1

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                nota.setNota(stoi(resultado.getValorColuna()));
                listaResultado.pop_back(); //2

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                descricao.setDescricao(resultado.getValorColuna());

                listaResultado.pop_back(); //3

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                digito_verificador = stoi(resultado.getValorColuna());

                listaResultado.pop_back(); //4

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                avaliador.setEmail(resultado.getValorColuna());
                listaResultado.pop_back(); //5

                if (listaResultado.empty())
                {
                        throw EErroPersistencia("Lista de resultados vazia!");
                }
                resultado = listaResultado.back();
                codigoExcursao.setCodigo(codigoExcursao.getCodigoDigitoVerificador(stoi(resultado.getValorColuna())));

                listaResultado.pop_back(); //6

                // Adicionando os domínios adicionados dentro da Sessão
                avaliacao.setCodigo(codigo);
                avaliacao.setNota(nota);
                avaliacao.setDescricao(descricao);
                avaliacao.setEmail(avaliador);
                avaliacao.setCodigoExcursao(codigoExcursao);
                avaliacoes.push_back(avaliacao);
        }

        return avaliacoes;
}