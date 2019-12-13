public class Empregado {

    private String mNome;
    private int mMatricula;

    public Empresa empresa;

    Empregado(String mNome, int mMatricula) {
        this.mNome = mNome;
        this.mMatricula = mMatricula;
    }

    public void setEmpresa(Empresa empresa) {
        this.empresa = empresa;
    }

    public String toString() {
        String empregado = "Nome:      " + mNome + "\n"
                         + "Matricula: " + mMatricula + "\n"
                         + "Empresa:   " + empresa;
        return empregado;
    }
}