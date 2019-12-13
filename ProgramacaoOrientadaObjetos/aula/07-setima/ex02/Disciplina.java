import java.io.IOException;
import java.io.NotSerializableException;
import java.io.Serializable;

public class Disciplina implements Serializable {
    int codigo;
    String nome;
    
    Disciplina(int codigo, String nome) throws IOException {
        this.codigo = codigo;
        this.nome = nome;
    }

    public String toString() {
        return nome + " - Codigo: " + codigo;
    }
}