public class Candidato {
    private String nome;
    private int numero;
    private String partido;
    private String cargo;
    private int votos = 0;

    Candidato(String cargo, String nome, int numero, String partido) {
        this.nome = nome;
        this.numero = numero;
        this.partido = partido;
        this.cargo = cargo;
    }

    public String getCargo() {
        return cargo;
    }

    public String getNome() {
        return nome;
    }

    public int getNumero() {
        return numero;
    }

    public String getPartido() {
        return partido;
    }

    public int getVotos() {
        return votos;
    }

    public void somaVoto() {
        this.votos++;
    }
}