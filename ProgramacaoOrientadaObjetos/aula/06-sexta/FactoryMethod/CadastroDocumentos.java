public class CadastroDocumentos {
    final static String CARTA = "C";
    final static String NOTIFICACAO = "N";
    final static String TELEGRAMA = "T";

    public static void main(String[] args) {
        FabricaDocumento factory = new FabricaDocumento();
        int numero = 1000;
        String remetente = "Joaoziho";
        Documento doc = factory.criaDocumento(numero, remetente, CARTA);

        numero = 1001;
        remetente = "Mariazinha";
        doc = factory.criaDocumento(numero, remetente, NOTIFICACAO);

        numero = 1002;
        remetente = "Pedrinho";
        doc = factory.criaDocumento(numero, remetente, TELEGRAMA);
    }
}