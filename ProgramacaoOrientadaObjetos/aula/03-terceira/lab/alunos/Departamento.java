public class Departamento {

    private String mNome;
    private String mSigla;

    Departamento(String mNome, String mSigla) {
        this.mNome = mNome;
        this.mSigla = mSigla;
    }

    public String toString() {
        String departamento = mNome + " (" + mSigla + ")";
        return departamento;
    }
}