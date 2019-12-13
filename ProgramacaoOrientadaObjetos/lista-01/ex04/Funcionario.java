public class Funcionario {

    protected String nome;
    protected String CPF;
    protected double salario;
    protected double bonificacao;

    Funcionario(String nome, String CPF) {
        this.nome = nome;
        this.CPF = CPF;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public void setBonificacao(double bonificacao) {
        this.bonificacao = bonificacao;
    }

    /*public void setSalarioTotal(double salarioTotal) {
        this.salarioTotal = salarioTotal;
    }*/

    public void aumentarSalario(double percentual) {
        this.salario += salario*percentual; 
    }

    public String toString() {
        String funcionario = "Nome: " + nome + "\n"
                           + "CPF: " + CPF + "\n"
                           + "Salario mensal: " + salario + "\n"
                           + "Bonificação: " + bonificacao + "\n";
        return funcionario;
    }
}