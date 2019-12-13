import java.util.ArrayList;

public class HistoricoPagsWeb {

    ArrayList <URLVisitada> urlVisitadas = new ArrayList<URLVisistada>();

    adicionaURL(String url) {
        urlVisitadas.add(new URLVisitada(url));
    }
}