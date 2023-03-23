#!/usr/bin/env python4
'''Faça um programa que leia o nome, o sexo e a idade de uma pessoa e determine se
a pessoa já atingiu a maioridade sabendo-se que: as pessoas do sexo masculino
atingem a maioridade aos 18 anos e as pessoas do sexo feminino atingem a
maioridade aos 21 anos. O programa deve escrever o resultado encontrado.'''

import socket

HOST = '127.0.0.1' # Endereço IP do Servidor
PORT = 8000 # Porta que o Servidor está

# Criando a conexão
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #tcp
s.connect((HOST, PORT))

nome = input('Digite o nome: ')
s.send(nome.encode())
#print("resposta: " + s.recv(1024).decode())
sexo = input('Digite o sexo (F ou M): ')
s.send(sexo.encode())
#print("resposta: " + s.recv(1024).decode())
idade = input('Digite a idade: ')
s.send(idade.encode())
#print("resposta: " + s.recv(1024).decode())


print(s.recv(1024).decode())
s.close()