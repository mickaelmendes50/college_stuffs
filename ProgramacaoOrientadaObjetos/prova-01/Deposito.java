public class Deposito {
	private String descricao;
	private double valor;
		
	Deposito (String descricao, double valor) {
		this.descricao = descricao;
		this.valor = valor;
	}

	public String getDescricao() {
		return descricao;
	}

	public double getValor() {
		return valor;
	}		
		
	public String toString () {
		return descricao + " - " + valor;
	}
}