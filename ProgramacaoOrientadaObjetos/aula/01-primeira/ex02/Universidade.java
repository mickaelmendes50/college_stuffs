import java.util.Scanner;

public class Universidade {
    String nome;
    int periodos;
    String grau;
    String instituto;

    Scanner sc = new Scanner(System.in);

    public void setNome() {
        this.nome = sc.nextLine();
    }

    public void setPeriodos() {
        this.periodos = sc.nextInt();
    }

    public void setGrau() {
        this.grau = sc.nextLine();
    }

    public void setInstituto() {
        this.instituto = sc.nextLine();
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
        Universidade curso1 = new Universidade();
        Universidade curso2 = new Universidade();
        Universidade curso3 = new Universidade();
        Universidade curso4 = new Universidade();

        System.out.println("Bem-vindo ao sistema de cadastro de cursos da UFG!");
        System.out.println("Primeiro Curso:");
        curso1.cadastrarCurso();
        System.out.println("");
        System.out.println("Segundo Curso");
        curso2.cadastrarCurso();
        System.out.println("");
        System.out.println("Terceiro Curso");
        curso3.cadastrarCurso();
        System.out.println("");
        System.out.println("Quarto Curso");
        curso4.cadastrarCurso();

        System.out.println("Os cursos cadastrados foram:");
        curso1.mostrarCurso();
        System.out.println("");
        curso2.mostrarCurso();
        System.out.println("");
        curso3.mostrarCurso();
        System.out.println("");
        curso4.mostrarCurso();
    }
}
