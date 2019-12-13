/*
 *  Aluno: Mickael Mendes Mesquita
 *  Matrícula: 201900967
 */

import java.util.Scanner;

public class Produto {
    // Atributos
    private String mNome;
    private String mTipo;
    private int mCodigoSequencial;
    private int mQuantidade;
    private double mValor;

    public static int sCodigoInicial = 1;

    /*
     *  Construtores
     */
    Produto() {
        this.mCodigoSequencial = this.sCodigoInicial;
    }

    Produto(String mNome) {
        this.mCodigoSequencial = (1 + this.sCodigoInicial);
        this.mNome = mNome;
    }

    Produto(String mNome, int mQuantidade) {
        this.mCodigoSequencial = (2 + this.sCodigoInicial);
        this.mNome = mNome;
        this.mQuantidade = mQuantidade;
    }

    Produto(String mNome, int mQuantidade, String mTipo, double mValor) {
        this.mCodigoSequencial = (3 + this.sCodigoInicial);
        this.mNome = mNome;
        this.mTipo = mTipo;
        this.mQuantidade = mQuantidade;
        this.mValor = mValor;
    }

    /*
     *  Metodos
     */
    public void inserirDados(String mNome, int mQuantidade, String mTipo, double mValor) {
        this.mNome = mNome;
        this.mQuantidade = mQuantidade;
        this.mTipo = mTipo;
        this.mValor = mValor;
    } 

    public double venderProduto(int mQuantidade) {
        if (this.mQuantidade >= mQuantidade) {
            this.mQuantidade = this.mQuantidade - mQuantidade;
            return mQuantidade * this.mValor;
        } else {
            return 0; // Caso não tenha quantidade suficiente no estoque 
        }
    }

    public void renovarEstoque(int mQuantidade) {
        this.mQuantidade = this.mQuantidade + mQuantidade;
        System.out.println("Nova quantidade em estoque: " + this.mQuantidade);
    }

    public void renovarEstoque(int mQuantidade, double mValor) {
        this.mQuantidade = this.mQuantidade + mQuantidade;
        this.mValor = mValor;
        System.out.println("Nova quantidade em estoque: " + this.mQuantidade);
        System.out.println("Novo valor: " + this.mValor);
    }

    public void toString(int mCodigoSequencial, String mNome, int mQuantidade, String mTipo, double mValor) {
        System.out.println("Código:     " + mCodigoSequencial);
        System.out.println("Nome:       " + mNome);
        System.out.println("Tipo:       " + mTipo);
        System.out.println("Quantidade: " + mQuantidade);
        System.out.println("Valor:      " + mValor);
    }

    public boolean comparaProduto(Produto p2) {
        if (this.mNome == p2.mNome && this.mCodigoSequencial == p2.mCodigoSequencial) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {

        Produto produto1 = new Produto();
        Produto produto2 = new Produto("Motorola Moto G7 Plus");
        Produto produto3 = new Produto("Mortal Combat X", 7);
        Produto produto4 = new Produto("Kingston 8Gb", 3, "PenDrive", 30);

        System.out.println("Produto 1");
        String nome = "Mona Lisa"; 
        String tipo = "Decoração";
        int quantidade = 1;
        double valor = 1500;
        produto1.inserirDados(nome, quantidade, tipo, valor);
        double total = produto1.venderProduto(2);
        if (total == 0) {
            System.out.println("Não há quantidade suficiente no estoque");
        } else {
            System.out.println("O valor total é: " + total);
        }
        produto1.renovarEstoque(3, 3000);
        produto1.toString(produto1.mCodigoSequencial, produto1.mNome, produto1.mQuantidade, produto1.mTipo, produto1.mValor);
        if (produto1.comparaProduto(produto2) == true) {
            System.out.println("Iguais");
        } else {
            System.out.println("Diferentes");
        }

        System.out.println("");
        System.out.println("Produto 2");
        tipo = "Celular";
        quantidade = 5;
        valor = 900;
        produto2.inserirDados(produto2.mNome, quantidade, tipo, valor);
        total = produto2.venderProduto(1);
        if (total == 0) {
            System.out.println("Não há quantidade suficiente no estoque");
        } else {
            System.out.println("O valor total é: " + total);
        }
        produto2.renovarEstoque(7);
        produto2.toString(produto2.mCodigoSequencial, produto2.mNome, produto2.mQuantidade, produto2.mTipo, produto2.mValor);
        if (produto2.comparaProduto(produto3) == true) {
            System.out.println("Iguais");
        } else {
            System.out.println("Diferentes");
        }

        System.out.println("");
        System.out.println("Produto 3");
        tipo = "Jogo";
        valor = 100;
        produto3.inserirDados(produto3.mNome, produto3.mQuantidade, tipo, valor);
        total = produto3.venderProduto(4);
        if (total == 0) {
            System.out.println("Não há quantidade suficiente no estoque");
        } else {
            System.out.println("O valor total é: " + total);
        }
        produto3.renovarEstoque(5, 80);
        produto3.toString(produto3.mCodigoSequencial, produto3.mNome, produto3.mQuantidade, produto3.mTipo, produto3.mValor);
        if (produto3.comparaProduto(produto4) == true) {
            System.out.println("Iguais");
        } else {
            System.out.println("Diferentes");
        }

        System.out.println("");
        System.out.println("Produto 4");
        total = produto4.venderProduto(2);
        if (total == 0) {
            System.out.println("Não há quantidade suficiente no estoque");
        } else {
            System.out.println("O valor total é: " + total);
        }
        produto4.renovarEstoque(1);
        produto4.toString(produto4.mCodigoSequencial, produto4.mNome, produto4.mQuantidade, produto4.mTipo, produto4.mValor);
        if (produto4.comparaProduto(produto1) == true) {
            System.out.println("Iguais");
        } else {
            System.out.println("Diferentes");
        }
    }
}