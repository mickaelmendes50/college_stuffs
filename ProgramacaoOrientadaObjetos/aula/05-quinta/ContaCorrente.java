public class ContaCorrente extends Conta {
    private static final double taxa = 0.05;
    
    ContaCorrente(int numero, Cliente dono) {
        super(numero, dono);
    }

    public void sacar(double valor) {
        super.sacar(valor+taxa);
    }

    public void depositar(double valor) {
        super.depositar(valor-taxa);
    }

    @Override
    public void transferir(double valor, Conta destino) {
        super.sacar(valor);
        destino.depositar(valor);
    }
}