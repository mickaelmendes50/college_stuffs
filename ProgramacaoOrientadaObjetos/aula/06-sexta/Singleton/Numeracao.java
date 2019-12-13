public final class Numeracao {
    private static Numeracao instNumeracao;
    private static int seq = 0;
    private int numero;
 
    private Numeracao() {
        numero = ++seq;
    }
 
    public static Numeracao getInstance() {
        if (instNumeracao == null)
            instNumeracao = new Numeracao();

        return instNumeracao;
    }

    public String toString() {
       return "Numeração " + numero;
    }
}