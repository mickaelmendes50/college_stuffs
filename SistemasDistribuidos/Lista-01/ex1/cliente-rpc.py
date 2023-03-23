'''Faça um programa que leia o nome, o cargo e o salário de um funcionário e escreva
seu salário reajustado. Se o cargo do funcionário for operador, ele deverá receber
um reajuste de 20%, se for programador, ele deverá receber um reajuste de 18%. O
programa deve escrever o nome do funcionário e seu salário reajustado.'''
import xmlrpc.client

print('Cliente')

IP = '127.0.0.1' #input('Digite o ip do servidor: ')
PORTA = 8000 #int (input('Digite a porta do servidor: '))

servidor = xmlrpc.client.ServerProxy('http://{0}:{1}/'.format(IP, PORTA))


nome = input('\n Digite o nome: ')
cargo = input('\n Digite o cargo do funcionário: ')
salario = float (input('\nDigite o salario: '))
salarioFinal = servidor.reajuste(cargo, salario)

if salarioFinal =='1':
    print('\n Não existe esse tipo de cargo!')

else:
    print('\n Funcionário(a): ' + nome.upper())
    print('-'*10)
    print('|Salário Ajustado: ' + str(salarioFinal) + '|')
    print('-'*10)