public class Funcoes {

    public static void main(String[] args) {
        // declarar variavel do tipo da classe
        Funcoes variavel = new Funcoes();
        // chamar o metodo dentro da variavel
        variavel.helloWord();
        variavel.hello("Mesquita");
        variavel.hello("Mickael");
        System.out.println(variavel.soma(2,2));
    }

    /* a função pode ser 'public' ou 'private'
     * public: Pode ser acessada por qualquer classe
     * private: Pode ser acessada somente pela classe atual
     * sintaxe: / usabilidade / tipo / nome / (argumentos)
     * o tipo void não retorna nada, somente executa.
     */
    private void helloWord() {
        System.out.println("Olá, Mundo!");
    }

    private void hello(String name) {
        System.out.println("Olá, " + name + "!");
    }

    private int soma(int n1, int n2) {
        int resultado = n1+n2;
        return resultado;
    }
}
