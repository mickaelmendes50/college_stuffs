'''Faça um programa que leia o nome, o sexo e a idade de uma pessoa e determine se
a pessoa já atingiu a maioridade sabendo-se que: as pessoas do sexo masculino
atingem a maioridade aos 18 anos e as pessoas do sexo feminino atingem a
maioridade aos 21 anos. O programa deve escrever o resultado encontrado.'''
import xmlrpc.client

print('Cliente')

IP = '127.0.0.1' #input('Digite o ip do servidor: ')
PORTA = 8000 #int (input('Digite a porta do servidor: '))

servidor = xmlrpc.client.ServerProxy('http://{0}:{1}/'.format(IP, PORTA))

nome = input('\n Digite o nome: ')
sexo = input('\n Digite o sexo: ')
idade = int (input('\nDigite a idade: '))
Maioridade = servidor.maioridade(sexo, idade)

if Maioridade =='1':
    print('\n Maioridade!')

else:
    print('\n Menor de idade')