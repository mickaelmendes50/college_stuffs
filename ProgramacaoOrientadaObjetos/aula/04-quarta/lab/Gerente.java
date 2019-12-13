public class Gerente extends Funcionario {
    private String tipo;
    
    Gerente(String nome, int matricula) {
        super (nome, matricula);
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String getTipo() {
        return tipo;
    }
}