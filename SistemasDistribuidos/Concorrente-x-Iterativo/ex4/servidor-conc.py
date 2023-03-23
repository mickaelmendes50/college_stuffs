import socket

import _thread

HOST = 'localhost'     # Endereco IP do Servidor

PORT = 5000            # Porta que o Servidor está

# Função chamada quando uma nova thread for iniciada

def conectado(con, cliente):

    print('\nCliente conectado:', cliente)

    # recebe o nome
    altura = (con.recv(1024).decode())
    #Envia os dados de volta para confirmação
    #con.send(('mensagem resposta do serv ' + altura).encode())
    sexo = con.recv(1024).decode()
    #con.send(('mensagem resposta do serv ' + sexo).encode())
    altura = float(altura)

    if sexo == 'F':
            pesoIdeal = (62.1 * altura) - 44.7
            con.send((str(pesoIdeal)).encode())  
    else:
            pesoIdeal = (72.7 * altura) - 58
            con.send((str(pesoIdeal)).encode())  



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