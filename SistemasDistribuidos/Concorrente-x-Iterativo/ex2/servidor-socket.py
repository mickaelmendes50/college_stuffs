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
nome = conn.recv(1024).decode()
sexo = conn.recv(1024).decode()
idade = conn.recv(1024).decode()


if (sexo == 'F' and int(idade) >= 21) or (sexo == 'M' and int(idade) >= 18):
        
    conn.send(("Maioridade").encode()) #Envia a resposta para o cliente
else:
    conn.send(("Menor Idade").encode())

