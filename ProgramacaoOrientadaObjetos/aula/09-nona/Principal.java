import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Principal {

    public static void main(String[] args) throws IOException {
        InputStream inputStream = new FileInputStream("votos.txt");
        InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
        BufferedReader bufferedReader = new BufferedReader(inputStreamReader);

        Candidato novoCandidato;
        ArrayList<Candidato> candidatos = new ArrayList<Candidato>();

        String linha = bufferedReader.readLine();

        String[] dado = linha.split(";");
        novoCandidato = new Candidato(dado[0], dado[1], Integer.parseInt(dado[2]), dado[3]);
        candidatos.add(novoCandidato);
        linha = bufferedReader.readLine();

        //System.out.println("tá ok");

        while (linha != null) {
            dado = linha.split(";");
            if (linha == " ") {
                linha = bufferedReader.readLine();
                System.out.println("linha branca");
            } else {
                System.out.println("tá ok");
                for (int i = 0; i < candidatos.size(); i++) {
                    /*if (candidatos.get(i).getNumero() != Integer.parseInt(dado[2]) && i >= candidatos.size()) {
                        novoCandidato = new Candidato(dado[0], dado[1], Integer.parseInt(dado[2]), dado[3]);
                        System.out.println("Criou candidato " + dado[0] + dado[1] + dado[2] + dado[3]);
                    } else if (candidatos.get(i).getNumero() == Integer.parseInt(dado[2])) {
                        novoCandidato.somaVoto();
                        System.out.println("Somou voto");
                    }*/
                    for (int j = 0; j < candidatos.size(); j++) {
                        if (candidatos.get(i).equals(candidatos.get(j))) {
                            candidatos.get(i).somaVoto();
                            System.out.println("Sommou voto");
                            break;
                        }
                    }
                }
            }
            linha = bufferedReader.readLine();
        }
    }
}