public class Loja extends LojaAbstract implements IRegistro {
    private String endereco;
    private String gerente;
    
    Loja(String identificador, String cnpj, String razaoSocial, String endereco, String gerente) {
        super(cnpj, razaoSocial);
        super.identificador = identificador;
        this.endereco = endereco;
        this.gerente = gerente;
    }

    public String getEndereco() {
        return endereco;
    }

    public String getGerente() {
        return gerente;
    }

    public void registra_abertura_dia() {
        if (!(super.aberta)) {
            super.aberta = true;
        }
    }

    public void registra_fechamento_dia() {
        if (super.aberta) {
            super.aberta = false;
        }
    }

    public String toString() {
        String loja = "Identificador: " + super.getIdentificador() + "\n"
                    + "Razao Social: " + super.getRazaoSocial() + "\n"
                    + "CNPJ: " + super.getCnpj() + "\n"
                    + "Endereço: " + getEndereco() + "\n"
                    + "Gerente: " + getGerente() + "\n"
                    + "Estado: " + super.getAberta() + "\n";
        return loja;
    }
}