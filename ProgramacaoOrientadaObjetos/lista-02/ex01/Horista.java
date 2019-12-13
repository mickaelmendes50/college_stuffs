public class Horista extends Funcionario {

    private int horasTrabalhadas;
    private double valorDaHora;

    Horista(String nome, String sobrenome) {
        super(nome, sobrenome);
    }

    public void setHorasTrabalhadas(int horasTrabalhadas) {
        this.horasTrabalhadas = horasTrabalhadas;
    }

    public int getHorasTrabalhadas() {
        return horasTrabalhadas;
    }

    public void setValorDaHora(double valorDaHora) {
        this.valorDaHora = valorDaHora;
    }
    
    public double getValorDaHora() {
        return valorDaHora;
    }

    public double getSalarioTotal() {
        return getValorDaHora() * getHorasTrabalhadas();
    }

    public String toString() {
        String horista = "Horas trabalhadas: " + getHorasTrabalhadas() + "\n"
                       + "Valor por hora: " + getValorDaHora() + "\n"
                       + "Salario total: " + getSalarioTotal(); 
        return super.toString() + "\n" + horista;
    }
}