public class Endereco {

    private String mRua;
    private String mBairro;
    private String mComplemento;
    private String mCidade;
    private String mEstado;
    private int mNumero;

    Endereco(String mRua, int mNumero, String mBairro, String mComplemento, String mCidade, String mEstado) {
        this.mRua = mRua;
        this.mNumero = mNumero;
        this.mBairro = mBairro;
        this.mComplemento = mComplemento;
        this.mCidade = mCidade;
        this.mEstado = mEstado;
    }

    public String toString() {
        String endereco = mRua + " " +
                          mComplemento + " " +
                          "nº " + mNumero + " " +
                          mBairro + ", " +
                          mCidade + " - " +
                          mEstado;
        return endereco;
    }
}