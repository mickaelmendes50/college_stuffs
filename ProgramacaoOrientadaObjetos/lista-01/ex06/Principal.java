import java.util.Scanner;
import java.util.ArrayList;

public class Principal {

    public static void main(String[] args) {
        ArrayList<Livro> livros = new ArrayList<Livro>();

        Scanner sc = new Scanner(System.in);
        Livro novoLivro;

        do {
            System.out.println("Insira o código");
            int codigo = sc.nextInt();
            sc.nextLine();
            if (codigo == 0) {
                break;
            }

            System.out.println("Insira o titulo da obra");
            String titulo = sc.nextLine();
            novoLivro = new Livro(codigo, titulo);

            System.out.println("Insira o nome do autor");
            String nome = sc.next(), doMeio = sc.next(), sobrenome= sc.next();
            novoLivro.setAutor(new Pessoa(nome, doMeio, sobrenome));

            System.out.println("Insira a edição");
            novoLivro.setEdicao(sc.nextInt());
            sc.nextLine();

            System.out.println("Insira o local");
            novoLivro.setLocal(sc.nextLine());

            System.out.println("Insira a editora");
            novoLivro.setEditora(sc.nextLine());

            System.out.println("Insira o ano");
            novoLivro.setAno(sc.nextInt());
            sc.nextLine();

            System.out.println("Insira o genero");
            novoLivro.setGenero(sc.nextLine());
            livros.add(novoLivro);
        } while (novoLivro.getCodigo() != 0);

        for (int i = 0; i < livros.size(); i++) {
            System.out.println(livros.get(i));
        }
        System.out.println("Total de livros: " + Livro.getTotalDeLivros());
    }
}