import socket

import _thread

HOST = 'localhost'     # Endereco IP do Servidor

PORT = 8000            # Porta que o Servidor está

# Função chamada quando uma nova thread for iniciada

def conectado(con, cliente):

    print('\nCliente conectado:', cliente)

    nome = con.recv(1024).decode()
    #conn.send(('mensagem resposta do serv' + nome).encode())
    cargo = con.recv(1024).decode()
    #conn.send(('mensagem resposta do serv' + cargo).encode())
    salario = con.recv(1024).decode()
    #conn.send(('mensagem resposta do serv' + salario).encode())

    salario = float(salario)

    if cargo == 'operador':
        salarioReajustado = float(salario + salario *0.2)
    
    else:
        salarioReajustado = float(salario+salario*0.18)
    
        
    MensagemFinal = nome + "| Salario Final: " + str(salarioReajustado)
    con.send(MensagemFinal.encode()) #Envia a resposta final para o cliente

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