import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.ArrayList;

public class LerArquivo {
    private static final String ARQ_FUNCIONARIOS = "funcionarios.txt";
    private static Double impostoTotal = 0.0;
    private static Double impostoMulheres = 0.0;
    private static Double impostoHomens = 0.0;

    public static void main(String[] args) throws IOException {
        InputStream is = new FileInputStream(ARQ_FUNCIONARIOS);
        InputStreamReader isr = new InputStreamReader(is);
        BufferedReader br = new BufferedReader(isr);

        String fileLine = br.readLine();

        Funcionario novoFuncionario;
        ArrayList<Funcionario> funcionarios = new ArrayList<Funcionario>();

        while (fileLine != null) {
            String[] dado = fileLine.split("#");
            novoFuncionario = new Funcionario(dado[0], dado[1].charAt(0), Double.parseDouble(dado[2]), Integer.parseInt(dado[3]));
            System.out.println(novoFuncionario.mostraFuncionario());
            funcionarios.add(novoFuncionario);
            fileLine = br.readLine();
        }

        for (int i = 0; i < funcionarios.size(); i++) {
            impostoTotal += funcionarios.get(i).impostoRenda();
            if (funcionarios.get(i).getSexo() == 'M') {
                impostoHomens += funcionarios.get(i).impostoRenda();
            } else {
                impostoMulheres += funcionarios.get(i).impostoRenda();
            }
        }

        DecimalFormat df = new DecimalFormat("#.##");
        df.setRoundingMode(RoundingMode.CEILING);

        System.out.println("\nTotal de imposto dos homens: R$" + df.format(impostoHomens));
        System.out.println("Total de imposto dos mulheres: R$" + df.format(impostoMulheres));
        System.out.println("Total de imposto total: R$" + df.format(impostoTotal));
    }
}