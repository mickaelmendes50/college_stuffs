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
# recebe o idade
idade = (conn.recv(1024).decode())
idade = int(idade)

if idade >= 5 and idade <= 7:
        conn.send(('infantil A').encode())  
elif idade >= 8 and idade <= 10:
        conn.send(('infantil B').encode()) 
elif idade >= 11 and idade <= 13:
        conn.send(('juvenil A').encode()) 
elif idade >= 14 and idade <= 17:
        conn.send(('juvenil B').encode()) 
elif idade >= 18:
        conn.send(('adulto').encode()) 
else:
        conn.send((0).encode()) 


conn.close()
s.close()
