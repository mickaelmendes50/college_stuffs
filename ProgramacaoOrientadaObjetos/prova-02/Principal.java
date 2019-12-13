
import javax.swing.JOptionPane;

import java.io.*;
import java.util.ArrayList;


public class Principal {

	public static void main(String[] args) {
			ArrayList<Funcionario> lista = new ArrayList<Funcionario>();
			
			//Leitura do arquivo (Completar)
		    File farqEnt = new File("colaboradores.csv");
		    try {
		    	
		        FileReader f = new FileReader(farqEnt);
		        BufferedReader in = new BufferedReader(f);
		        String linha = in.readLine();
		            
		        while(linha !=null ){	
		             
		        	String[] dados = linha.split(":");
		        			        	
		        	if (dados[0].equals("1")) {
		        		//System.out.println("Funcionario : " + dados[1]);
						String[] dadosFuncionario = dados[1].split("#");
						Funcionario novoFuncionario = new Funcionario(dadosFuncionario[0], Integer.parseInt(dadosFuncionario[2]), 
																	  dadosFuncionario[1].charAt(0), Integer.parseInt(dadosFuncionario[3]));

						lista.add(novoFuncionario);						
		        	}
		        	/*else {
		        		System.out.println("Estagiário : " + dados[1]);
		        	}*/
		             
		             linha = in.readLine();
		         } 
				  in.close();
				  
		     } catch (Exception e) { 
		    	 System.out.println(e); 
		     	}
		    
		    //------------------------
		    // Entrada dos dependentes (Completar)
		     for (int i=0;i<lista.size();i++) {
		    	int num = Integer.parseInt(JOptionPane.showInputDialog("Numero de dependentes de : " + lista.get(i) ));
		    	if (num > 0) {
		    		for (int j=0;j<num;j++) {
		    			int tipo = Integer.parseInt(JOptionPane.showInputDialog("Tipo (1-Filho/Filha, 2-Marido/Esposa, 3-Outros:"));
		    			String nome = JOptionPane.showInputDialog("Nome:");
		    			int idade = Integer.parseInt(JOptionPane.showInputDialog("Idade:"));
						char sexo = JOptionPane.showInputDialog("Sexo:").charAt(0);    
						
						Dependente novoDependente = new Dependente(nome, idade, sexo, tipo);
						lista.get(i).registrarObjetos(novoDependente);
		    		}
		    	}
		    }
		    
		    
		//--------------------------
		// Calculo do valor do plano (implementar)
		for (int i = 0; i < lista.size(); i++) {
			//System.out.println(lista.get(i));
			double valorTotal = lista.get(i).calcularValorPlanoSaude();
			for (int j = 0; j < lista.get(i).dependentes.size(); j++) {
				valorTotal += lista.get(i).dependentes.get(j).calcularValorPlanoSaude();
			}
			System.out.println(lista.get(i).toString() + "Valor do plano: " + valorTotal + "\n");
		}
	}
}

