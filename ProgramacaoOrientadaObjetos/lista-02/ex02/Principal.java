import java.util.ArrayList;

public class Principal {

    public static void main(String[] args) {
        ArrayList<Loja> lojas = new ArrayList<Loja>();
        
        Loja novaLoja = new Loja("1583", "42.318.949/0001-84", "EletroBras", "Avenida Brasil - RJ", "João Marcos");
        lojas.add(novaLoja);

        novaLoja = new Loja("4301", "22.159.753/0596-45", "CELG", "Avenida Goiás - GO", "Mickael Mesquita");
        lojas.add(novaLoja);

        novaLoja = new Loja("7598", "62.987.352/1684-79", "Enel", "Marginal Botafogo - GO", "Matheus Pereira");
        lojas.add(novaLoja);

        for (int i = 0; i < lojas.size(); i++) {
            System.out.println(lojas.get(i));
        }

        for (int i = 0; i < lojas.size(); i++) {
            lojas.get(i).registra_abertura_dia();
            System.out.println(lojas.get(i));
        }

        for (int i = 0; i < lojas.size(); i++) {
            lojas.get(i).registra_fechamento_dia();
            System.out.println(lojas.get(i));
        }
    }    
}