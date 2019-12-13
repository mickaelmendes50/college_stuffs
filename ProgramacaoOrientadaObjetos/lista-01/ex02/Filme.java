import java.util.Scanner;

public class Filme {

    public static int sTotalDeFilmes = 0;

    private int mCodigo;
    private int mAno;
    private String mNome;
    private String mGenero;
    private String mAtorPrincipal;

    Filme(int mCodigo, String mNome) {
        this.mCodigo = mCodigo;
        this.mNome = mNome;
        this.sTotalDeFilmes++;
    }

    public void setGenero(String mGenero) {
        this.mGenero = mGenero;
    }

    public void setAno(int mAno) {
        this.mAno = mAno;
    }

    public void setAtorPrincipal(String mAtorPrincipal) {
        this.mAtorPrincipal = mAtorPrincipal;
    }

    public static int getTotalDeFilmes() {
        return sTotalDeFilmes;
    }

    public String toString() {
        String filme = "Nome: " + mNome + "\n"
                     + "Código: " + mCodigo + "\n"
                     + "Gênero: " + mGenero + "\n"
                     + "Ano: " + mAno + "\n"
                     + "Ator Principal: " + mAtorPrincipal + "\n";
        return filme;
    }
}