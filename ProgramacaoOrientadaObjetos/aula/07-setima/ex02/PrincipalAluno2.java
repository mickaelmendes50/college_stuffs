import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.NotSerializableException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.lang.reflect.Array;
import java.util.ArrayList;

import javax.swing.JOptionPane;

public class PrincipalAluno2 {

	public static void main(String[] args) throws NotSerializableException {
		// TODO Auto-generated method stub

		String nome;
		int matricula;

		Aluno al;
		Disciplina novaDisciplina;

		ArrayList<Disciplina> disciplinas = new ArrayList<Disciplina>();
		ArrayList<Aluno> alunos = new ArrayList<Aluno>();

		try {
		FileOutputStream fx = new FileOutputStream("arquivoObj.txt");
		ObjectOutputStream sx = new ObjectOutputStream(fx);

			nome = JOptionPane.showInputDialog("Entre com o nome");

			while (!(nome.equals("Fim"))) {
				matricula = Integer.parseInt(JOptionPane
                        .showInputDialog("Entre com a matricula"));

                al = new Aluno(matricula, nome);

                String nomedisc = JOptionPane.showInputDialog("Entre com o nome da disciplina");
                while(!(nomedisc.equals("f"))) {
                    int codigo = Integer.parseInt(JOptionPane.showInputDialog("Entre com o codigo da disciplina"));

					novaDisciplina = new Disciplina(codigo, nomedisc);
					disciplinas.add(novaDisciplina);

                    nomedisc = JOptionPane.showInputDialog("Entre com o nome da disciplina");
				}
				al.disciplinas = disciplinas;

				sx.writeObject(al);
				nome = JOptionPane.showInputDialog("Entre com o nome");
			}
			
			sx.close();
			fx.close();
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		try {
			FileInputStream f = new FileInputStream("arquivoObj.txt");
			ObjectInputStream s = new ObjectInputStream(f);
			
								
			while ((al = (Aluno)s.readObject()) != null) {
			
				System.out.println(al.mostra());
			}
			
			s.close();
			f.close();

		}
		catch (IOException e) { System.out.println("Fim"); }
		
		catch (Exception e) { e.printStackTrace(); }
		}	

	}
