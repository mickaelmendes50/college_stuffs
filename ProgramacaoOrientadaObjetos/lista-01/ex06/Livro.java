import java.util.Scanner;

public class Livro {

    private String mTitulo;
    private String mEditora;
    private String mLocal;
    private String mGenero;
    private int mEdicao;
    private int mCodigo;
    private int mAno;
    private Pessoa mAutor;

    private static int sTotalDeLivros = 0;

    Scanner sc = new Scanner(System.in);

    Livro(int mCodigo, String mTitulo) {
        this.mTitulo = mTitulo;
        this.mCodigo = mCodigo;

        this.sTotalDeLivros++;
    }

    public void setTitulo(String mTitulo) {
        this.mTitulo = mTitulo;
    }

    public String getTitulo() {
        return mTitulo;
    }

    public int getCodigo() {
        return mCodigo;
    }

    public static int getTotalDeLivros() {
        return sTotalDeLivros;
    }

    public void setAutor(Pessoa mAutor) {
        this.mAutor = mAutor;
    }

    public void setEdicao(int mEdicao) {
        this.mEdicao = mEdicao;
    }

    public void setAno(int mAno) {
        this.mAno = mAno;
    }

    public void setLocal(String mLocal) {
        this.mLocal = mLocal;
    }

    public void setEditora(String mEditora) {
        this.mEditora = mEditora;
    }

    public void setGenero(String mGenero) {
        this.mGenero = mGenero;
    }

    @Override
    public String toString() {
        String livro = "Código: " + mCodigo + "\n"
                     + "Título: " + mTitulo + "\n"
                     + "Gênero: " + mGenero + "\n"
                     + "Referência: " + mAutor.toString() + " " + mTitulo + ". " + mEdicao + "a. edição. " + mLocal + ": " + mEditora+ ", " + mAno + ".\n";
        return livro;
    }
}