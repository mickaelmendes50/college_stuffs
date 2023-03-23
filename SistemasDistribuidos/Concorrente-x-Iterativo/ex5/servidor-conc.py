import socket

import _thread

HOST = 'localhost'     # Endereco IP do Servidor

PORT = 8000            # Porta que o Servidor está

# Função chamada quando uma nova thread for iniciada

def conectado(con, cliente):

    print('\nCliente conectado:', cliente)

   # recebe o idade
    idade = (con.recv(1024).decode())
    idade = int(idade)

    if idade >= 5 and idade <= 7:
            con.send(('infantil A').encode())  
    elif idade >= 8 and idade <= 10:
            con.send(('infantil B').encode()) 
    elif idade >= 11 and idade <= 13:
            con.send(('juvenil A').encode()) 
    elif idade >= 14 and idade <= 17:
            con.send(('juvenil B').encode()) 
    elif idade >= 18:
            con.send(('adulto').encode()) 
    else:
            con.send(('Classificação não disponível').encode()) 


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