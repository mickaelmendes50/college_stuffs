import java.util.ArrayList;
import javax.swing.JOptionPane;

public class Curso {
    private String nome;
    private String sigla;
    private String area;

    ArrayList<Aluno> alunos = new ArrayList<Aluno>();

    Curso(String nome, String sigla, String area) {
        this.nome = nome;
        this.sigla = sigla;
        this.area = area;
    }

    public String getNome() {
        return nome;
    }

    public void novoAluno() {
        String aluno = "----------------------------------------------------------\n"
                     + "    Cadastro de Aluno\n"
                     + "----------------------------------------------------------\n";
        String nome = JOptionPane.showInputDialog(aluno + "Insira o nome\n");
        int matricula = Integer.parseInt(JOptionPane.showInputDialog(aluno + "Insira a matricula\n"));
        String dataNascimento = JOptionPane.showInputDialog(aluno + "Insira a data de nascimento (dd|mm|aaaa)\n");
        int anoIngresso = Integer.parseInt(JOptionPane.showInputDialog(aluno + "Insira o ano de ingresso\n"));
        String situacao = JOptionPane.showInputDialog(aluno + "Insira a situacao\n");

        Aluno novoAluno = new Aluno(nome, matricula, dataNascimento, anoIngresso, situacao);
        alunos.add(novoAluno);
    }
}