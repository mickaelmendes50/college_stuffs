public class Gerente extends Funcionario {

    private double salarioMensal;
    private double bonificacao;

    Gerente(String nome, String sobrenome) {
        super(nome, sobrenome);
    }

    public void setSalarioMensal(double salarioMensal) {
        this.salarioMensal = salarioMensal;
    }

    public double getSalarioMensal() {
        return salarioMensal;
    }

    public void setBonificacao(double bonificacao) {
        this.bonificacao = bonificacao;
    }

    public double getBonificacao() {
        return bonificacao;
    }

    public double getSalarioTotal() {
        return getSalarioMensal() + getBonificacao();
    }

    public String toString() {
        String gerente = "Salario mensal: " + getSalarioMensal() + "\n"
                       + "Bonificacao: " + getBonificacao() + "\n"
                       + "Total: " + getSalarioTotal();
        return super.toString() + "\n" + gerente;
    }
}