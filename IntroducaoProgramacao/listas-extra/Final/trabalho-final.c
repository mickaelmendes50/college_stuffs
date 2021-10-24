#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUANT_MAX_CLIENTES 100
#define QUANT_MAX_CONTAS 200
#define QUANT_MAX_TRANSACOES 1000

#define TAM_MAX_NOME 30
#define TAM_CPF 11
#define TAM_TELEFONE 15
#define TAM_MAX_ENDERECO 50

// Menu de gestão de clientes
void menu_gerenciar_cliente() {
    printf("============ Gerenciar Clientes ============\n");
    printf("Digite um comando para prosseguir:\n");
    printf("C – Cadastrar um cliente\n");
    printf("L – Listar todos os clientes cadastrados\n");
    printf("B – Buscar cliente já cadastrado\n");
    printf("A – Atualizar um cliente cadastrado\n");
    printf("E – Excluir um cliente cadastrado\n");
    printf("S – Sair\n");

    char opcao = getchar();
    getchar();

    do {
        switch (opcao) {
            case 'C':
                
                break;
            
            case 'S':
                break;
            
            default:
                printf("\n** Comando inválido digite C, T ou S para prosseguir **\n");
                break;
        }
    } while (opcao != 'S');
}

// Menu de gestão de contas
void menu_gerenciar_conta() {
    printf("============ Gerenciar Contas ============\n");
    printf("Digite um comando para prosseguir:\n");
    printf("R – Listagem de todas as contas cadastradas.\n");
    printf("C – Cadastrar uma conta para um cliente.\n");
    printf("L – Listar todas as contas de um cliente.\n");
    printf("W – Realizar um saque em uma conta.\n");
    printf("D – Realizar um depósito em uma conta.\n");
    printf("T – Realizar transferência entre contas.\n");
    printf("E – Exibir extrato de uma conta.\n");
    printf("S – Sair\n");
}

// Menu inicial
void menu_principal() {
    char opcao;
    do {
        printf("\n============ Bem Vindo! ============\n");
        printf("Digite um comando para prosseguir:\n");
        printf("C - Gerenciar Clientes\n");
        printf("T - Gerenciar Contas\n");
        printf("S - Sair\n");
        printf("\nEscolha: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'C':
                menu_gerenciar_cliente();
                break;
            case 'T':
                menu_gerenciar_cliente();
                break;
            case 'S':
                break;
            default:
                printf("\n** Comando inválido digite C, T ou S para prosseguir **\n");
        }
    } while (opcao != 'S');
    printf("\nAté mais!\n");
}

// Cria um novo tipo de dados chamado Cliente com 
// as caracteristicas descritas
typedef struct {
    int codigo;
    char nome[TAM_MAX_NOME + 1];
    char cpf[TAM_CPF + 1];
    char telefone[TAM_TELEFONE + 1];
    char endereco[TAM_MAX_ENDERECO + 1];
} Cliente;
// Intancia os clientes de forma global
// para estar definido em qualquer escopo
Cliente clientes[QUANT_MAX_CLIENTES + 1];

int main(int argc, char const *argv[]) {

    menu_principal();
    return 0;
}
