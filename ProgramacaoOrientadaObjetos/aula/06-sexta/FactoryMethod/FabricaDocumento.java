public class FabricaDocumento {
    public Documento criaDocumento(int numero, String remetente, String tipo) {
        if (tipo.equals("C"))
            return new Carta(numero, remetente);
        if (tipo.equals("N"))
            return new Notificacao(numero, remetente);
        if (tipo.equals("T"))
            return new Telegrama(numero, remetente);
        return null;
    }
}