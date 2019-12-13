public class TestaConta {
    public static void main(String[] args) {
        ContaCorrente novaContaCorrente = new ContaCorrente(1248, new Cliente("João Marcos", 991670290));
        novaContaCorrente.depositar(6800);
        System.out.println(novaContaCorrente.toString());
        novaContaCorrente.sacar(800);
        System.out.println(novaContaCorrente.toString());
        
        ContaPoupanca novaContaPoupanca = new ContaPoupanca(8421, new Cliente("Mickael Mesquita", 991596791));
        novaContaPoupanca.depositar(1100);
        System.out.println(novaContaPoupanca.toString());
        novaContaPoupanca.sacar(110);
        System.out.println(novaContaPoupanca.toString());
        novaContaPoupanca.atualizaSaldo(20);
        System.out.println(novaContaPoupanca.toString());

        novaContaCorrente.transferir(790, novaContaPoupanca);
        System.out.println(novaContaCorrente.toString());
        novaContaPoupanca.transferir(650, novaContaCorrente);
        System.out.println(novaContaPoupanca.toString());

        ContaSalario novaContaSalario = new ContaSalario(4569, new Cliente("Matheus Pereira", 991333288));
        novaContaSalario.depositar(3000);
        System.out.println(novaContaSalario.toString());
        novaContaSalario.sacar(1500);
        System.out.println(novaContaSalario.toString());
        novaContaSalario.transferir(500, novaContaCorrente);
        System.out.println(novaContaSalario.toString());
    }
}