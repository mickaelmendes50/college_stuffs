public abstract class LojaAbstract {
    protected String identificador;
    protected String cnpj;
    protected String razaoSocial;
    protected boolean aberta;

    LojaAbstract(String cnpj, String razaoSocial) {
        this.cnpj = cnpj;
        this.razaoSocial = razaoSocial;
        this.aberta = false;
    }

    public String getCnpj() {
        return cnpj;
    }

    public String getIdentificador() {
        return identificador;
    }

    public String getRazaoSocial() {
        return razaoSocial;
    }

    public String getAberta() {
        String aberta;
        if (this.aberta) {
            aberta = "Aberta";
        } else {
            aberta = "Fechada";
        }
        return aberta;
    }
}