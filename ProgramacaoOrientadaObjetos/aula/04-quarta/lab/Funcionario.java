public class Funcionario {
    protected String nome;
    protected int telefone;
    protected int matricula;
    protected float salario;
    protected float bonificacao;

    private boolean isGerente;
    private Caixa caixa;
    private Gerente gerente;

    Funcionario(String nome, int matricula) {
        this.nome = nome;
        this.matricula = matricula;
    }

    public String getNome() {
        return this.nome;
    }

    public int getMatricula() {
        return this.matricula;
    }

    public void setBonificacao(float bonificacao) {
        this.bonificacao = bonificacao;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }
    
    public float getSalario() {
        return salario;
    }

    public float getSalarioAnual() {
        if (this.bonificacao == 0) {
            return this.salario*12;
        } else {
            return (this.salario+this.bonificacao)*12;
        }
    }

    public void setCaixa(Caixa caixa) {
        this.isGerente = false;
        this.caixa = caixa;
    }

    public Caixa getCaixa() {
        return caixa;
    }
    
    public void setGerente(Gerente gerente) {
        this.isGerente = true;
        this.gerente = gerente;
    }

    public Gerente getGerente() {
        return gerente;
    }

    public void setTelefone(int telefone) {
        this.telefone = telefone;
    }

    public void aumentoSalario(double percentual) {
        this.salario += this.salario*percentual;
    }

    public String toString() {
        String funcionario = "Nome: " + nome + "   Matrícula: " + matricula + "\n"
                           + "Telefone: " + telefone + "\n";
        if (this.isGerente == true) {
            funcionario = funcionario + "Cargo: Gerente   Tipo: " + getGerente().getTipo() + "\n"
                        + "Salario: " + getSalario() + "   Bonificação " + bonificacao + "\n";
        } else {
            funcionario = funcionario + "Cargo: Caixa   Horario: " + getCaixa().getHorario() + "\n"
                        + "Salario: " + getSalario() + "\n"; 
        }
        funcionario = funcionario + "Salario anual: " + getSalarioAnual();
        return funcionario + "\n";
    }
}