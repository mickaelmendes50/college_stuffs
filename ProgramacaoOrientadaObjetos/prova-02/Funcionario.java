import java.util.ArrayList;

public class Funcionario extends Pessoa implements IRegistro {
    private int matricula;
    
    ArrayList<Dependente> dependentes = new ArrayList<Dependente>();

    Funcionario(String nome, int idade, char sexo, int matricula) {
        super(nome, idade, sexo);
        this.matricula = matricula;
    }

    public double calcularValorPlanoSaude() {
        if (super.idade <= 20) {
            return 100;
        } else if (super.idade <= 40 && super.idade >= 21) {
            return 200;
        } else if (super.idade <= 60 && super.idade >= 41) {
            return 300;
        }
        return 400;
    }

    public void registrarObjetos(Dependente dependente) {
        dependentes.add(dependente);
    }

    public String toString() {
        return super.toString() + "Matricula: " + matricula + "\n";
    }
}