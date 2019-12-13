public class Compositor {

    private String mNome;
    private String mNacionalidade;

    Compositor(String mNome, String mNacionalidade) {
        this.mNome = mNome;
        this.mNacionalidade = mNacionalidade;
    }

    public String toString() {
		return mNome + " (" + mNacionalidade + ")";
	}
}