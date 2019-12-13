import java.util.ArrayList;

public class Principal {

    public static void main(String[] args) {
        ArrayList <Aluno> alunos = new ArrayList <Aluno>();

        Aluno novoAluno = new Aluno("Mickael Mendes Mesquita", 201900967, 2019);
        novoAluno.setCurso(new Curso("Ciências da Computação", "CC"));
        novoAluno.curso.setDepartamento(new Departamento("Instituto de Informática", "INF"));
        alunos.add(novoAluno);

        novoAluno = new Aluno("Áquila Nogueira Gomes", 201702418, 2017);
        novoAluno.setCurso(new Curso("Biblioteconomia", "BIBL"));
        novoAluno.curso.setDepartamento(new Departamento("Faculdade de Informação e Comunicação", "FIC"));
        alunos.add(novoAluno);

        for (int i = 0; i < alunos.size(); i++) {
            System.out.println(alunos.get(i) + "\n");
        }
    }
}