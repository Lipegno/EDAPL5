//
// Created by Filipe Quintal on 24/03/2022.
//

#include "opVetoresInt.h"
#include "opVetoresFloat.h"
#include <iostream>

using namespace std;

void inserirDados(float v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << "Insira um numero real:";
        cin >> v[i];
    }

}

void escreverDados(float v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << v[i] << " | ";
    }

}

float somarElementos(float v[], int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma = soma + v[i]; //soma += v[i];
    }
    return soma;
}
float media(float v[], int tamanho) {
    return somarElementos(v, tamanho) / tamanho;
}

int posicaoValorMax(float v[], int tamanho) {
    int posMax = 0;
    for (int i = 1; i < tamanho; i++) {
        if (v[i] > v[posMax])
            posMax = i;
    }
    return posMax;
}

int posicaoValorMin(float v[], int tamanho) {
    int posMin = 0;
    for (int i = 1; i < tamanho; i++) {
        if (v[i] < v[posMin])
            posMin = i;
    }
    return posMin;
}

void troca(float& a, float& b) {
    float temp = a;
    a = b;
    b = temp;
}

void inverterVetor(float v[], int tamanho) {
    for (int i = 0; i < tamanho / 2; i++) {
        troca(v[i], v[tamanho - 1 - i]);
    }
}

void opcoes(float v[], int tamanho) {
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
        cout << "8 - Calcular notas de turma"<< endl;
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
                resultado(v,tamanho);
            case '0':
                cout << "Escolheu a opcao Sair. Adeus!" << endl;
                sair = true;
                break;
            default:
                cout << "Escolha uma opcao valida." << endl;
        }
    } while (!sair);

}

int acimaDaMedia(float notas[], int tamanho, float media){
    int alunos_acima_media = 0;
    for(int i=0;i<tamanho;i++){
        if(notas[i]>media)
            alunos_acima_media++;
    }
    return alunos_acima_media;
}

void resultado(float notas[], int tamanho){
    int exc=0;
    int mb=0;
    int b=0;
    int s=0;
    int rep =0;
    for(int i=0;i<tamanho;i++){
        if(notas[i]>=18){
            exc++;
        }else if(notas[i]>=15){
            mb++;
        }else if(notas[i]>=12){
            b++;
        }else if(notas[i]>=10){
            s++;
        }else {
            rep++;
        }
    }
    cout << "Houve "<<exc<<" alunos que tiveram nota superior ou igual a 18,";
    cout << mb <<" com nota entre 15 e 18, ";
    cout << b <<" com nota entre 12 e 15, ";
    cout << s << "com nota entre 10 e 12 e ";
    cout << rep<<" que reprovaram" << endl;
    float m = media(notas,tamanho);
    //cout << setprecision(4)<<"Media: " << m;
    cout << endl << "Numero de notas acima da média: "<< acimaDaMedia(notas,tamanho,m);

}
