import socket

HOST = 'localhost'     # Endereço IP do Servidor

PORT = 8000            # Porta que o Servidor está

# Criando a conexão

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

destino = (HOST, PORT)

tcp.connect(destino)

nome = input('Digite o nome: ')
tcp.send(nome.encode())
#print("resposta: " + tcp.recv(1024).decode())
sexo = input('Digite o sexo (F ou M): ')
tcp.send(sexo.encode())
#print("resposta: " + tcp.recv(1024).decode())
idade = input('Digite a idade: ')
tcp.send(idade.encode())
#print("resposta: " + tcp.recv(1024).decode())

print(tcp.recv(1024).decode())


# Fechando o Socket

tcp.close()

