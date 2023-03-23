#!/usr/bin/env python4

import socket

HOST = 'localhost'
PORT = 5000

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen()

print('Aguardando conexao de um cliente')
conn, ender = s.accept()  #aceitar conexao

print('Conectado em', ender)
# recebe o nome
nota1 = float(conn.recv(1024).decode())
#Envia os dados de volta para confirmação
#conn.send(('mensagem resposta do serv' + nome).encode())
nota2 = float(conn.recv(1024).decode())


media = (nota1+nota2)/2
if media >= 7:
    conn.send(("Aprovado(a)!").encode())
    
elif media <= 3:
    conn.send(("Reprovado(a)!").encode())

elif media > 3 and media < 7:
    conn.send(('nota 3').encode())
    nota3 = float(conn.recv(1024).decode())
    mediaTotal = (media+nota3)/2

    if mediaTotal >= 5:
        conn.send(("Aprovado(a)!").encode())
    else:
        conn.send(("Reprovado(a)!").encode())



conn.close()
s.close()
