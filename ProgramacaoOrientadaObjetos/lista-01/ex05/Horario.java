public class Horario {

    private int mHora;
    private int mMinuto;
    private int mSegundo;

    Horario(int mHora) {
        this.mHora = mHora;
        this.mMinuto = 0;
        this.mSegundo = 0;
    }

    Horario(int mHora, int mMinuto, int mSegundo) {
        if (isHourElegible(mHora)) this.mHora = mHora;
        else System.out.println("Inválido");
        if (isMinuteElegible(mMinuto)) this.mMinuto = mMinuto;
        else System.out.println("Inválido");
        if (isSecondElegible(mSegundo)) this.mSegundo = mSegundo;
        else System.out.println("Inválido");
    }

    public void setHora(int mHora) {
        if (isHourElegible(mHora)) this.mHora = mHora;
        else System.out.println("Inválido");
    }

    public int getHora() {
        return mHora;
    }

    public void setMinuto(int mMinuto) {
        if (isMinuteElegible(mMinuto)) this.mMinuto = mMinuto;
        else System.out.println("Inválido");
    }

    public int getMinuto() {
        return mMinuto;
    }

    public void setSegundo(int mSegundo) {
        if (isSecondElegible(mSegundo)) this.mSegundo = mSegundo;
        else System.out.println("Inválido");
    }

    public int getSegundo() {
        return mSegundo;
    }

    public void setHorario(int mHora, int mMinuto, int mSegundo) {
        this.mHora = mHora;
        this.mMinuto = mMinuto;
        this.mSegundo = mSegundo;
    }

    public String getHorario() {
        return getHora() + ":" + getMinuto() + ":" + getSegundo();
    }

    private boolean isHourElegible(int mHora) {
        if (mHora < 24 && mHora >= 0) {
            return true;
        } else {
            return false;
        }
    }

    private boolean isMinuteElegible(int mMinuto) {
        if (mMinuto < 60 && mMinuto >= 0) {
            return true;
        } else {
            return false;
        }
    }

    private boolean isSecondElegible(int mSegundo) {
        if (mSegundo < 60 && mSegundo >= 0) {
            return true;
        } else {
            return false;
        }
    }

    public static String diferencaHorarios(Horario primeiro, Horario segundo) {
        int diferencaEmMinutos = ((segundo.getHora() * 60) + segundo.getMinuto()) - ((primeiro.getHora() * 60) + primeiro.getMinuto());
        
        if (diferencaEmMinutos > 0) {
            return "Faltam " + diferencaEmMinutos + " minuto(s)";
        } else {
            return "Atraso de " + diferencaEmMinutos + " minuto(s)";
        }
    }

    public String toString() {
        return getHorario();
    }
}