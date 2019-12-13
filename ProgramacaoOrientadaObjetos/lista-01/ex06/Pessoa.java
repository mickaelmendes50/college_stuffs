public class Pessoa {

    private String mNome;
    private String mSobrenome;
    private String mNomeDoMeio;

    Pessoa(String mNome, String mNomeDoMeio, String mSobrenome) {
        this.mNome = mNome;
        this.mNomeDoMeio = mNomeDoMeio;
        this.mSobrenome = mSobrenome;
    }

    public String toString() {
        return mSobrenome.toUpperCase() + ", " + mNome.charAt(0) + ". " + mNomeDoMeio.charAt(0) + ".";
    }
}