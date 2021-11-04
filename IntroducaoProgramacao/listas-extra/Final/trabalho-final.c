#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QUANT_MAX_CLIENTES 100
#define QUANT_MAX_CONTAS 200
#define QUANT_MAX_TRANSACOES 1000

#define TAM_MAX_NOME 30
#define TAM_CPF 11
#define TAM_TELEFONE 15
#define TAM_MAX_ENDERECO 50
#define TAM_MAX_DESCRICAO 100

/**
 * Tipos de dados 
 */
 
// Cria um novo tipo de dados chamado Trasacao com 
// as caracteristicas descritas
typedef struct {
    int tipo; // 0 - debito e 1 - credito
    double valor;
    time_t data;
    char descricao[TAM_MAX_DESCRICAO + 1];
    int agencia;
    int numero;
} Trasacao;
// Vamos definir um contador para auxiliar no
// cadastro de novas transacoes, visto que elas não
// pode exceder o limite previsto
Trasacao transacoes[QUANT_MAX_TRANSACOES + 1];
int contador_transacoes = 0;
 
// Cria um novo tipo de dados chamado Conta com 
// as caracteristicas descritas
typedef struct {
    int agencia;
    int numero;
    double saldo;
    int quant_transacoes;
    //Trasacao transacoes[QUANT_MAX_TRANSACOES + 1];
} Conta;
// Vamos definir um contador para auxiliar no
// cadastro de novas contas, visto que ela não
// pode exceder o limite previsto
int contador_contas = 0;

// Cria um novo tipo de dados chamado Cliente com 
// as caracteristicas descritas
typedef struct {
    int codigo;
    char nome[TAM_MAX_NOME + 1];
    char cpf[TAM_CPF + 1];
    char telefone[TAM_TELEFONE + 1];
    char endereco[TAM_MAX_ENDERECO + 1];
    Conta contas[QUANT_MAX_CONTAS + 1];
    int quant_contas; // Pra controlar a quantidade de contas vinculadas a cada usuário
} Cliente;
// Intancia os clientes de forma global
// para estar definido em qualquer escopo
Cliente clientes[QUANT_MAX_CLIENTES + 1];
// Vamos definir um contador para auxiliar no
// cadastro de novos clientes, visto que ele não
// pode exceder o limite previsto
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
    clientes[contador_clientes].quant_contas = 0;
    strcpy(clientes[contador_clientes].nome, nome);
    strcpy(clientes[contador_clientes].cpf, cpf);
    strcpy(clientes[contador_clientes].telefone, telefone);
    strcpy(clientes[contador_clientes].endereco, endereco);

    // Incrementa o número de clientes
    contador_clientes++;
    return 1;
}

// Função para listar clientes
void listar_clientes(int contas) {
    int aux_int;
    int aux_quant_contas;
    Conta aux_contas[QUANT_MAX_CONTAS + 1];
    char aux_string[50] = "";

    // Ordenando o struct de clientes
    for (int i = 0; i < contador_clientes-1; i++) {
        for (int j = 1; j < contador_clientes; j++) {

            // Compara as strings do nome para saber quem vem antes
            if (strcmp(clientes[i].nome, clientes[j].nome) > 0) {
                // Inverte a posição do código
                aux_int = clientes[j].codigo;
                clientes[j].codigo = clientes[i].codigo;
                clientes[i].codigo = aux_int;
                
                // Inverte a posição da quantidade de contas
                aux_quant_contas = clientes[j].quant_contas;
                clientes[j].quant_contas = clientes[i].quant_contas;
                clientes[i].quant_contas = aux_quant_contas;

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
                
                // Inverte a posição das contas
                memcpy(aux_contas, clientes[j].contas, sizeof(Conta) * QUANT_MAX_CONTAS+1);
                memcpy(clientes[j].contas, clientes[i].contas, sizeof(Conta) * QUANT_MAX_CONTAS+1);
                memcpy(clientes[i].contas, aux_contas, sizeof(Conta) * QUANT_MAX_CONTAS+1);
            }
        }   
    }
    
    int aux_agencia;
    int aux_numero;
    double aux_saldo;
    if (contas) {
        // Ordenando o struct de contas
        for (int i = 0; i < clientes[i].quant_contas-1; i++) {
            for (int j = 1; j < clientes[j].quant_contas; j++) {

                // Compara o saldo para saber quem vem antes
                if (clientes[i].contas[i].saldo < clientes[j].contas[j].saldo) {
                    // Inverte a posição da agencia
                    aux_agencia = clientes[j].contas[j].agencia;
                    clientes[j].contas[j].agencia = clientes[i].contas[i].agencia;
                    clientes[i].contas[i].saldo = aux_agencia;

                    // Inverte a posição do numero da conta
                    aux_numero = clientes[j].contas[j].numero;
                    clientes[j].contas[j].numero = clientes[i].contas[i].numero;
                    clientes[i].contas[i].saldo = aux_numero;

                    // Inverte a posição do saldo
                    aux_saldo = clientes[j].contas[j].saldo;
                    clientes[j].contas[j].saldo = clientes[i].contas[i].saldo;
                    clientes[i].contas[i].saldo = aux_saldo;
                }
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

        if (contas) {
            for (int j = 0; j < clientes[i].quant_contas; j++) {
                printf("\n----- Conta %d -----\n", j+1);
                printf("Agencia: %d\n", clientes[i].contas[j].agencia);
                printf("Conta: %d\n", clientes[i].contas[j].numero);
                printf("Saldo: %.2lf\n", clientes[i].contas[j].saldo);
            }
        }
    }
}

// Função para buscar clientes
int buscar_clientes(int contas) {
    int opcao;
    //do {
        printf("\n============ Buscar Cliente ============\n");
        printf("Digite um comando para prosseguir:\n");
        printf("1 – Buscar por nome\n");
        printf("2 – Buscar por código\n");
        printf("3 – Buscar por CPF/CNPJ\n");
        printf("0 – Sair\n");
        printf("\nEscolha: ");
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

                        if (contas) {
                            if (clientes[i].quant_contas == 0) {
                                printf("\nNenhuma conta cadastrada\n");
                            } else {
                                for (int j = 0; j < clientes[i].quant_contas; j++) {
                                    printf("\n----- Conta %d -----\n", j+1);
                                    printf("Agencia: %d\n", clientes[i].contas[j].agencia);
                                    printf("Conta: %d\n", clientes[i].contas[j].numero);
                                    printf("Saldo: %.2lf\n", clientes[i].contas[j].saldo);
                                }
                            }
                        }

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

                        if (contas) {
                            if (clientes[i].quant_contas == 0) {
                                printf("\nNenhuma conta cadastrada\n");
                            } else {
                                for (int j = 0; j < clientes[i].quant_contas; j++) {
                                    printf("\n----- Conta %d -----\n", j+1);
                                    printf("Agencia: %d\n", clientes[i].contas[j].agencia);
                                    printf("Conta: %d\n", clientes[i].contas[j].numero);
                                    printf("Saldo: %.2lf\n", clientes[i].contas[j].saldo);
                                }
                            }
                        }

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

                        if (contas) {
                            if (clientes[i].quant_contas == 0) {
                                printf("\nNenhuma conta cadastrada\n");
                            } else {
                                for (int j = 0; j < clientes[i].quant_contas; j++) {
                                    printf("\n----- Conta %d -----\n", j+1);
                                    printf("Agencia: %d\n", clientes[i].contas[j].agencia);
                                    printf("Conta: %d\n", clientes[i].contas[j].numero);
                                    printf("Saldo: %.2lf\n", clientes[i].contas[j].saldo);
                                }
                            }
                        }

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

// Função para atualizar clientes
int atualizar_clientes() {
    int opcao;
    //do {
        printf("\n============ Atualizar Cliente ============\n");
        printf("Digite um comando para prosseguir:\n");
        printf("1 – Buscar por código\n");
        printf("2 – Buscar por CPF/CNPJ\n");
        printf("0 – Sair\n");
        printf("\nEscolha: ");
        scanf("%d", &opcao);

        int aux_codigo;
        char aux_nome[TAM_MAX_NOME + 1];
        char aux_cpf[TAM_CPF + 1];
        char aux_telefone[TAM_TELEFONE + 1];
        char aux_endereco[TAM_MAX_ENDERECO + 1];

        switch (opcao) {
            case 1:
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

                        printf("\n========== Atualizar =========\n");
                        printf("Código: ");
                        scanf("%d", &aux_codigo);
                        printf("Nome: ");
                        scanf("%s", aux_nome);
                        printf("CPF/CPNJ: ");
                        scanf("%s", aux_cpf);
                        printf("Telefone: ");
                        scanf("%s", aux_telefone);
                        printf("Endereço: ");
                        scanf("%s", aux_endereco);

                        clientes[i].codigo = aux_codigo;
                        strcpy(clientes[i].nome, aux_nome);
                        strcpy(clientes[i].cpf, aux_cpf);
                        strcpy(clientes[i].telefone, aux_telefone);
                        strcpy(clientes[i].endereco, aux_endereco);
                        return 1;
                    }
                }
                break;

            case 2:
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

                        printf("\n========== Atualizar =========\n");
                        printf("Código: ");
                        scanf("%d", &aux_codigo);
                        printf("Nome: ");
                        scanf("%s", aux_nome);
                        printf("CPF/CPNJ: ");
                        scanf("%s", aux_cpf);
                        printf("Telefone: ");
                        scanf("%s", aux_telefone);
                        printf("Endereço: ");
                        scanf("%s", aux_endereco);

                        clientes[i].codigo = aux_codigo;
                        strcpy(clientes[i].nome, aux_nome);
                        strcpy(clientes[i].cpf, aux_cpf);
                        strcpy(clientes[i].telefone, aux_telefone);
                        strcpy(clientes[i].endereco, aux_endereco);
                        return 1;
                    }
                }
                break;
            
            case 0:
                break;
        
            default:
                printf("\n** Comando inválido digite 1, 2 ou 0 para prosseguir **\n");
                break;
        }
    //} while (opcao != 0);
    return 0;
}

// Função para excluir clientes
int excluir_clientes() {
    int opcao;
    //do {
        printf("\n============ Excluir Cliente ============\n");
        printf("Digite um comando para prosseguir:\n");
        printf("1 – Buscar por código\n");
        printf("2 – Buscar por CPF/CNPJ\n");
        printf("0 – Sair\n");
        printf("\nEscolha: ");
        scanf("%d", &opcao);

        int aux_codigo;
        char aux_cpf[TAM_CPF + 1];
        int confirmacao;

        switch (opcao) {
            case 1:
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

                        printf("\nDeseja realmente excluir?\n");
                        printf("1 - Sim\n");
                        printf("2 - Não\n");
                        printf("Escolha: ");
                        scanf("%d", &confirmacao);
                        if (confirmacao == 1) {
                            for (int j = i; j < contador_clientes; j++) {
                                clientes[j].codigo = clientes[j+1].codigo;
                                strcpy(clientes[j].nome, clientes[j+1].nome);
                                strcpy(clientes[j].cpf, clientes[j+1].cpf);
                                strcpy(clientes[j].telefone, clientes[j+1].telefone);
                                strcpy(clientes[j].endereco, clientes[j+1].endereco);
                            }
                            contador_clientes--;
                            printf("\nExcluído com sucesso!\n");
                            return 1;
                        }
                        return -1;
                    }
                }
                break;

            case 2:
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

                        printf("\nDeseja realmente excluir?\n");
                        printf("1 - Sim\n");
                        printf("2 - Não\n");
                        printf("Escolha: ");
                        scanf("%d", &confirmacao);
                        if (confirmacao == 1) {
                            for (int j = i; j < contador_clientes; j++) {
                                clientes[j].codigo = clientes[j+1].codigo;
                                strcpy(clientes[j].nome, clientes[j+1].nome);
                                strcpy(clientes[j].cpf, clientes[j+1].cpf);
                                strcpy(clientes[j].telefone, clientes[j+1].telefone);
                                strcpy(clientes[j].endereco, clientes[j+1].endereco);
                            }
                            contador_clientes--;
                            printf("\nExcluído com sucesso!\n");
                            return 1;
                        }
                        return -1;
                    }
                }
                break;
            
            case 0:
                break;
        
            default:
                printf("\n** Comando inválido digite 1, 2 ou 0 para prosseguir **\n");
                break;
        }
    //} while (opcao != 0);
    return 0;
}

int cadastrar_conta() {
    int opcao;
    int aux_codigo;
    int aux_agencia;
    int aux_numero;
    char aux_cpf[TAM_CPF + 1];

    printf("\n===== Buscar Cliente =====\n");
    printf("1 - Código\n");
    printf("2 - CPF/CNPJ\n");
    printf("0 - Sair\n");
    printf("\nEscolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
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

                    printf("\n===== Informações da Conta =====\n");
                    printf("Agencia: ");
                    scanf("%d", &aux_agencia);
                    printf("Conta: ");
                    scanf("%d", &aux_numero);
                    for (int k = 0; k < contador_clientes; k++) {
                        for (int j = 0; j < clientes[k].quant_contas; j++) {
                            if (clientes[k].contas[j].agencia == aux_agencia && clientes[k].contas[j].numero) {
                                printf("\n** Conta já cadastrada **\n\n");
                                return 0;
                            }
                        }
                    }

                    clientes[i].contas[clientes[i].quant_contas].agencia = aux_agencia;
                    clientes[i].contas[clientes[i].quant_contas].numero = aux_numero;
                    clientes[i].contas[clientes[i].quant_contas].saldo = 0;
                    clientes[i].contas[clientes[i].quant_contas].quant_transacoes = 0;
                    clientes[i].quant_contas++;
                    return 1;
                }
            }
            break;

        case 2:
            printf("Informe o código: ");
            scanf("%d", &aux_codigo);
            for (int i = 0; i < contador_clientes; i++) {
                // Caso o CPF/CNPJ seja igual
                if (strcmp(aux_cpf, clientes[i].cpf) == 0) {
                    printf("\n========== Cliente =========\n");
                    printf("Código: %d\n", clientes[i].codigo);
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("CPF/CNPJ: %s\n", clientes[i].cpf);
                    printf("Telefone: %s\n", clientes[i].telefone);
                    printf("Endereço: %s\n", clientes[i].endereco);

                    printf("\n===== Informações da Conta =====\n");
                    printf("Agencia: ");
                    scanf("%d", &aux_agencia);
                    printf("Conta: ");
                    scanf("%d", &aux_numero);
                    for (int j = 0; j < clientes[i].quant_contas; j++) {
                        if (clientes[i].contas[j].agencia == aux_agencia && clientes[i].contas[j].numero) {
                            printf("\n** Conta já cadastrada **\n\n");
                            return 0;
                        }
                    }

                    clientes[i].contas[clientes[i].quant_contas].agencia = aux_agencia;
                    clientes[i].contas[clientes[i].quant_contas].numero = aux_numero;
                    clientes[i].contas[clientes[i].quant_contas].saldo = 0;
                    clientes[i].quant_contas++;
                    return 1;
                }
            }
            break;

        case 0:
            break;
        
        default:
            printf("\n** Comando inválido digite 1, 2 ou 0 para prosseguir **\n");
            break;
    }
    printf("Cliente não encontrado\n");
    return 0;
}

void depositar(double valor, int cliente, int conta, int tipo) {
    transacoes[contador_transacoes].tipo = 1;
    transacoes[contador_transacoes].valor = valor;
    transacoes[contador_transacoes].data = time(NULL);
    
    /*struct tm tm = *localtime(&clientes[cliente].contas[conta].transacoes[clientes[cliente].contas[conta].quant_transacoes+1].data);
    printf("Data: %d/%d/%d/\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);*/

    if (tipo == 2) {
        strcpy(transacoes[contador_transacoes].descricao, "Transferência de conta: {agência}-{conta}");
    } else {
        strcpy(transacoes[contador_transacoes].descricao, "DEPOSITO");
    }
    transacoes[contador_transacoes].agencia = clientes[cliente].contas[conta].agencia;
    transacoes[contador_transacoes].numero = clientes[cliente].contas[conta].numero;
    clientes[cliente].contas[conta].saldo += valor;
    clientes[cliente].contas[conta].quant_transacoes++;    
}

void sacar(double valor, int cliente, int conta, int tipo) {
    if (clientes[cliente].contas[conta].saldo - valor > 0) {
        transacoes[contador_transacoes].tipo = 1;
        transacoes[contador_transacoes].valor = valor;
        transacoes[contador_transacoes].data = time(NULL);
        
        /*struct tm tm = *localtime(&clientes[cliente].contas[conta].transacoes[clientes[cliente].contas[conta].quant_transacoes+1].data);
        printf("Data: %d/%d/%d/\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);*/
        
        if (tipo == 2) {
            strcpy(transacoes[contador_transacoes].descricao, "Transferência para conta: {agência}-{conta}");
        // Solicita a descricao
        } else {
            char aux[TAM_MAX_DESCRICAO + 1];
            scanf("%s", aux);
            strcpy(transacoes[contador_transacoes].descricao, aux);
        }

        clientes[cliente].contas[conta].quant_transacoes++;
        clientes[cliente].contas[conta].saldo -= valor;
    } else {
        printf("\n** Saldo insuficiente **\n");
    }
}

int realizar_transacao(int tipo) {
    int agencia, numero;
    double valor;
    printf("\n============= Depositar ===============\n");
    printf("Agencia: ");
    scanf("%d", &agencia);
    printf("Conta: ");
    scanf("%d", &numero);
    
    for(int i = 0; i < contador_clientes; i++) {
        for(int j = 0; j < clientes[i].quant_contas; j++) {
            if (agencia == clientes[i].contas[j].agencia && numero == clientes[i].contas[j].numero) {
                printf("\n========== Cliente =========\n");
                printf("Código: %d\n", clientes[i].codigo);
                printf("Nome: %s\n", clientes[i].nome);
                printf("CPF/CNPJ: %s\n", clientes[i].cpf);
                printf("Telefone: %s\n", clientes[i].telefone);
                printf("Endereço: %s\n", clientes[i].endereco);

                printf("\n========== Conta =========\n");
                printf("Agencia: %d\n", clientes[i].contas[j].agencia);
                printf("Conta: %d\n", clientes[i].contas[j].numero);
                printf("Saldo: %.2lf", clientes[i].contas[j].saldo);
                
                printf("\n========== Trasação =========\n");
                if (tipo == 0) {
                    printf("Valor para o saque: ");
                    scanf("%lf", &valor);
                    sacar(valor, i, j, 0);
                }
                if (tipo == 1) {
                    printf("Valor para o depósito: ");
                    scanf("%lf", &valor);
                    depositar(valor, i , j, 1);
                }
                if (tipo == 2) {
                    int dagencia, dnumero;
                    printf("\n----- Conta de destino -----\n");
                    printf("Agencia: ");
                    scanf("%d", &dagencia);
                    printf("Conta: ");
                    scanf("%d", &dnumero);
                    for(int k = 0; k < contador_clientes; k++) {
                        for(int l = 0; l < clientes[k].quant_contas; l++) {
                            if (agencia == clientes[k].contas[l].agencia && numero == clientes[k].contas[l].numero) {
                                printf("Valor para a transferência: ");
                                scanf("%lf", &valor);
                                sacar(valor, i, j, 2);
                                depositar(valor, k, l, 2);
                                
                                return 1;
                            }
                        }
                    }
                }
                return 1;
            }
        }
    }
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
        printf("\nEscolha: ");
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
                    listar_clientes(0);
                    break;
                }
                printf("\nNenhum cliente cadastrado.\n\n");
                break;
            
            case 'B':
                if (buscar_clientes(0)) {
                    break;
                }
                printf("\nCliente não encontrado.\n\n");
                break;

            case 'A':
                if (atualizar_clientes()) {
                    break;
                }
                printf("\nCliente não encontrado.\n\n");
                break;

            case 'E':
                if (excluir_clientes()) {
                    break;
                } else if (excluir_clientes() == -1) {
                    printf("\nOperação cancelada pelo usuário\n\n");
                    break;
                }
                printf("\nCliente não encontrado.\n\n");
                break;

            case 'S':
                break;
            
            default:
                printf("\n** Comando inválido digite C, L, B, A, E ou S para prosseguir **\n");
                break;
        }
    } while (opcao != 'S');
}

// Menu de gestão de contas
void menu_gerenciar_conta() {
    char opcao;
    do {
        printf("\n============ Gerenciar Contas ============\n");
        printf("Digite um comando para prosseguir:\n");
        printf("R – Listagem de todas as contas cadastradas.\n");
        printf("C – Cadastrar uma conta para um cliente.\n");
        printf("L – Listar todas as contas de um cliente.\n");
        printf("W – Realizar um saque em uma conta.\n");
        printf("D – Realizar um depósito em uma conta.\n");
        printf("T – Realizar transferência entre contas.\n");
        printf("E – Exibir extrato de uma conta.\n");
        printf("S – Sair\n");
        printf("\nEscolha: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case 'R':
                listar_clientes(1);
                break;

            case 'C':
                if (cadastrar_conta()) {
                    printf("\n** Concluído com sucesso! **\n");
                    break;
                }
                break;

            case 'L':
                if (buscar_clientes(1)) {
                    printf("\n** Concluído com sucesso! **\n");
                    break;
                }
                printf("Cliente não encontrado");
                break;
                
            case 'W':
                if (realizar_transacao(0)) {
                    printf("\n** Concluído com sucesso! **\n");
                    break;
                }
                printf("Conta não encontrada");
                break;
                
            case 'D':
                if (realizar_transacao(1)) {
                    printf("\n** Concluído com sucesso! **\n");
                    break;
                }
                printf("Conta não encontrada");
                break;

            case 'T':
                if (realizar_transacao(2)) {
                    printf("\n** Concluído com sucesso! **\n");
                    break;
                }
                printf("Conta não encontrada");
                break;

            case 'S':
                break;

            default:
                printf("\n** Comando inválido digite R, C, L, W, D, T, E ou S para prosseguir **\n");
                break;
        }
    } while (opcao != 'S');
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
                menu_gerenciar_conta();
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
