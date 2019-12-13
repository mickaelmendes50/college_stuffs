import java.util.ArrayList;
import javax.swing.JOptionPane;

public class Universidade {
    private String nome;
    private String endereco;
    private String bairro;
    private String cidade;
    private String estado;

    ArrayList<Curso> cursos = new ArrayList<Curso>();

    Universidade(String nome, String endereco, String bairro, String cidade, String estado) {
        this.nome = nome;
        this.endereco = endereco;
        this.bairro = bairro;
        this.cidade = cidade;
        this.estado = estado;
    }

    public String getNome() {
        return nome;
    }

    public void novoCurso() {
        String curso = "----------------------------------------------------------\n"
                     + "    Cadastro de Curso\n"
                     + "----------------------------------------------------------\n";
        String nome = JOptionPane.showInputDialog(curso + "Insira o nome\n");
        String sigla = JOptionPane.showInputDialog(curso + "Insira a sigla\n");
        String area = JOptionPane.showInputDialog(curso + "Insira a area\n");

        Curso novoCurso = new Curso(nome, sigla, area);

        int opt = Integer.parseInt(JOptionPane.showInputDialog("Deseja cadastrar um aluno para este curso?\n 1 - Sim\n 2 - Nao"));
        while (opt == 1) {
            novoCurso.novoAluno();
            opt = Integer.parseInt(JOptionPane.showInputDialog("Deseja cadastrar um novo aluno para este curso?\n 1 - Sim\n 2 - Nao"));
        }
        cursos.add(novoCurso);
    }
}