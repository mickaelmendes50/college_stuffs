#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "ArvoreLLRB.h"

using namespace std;

void mostra_TempoContador(clock_t tempo_inicial, clock_t tempo_final) {
    unsigned long int tempo;
    tempo = ((tempo_final - tempo_inicial) * 1000/CLOCKS_PER_SEC);
    cout << "Tempo: " << tempo << endl;
    cout << "Iterações: " << getCont() << endl;
}

int main() {
    ArvLLRB * llrb = cria_ArvLLRB();
    clock_t tempo_inicial, tempo_final;
    vector<int> vector;

    // LLRB 500000
    cout << "/ Inserção" << endl;
    // Crescente
    resetCont();
    tempo_inicial = clock();
    for (int i = 0; i < 500000; i++) {
        insere_ArvLLRB(llrb, i);
    }
    tempo_final = clock();
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Decrescente
    resetCont();
    tempo_inicial = clock();
    for (int i = 500000; i > 0; i--) {
        insere_ArvLLRB(llrb, i);
    }
    tempo_final = clock();
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Aleatório
    resetCont();
    tempo_inicial = clock();
    vector.clear();
    for (int i = 0; i < 500000; i++) {
        int random;
        random = rand()%500000;
        vector.push_back(random);
        insere_ArvLLRB(llrb, vector[i]);
    }
    tempo_final = clock();
    cout << "Aleatorio" << endl;
    mostra_TempoContador(tempo_inicial, tempo_final);

    cout << "/ Consulta" << endl;
    // Crescente
    resetCont();
    tempo_inicial = clock();
    for (int i = 0; i < 500000; i++) {
        consulta_ArvLLRB(llrb, i);
    }
    tempo_final = clock();
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Decrescente
    resetCont();
    tempo_inicial = clock();
    for (int i = 500000; i > 0; i--) {
        consulta_ArvLLRB(llrb, i);
    }
    tempo_final = clock();
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Aleatório
    resetCont();
    tempo_inicial = clock();
    for (int i = 0; i < 500000; i++) {
        insere_ArvLLRB(llrb, vector[i]);
    }
    tempo_final = clock();
    cout << "Aleatorio" << endl;
    mostra_TempoContador(tempo_inicial, tempo_final);

    cout << "/ Remoção" << endl;
    // Crescente
    resetCont();
    tempo_inicial = clock();
    for (int i = 0; i < 500000; i++) {
        remove_ArvLLRB(llrb, i);
    }
    tempo_final = clock();
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Decrescente
    resetCont();
    tempo_inicial = clock();
    for (int i = 500000; i > 0; i--) {
        remove_ArvLLRB(llrb, i);
    }
    tempo_final = clock();
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Aleatório
    resetCont();
    tempo_inicial = clock();
    for (int i = 0; i < 500000; i++) {
        remove_ArvLLRB(llrb, vector[i]);
    }
    tempo_final = clock();
    cout << "Aleatorio" << endl;
    mostra_TempoContador(tempo_inicial, tempo_final);

    return 0;
}