'''Tendo como dados de entrada a altura e o sexo de uma pessoa, construa um
programa que calcule seu peso ideal, utilizando as seguintes fórmulas:
- para homens: (72.7 * altura) – 58;
- para mulheres (62.1 * altura) – 44.7.'''


import xmlrpc.client

print('Cliente')

IP = '127.0.0.1' #input('Digite o ip do servidor: ')
PORTA = 8000 #int (input('Digite a porta do servidor: '))

servidor = xmlrpc.client.ServerProxy('http://{0}:{1}/'.format(IP, PORTA))


altura = float(input('\nDigite a altura: '))
sexo = input('\nDigite o sexo: ')

pesoIdeal = servidor.pesoIdeal(altura, sexo)


print('-'*10)
print('|Peso ideal: ' + str(pesoIdeal) + '|')
print('-'*10)

