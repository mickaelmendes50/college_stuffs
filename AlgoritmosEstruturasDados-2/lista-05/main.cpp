#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "FilaPrioridade.h"

using namespace std;

void mostra_Tempo(clock_t tempo_inicial, clock_t tempo_final) {
    unsigned long int tempo;
    tempo = ((tempo_final - tempo_inicial) * 1000/CLOCKS_PER_SEC);
    cout << "Tempo: " << tempo << endl;
}

int main() {


    return 0;
}