#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "ArvoreAVL.h"

using namespace std;

void mostra_TempoContador(clock_t tempo_inicial, clock_t tempo_final) {
    unsigned long int tempo;
    tempo = ((tempo_final - tempo_inicial) * 1000/CLOCKS_PER_SEC);
    cout << "Tempo: " << tempo << endl;
    cout << "Iterações: " << getCont() << endl;
}

int main() {
    ArvAVL * avl = cria_ArvAVL();
    clock_t tempo_inicial, tempo_final;
    vector<int> vector;

    // avl 10000
    // Inserção
    // Crescente
    tempo_inicial = clock();
    for (int i = 0; i < 10000; i++) {
        insere_ArvAVL(avl, i);
    }
    tempo_final = clock();
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Decrescente
    tempo_inicial = clock();
    for (int i = 10000; i > 0; i--) {
        insere_ArvAVL(avl, i);
    }
    tempo_final = clock();
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Aleatório
    tempo_inicial = clock();
    vector.clear();
    for (int i = 0; i < 10000; i++) {
        int random;
        random = rand()%10000;
        vector.push_back(random);
        insere_ArvAVL(avl, vector[i]);
    }
    tempo_final = clock();
    cout << "Aleatorio" << endl;
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Consulta
    // Crescente
    tempo_inicial = clock();
    for (int i = 0; i < 10000; i++) {
        consulta_ArvAVL(avl, i);
    }
    tempo_final = clock();
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Decrescente
    tempo_inicial = clock();
    for (int i = 10000; i > 0; i--) {
        consulta_ArvAVL(avl, i);
    }
    tempo_final = clock();
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Aleatório
    tempo_inicial = clock();
    for (int i = 0; i < 10000; i++) {
        insere_ArvAVL(avl, vector[i]);
    }
    tempo_final = clock();
    cout << "Aleatorio" << endl;
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Remoção
    // Crescente
    tempo_inicial = clock();
    for (int i = 0; i < 10000; i++) {
        remove_ArvAVL(avl, i);
    }
    tempo_final = clock();
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Decrescente
    tempo_inicial = clock();
    for (int i = 10000; i > 0; i--) {
        remove_ArvAVL(avl, i);
    }
    tempo_final = clock();
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Aleatório
    tempo_inicial = clock();
    for (int i = 0; i < 10000; i++) {
        remove_ArvAVL(avl, vector[i]);
    }
    tempo_final = clock();
    cout << "Aleatorio" << endl;
    mostra_TempoContador(tempo_inicial, tempo_final);

    return 0;
}