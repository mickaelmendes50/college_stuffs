public class Aluno {

    private String mNome;
    private int mMatricula;
    private int mAno;

    public Curso curso;

    Aluno(String mNome, int mMatricula, int mAno) {
        this.mNome = mNome;
        this.mMatricula = mMatricula;
        this.mAno = mAno;
    }

    public void setCurso(Curso curso) {
        this.curso = curso;
    }

    public String toString() {
        String aluno = "Nome:         " + mNome + "\n"
                     + "Matricula:    " + mMatricula + "\n"
                     + "Ano:          " + mAno + "\n"
                     + "Curso:        " + curso;
        return aluno;
    }
}