import socket

HOST = 'localhost'     # Endereço IP do Servidor

PORT = 8000            # Porta que o Servidor está

# Criando a conexão

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

destino = (HOST, PORT)

tcp.connect(destino)

nota1 = input('Digite a 1ª nota: ')
tcp.send(nota1.encode())
#print("mensagem resposta do serv: " + tcp.recv(1024).decode())
nota2 = input('Digite a 2ª nota: ')
tcp.send(nota2.encode())

if tcp.recv(1024).decode() == "nota 3":
    nota3 = input("Digite a 3ª nota: ")
    tcp.send(nota3.encode())
    print("Situação: " + tcp.recv(1024).decode())


print("Situação: " + tcp.recv(1024).decode())

# Fechando o Socket

tcp.close()

