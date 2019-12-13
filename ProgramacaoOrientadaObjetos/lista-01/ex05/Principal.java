import java.util.Scanner;

public class Principal {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        Horario primeiroHorario = new Horario(sc.nextInt(), sc.nextInt(), sc.nextInt());
        Horario segundoHorario = new Horario(sc.nextInt());

        System.out.println(primeiroHorario);
        System.out.println(segundoHorario);
        System.out.println(Horario.diferencaHorarios(primeiroHorario, segundoHorario));
    }
}