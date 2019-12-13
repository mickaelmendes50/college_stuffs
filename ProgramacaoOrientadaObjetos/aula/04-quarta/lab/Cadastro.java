import java.util.ArrayList;

public class Cadastro {
    
    public static void main(String[] args) {
        ArrayList <Funcionario> funcionarios = new ArrayList<Funcionario>();
        ArrayList <Cliente> clientes = new ArrayList<Cliente>();

        Funcionario novoCaixa = new Funcionario("Lucas", 201702418);
        novoCaixa.setCaixa(new Caixa(novoCaixa.getNome(), novoCaixa.getMatricula()));
        novoCaixa.setSalario(1200);
        novoCaixa.setTelefone(991596791);
        novoCaixa.getCaixa().setHorario("matutino");
        novoCaixa.aumentoSalario(0.1);
        funcionarios.add(novoCaixa);

        Funcionario novoGerente = new Funcionario("João", 201900967);
        novoGerente.setGerente(new Gerente(novoGerente.getNome(), novoGerente.getMatricula()));
        novoGerente.setSalario(1500);
        novoGerente.setBonificacao(300);
        novoGerente.setTelefone(991670290);
        novoGerente.getGerente().setTipo("PF");
        novoGerente.aumentoSalario(0.2);
        funcionarios.add(novoGerente);

        for (int i = 0; i < funcionarios.size(); i++) {
            System.out.println(funcionarios.get(i));
        }

        Cliente novoCliente = new Cliente("Claudio", 991663861, 32, "037.252.571-75");
        clientes.add(novoCliente);

        novoCliente = new Cliente("Maria", 996960564, 28, "037.252.581-47");
        novoCliente.setStatus();
        clientes.add(novoCliente);

        novoCliente = new Cliente("Pedro", 981389472, 23, "815.755.951-00");
        clientes.add(novoCliente);

        for (int i = 0; i < clientes.size(); i++) {
            System.out.println(clientes.get(i));
        }
    }
}