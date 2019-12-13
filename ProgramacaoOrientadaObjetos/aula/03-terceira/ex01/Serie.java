public class Serie extends ProgramaTV {
    private int mTemporadas;
    private int mEpisodios;

    Serie(String mNome, String mCategoria, int mTemporadas, int mEpisodios) {
        super (mNome, mCategoria);
        this.mTemporadas = mTemporadas;
        this.mEpisodios = mEpisodios;
    }

    public String toString() {
        return super.toString() + "Temporadas: " + mTemporadas + "\n" + "Episodios: " + mEpisodios;
    }
}