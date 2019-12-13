public class Saque {
	private String descricao;
    private double valor;
    private String diaDoSaque;
		
	Saque (String dia, String descricao, double valor) {
		this.descricao = descricao;
        this.valor = valor;
        this.dia = dia;
	}

	public String getDescricao() {
		return descricao;
    }

    public String getDiaDoSaque() {
        return diaDoSaque;
    }

	public double getValor() {
		return valor;
	}		
		
	public String toString () {
		return diaDoSaque + " - " + descricao + " - " + valor;
	}
}