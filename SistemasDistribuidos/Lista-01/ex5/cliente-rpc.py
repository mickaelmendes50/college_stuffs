import xmlrpc.client

print('Cliente')

IP = '127.0.0.1' #input('Digite o ip do servidor: ')
PORTA = 8000 #int (input('Digite a porta do servidor: '))

servidor = xmlrpc.client.ServerProxy('http://{0}:{1}/'.format(IP, PORTA))


idade = float(input('\nDigite a idade do nadador: '))

categoria = servidor.categoria(idade)


print('-'*18)
print('|Categoria: ' + str(categoria) + '|')
print('-'*18)

