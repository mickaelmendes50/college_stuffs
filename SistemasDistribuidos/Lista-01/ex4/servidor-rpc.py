'''Tendo como dados de entrada a altura e o sexo de uma pessoa, construa um
programa que calcule seu peso ideal, utilizando as seguintes fórmulas:
- para homens: (72.7 * altura) – 58;
- para mulheres (62.1 * altura) – 44.7.'''

from xmlrpc.server import SimpleXMLRPCServer

print('\tServidor')

IP = '127.0.0.1'
PORTA = 8000


print('Esperando por cliente')
def calculaPeso(altura, sexo):
    if sexo == 'F':
        pesoIdeal = (62.1 * altura) - 44.7
        return pesoIdeal
    elif sexo == 'M':
        pesoIdeal = (72.7 * altura) - 58
        return pesoIdeal
    else:
        return 'Sexo nao definido'

   
    
    

servidor = SimpleXMLRPCServer((IP, PORTA))
servidor.register_function(calculaPeso, 'pesoIdeal')
servidor.serve_forever()