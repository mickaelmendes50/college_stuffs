import java.util.ArrayList;

import javax.swing.JOptionPane;

public class ProgramaTrainee {

    //
    //  Menus de inicialização
    //
    public static int menuInicial() {
        String menuInicial = "----------------------------------------------------------\n"
                           + "   Sistema de Controle de Trainees \n"
                           + "----------------------------------------------------------\n\n"
                           + "Selecione um topico:\n"
                           + " 1 - Aluno\n"
                           + " 2 - Curso\n"
                           + " 3 - Universidade\n"
                           + " 4 - Busca de Trainee\n"
                           + " 0 - Sair do programa\n\n";

        int topic = Integer.parseInt(JOptionPane.showInputDialog(menuInicial));
        return topic;
    }

    public static int menuSecundario(int topic) {
        String topicStr = "";
        if (topic == 1) topicStr = "Alunos";
        if (topic == 2) topicStr = "Cursos";
        if (topic == 3) topicStr = "Universidades";

        int option = 5;

        String menuSecundario = "----------------------------------------------------------\n"
                              + "   Catalogo de " + topicStr + " \n"
                              + "----------------------------------------------------------\n\n"
                              + "Escolha uma opcao:\n"
                              + " 1 - Inclusao\n"
                              + " 2 - Alteracao\n"
                              + " 3 - Consulta\n"
                              + " 4 - Exclusao\n"
                              + " 0 - Voltar ao menu principal\n\n";       

        option = Integer.parseInt(JOptionPane.showInputDialog(menuSecundario));
        return option;
    }

    //
    // Operacoes
    //
    public static void inclusao(int topic) {
        ArrayList<Universidade> universidades = new ArrayList<Universidade>();

        if (topic == 1) {
            String universidade = JOptionPane.showInputDialog("Insira o nome da Universidade vinculada");
            boolean achou = false;
            for (int i = 0; i < universidades.size(); i++) {
                if (universidade.equals(universidades.get(i).getNome())) {
                    String curso = JOptionPane.showInputDialog("Insira o nome do Curso vinculado");
                    for (int j = 0; i < universidades.get(i).cursos.size(); j++) {
                        if (curso.equals(universidades.get(i).cursos.get(j).getNome())) {
                            achou = true;
                            break;
                        }
                    }              
                    if (achou) break;
                }
            }
            if (!achou) {
                String x = "Universidade nao encontrada!\n\n"
                         + "Deseja cadastra-la?\n"
                         + " 1 - Sim\n"
                         + " 2 - Nao\n";
                
                int opt = Integer.parseInt(JOptionPane.showInputDialog(x));
                if (opt == 1) {
                    novaUniversidade(universidades);
                }
            }
        }

        if (topic == 2) {
            String universidade = JOptionPane.showInputDialog("Insira o nome da Universidade vinculada");
            boolean achou = false;
            for (int i = 0; i < universidades.size(); i++) {
                if (universidade.equals(universidades.get(i).getNome())) {
                    universidades.get(i).novoCurso();
                    achou = true;
                    break;
                }
            }
            if (!achou) {
                String x = "Universidade nao encontrada!\n\n"
                         + "Deseja cadastra-la?\n"
                         + " 1 - Sim\n"
                         + " 2 - Nao\n";
                
                int opt = Integer.parseInt(JOptionPane.showInputDialog(x));
                if (opt == 1) {
                    novaUniversidade(universidades);
                }
            }
        }

        if (topic == 3) novaUniversidade(universidades);
    }

    public static void novaUniversidade(ArrayList universidades) {
        String university = "----------------------------------------------------------\n"
                          + "    Cadastro de Universidade\n"
                          + "----------------------------------------------------------\n";
        String nome = JOptionPane.showInputDialog(university + "Insira o nome\n");
        String endereco = JOptionPane.showInputDialog(university + "Insira o endereco\n");
        String bairro = JOptionPane.showInputDialog(university + "Insira o bairro\n");
        String cidade = JOptionPane.showInputDialog(university + "Insira a cidade\n");
        String estado = JOptionPane.showInputDialog(university + "Insira o estado\n");

        Universidade novaUniversidade = new Universidade(nome, endereco, bairro, cidade, estado);

        int opt = Integer.parseInt(JOptionPane.showInputDialog("Deseja cadastrar um curso para essa universidade?\n 1 - Sim\n 2 - Nao"));
        while (opt == 1) {
            novaUniversidade.novoCurso();
            opt = Integer.parseInt(JOptionPane.showInputDialog("Deseja cadastrar um novo curso para essa universidade?\n 1 - Sim\n 2 - Nao"));
        }
        universidades.add(novaUniversidade);
    }

    public static void main(String[] args) {
        int option = 5;
        int topic = 5;

        while (topic != 0) {
            topic = menuInicial();
            switch (topic) {
                case 0:
                    break;
                    
                case 1:
                    option = menuSecundario(topic);
                    break;

                case 2:
                    option = menuSecundario(topic);
                    break;

                case 3:
                    option = menuSecundario(topic);
                    break;

                case 4:
                    break;
                    
                default:
                    JOptionPane.showMessageDialog(null, "Opcao invalida!");
                    break;
            }
            if (topic == 0) break; // Forçar parada do programa
            
            while (option != 0) {
                switch (option) {
                    case 0:
                        break;
                        
                    case 1:
                        inclusao(topic);
                        break;
                    
                    case 2:
                        inclusao(topic);
                        break;

                    case 3:
                        inclusao(topic);
                        break;
                    
                    case 4:
                        inclusao(topic);
                        break;

                    default:
                        JOptionPane.showMessageDialog(null, "Opcao invalida!");
                        break;
                }
                option = menuSecundario(topic);
            }
        }
    }
}