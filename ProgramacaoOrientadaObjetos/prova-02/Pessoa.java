public abstract class Pessoa {
    protected String nome;
    protected int idade;
    protected char sexo;
    
    Pessoa(String nome, int idade, char sexo) {
        this.nome = nome;
        this.idade = idade;
        this.sexo = sexo;
    }

    public abstract double calcularValorPlanoSaude();

    public String toString() {
        String pessoa = "Nome: " + nome + "\n"
                      + "Idade: " + idade + "\n";
        return pessoa;
    }
}