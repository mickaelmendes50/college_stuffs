#!/usr/bin/env python4

import socket

HOST = '127.0.0.1' # Endereço IP do Servidor
PORT = 8000 # Porta que o Servidor está

# Criando a conexão
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #tcp
s.connect((HOST, PORT))


nome = input('Digite o nome do funcionário: ')
s.send(nome.encode())
#print("resposta: " + s.recv(1024).decode())

cargo = input('Digite o cargo do funcionário: ')
s.send(cargo.encode())
#print("resposta: " + s.recv(1024).decode())

salario = input('Digite o salario do funcionário: ')
s.send(salario.encode())
#print("resposta: " + s.recv(1024).decode())


print("Nome: " + s.recv(1024).decode())
s.close()