import java.util.ArrayList;

public class Principal {
    public static void main(String[] args) {
        ArrayList <Musica> musicas = new ArrayList <Musica>();

        Musica novaMusica = new Musica("Faded", 2015, "Eletronica");
        novaMusica.setCompositor(new Compositor("Alan Walker", "Noruegues"));
        musicas.add(novaMusica);

        novaMusica = new Musica("Hear me Now", 2007, "Eletronica");
        novaMusica.setCompositor(new Compositor("Alok", "Brasileiro"));
        novaMusica.setCompositor(new Compositor("Bruno Martini", "Brasileiro"));
        musicas.add(novaMusica);

        for (int i = 0; i < musicas.size(); i++) {
            System.out.println(musicas.get(i));
        }
    }
}