public class Filme extends Item {

    private String mDiretor;

    Filme(String titulo, String tipo) {
        super(titulo, tipo);
    }
    
    public void setDiretor(String mDiretor) {
        this.mDiretor = mDiretor;
    }

    public String toString() {
        String filme = "Diretor: " + mDiretor + "\n";
        return super.toString() + filme;
    }
}