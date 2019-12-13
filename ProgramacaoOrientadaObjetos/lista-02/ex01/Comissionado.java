public class Comissionado extends Funcionario {

    private double salarioMensal;
    private double totalDeVendas;
    private double percentualComissao;

    Comissionado(String nome, String sobrenome) {
        super(nome, sobrenome);
    }

    public void setSalarioMensal(double salarioMensal) {
        this.salarioMensal = salarioMensal;
    }

    public double getSalarioMensal() {
        return salarioMensal;
    }

    public void setPercentualComissao(double percentualComissao) {
        this.percentualComissao = percentualComissao;
    }

    public double getPercentualComissao() {
        return percentualComissao*100;
    }

    public void setTotalDeVendas(double totalDeVendas) {
        this.totalDeVendas = totalDeVendas;
    }

    public double getTotalDeVendas() {
        return totalDeVendas;
    }

    public double getSalarioTotal() {
        return salarioMensal + (salarioMensal*percentualComissao);
    }

    public String toString() {
        String comissionado = "Salario mensal: " + getSalarioMensal() + "\n"
                            + "Total de vendas: " + getTotalDeVendas() + "\n"
                            + "Percentual de comissao: " + getPercentualComissao() + "%\n"
                            + "Salario total: " + getSalarioTotal();
        return super.toString() + "\n" + comissionado;
    }
}