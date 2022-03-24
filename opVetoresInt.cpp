#include "opVetoresInt.h"
#include <iostream>

using namespace std;

void inserirDados(int v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << "Insira um numero inteiro:";
        cin >> v[i];
    }

}

void escreverDados(int v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << " | ";
    }

}

float somarElementos(int v[], int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma = soma + v[i]; //soma += v[i];
    }
    return soma;
}
float media(int v[], int tamanho) {
    return somarElementos(v, tamanho) / tamanho;
}

int posicaoValorMax(int v[], int tamanho) {
    int posMax = 0;
    for (int i = 1; i < tamanho; i++) {
        if (v[i] > v[posMax])
            posMax = i;
    }
    return posMax;
}

int posicaoValorMin(int v[], int tamanho) {
    int posMin = 0;
    for (int i = 1; i < tamanho; i++) {
        if (v[i] < v[posMin])
            posMin = i;
    }
    return posMin;
}

void troca(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void inverterVetor(int v[], int tamanho) {
    for (int i = 0; i < tamanho / 2; i++) {
        troca(v[i], v[tamanho - 1 - i]);
    }
}

void opcoes(int v[], int tamanho) {
    bool sair = false;
    char opcao;
    do
    {
        cout << "\nEscolha uma opcao:\n";
        cout << "1 - Inserir dados" << endl;
        cout << "2 - Visualizar dados" << endl;
        cout << "3 - Somar" << endl;
        cout << "4 - Calcular media" << endl;
        cout << "5 - Posicao Valor Maximo" << endl;
        cout << "6 - Posicao Valor Minimo" << endl;
        cout << "7 - Inverter" << endl;
        cout << "8 - Soma de Vetores"<< endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;
        cout << endl;
        switch (opcao) {
            case '1':
                //cout << "Escolheu a opcao Inserir dados" << endl;
                inserirDados(v, tamanho);
                break;
            case '2':
                //cout << "Escolheu a opcao Visualizar dados" << endl;
                escreverDados(v, tamanho);
                break;
            case '3':
                //cout << "Escolheu a opcao Somar" << endl;
                cout << "Soma: " << somarElementos(v, tamanho);
                break;
            case '4':
                cout << "Media " << media(v, tamanho) << endl;
                break;
            case '5':
                cout << "Posicao Valor Maximo " << posicaoValorMax(v, tamanho) << endl;
                break;
            case '6':
                cout << "Posicao Valor Minimo " << posicaoValorMin(v, tamanho) << endl;
                break;
            case '7':
                cout << "Escolheu a opcao Inverter" << endl;
                inverterVetor(v, tamanho);
                escreverDados(v, tamanho);
                break;
            case '8':
                somaVetores();
                break;
            case '0':
                cout << "Escolheu a opcao Sair. Adeus!" << endl;
                sair = true;
                break;
            default:
                cout << "Escolha uma opcao valida." << endl;
        }
    } while (!sair);

}

int * somaVetores(){
    int tam=0;
    cout << "Introduza o tamanho do array:";
    cin>>tam;
    if(tam<20){
        int * a = new int[tam];
        int * b = new int[tam];
        int * c = new int[tam];

        cout << "introduza os valores para o array a:";
        inserirDados(a,tam);
        cout << "introduza os valores para o array b:";
        inserirDados(b,tam);

        for(int i = 0; i < tam ; i++)
            c[i]=a[i]+b[i];

        delete[] a;
        delete[] b;
        escreverDados(c,tam);
        return c;
    }else{
        return new int[0]; // hack aldrabado
    }
}



