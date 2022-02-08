#!/usr/bin/env python3

"""
 @file formatEmails.py

 @brief this file is the base structure of email validation using python.

 @author Aquila Macedo  - 202021800

"""

def isValid(local, dominio, n, m):
    if n > 64:
        return "Email Invalido. A parte local do email nao pode passar de 64 caracteres."
    if m > 253:
        return "Email Invalido. A parte dominio do email nao pode passar de 253 caracteres."
    
    lista = ["!", "#", "$", "%", "&", "'", "*", "+", "-", "/", "=", "?", "^", "_", "`", "{", "|", "}", "~", "."]
    flag = 0
    especialChars = ""
    for i in range(n):
        if not(local[i].isalpha()) and not(local[i].isdigit()):
                especialChars+=local[i]
        if (local[0] == '.' or local[n-1] == '.') or (local[i] == '.' and i != n-1 and local[i+1] == '.'):
            return "Email Invalido. A parte local nao pode conter ponto(.) no primeiro e no ultimo caractere, tambem nao eh possivel pontos consecultivos."
    
    for i in range(len(especialChars)):
        for j in range(len(lista)):
            if especialChars[i] == lista[j]:
                flag+=1
    
    if len(especialChars) != flag:
        return "Email Invalido. Utilize apenas os seguintes caracteres especiais !#$%&'*+-/=?^_`{|}~"

    for i in range(m):
        if not(dominio[i].isalpha()) and not(dominio[i].isdigit()) and dominio[i] != "-" and dominio[i] != '.':
            return "Email Invalido. Na parte dominio apenas os caracteres (A-Z ou a-z), hifen(-), ponto(.) e digitos(0-9) podem ser utilizados."
        if (dominio[0] == '.') or (i != m-1 and dominio[i] == '.' and dominio[i+1] == '.'):
            return "Email Invalido. A parte dominio o primeiro caractere nao pode ser um ponto(.) e tambem nao eh possivel pontos consecultivos."
    return True


entrada = input()

parte_local, dominio = entrada.split("@")
tamanhoLocal, tamanhoDominio = len(parte_local), len(dominio)

print(isValid(parte_local, dominio, tamanhoLocal, tamanhoDominio))

