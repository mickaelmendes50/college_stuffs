public class Cliente {
    private String nome;
    private int telefone;

    Cliente(String nome, int telefone) {
        this.nome = nome;
        this.telefone = telefone;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setTelefone(int telefone) {
        this.telefone = telefone;
    }

    public int getTelefone() {
        return telefone;
    }
}