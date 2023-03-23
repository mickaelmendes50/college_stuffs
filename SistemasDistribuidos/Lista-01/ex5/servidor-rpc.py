'''Tendo como dados de entrada a altura e o sexo de uma pessoa, construa um
programa que calcule seu peso ideal, utilizando as seguintes fórmulas:
- para homens: (72.7 * altura) – 58;
- para mulheres (62.1 * altura) – 44.7.'''

from xmlrpc.server import SimpleXMLRPCServer

print('\tServidor')

IP = '127.0.0.1'
PORTA = 8000


print('Esperando por cliente')
def categoriaIdade(idade):
    if idade >= 5 and idade <= 7:
        return 'infantil A'
    elif idade >= 8 and idade <= 10:
        return 'infantil B'
    elif idade >= 11 and idade <= 13:
        return 'juvenil A'
    elif idade >= 14 and idade <= 17:
        return 'juvenil B'
    elif idade >= 18:
        return 'adulto'
    else:
        return 0

   
    
    

servidor = SimpleXMLRPCServer((IP, PORTA))
servidor.register_function(categoriaIdade, 'categoria')
servidor.serve_forever()