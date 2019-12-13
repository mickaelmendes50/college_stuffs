public class ContaPoupanca extends Conta {
    
    ContaPoupanca(int numero, Cliente dono) {
        super(numero, dono);
    }

    public void atualizaSaldo(double percentual) {
        super.saldo += saldo * (percentual/100);
    }

    @Override
    public void transferir(double valor, Conta destino) {
        super.sacar(valor);
        destino.depositar(valor);
    }
}