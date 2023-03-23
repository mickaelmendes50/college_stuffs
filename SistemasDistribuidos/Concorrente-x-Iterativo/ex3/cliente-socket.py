'''Escreva um programa que leia as três notas (N1, N2 e N3) de um aluno de
Faculdade e escreva se o mesmo foi aprovado ou reprovado. Considere as regras: se
a média aritmética M, entre N1 e N2, for maior ou igual a 7,0, o aluno está
aprovado; se a média aritmética M entre N1 e N2 for maior que 3,0 e menor que
7,0, o aluno deve fazer a N3. O aluno é aprovado se a média aritmética entre M e
N3 for maior ou igual a 5,0.'''

import socket

HOST = '127.0.0.1' # Endereço IP do Servidor
PORT = 8000 # Porta que o Servidor está

# Criando a conexão
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #tcp
s.connect((HOST, PORT))

nota1 = input('Digite a 1ª nota: ')
s.send(nota1.encode())
#print("mensagem resposta do serv: " + s.recv(1024).decode())
nota2 = input('Digite a 2ª nota: ')
s.send(nota2.encode())

if s.recv(1024).decode() == "nota 3":
    nota3 = input("Digite a 3ª nota: ")
    s.send(nota3.encode())
    print("Situação: " + s.recv(1024).decode())


print("Situação: " + s.recv(1024).decode())
