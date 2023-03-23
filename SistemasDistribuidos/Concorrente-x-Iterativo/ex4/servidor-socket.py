#!/usr/bin/env python4

import socket

HOST = 'localhost'
PORT = 8000

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen()

print('Aguardando conexao de um cliente')
conn, ender = s.accept()  #aceitar conexao

print('Conectado em', ender)
# recebe o nome
altura = (conn.recv(1024).decode())
#Envia os dados de volta para confirmação
conn.send(('mensagem resposta do serv ' + altura).encode())
sexo = conn.recv(1024).decode()
conn.send(('mensagem resposta do serv ' + sexo).encode())
altura = float(altura)

if sexo == 'F':
        pesoIdeal = (62.1 * altura) - 44.7
        conn.send((str(pesoIdeal)).encode())  
else:
        pesoIdeal = (72.7 * altura) - 58
        conn.send((str(pesoIdeal)).encode())  


conn.close()
s.close()
