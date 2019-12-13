import java.util.ArrayList;

public class Empresa {

    private String mNome;
    private String mCNPJ;

    ArrayList<Funcionario> funcionarios = new ArrayList<Funcionario>();

    Empresa(String mNome, String mCNPJ) {
        this.mNome = mNome;
        this.mCNPJ = mCNPJ;
    }

    public void addFuncionario(Funcionario novoFuncionario) {
        funcionarios.add(novoFuncionario);
    }

    public String toString() {
        String empresa = "Empresa: " + mNome + "\n"
                       + "CNPJ: " + mCNPJ + "\n\n"
                       + "Funcionários:\n";
        for (int i = 0; i < funcionarios.size(); i++) {
            empresa += funcionarios.get(i) + "\n";
        }
        return empresa;
    }
}