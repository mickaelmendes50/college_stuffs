public class Cliente {
    private String nome;
    private int telefone;
    private int idade;
    private String cpf;
    private String status;
    
    Cliente(String nome, int telefone, int idade, String cpf) {
        this.nome = nome;
        this.telefone = telefone;
        this.idade = idade;
        this.cpf = cpf;
        this.status = "A";
    }

    public void setStatus() {
        if (this.status.equals("A")) {
            this.status = "I";
        } else {
            this.status = "A";
        }
    }

    public String getStatus() {
        if (this.status.equals("A")) {
            return "Ativo";
        } else {
            return "Inativo";
        }       
    }

    public String toString() {
        String cliente = nome + " - Tel: " + telefone + " - Idade: " + idade + " anos " + " - CPF: " + cpf + " - " + getStatus();
        return cliente;
    }
}