from xmlrpc.server import SimpleXMLRPCServer

print('\tServidor')

IP = '127.0.0.1'
PORTA = 8000


print('Esperando por cliente')
def reajuste(cargo, salario):
    if cargo == 'operador':
        salarioReajustado = (salario+(salario*0.2))
        return salarioReajustado
    elif cargo == 'programador':
        salarioReajustado = (salario+(salario*0.18))
        return salarioReajustado
    else:
        return '1' 

   
    
    

servidor = SimpleXMLRPCServer((IP, PORTA))
servidor.register_function(reajuste, 'reajuste')
servidor.serve_forever()