public class Administrador extends Funcionario {

    private double salarioMensal;

    Administrador(String nome, String sobrenome) {
        super(nome, sobrenome);
    }

    public void setSalarioMensal(double salarioMensal) {
        this.salarioMensal = salarioMensal;
    }

    public double getSalarioMensal() {
        return salarioMensal;
    }

    public String toString() {
        return super.toString() + "\n" + "Salario mensal: " + getSalarioMensal();
    }
}