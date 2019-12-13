import java.util.ArrayList;
import javax.swing.JOptionPane;

public class Principal {

    public static void main(String[] args) {
        ArrayList<Cliente> clientes = new ArrayList<Cliente>();
        ArrayList<Conta> contas = new ArrayList<Conta>();

        String resp = "S";
        JOptionPane.showMessageDialog(null,"Cadastrar um cliente");
        while (resp.toUpperCase().equals("S")) {
            String nome = JOptionPane.showInputDialog(null, "Insira o nome");
            int telefone = Integer.parseInt(JOptionPane.showInputDialog(null, "Insira o telefone"));
            Cliente nCliente = new Cliente(nome, telefone);
            clientes.add(nCliente);

            int numero = 1;

            while (numero != 0) {
                numero = Integer.parseInt(JOptionPane.showInputDialog(null, "Insira o numero da conta"));
                if (numero == 0) {
                    break;
                }
                int tipoDeConta = Integer.parseInt(JOptionPane.showInputDialog(null, "Escolha o tipo de conta:\n 1 - Corrente\n 2 - Salario\n 3 - Poupanca"));
                if (tipoDeConta == 1) {
                    ContaCorrente nConta = new ContaCorrente(numero, nCliente);
                    double saldo = Double.parseDouble(JOptionPane.showInputDialog(null, "Valor do depósito"));
                    nConta.depositar(saldo);
                    contas.add(nConta);
                } else if (tipoDeConta == 2) {
                    ContaSalario nConta = new ContaSalario(numero, nCliente);
                    double saldo = Double.parseDouble(JOptionPane.showInputDialog(null, "Valor do depósito"));
                    nConta.depositar(saldo);
                    contas.add(nConta);
                } else if (tipoDeConta == 3) {
                    ContaPoupanca nConta = new ContaPoupanca(numero, nCliente);
                    double saldo = Double.parseDouble(JOptionPane.showInputDialog(null, "Valor do depósito"));
                    nConta.depositar(saldo);
                    nConta.atualizaSaldo(6);
                    contas.add(nConta);
                }
            }

            resp = JOptionPane.showInputDialog(null,"Deseja cadastrar um novo cliente? [S/N]");            
        }

        for (int i = 0; i < contas.size(); i++) {
            JOptionPane.showMessageDialog(null, contas.get(i));
        }
    }
}