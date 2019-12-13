/*
 * Copyright (C) 2019 The Universidade Federal de Goiás
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

#include <iostream>
using namespace std;

main () {
    int n1, n2, qtdAlunos;
    float media, global;
    cout << "Informe a quantidade de alunos\n";
    cin >> qtdAlunos;

    for (int i = 0; i < qtdAlunos; i++) {
        cout << "\nInforme as notas \n";
        cin >> n1 >> n2;
        media = (n1+n2)/2;
        cout << "media: " << media;

        if (media >= 6) {
            cout << "\nAprovado \n\n";
        } else {
            cout << "\nReprovado \n\n";
        }

        global += media;
    }

    global = global/qtdAlunos;
    cout << "media global: " << global;
}

