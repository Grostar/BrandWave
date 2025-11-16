#include <iostream>
#include <array>
using namespace std;

void leer_y_contar(array<int,10>& frecuencias){
    cout << "Introduzca una secuencia de numeros (hasta negativo): ";
    int numero;
    
    while(cin >> numero){
        if(numero < 0){
            break;
        }
        if(numero >= 0 && numero <= 9){
            frecuencias[numero]++;
        }
    }
}

int calcular_maximo(const array<int,10>& frecuencias){
    int max_valor = frecuencias[0];
    for(int i = 1; i < 10; i++){
        if(frecuencias[i] > max_valor){
            max_valor = frecuencias[i];
        }
    }
    return max_valor;
}

void dibujar_histograma(const array<int,10>& frecuencias){
    int altura_maxima = calcular_maximo(frecuencias);
    
    cout << "-------------------" << endl;
    
    for(int nivel = altura_maxima; nivel >= 1; nivel--){
        for(int digito = 0; digito < 10; digito++){
            if(frecuencias[digito] >= nivel){
                cout << "*";
            } else {
                cout << " ";
            }
            if(digito < 9){
                cout << " ";
            }
        }
        cout << endl;
    }
    
    cout << "-------------------" << endl;
    
    for(int digito = 0; digito < 10; digito++){
        cout << digito;
        if(digito < 9){
            cout << " ";
        }
    }
    cout << endl;
}

int main(){
    array<int,10> frecuencias = {};
    
    leer_y_contar(frecuencias);
    dibujar_histograma(frecuencias);
    
    return 0;
}
