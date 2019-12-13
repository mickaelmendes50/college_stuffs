public class CD extends Item {

    private String mArtista;
    private int mQuantidadeDeFaixas;

    CD(String titulo, String tipo, String mArtista) {
        super(titulo, tipo);
        this.mArtista = mArtista;
    }

    public void setQuantidadeDeFaixas(int mQuantidadeDeFaixas) {
        this.mQuantidadeDeFaixas = mQuantidadeDeFaixas;
    }

    public String toString() {
        String cd = "Artista: " + mArtista + "\n"
                  + "Quantidade de faixas: " + mQuantidadeDeFaixas + "\n";
        return super.toString() + cd;
    }
}