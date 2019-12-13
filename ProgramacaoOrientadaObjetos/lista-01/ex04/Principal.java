import java.util.ArrayList;

public class Principal {

    public static void main(String[] args) {
        ArrayList<Funcionario> funcionarios = new ArrayList<Funcionario>();

        Empresa novaEmpresa = new Empresa("Procuradoria-Geral do Estado", "25.951.753/1501-13");

        Gerente novoGerente = new Gerente("Luiz Carlos", "159.753.852-12", 1355);
        novoGerente.setSalario(2300);
        novoGerente.setBonificacao(300);
        funcionarios.add(novoGerente);
        novaEmpresa.addFuncionario(novoGerente);

        novoGerente = new Gerente("Maria Luíza", "951.753.456-98", 6584);
        novoGerente.setSalario(2500);
        novoGerente.setBonificacao(150);
        funcionarios.add(novoGerente);
        novaEmpresa.addFuncionario(novoGerente);

        Vendedor novoVendedor = new Vendedor("Juliana Bento", "987.123.951-12", 7598);
        novoVendedor.setSalario(1800);
        novoVendedor.setBonificacao(180);
        funcionarios.add(novoVendedor);
        novaEmpresa.addFuncionario(novoVendedor);


        novoVendedor = new Vendedor("João Marcos", "741.852.963-00", 12698);
        novoVendedor.setSalario(2700);
        novoVendedor.setBonificacao(420);
        funcionarios.add(novoVendedor);
        novaEmpresa.addFuncionario(novoVendedor);

        novoVendedor = new Vendedor("Matheus Pereira", "321.654.987-11", 1307);
        novoVendedor.setSalario(1200);
        novoVendedor.setBonificacao(110);
        funcionarios.add(novoVendedor);
        novaEmpresa.addFuncionario(novoVendedor);

        System.out.println(novaEmpresa.toString());

        for (int i = 0; i < funcionarios.size(); i++) {
            //System.out.println(funcionarios.get(i));
            funcionarios.get(i).aumentarSalario(0.1);
        }

        System.out.println("-- Aumento de 10% --\n");

        System.out.println(novaEmpresa.toString());

        /*for (int i = 0; i < funcionarios.size(); i++) {
            System.out.println(funcionarios.get(i));
            //funcionarios.get(i).aumentarSalario(0.1);
        }*/
    }
}