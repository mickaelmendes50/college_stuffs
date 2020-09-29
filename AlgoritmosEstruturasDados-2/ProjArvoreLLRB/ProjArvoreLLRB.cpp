#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

    // LLRB
    // Inserção
    // Crescente
    tempo_inicial = clock();
    for (int i = 0; i < 10000; i++) {
        insere_ArvLLRB(llrb, i);
    }
    tempo_final = clock();
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Consulta
    // Crescente
    tempo_inicial = clock();
    for (int i = 0; i < 10000; i++) {
        consulta_ArvLLRB(llrb, i);
    }
    tempo_final = clock();
    mostra_TempoContador(tempo_inicial, tempo_final);

    // Remoção
    // Crescente
    tempo_inicial = clock();
    for (int i = 0; i < 10000; i++) {
        remove_ArvLLRB(llrb, i);
    }
    tempo_final = clock();
    mostra_TempoContador(tempo_inicial, tempo_final);

    return 0;
}