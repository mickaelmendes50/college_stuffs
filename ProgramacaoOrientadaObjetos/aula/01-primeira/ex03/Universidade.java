import java.util.Scanner;

public class Universidade {
    String nome;
    String grau;
    String instituto;
    int periodos;
    int quantCursos;

    Scanner sc = new Scanner(System.in);

    public void setNome() {
        this.nome = sc.nextLine();
    }

    public void setGrau() {
        this.grau = sc.nextLine();
    }

    public void setInstituto() {
        this.instituto = sc.nextLine();
    }

    public void setPeriodos() {
        this.periodos = sc.nextInt();
    }

    public int setQuantCursos() {
        this.quantCursos = sc.nextInt();
        return this.quantCursos;
    }

    public void cadastrarCurso() {
        System.out.println("Qual o nome do curso?");
        setNome();
        System.out.println("Qual o grau?");
        setGrau();
        System.out.println("Qual o instituto?");
        setInstituto();
        System.out.println("Quantos periodos?");
        setPeriodos();
    }

    public void mostrarCurso() {
        System.out.println("Nome:      " + this.nome);
        System.out.println("Grau:      " + this.grau);
        System.out.println("Instituto: " + this.instituto);
        System.out.println("Periodos:  " + this.periodos);
    }

    public static void main(String[] args) {
        Universidade curso = new Universidade();
        int num;

        System.out.println("Bem-vindo ao sistema de cadastro de cursos da UFG!");
        System.out.println("Quantos cursos deseja cadastrar?");
        num = curso.setQuantCursos();
        Universidade[] novoCurso = new Universidade[num];

        for (int i = 0; i < num; i++) {
            System.out.println("Curso "+ (i+1));
            novoCurso[i] = new Universidade();
            novoCurso[i].cadastrarCurso();
            System.out.println("");
        }

        System.out.println("Os cursos cadastrados foram:");
        for (int j = 0; j < num; j++) {
            novoCurso[j].mostrarCurso();
            System.out.println("");
        }
    }
}