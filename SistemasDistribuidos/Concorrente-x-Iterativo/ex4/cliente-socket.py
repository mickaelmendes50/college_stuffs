'''Tendo como dados de entrada a altura e o sexo de uma pessoa, construa um
programa que calcule seu peso ideal, utilizando as seguintes fórmulas:
- para homens: (72.7 * altura) – 58;
- para mulheres (62.1 * altura) – 44.7.'''
import socket

HOST = '127.0.0.1' # Endereço IP do Servidor
PORT = 8000 # Porta que o Servidor está

# Criando a conexão
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #tcp
s.connect((HOST, PORT))

altura = input('Digite a altura: ')
s.send(altura.encode())
#print('mensagem resposta do serv: ' + s.recv(1024).decode())
sexo = input('Informe o sexo (M ou F): ')
s.send(sexo.encode())
#print('mensagem resposta do serv: ' + s.recv(1024).decode())

print('Peso Ideal: ' + s.recv(1024).decode())

#fechando o socket
s.close()