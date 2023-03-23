from xmlrpc.server import SimpleXMLRPCServer

print('\tServidor')

IP = '127.0.0.1'
PORTA = 8000

print('Esperando por cliente')
def Maioridade(sexo, idade):
    if (sexo == 'F' and idade >= 21) or (sexo == 'M' and idade >= 18):
        
        return '1'
    else:
        return '0' 

       

servidor = SimpleXMLRPCServer((IP, PORTA))
servidor.register_function(Maioridade, 'maioridade')
servidor.serve_forever()