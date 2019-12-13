public class ContaSalario extends ContaCorrente {
    private final double descontoTaxa = 0.04;

    ContaSalario(int numero, Cliente dono) {
        super(numero, dono);
    }

    @Override
    public void sacar(double valor) {
        super.sacar(valor+descontoTaxa);
    }

    @Override
    public void depositar(double valor) {
        super.depositar(valor+descontoTaxa);
    }
}