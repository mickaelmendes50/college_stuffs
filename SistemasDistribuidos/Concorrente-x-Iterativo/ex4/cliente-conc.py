import socket

HOST = 'localhost'     # Endereço IP do Servidor

PORT = 5000            # Porta que o Servidor está

# Criando a conexão

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

destino = (HOST, PORT)

tcp.connect(destino)

altura = input('Digite a altura: ')
tcp.send(altura.encode())
#print('mensagem resposta do serv: ' + tcp.recv(1024).decode())
sexo = input('Informe o sexo (M ou F): ')
tcp.send(sexo.encode())
#print('mensagem resposta do serv: ' + tcp.recv(1024).decode())


print('Peso Ideal: ' + tcp.recv(1024).decode())


# Fechando o Socket

tcp.close()

