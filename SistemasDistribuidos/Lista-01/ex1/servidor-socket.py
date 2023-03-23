#!/usr/bin/env python4

import socket

HOST = 'localhost'
PORT = 8000

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))# Colocando um endereço IP e uma porta no Socket
s.listen(0) # Colocando o Socket em modo passivo

print('Aguardando conexao de um cliente')

conn, ender = s.accept()  #aceitar conexao
print('Conectado em', ender)

nome = conn.recv(1024).decode()
#conn.send(('mensagem resposta do serv' + nome).encode())
cargo = conn.recv(1024).decode()
#conn.send(('mensagem resposta do serv' + cargo).encode())
salario = conn.recv(1024).decode()
#conn.send(('mensagem resposta do serv' + salario).encode())

salario = float(salario)

if cargo == 'operador':
    salarioReajustado = float(salario + salario *0.2)
    
else:
    salarioReajustado = float(salario+salario*0.18)
  
    
MensagemFinal = nome + "| Salario Final: " + str(salarioReajustado)
conn.send(MensagemFinal.encode()) #Envia a resposta final para o cliente

conn.close()

