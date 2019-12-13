public class Aluno {
    private String nome;
    private int matricula;
    private String dataNascimento;
    private int anoIngresso;
    private String situacao;

    Aluno(String nome, int matricula, String dataNascimento, int anoIngresso, String situacao) {
        this.nome = nome;
        this.matricula = matricula;
        this.dataNascimento = dataNascimento;
        this.anoIngresso = anoIngresso;
        this.situacao =  situacao;
    }
}