//
// Created by Filipe Quintal on 24/03/2022.
//

/*
* main inicial para Lab 4
*/

#include <iostream>
#include "opVetoresInt.h"
#include "constantes.h"
#include "opVetoresFloat.h"

using namespace std;

int main() {
    int tipoDados = -1;
    cout << "Inteiros (1) ou Reais (2)?" << endl;
    cin >> tipoDados;
    int tamanho;
    if (tipoDados == 1) {
        cout << "Quantos elementos quer inserir no vector? \n";
        cin >> tamanho;
        int * v = new int[tamanho];

        if (tamanho > 0) {
            opcoes(v, tamanho);
            delete[] v;
        }else
            cout << "Inseriu numero de elementos invalido. " << endl;
    }
    else if (tipoDados == 2) {
        cout << "Quantos elementos quer inserir no vector? \n";
        cin >> tamanho;
        float * v =  new float[tamanho];

        if (tamanho > 0) {
            opcoes(v, tamanho);
            delete[] v;
        }else
            cout << "Inseriu numero de elementos invalido. " << endl;
    }
    else
        cout << "Inseriu tipo de dados invalido. " << endl;

    cout << "Prima ENTER para terminar." << endl;
    cin.ignore();
    cin.get();
    return 0;

}