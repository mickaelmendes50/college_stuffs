import java.util.ArrayList;

public class Principal {

    public static void main(String[] args) {
        ArrayList <Empregado> empregados = new ArrayList<Empregado>();

        Empregado novoEmpregado = new Empregado("Mickael Mendes Mesquita", 201900967);
        novoEmpregado.setEmpresa(new Empresa("Procuradoria Geral do Estado", "04.139.403/0001-77"));
        novoEmpregado.empresa.setEndereco(new Endereco("Rua 2", 1693, "Setor-Oeste", "Qd. D-2 Lt. 20/26/28", "Goiânia", "Goiás"));
        empregados.add(novoEmpregado);

        novoEmpregado = new Empregado("João Marcos Barcelos", 201702418);
        novoEmpregado.setEmpresa(new Empresa("JSL S.A.", "52.548.435/0001-79"));
        novoEmpregado.empresa.setEndereco(new Endereco("Rua 1", 0, "Vila Romana", " ", "Goiânia", "Goiás"));
        empregados.add(novoEmpregado);

        for (int i = 0; i < empregados.size(); i++) {
            System.out.println(empregados.get(i) + "\n");
        }
    }
}