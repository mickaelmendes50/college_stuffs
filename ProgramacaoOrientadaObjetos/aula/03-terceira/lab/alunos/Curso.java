public class Curso {

    private String mNome;
    private String mSigla;
    private Departamento departamento;

    Curso(String mNome, String mSigla) {
        this.mNome = mNome;
        this.mSigla = mSigla;
    }

    public void setDepartamento(Departamento departamento) {
        this.departamento = departamento;
    }

    public String toString() {
        String curso = mNome + " (" + mSigla + ")" + "\n"
                     + "Departamento: " + departamento;
        return curso;
    }
}