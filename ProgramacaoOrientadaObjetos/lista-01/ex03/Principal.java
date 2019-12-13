import java.util.ArrayList;

public class Principal {

    public static void main(String[] args) {
        ArrayList<Item> itens = new ArrayList<Item>();

        CD novoCD = new CD("Apocalipse 16", "CD", "Pregador Luo");
        novoCD.setAno(2007);
        novoCD.setComentarios("Muito bom!");
        novoCD.setTempoDeDuracao("53 minutos");
        novoCD.setQuantidadeDeFaixas(12);
        itens.add(novoCD);

        Filme novoFilme = new Filme("O Senhor dos Anéis", "Filme");
        novoFilme.setAno(2001);
        novoFilme.setComentarios("Excelente");
        novoFilme.setTempoDeDuracao("3hrs e 48 minutos");
        novoFilme.setDiretor("Peter Jackson");
        itens.add(novoFilme);

        Jogo novoJogo = new Jogo("The Witcher", "Jogo", "PC ou Console");
        novoJogo.setAno(2016);
        novoJogo.setComentarios("O melhor!");
        novoJogo.setTempoDeDuracao("158 horas");
        novoJogo.setNumeroDeJogadores(1);
        itens.add(novoJogo);

        novoCD = new CD("Envolvimento", "CD", "Mc Loma");
        novoCD.setAno(2018);
        novoCD.setComentarios("Viciante");
        novoCD.setTempoDeDuracao("37 minutos");
        novoCD.setQuantidadeDeFaixas(8);
        itens.add(novoCD);

        novoFilme = new Filme("Harry Potter", "Filme");
        novoFilme.setAno(2000);
        novoFilme.setComentarios("Perfeito!");
        novoFilme.setTempoDeDuracao("2hrs e 37 minutos");
        novoFilme.setDiretor("David Yates");
        itens.add(novoFilme);

        novoJogo = new Jogo("Tekken 6", "Jogo", "Console only");
        novoJogo.setAno(2013);
        novoJogo.setComentarios("O melhor da categoria!");
        novoJogo.setTempoDeDuracao("83 horas");
        novoJogo.setNumeroDeJogadores(2);
        itens.add(novoJogo);

        novoFilme = new Filme("As Cronicas de Nárnia", "Filme");
        novoFilme.setAno(2005);
        novoFilme.setComentarios("Magnifico!");
        novoFilme.setTempoDeDuracao("2hrs e 21 minutos");
        novoFilme.setDiretor("Andrew Adamson");
        itens.add(novoFilme);

        for (int i = 0; i < itens.size(); i++) {
            System.out.println(itens.get(i));
        }
    }
}