#include <iostream>
#include <array>
#include <cmath>
using namespace std;

const int MAXIMO = 100;

void leer_valor(int& K){
    cout << "Introduzca el valor de K (<= 100): ";
    cin >> K;
}

void eratostenes(int K){
    array<bool,MAXIMO+1> es_primo;
    
    for(int i = 0; i <= MAXIMO; i++){
        es_primo[i] = true;
    }
    
    if(K > 0){
        es_primo[0] = false;
    }
    if(K > 1){
        es_primo[1] = false;
    }
    
    int limite = static_cast<int>(sqrt(K));
    for(int i = 2; i <= limite; i++){
        if(es_primo[i]){
            for(int multiplo = i * i; multiplo < K; multiplo += i){
                es_primo[multiplo] = false;
            }
        }
    }
    
    for(int numero = 2; numero < K; numero++){
        if(es_primo[numero]){
            cout << numero << " ";
        }
    }
    cout << endl;
}

int main(){
    int K;
    leer_valor(K);
    eratostenes(K);
    return 0;
}
