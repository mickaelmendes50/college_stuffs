import socket

HOST = 'localhost'     # Endereço IP do Servidor

PORT = 8000            # Porta que o Servidor está

# Criando a conexão

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

destino = (HOST, PORT)

tcp.connect(destino)

idade = input('Digite a idade do nadador: ')
tcp.send(idade.encode())
#print('mensagem resposta do serv: ' + s.recv(1024).decode())


print('Classificação: ' + tcp.recv(1024).decode())

# Fechando o Socket

tcp.close()

