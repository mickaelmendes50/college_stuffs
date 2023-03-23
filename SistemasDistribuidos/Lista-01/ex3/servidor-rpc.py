'''Escreva um programa que leia as três notas (N1, N2 e N3) de um aluno de
Faculdade e escreva se o mesmo foi aprovado ou reprovado. Considere as regras: se
a média aritmética M, entre N1 e N2, for maior ou igual a 7,0, o aluno está
aprovado; se a média aritmética M entre N1 e N2 for maior que 3,0 e menor que
7,0, o aluno deve fazer a N3. O aluno é aprovado se a média aritmética entre M e
N3 for maior ou igual a 5,0.'''
from xmlrpc.server import SimpleXMLRPCServer

print('\tServidor')

IP = '127.0.0.1'
PORTA = 8000

print('Esperando por cliente')

def CalculaMedia(nota1, nota2):
    media = (nota1+nota2)/2
    if media >= 7.0:
        return '1'
    elif media>3:
        return '0'
    else:
        return '-1'
    
def CalculaMediaNota3(nota1, nota2, nota3):
    media = (nota1+nota2)/2
    if ((media+nota3)/2 >= 5):
        return '1'
    else:
        return '0'


       

servidor = SimpleXMLRPCServer((IP, PORTA))
servidor.register_function(CalculaMedia, 'calculaMedia')
servidor.register_function(CalculaMediaNota3, 'calculaMediaNota3')
servidor.serve_forever()