public class Dependente extends Pessoa {
    private int tipo;
    
    Dependente(String nome, int idade, char sexo, int tipo) {
        super(nome, idade, sexo);
        this.tipo = tipo;
    }

    public double calcularValorPlanoSaude() {
        if (this.tipo == 1 || this.tipo == 2) {
            if (super.idade <= 20) {
                return 100;
            } else if (super.idade <= 40 && super.idade >= 21) {
                return 200;
            } else if (super.idade <= 60 && super.idade >= 41) {
                return 300;
            }
            return 400;
        }
        if (this.idade <= 60) {
            return 300;
        }
        return 500;
    }

    public String toString() {
        return super.toString() + "Tipo: " + tipo + "\n";
    }
}