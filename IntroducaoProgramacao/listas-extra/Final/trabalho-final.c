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

/**
 * Tipos de dados 
 */
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
// Vamos definir um contador para auxiliar no
// cadastro de novos clientes
int contador_clientes = 0;

/**
 * Utilitários
 */
// Função de cadastro dos clientes
int cadastrar_cliente() {
    int codigo;
    char nome[TAM_MAX_NOME + 1];
    char cpf[TAM_CPF + 1];
    char telefone[TAM_TELEFONE + 1];
    char endereco[TAM_MAX_ENDERECO + 1];

    printf("\n===== Informações =====\n");
    printf("Código: ");
    scanf("%d", &codigo);
    for (int i = 0; i < contador_clientes; i++) {
        if (clientes[i].codigo == codigo) {
            printf("Cliente já cadastrado\n");
            return 0;
        }
    }
    printf("Nome: ");
    scanf("%s", nome);
    printf("CPF/CPNJ: ");
    scanf("%s", cpf);
    printf("Telefone: ");
    scanf("%s", telefone);
    printf("Endereço: ");
    scanf("%s", endereco);

    clientes[contador_clientes].codigo = codigo;
    strcpy(clientes[contador_clientes].nome, nome);
    strcpy(clientes[contador_clientes].cpf, cpf);
    strcpy(clientes[contador_clientes].telefone, telefone);
    strcpy(clientes[contador_clientes].endereco, endereco);

    // Incrementa o número de clientes
    contador_clientes++;
    return 1;
}

// Função para listar clientes
void listar_clientes() {
    int aux_int;
    char aux_string[50] = "";

    // Ordenando o struct
    for (int i = 0; i < contador_clientes-1; i++) {
        for (int j = 1; j < contador_clientes; j++) {

            // Compara as strings do nome para saber quem vem antes
            if (strcmp(clientes[i].nome, clientes[j].nome) > 0) {
                // Inverte a posição do código
                aux_int = clientes[j].codigo;
                clientes[j].codigo = clientes[i].codigo;
                clientes[i].codigo = aux_int;

                // Inverte a posição do nome
                strcpy(aux_string, clientes[j].nome);
                strcpy(clientes[j].nome, clientes[i].nome);
                strcpy(clientes[i].nome, aux_string);

                // Inverte a posição do CPF/CNPJ
                strcpy(aux_string, clientes[j].cpf);
                strcpy(clientes[j].cpf, clientes[i].cpf);
                strcpy(clientes[i].cpf, aux_string);                

                // Inverte a posição do telefone
                strcpy(aux_string, clientes[j].telefone);
                strcpy(clientes[j].telefone, clientes[i].telefone);
                strcpy(clientes[i].telefone, aux_string);

                // Inverte a posição do endereço
                strcpy(aux_string, clientes[j].endereco);
                strcpy(clientes[j].endereco, clientes[i].endereco);
                strcpy(clientes[i].endereco, aux_string);
            }
        }   
    }
    
    // Imprime a struct na tela
    for (int i = 0; i < contador_clientes; i++) {
        printf("\n========== Cliente %d =========\n", i+1);
        printf("Código: %d\n", clientes[i].codigo);
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF/CNPJ: %s\n", clientes[i].cpf);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("Endereço: %s\n", clientes[i].endereco);
    }
}

// Função para buscar clientes
int buscar_clientes() {
    int opcao;
    //do {
        printf("\n============ Buscar Cliente ============\n");
        printf("Digite um comando para prosseguir:\n");
        printf("1 – Buscar por nome\n");
        printf("2 – Buscar por código\n");
        printf("3 – Buscar por CPF/CNPJ\n");
        printf("0 – Sair\n");
        scanf("%d", &opcao);

        char aux_nome[TAM_MAX_NOME + 1];
        int aux_codigo;
        char aux_cpf[TAM_CPF + 1];

        switch (opcao) {
            case 1:
                printf("Informe o nome: ");
                scanf("%s", aux_nome);
                for (int i = 0; i < contador_clientes; i++) {
                    // Caso o nome seja igual
                    if (strcmp(aux_nome, clientes[i].nome) == 0) {
                        printf("\n========== Cliente =========\n");
                        printf("Código: %d\n", clientes[i].codigo);
                        printf("Nome: %s\n", clientes[i].nome);
                        printf("CPF/CNPJ: %s\n", clientes[i].cpf);
                        printf("Telefone: %s\n", clientes[i].telefone);
                        printf("Endereço: %s\n", clientes[i].endereco);
                        return 1;
                    }
                }
                break;
            
            case 2:
                printf("Informe o código: ");
                scanf("%d", &aux_codigo);
                for (int i = 0; i < contador_clientes; i++) {
                    // Caso o código seja igual
                    if (aux_codigo == clientes[i].codigo) {
                        printf("\n========== Cliente =========\n");
                        printf("Código: %d\n", clientes[i].codigo);
                        printf("Nome: %s\n", clientes[i].nome);
                        printf("CPF/CNPJ: %s\n", clientes[i].cpf);
                        printf("Telefone: %s\n", clientes[i].telefone);
                        printf("Endereço: %s\n", clientes[i].endereco);
                        return 1;
                    }
                }
                break;

            case 3:
                printf("Informe o CPF/CNPJ: ");
                scanf("%s", aux_cpf);
                for (int i = 0; i < contador_clientes; i++) {
                    // Caso o CPF/CNPJ seja igual
                    if (strcmp(aux_cpf, clientes[i].cpf) == 0) {
                        printf("\n========== Cliente =========\n");
                        printf("Código: %d\n", clientes[i].codigo);
                        printf("Nome: %s\n", clientes[i].nome);
                        printf("CPF/CNPJ: %s\n", clientes[i].cpf);
                        printf("Telefone: %s\n", clientes[i].telefone);
                        printf("Endereço: %s\n", clientes[i].endereco);
                        return 1;
                    }
                }
                break;
            
            case 0:
                break;
        
            default:
                printf("\n** Comando inválido digite 1, 2, 3 ou 0 para prosseguir **\n");
                break;
        }
    //} while (opcao != 0);
    return 0;
}

/**
 * Menus de interação
 */
// Menu de gestão de clientes
void menu_gerenciar_cliente() {
    char opcao;
    do {
        printf("\n============ Gerenciar Clientes ============\n");
        printf("Digite um comando para prosseguir:\n");
        printf("C – Cadastrar um cliente\n");
        printf("L – Listar todos os clientes cadastrados\n");
        printf("B – Buscar cliente já cadastrado\n");
        printf("A – Atualizar um cliente cadastrado\n");
        printf("E – Excluir um cliente cadastrado\n");
        printf("S – Sair\n");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'C':
                if (cadastrar_cliente()) {
                    printf("\nCadastro concluído com sucesso\n\n");
                    break;
                }
                printf("\nOps! Algo deu errado\n\n");
                break;
            
            case 'L':
                if (contador_clientes > 0) {
                    listar_clientes();
                    break;
                }
                printf("\nNenhum cliente cadastrado.\n\n");
                break;
            
            case 'B':
                if (buscar_clientes()) {
                    break;
                }
                printf("\nCliente não encontrado.\n\n");
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

int main(int argc, char const *argv[]) {

    menu_principal();
    return 0;
}
