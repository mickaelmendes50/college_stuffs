public class Gerente extends Funcionario {

    private int mSenha;

    Gerente(String nome, String CPF, int mSenha) {
        super(nome, CPF);
        this.mSenha = mSenha;
    }

    public double salarioAnual() {
        return (super.salario + super.bonificacao) * 12;
    }

    public String toString() {
        String gerente = "Senha: " + mSenha + "\n"
                       + "Salario anual: " + salarioAnual() + "\n";
        return super.toString() + gerente;
    }
}