public class Pessoa {
    private String nome;
    private double salario;
    private int dependentes;
    private int idade;

    Pessoa(String nome, double salario, int dependentes, int idade) {
        this.nome = nome;
        this.salario = salario;
        this.dependentes = dependentes;
        this.idade = idade;
    }

    boolean isAgeElegible(int idade) {
        if (idade >= 65) {
            return false;
        }
        return true;
    }

    boolean isDependentsElegible(int dependentes) {
        if (dependentes > 0) {
            return true;
        }
        return false;
    }

    double calculaImposto() {
        if (!(isAgeElegible(this.idade)) || this.salario <= 1787.77) 
            return 0.0;

        double imposto;
        if (this.salario >= 1787.78 && this.salario <= 2679.29) {
            imposto = (this.salario * 0.075) - 134.08;
        } else if (this.salario >= 2679.30 && this.salario <= 3572.43) {
            imposto = (this.salario * 0.15) - 335.03;
        } else if (this.salario >= 3572.44 && this.salario <= 4463.81) {
            imposto = (this.salario * 0.225) - 602.96;
        } else {
            imposto = (this.salario * 0.275) - 826.15;
        }

        if (isDependentsElegible(this.dependentes)) {
            imposto -= 179.71 * dependentes;
        }

        imposto = (imposto < 0) ? 0.0 : imposto; 

        return imposto;
    }
}