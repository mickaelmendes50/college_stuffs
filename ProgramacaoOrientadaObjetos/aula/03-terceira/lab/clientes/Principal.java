import java.util.ArrayList;

public class Principal {

    public static void main(String[] args) {
        ArrayList <Cliente> clientes = new ArrayList <Cliente>();

        Cliente novoCliente = new Cliente("Mickael Mendes Mesquita", "037.252.581-47");
        novoCliente.setEndereco(new Endereco("Rua BF17B", 0, "Floresta", "Qd. 38, Lt. 24", "Goiânia", "Goiás"));
        clientes.add(novoCliente);

        novoCliente = new Cliente("Harry Potter", "123.456.789-00");
        novoCliente.setEndereco(new Endereco("Rua dos Alfeneteiros", 4, "Godric's Hollow", "Qd. 10, Lt. 8", "Little Whinging", "Inglaterra"));
        clientes.add(novoCliente);

        for (int i = 0; i < clientes.size(); i++) {
            System.out.println(clientes.get(i) + "\n");
        }
    }
}