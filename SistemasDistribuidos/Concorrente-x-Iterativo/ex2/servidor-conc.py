import socket

import _thread

HOST = 'localhost'     # Endereco IP do Servidor

PORT = 8000            # Porta que o Servidor está

# Função chamada quando uma nova thread for iniciada

def conectado(con, cliente):

    print('\nCliente conectado:', cliente)

   # recebe o nome
    nome = con.recv(1024).decode()
    sexo = con.recv(1024).decode()
    idade = con.recv(1024).decode()


    if (sexo == 'F' and int(idade) >= 21) or (sexo == 'M' and int(idade) >= 18):
            
        con.send(("Maioridade").encode()) #Envia a resposta para o cliente
    else:
        con.send(("Menor Idade").encode())


    print('\nFinalizando conexao do cliente', cliente)

    con.close()

    _thread.exit()

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

orig = (HOST, PORT)

# Colocando um endereço IP e uma porta no Socket

tcp.bind(orig)

# Colocando o Socket em modo passivo

tcp.listen(1)

print('\nServidor TCP concorrente iniciado no IP', HOST, 'na porta', PORT)

while True:

   # Aceitando uma nova conexão

   con, cliente = tcp.accept()

   print('\nNova thread iniciada para essa conexão')

   # Abrindo uma thread para a conexão

   _thread.start_new_thread(conectado, tuple([con, cliente]))

# Fechando a conexão com o Socket

tcp.close()