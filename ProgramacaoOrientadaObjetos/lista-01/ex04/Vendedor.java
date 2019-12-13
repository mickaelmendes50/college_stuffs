public class Vendedor extends Funcionario {

    private double comissao = 0.15;
    private int mTotalDeVendas = 0;

    Vendedor(String nome, String CPF, int mTotalDeVendas) {
        super(nome, CPF);
        this.mTotalDeVendas = mTotalDeVendas;
    }

    public double salarioAnual() {
        double total = (super.salario + super.bonificacao) * 12;
        total += total*this.comissao;
        return total;
    }

    public String toString() {
        String vendedor = "Total de vendas: " + mTotalDeVendas + "\n"
                        + "Salario anual: " + salarioAnual() + "\n";
        return super.toString() + vendedor;
    }
}