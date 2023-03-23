import socket

import _thread

HOST = 'localhost'     # Endereco IP do Servidor

PORT = 8000            # Porta que o Servidor está

# Função chamada quando uma nova thread for iniciada

def conectado(con, cliente):

    print('\nCliente conectado:', cliente)

    # recebe o nome
    nota1 = float(con.recv(1024).decode())
    #Envia os dados de volta para confirmação
    #conn.send(('mensagem resposta do serv' + nome).encode())
    nota2 = float(con.recv(1024).decode())


    media = (nota1+nota2)/2
    if media >= 7:
        con.send(("Aprovado(a)!").encode())
        
    elif media <= 3:
        con.send(("Reprovado(a)!").encode())

    elif media > 3 and media < 7:
        con.send(('nota 3').encode())
        nota3 = float(con.recv(1024).decode())
        mediaTotal = (media+nota3)/2

        if mediaTotal >= 5:
            con.send(("Aprovado(a)!").encode())
        else:
            con.send(("Reprovado(a)!").encode())

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