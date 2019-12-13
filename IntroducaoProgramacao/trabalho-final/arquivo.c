/*
 * Copyright (C) 2019 Mr Mesquita
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARY_EXTENSION ".dat"
#define DIR_BAR "/"
#define READ_AND_WRITE_BINARY "r+b"
#define READ_BINARY "rb"
#define WRITE_BINARY "wb"

// Struct para armazenar os dados dos alunos
struct documents {
    int mMatricula;
    char mName[30];
    double nExam[6];
    double nExercises[6];
    double nTrabalho;
    double nFinal;
    int mMissing;
    char mStatus[50];
} dataStudant;

// Funçao de calculo das faltas
int isMissing (int mFaltas) {
    if (mFaltas < 0.25*128) {
        return 1;
    } else {
        return 0;
    }
}

// Funcao de calculo das notas
int isApproved (double mNotas) {
    if (mNotas >= 6) {
        return 1;
    } else {
        return 0;
    }
}

// Funcao para escrever os dados do aluno
void writeData () {
    double mMediaExam = 0, mMediaExercises = 0;

    // Receber notas das Provas
    printf("\nNotas das Provas\n");
    for (int i = 0; i < 6; i++) {
        printf("Prova %d: ", i+1);
        scanf("%lf", &dataStudant.nExam[i]);
        mMediaExam += dataStudant.nExam[i];
    }

    // Receber notas das Listas
    printf("\nNotas das Listas\n");
    for (int i = 0; i < 6; i++) {
        printf("Lista %d: ", i+1);
        scanf("%lf", &dataStudant.nExercises[i]);
        mMediaExercises += dataStudant.nExercises[i];
    }

    // Receber nota do trabalho final
    printf("\nNota do Trabalho Final: ");
    scanf("%lf", &dataStudant.nTrabalho);

    // Calcular nota final
    dataStudant.nFinal = (mMediaExam/6)*0.8 + (mMediaExercises/6)*0.1 + dataStudant.nTrabalho*0.1;
    //printf("\n%.2lf\n", dataStudant.nFinal); //Mostrar nota final (desativado por padrão)

    // Receber numero de faltas
    printf("\nNumero de ausencias: ");
    scanf("%d", &dataStudant.mMissing);

    //Calcular a situacao do aluno
    if (isApproved(dataStudant.nFinal) == 1 && isMissing(dataStudant.mMissing) == 1) {
        strcpy(dataStudant.mStatus, "Aprovado");
    } else if (isApproved(dataStudant.nFinal) == 0 && isMissing(dataStudant.mMissing) == 1) {
        strcpy(dataStudant.mStatus, "Reprovado por nota");
    } else if (isApproved(dataStudant.nFinal) == 1 && isMissing(dataStudant.mMissing) == 0) {
        strcpy(dataStudant.mStatus, "Reprovado por ausencia");
    } else {
        strcpy(dataStudant.mStatus, "Reprovado por ausencia e por nota");
    }
    printf("\nSituacao: %s\n", dataStudant.mStatus);
}

// Funcao para ler os dados do arquivo
void readData (int Matricula, char *Arq) {
    FILE * dataBase = fopen(Arq, READ_BINARY);
    while (fread(&dataStudant, sizeof(dataStudant), 1, dataBase)) {
        // Testar o numero de matricula, se for igual, ele le, se não, se repete
        if (Matricula == dataStudant.mMatricula) {
            // Mostrar informações
            printf("\nNome: %s\n", dataStudant.mName);
            printf("\nNotas das Provas\n");
            for (int c = 0; c < 6; c++) {
                printf("Prova %d: %.2f\n", c+1, dataStudant.nExam[c]);
            }
            printf("\nNotas das Listas\n");
            for (int c = 0; c < 6; c++) {
                printf("Lista %d: %.2f\n", c+1, dataStudant.nExercises[c]);
            }
            printf("Trabalho Final: %.2f\n", dataStudant.nTrabalho);
            printf("Nota Final: %.2f\n", dataStudant.nFinal);
            printf("Ausencias: %d\n", dataStudant.mMissing);
            printf("%s\n\n", dataStudant.mStatus);
            break;
        }
    }
    fclose(dataBase);
}

// Funcao para sobrescrever dados
void overrideData(int Matricula, char *Arq) {
    FILE * dataBase = fopen(Arq, READ_AND_WRITE_BINARY);
    while (fread(&dataStudant, sizeof(dataStudant), 1, dataBase)) {
        // Testar o numero de matricula, se for igual, ele le, se não, se repete
        if (Matricula == dataStudant.mMatricula) {
            printf("\nDigite os novos dados do aluno\n");
            writeData();

            // Salvar novos dados do struct no arquivo
            fseek(dataBase, (-1)*sizeof(dataStudant), SEEK_CUR);
            fwrite(&dataStudant, sizeof(dataStudant), 1, dataBase);
            break;
        }
    }
    fclose(dataBase);
}

// Funcao para verificar o tamanho
int checkSize (char *Arq) {
    int contador = 0;
    FILE * dataBase = fopen(Arq, READ_BINARY);
    while(feof(dataBase) == 0) {
        fread(&dataStudant, sizeof(dataStudant), 1, dataBase);
        contador++;
    }
    fclose(dataBase);
    return contador;
}

// Funcao para ordenar os alunos
void orderData (int i, struct documents *auxiliar) {
    // Variaveis auxiliares para ordenação
    int nMatricula, nFaltas;
    char mNome[100], mSituacao[50];
    double nProva[6], nLista[6], nTrabalho, nFinal;

    // Gardar os valores do Struct na posicao i nas variaveis auxiliares
    nMatricula = auxiliar[i].mMatricula;
    strcpy(mNome, auxiliar[i].mName);
    strcpy(mSituacao, auxiliar[i].mStatus);
    nTrabalho = auxiliar[i].nTrabalho;
    nFinal = auxiliar[i].nFinal;
    nFaltas = auxiliar[i].mMissing;
    for(int j = 0; j < 6; j++) {
    nProva[j] = auxiliar[i].nExam[j];
        nLista[j] = auxiliar[i].nExercises[j]; 
    }
    // O Struct na posicao i recebe o valor do proximo struct
    auxiliar[i].mMatricula = auxiliar[i+1].mMatricula;
    strcpy(auxiliar[i].mName, auxiliar[i+1].mName);
    strcpy(auxiliar[i].mStatus, auxiliar[i+1].mStatus);
    auxiliar[i].nTrabalho = auxiliar[i+1].nTrabalho;
    auxiliar[i].nFinal = auxiliar[i+1].nFinal;
    auxiliar[i].mMissing = auxiliar[i+1].mMissing;
    for(int j = 0; j < 6; j++) {
        auxiliar[i].nExam[j] = auxiliar[i+1].nExam[j];
        auxiliar[i].nExercises[j] = auxiliar[i+1].nExercises[j]; 
    }
    //  Struct da posicao i+1 recebe os valores guardados nas variáveis auxiliares
    auxiliar[i+1].mMatricula = nMatricula;
    strcpy(auxiliar[i+1].mName, mNome);
    strcpy(auxiliar[i+1].mStatus, mSituacao);
    auxiliar[i+1].nTrabalho = nTrabalho;
    auxiliar[i+1].nFinal = nFinal;
    auxiliar[i+1].mMissing =  nFaltas;
    for(int j = 0; j < 6; j++) {
        auxiliar[i+1].nExam[j] = nProva[j];
        auxiliar[i+1].nExercises[j] = nLista[j]; 
    }
}

// Funcao para mostrar a listagem ordenada dos alunos
void showOrderedData (struct documents *auxiliar, int cont) {
    for(int i = 0; i < cont; i++) {
        printf("Matricula: %d\n", auxiliar[i].mMatricula);
        printf("Nome: %s\n", auxiliar[i].mName);
        for(int j = 0; j < 6; j++) {
            printf("Nota da prova %d: %lf\n",i+1, auxiliar[i].nExam[j]);       
        }
        for(int j = 0; j < 6; j++){
            printf("Nota da lista %d: %lf\n",i+1, auxiliar[i].nExercises[j]);
        }
        printf("Nota do trabalho: %lf\n", auxiliar[i].nTrabalho);
        printf("Nota final: %lf\n", auxiliar[i].nFinal);
        printf("Numero de ausencias: %d\n", auxiliar[i].mMissing);
        printf("Situacao: %s\n\n", auxiliar[i].mStatus);
    }
}

// Modulo para iniciar o cadastro de uma nova turma
void cadastrarTurma () {
    char mDatabase[15], mDirectory[30];
    printf("\nInsira o nome do arquivo: ");
    scanf("%s", mDatabase);
    printf("Insira o diretorio: ");
    scanf("%s", mDirectory);

    // Use DOCUMENT_DIR para o diretorio do arquivo que contera os dados informados dos alunos
    const char *DOCUMENT_DIR = strcat(strcat(mDirectory, DIR_BAR), strcat(mDatabase, BINARY_EXTENSION));
    FILE *dataBase = fopen(DOCUMENT_DIR, WRITE_BINARY);

    // Cadastrar alunos
    for (int cont = 0; cont >= 0; cont++) {
        printf("\nMatricula: ");
        scanf("%d", &dataStudant.mMatricula);
        // Se Matricula == 0 entenda como encerrado
        if (dataStudant.mMatricula == 0) {
            break;
        }
        printf("Nome: ");
        scanf("%s", &dataStudant.mName);

        // Chamar função que escreve os dados dos alunos no arquivo
        writeData();

        // Salvar dados do struct no arquivo
        fwrite(&dataStudant, sizeof(dataStudant), 1, dataBase);
    }
    fclose(dataBase);
}

// Modulo para consulta
void consultarAluno () {
    char mDatabase[15], mDirectory[30];
    int nMatricula, k = 0;
    FILE * dataBase;
    do {
        printf("\nInsira o nome do arquivo: ");
        scanf("%s", mDatabase);
        // Se o nome do arquivo for "fim" ele sai do laço
        if (strcmp(mDatabase, "fim") == 0) {
            break;
        }
        printf("Insira o diretorio: ");
        scanf("%s", mDirectory);

        // Use DOCUMENT_DIR para o diretorio do arquivo que contera os dados informados dos alunos
        const char *DOCUMENT_DIR = strcat(strcat(mDirectory, DIR_BAR), strcat(mDatabase, BINARY_EXTENSION));

        dataBase = fopen(DOCUMENT_DIR, READ_BINARY);
        // Testar se o documento foi aberto com sucesso
        if(!(dataBase == NULL)) {
            k = 1;
            do {
                printf("Informe o numero de matricula: ");
                scanf("%d", &nMatricula);
                // Se o numero de matricula for 0, sai do laço
                if (nMatricula == 0) {
                    break;
                }
                // Chamar funcao que le os dados do arquivo
                readData(nMatricula, DOCUMENT_DIR);
            } while (nMatricula != 0);
        }
        fclose(dataBase);
    } while (k == 0);
}

// Modulo para alteracao de dados
void alterarDados () {
    char mDatabase[15], mDirectory[30];
    int nMatricula, k = 0;
    FILE * dataBase;
    do {
        printf("\nInsira o nome do arquivo: ");
        scanf("%s", mDatabase);
        // Se o nome do arquivo for "fim" ele sai do laço
        if (strcmp(mDatabase, "fim") == 0) {
            break;
        }
        printf("Insira o diretorio: ");
        scanf("%s", mDirectory);

        // Use DOCUMENT_DIR para o diretorio do arquivo que contera os dados informados dos alunos
        const char *DOCUMENT_DIR = strcat(strcat(mDirectory, DIR_BAR), strcat(mDatabase, BINARY_EXTENSION));

        dataBase = fopen(DOCUMENT_DIR, READ_BINARY);
        // Testar se o documento foi aberto com sucesso
        if(!(dataBase == NULL)) {
            k = 1;
            do {
                printf("Informe o numero de matricula: ");
                scanf("%d", &nMatricula);
                // Se o numero de matricula for 0, sai do laço
                if (nMatricula == 0) {
                    break;
                }
                // Chamar funcao que le os dados dos arquivos e logo em seguida, a funcao que altera esses dados
                readData(nMatricula, DOCUMENT_DIR);
                overrideData(nMatricula, DOCUMENT_DIR);
            } while (nMatricula != 0);
        }
        fclose(dataBase);
    } while (k == 0);
}

// Modulo para ordenar os dados
void listarDados () {
    char mDatabase[15], mDirectory[30];
    int nOption, k = 0, mTamanho = 0;
    FILE * dataBase;
    do {
        printf("\nInsira o nome do arquivo: ");
        scanf("%s", mDatabase);
        // Se o nome do arquivo for "fim" ele sai do laço
        if (strcmp(mDatabase, "fim") == 0) {
            break;
        }
        printf("Insira o diretorio: ");
        scanf("%s", mDirectory);

        // Use DOCUMENT_DIR para o diretorio do arquivo que contera os dados informados dos alunos
        const char *DOCUMENT_DIR = strcat(strcat(mDirectory, DIR_BAR), strcat(mDatabase, BINARY_EXTENSION));

        dataBase = fopen(DOCUMENT_DIR, READ_BINARY);
        // Testar se o documento foi aberto com sucesso
        if(!(dataBase == NULL)) {
            k = 1;
            // Verificar o tamanho do arquivo
            mTamanho = checkSize(DOCUMENT_DIR);

            // Salvar os dados do arquivo em um struct auxiliar
            struct documents auxiliar[mTamanho];
            int cont = 0;
            while(feof(dataBase) == 0) {
                fread(&dataStudant, sizeof(dataStudant), 1, dataBase);
                if(cont != mTamanho-1) {
                    auxiliar[cont].mMatricula= dataStudant.mMatricula;
                    strcpy(auxiliar[cont].mName, dataStudant.mName);
                    strcpy(auxiliar[cont].mStatus, dataStudant.mStatus);
                    auxiliar[cont].nTrabalho = dataStudant.nTrabalho;
                    auxiliar[cont].nFinal = dataStudant.nFinal;
                    auxiliar[cont].mMissing = dataStudant.mMissing;
                    for(int i = 0; i < 6; i++) {
                        auxiliar[cont].nExam[i] = dataStudant.nExam[i];
                        auxiliar[cont].nExercises[i] = dataStudant.nExercises[i]; 
                    }
                    cont++;
                }
            }

            // Estutura principal do modulo
            do {
                puts("1 - Listar alunos por ordem crescente de matricula");
                puts("2 - Listar alunos por ordem alfabetica");
                puts("3 - Listar alunos por ordem crescente de nota final");
                puts("4 - Terminar e voltar para processar nova turma");
                puts("5 - Terminar execucao do modulo");
                scanf("%d", &nOption);

                // Se nOption for 4, ele sai do laco e pede o para digitar os arquivos novamente
                if (nOption == 4) {
                    break;
                // Se nOption for 5, ele sai do laco e volta ao menu principal
                } else if (nOption == 5) {
                    break;
                } else if (nOption == 1) {
                    for (int i = 0; i < cont-1; i++) {
                        // Se o numero de matricula da posicao i for maior que a do i+1, o programa chama a função
                        // que vai inverter as posições de todas as informações no struct, deixando em ordem crescente
                        if(auxiliar[i].mMatricula > auxiliar[i+1].mMatricula) {
                            orderData(i, auxiliar);
                            i = -1;
                        }
                    }
                    showOrderedData(auxiliar, cont);
                } else if (nOption == 2) {
                    for (int i = 0; i < cont-1; i++) {
                        // Se o valor retornado pela comparação dos nomes for maior que 0, o programa chama a função
                        // que vai inverter as posições de todas as informações no struct, deixando em ordem alfabetica
                        if(strcmp(auxiliar[i].mName, auxiliar[i+1].mName) > 0) {
                            orderData(i, auxiliar);
                            i = -1;
                        }
                    }
                    showOrderedData(auxiliar, cont);
                } else if (nOption == 3) {
                    for (int i = 0; i < cont-1; i++) {
                        // Se a nota final da posicao i for maior que a do i+1, o programa chama a função
                        // que vai inverter as posições de todas as informações no struct, deixando em ordem crescente
                        if(auxiliar[i].nFinal < auxiliar[i+1].nFinal){
                            orderData(i, auxiliar);
                            i = -1;
                        }
                    }
                    showOrderedData(auxiliar, cont);
                }
            } while (nOption != 4 || nOption != 5);
        }
        fclose(dataBase);
    } while (k == 0 || nOption == 4);
}

int main () {
    int mChoose;
    do {
        puts("1 - Cadastrar uma turma");
        puts("2 - Consultar um aluno");
        puts("3 - Alterar dados de um aluno");
        puts("4 - Listar dados de uma turma");
        puts("5 - Terminar a execucao");
        scanf("%d", &mChoose);
        switch (mChoose) {
        case 1:
            cadastrarTurma();
            break;
        case 2:
            consultarAluno();
            break;
        case 3:
            alterarDados();
            break;
        case 4:
            listarDados();
            break;
        case 5:
            break;
        default:
            printf("\n--Opcao invalida--\n");
        }
    } while (mChoose != 5);
    return 0;
}
