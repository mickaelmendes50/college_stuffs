import java.util.ArrayList;
import java.util.Scanner;

public class Principal {

    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
        ArrayList <Filme> filmes = new ArrayList<Filme>();

        System.out.println("-- Cadastro de filmes --");

        String nome;
        int codigo = 1;

        do {

            System.out.println("Insira o código");
            codigo = sc.nextInt();
            sc.nextLine();

            if (codigo == 0) {
                break;
            }

            System.out.println("Insira o nome");
            nome = sc.nextLine();

            Filme novoFilme = new Filme(codigo, nome);

            System.out.println("Insira o ano de lançamento");
            novoFilme.setAno(sc.nextInt());
            sc.nextLine();

            System.out.println("Insira o gênero");
            novoFilme.setGenero(sc.nextLine());

            System.out.println("Insira o nome do ator principal");
            novoFilme.setAtorPrincipal(sc.nextLine());

            filmes.add(novoFilme);

            System.out.println("-- Proximo filme --");
            
        } while (codigo != 0);
        
        for (int i = 0; i < filmes.size(); i++) {
            System.out.println(filmes.get(i));;
        }

        System.out.println("Total de filmes: " + Filme.sTotalDeFilmes);
    }
}