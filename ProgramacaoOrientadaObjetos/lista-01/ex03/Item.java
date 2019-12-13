public class Item {

    protected String titulo;
    protected String comentarios;
    protected String tempoDeDuracao;
    protected int ano;

    protected String tipo; // Acho coerente identificar qual é o tipo do item

    Item(String titulo, String tipo) {
        this.titulo = titulo;
        this.tipo = tipo;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public void setComentarios(String comentarios) {
        this.comentarios = comentarios;
    }

    public void setTempoDeDuracao(String tempoDeDuracao) {
        this.tempoDeDuracao = tempoDeDuracao;
    }

    public String toString() {
        String item = "Nome: " + titulo + "\n"
                    + "Tipo: " + tipo + "\n"
                    + "Ano: " + ano + "\n"
                    + "Comentários: " + comentarios + "\n"
                    + "Tempo de duração: " + tempoDeDuracao + "\n";
        return item;
    }
}