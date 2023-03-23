'''Escreva um programa que leia as três notas (N1, N2 e N3) de um aluno de
Faculdade e escreva se o mesmo foi aprovado ou reprovado. Considere as regras: se
a média aritmética M, entre N1 e N2, for maior ou igual a 7,0, o aluno está
aprovado; se a média aritmética M entre N1 e N2 for maior que 3,0 e menor que
7,0, o aluno deve fazer a N3. O aluno é aprovado se a média aritmética entre M e
N3 for maior ou igual a 5,0.'''

import xmlrpc.client

print('Cliente')

IP = '127.0.0.1' #input('Digite o ip do servidor: ')
PORTA = 8000 #int (input('Digite a porta do servidor: '))

servidor = xmlrpc.client.ServerProxy('http://{0}:{1}/'.format(IP, PORTA))


nota1 = float(input('\nDigite a 1ª nota: '))
nota2 = float(input('\nDigite a 2ª nota: '))

Media = servidor.calculaMedia(nota1, nota2)

if Media =='1':
    print('\nAprovado!')

elif Media =='-1':
    print('\nReprovado!')
else:
   nota3 = float(input('\nDigite a 3ª nota: '))
   Media = servidor.calculaMediaNota3(nota1, nota2, nota3)

   if Media == '1':
        print('\nAprovado!')
   else:
        print('\nReprovado')