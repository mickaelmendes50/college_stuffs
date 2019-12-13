/*
 * Aluno: Mickael Mendes Mesquita
 * Matrícula: 201900967
 */

import java.util.ArrayList;

public class Principal {

    public static void main(String[] args) {
        ArrayList<Funcionario> funcionarios = new ArrayList<Funcionario>();

        Gerente novoGerente = new Gerente("João Marcos", "Barcelos");
        novoGerente.setSalarioMensal(2900);
        novoGerente.setBonificacao(800);
        funcionarios.add(novoGerente);

        Horista novoHorista = new Horista("Mickael", "Mesquita");
        novoHorista.setHorasTrabalhadas(120);
        novoHorista.setValorDaHora(80);
        funcionarios.add(novoHorista);

        novoHorista = new Horista("Lucas", "Mendes");
        novoHorista.setHorasTrabalhadas(140);
        novoHorista.setValorDaHora(50);
        funcionarios.add(novoHorista);

        Comissionado novoComissionado = new Comissionado("Ariadne", "Barcelos");
        novoComissionado.setSalarioMensal(3000);
        novoComissionado.setTotalDeVendas(203);
        novoComissionado.setPercentualComissao(0.203);
        funcionarios.add(novoComissionado);

        novoComissionado = new Comissionado("Lucas", "Marques");
        novoComissionado.setSalarioMensal(1900);
        novoComissionado.setTotalDeVendas(158);
        novoComissionado.setPercentualComissao(0.158);
        funcionarios.add(novoComissionado);

        novoComissionado = new Comissionado("Guilherme", "Martins");
        novoComissionado.setSalarioMensal(2100);
        novoComissionado.setTotalDeVendas(260);
        novoComissionado.setPercentualComissao(0.26);
        funcionarios.add(novoComissionado);

        Administrador novoAdministrador = new Administrador("Marcia", "Barcelos");
        novoAdministrador.setSalarioMensal(2400);
        funcionarios.add(novoAdministrador);

        novoAdministrador = new Administrador("Pedro", "Buléia");
        novoAdministrador.setSalarioMensal(2800);
        funcionarios.add(novoAdministrador);

        novoAdministrador = new Administrador("Arthur", "Lapot");
        novoAdministrador.setSalarioMensal(1900);
        funcionarios.add(novoAdministrador);

        novoAdministrador = new Administrador("Henrique", "Martins");
        novoAdministrador.setSalarioMensal(1400);
        funcionarios.add(novoAdministrador);

        for (int i = 0; i < funcionarios.size(); i++) {
            System.out.println(funcionarios.get(i) + "\n");
        }
    }
}