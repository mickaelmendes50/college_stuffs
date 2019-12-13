public class Caixa extends Funcionario {
    private String horario;

    Caixa(String nome, int matricula) {
        super (nome, matricula);
    }

    public void setHorario(String horario) {
        this.horario = horario;
    }

    public String getHorario() {
        return horario;
    }
}