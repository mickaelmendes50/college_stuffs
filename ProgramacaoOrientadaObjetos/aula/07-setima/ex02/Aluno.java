import java.io.NotSerializableException;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;

public class Aluno implements Serializable {
    private static final long serialVersionUID = 1L;
    int matricula;
	String nome;
    Disciplina disciplina;

    ArrayList<Disciplina> disciplinas = new ArrayList<Disciplina>();
    
	Aluno (int matricula, String nome) {
		this.matricula = matricula;
		this.nome = nome;
    }
	
	String mostra() {
        String aluno = "Matricula : " + matricula + " Nome : " + nome + " Disciplinas:\n";
        for (int i = 0; i < disciplinas.size(); i++) {
            aluno += " - " + disciplinas.get(i) + "\n";
        }
        return aluno;
    }
}
