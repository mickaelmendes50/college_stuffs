public class Jogo extends Item {

    private int mNumeroDeJogadores;
    private String mPlataforma;

    Jogo(String titulo, String tipo, String mPlataforma) {
        super(titulo, tipo);
        this.mPlataforma = mPlataforma;
    }

    public void setNumeroDeJogadores(int mNumeroDeJogadores) {
        this.mNumeroDeJogadores = mNumeroDeJogadores;
    }

    public String getPlataforma() {
        return mPlataforma;
    }

    public String toString() {
        String jogo = "Numero de jogadores: " + mNumeroDeJogadores + "\n"
                    + "Plataforma: " + mPlataforma + "\n";
        return super.toString() + jogo;
    }
}