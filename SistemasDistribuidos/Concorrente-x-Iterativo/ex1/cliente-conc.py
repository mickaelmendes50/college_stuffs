import socket

HOST = 'localhost'     # Endereço IP do Servidor

PORT = 8000            # Porta que o Servidor está

# Criando a conexão

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

destino = (HOST, PORT)

tcp.connect(destino)

nome = input('Digite o nome do funcionário: ')
tcp.send(nome.encode()) # Enviando a mensagem para o Servidor TCP através da conexão
#print("resposta: " + tcp.recv(1024).decode())

cargo = input('Digite o cargo do funcionário: ')
tcp.send(cargo.encode())
#print("resposta: " + tcp.recv(1024).decode())

salario = input('Digite o salario do funcionário: ')
tcp.send(salario.encode())
#print("resposta: " + tcp.recv(1024).decode())


print("Nome: " + tcp.recv(1024).decode())


# Fechando o Socket

tcp.close()

