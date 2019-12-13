import java.util.ArrayList;

public class Musica {

    private String mNome;
    private String mTipo;
    private int mAno;
    
    ArrayList <Compositor> compositores = new ArrayList <Compositor>();

    Musica(String mNome, int mAno, String mTipo) {
        this.mNome = mNome;
        this.mAno = mAno;
        this.mTipo = mTipo;
    }

    public void setCompositor(Compositor compositor) {
        compositores.add(compositor);
    }

    public String toString() {
        String music = "Nome:   " + mNome + "\n"
                     + "Ano:    " + mAno + "\n"
                     + "Gênero: " + mTipo + "\n"
                     + "Compositores: \n";
        for (int i = 0; i < compositores.size(); i++) {
            music = music + compositores.get(i) + "\n";
        }
        return music;
    }
}