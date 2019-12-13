public class Cliente {

    private String mNome;
    private String mCPF;
    private Endereco mEndereco;

    Cliente(String mNome, String mCPF) {
        this.mNome = mNome;
        this.mCPF = mCPF;
    }

    public void setEndereco(Endereco mEndereco) {
        this.mEndereco = mEndereco;
    }

    public String toString() {
        String cliente = "Nome:     " + mNome + "\n"
                       + "CPF:      " + mCPF + "\n"
                       + "Endereço: " + mEndereco;
        return cliente;
    }
}