public class Empresa {
    
    private String mCNPJ;
    private String mRazaoSocial;
    
    public Endereco endereco;

    Empresa(String mRazaoSocial, String mCNPJ) {
        this.mRazaoSocial = mRazaoSocial;
        this.mCNPJ = mCNPJ;
    }

    public void setEndereco(Endereco endereco) {
        this.endereco = endereco;
    }

    public String toString() {
        String empresa = mRazaoSocial + "\n"
                       + "CNPJ:      " + mCNPJ + "\n"
                       + "Endereço:  " + endereco;
        return empresa;
    }
}