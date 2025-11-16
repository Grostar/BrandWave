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

void mostrar_frecuencias(const array<int,10>& frecuencias){
    cout << "La frecuencia de cada digito es:" << endl;
    for(int digito = 0; digito < 10; digito++){
        cout << digito << ": " << frecuencias[digito] << endl;
    }
}

int main(){
    array<int,10> frecuencias = {};
    
    leer_y_contar(frecuencias);
    mostrar_frecuencias(frecuencias);
    
    return 0;
}
