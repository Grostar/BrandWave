#include <iostream>
#include <array>
using namespace std;

const int TAMANO = 10;

void leer_numeros(array<int,TAMANO>& numeros){
    cout << "Introduzca 10 numeros: ";
    for(int i = 0; i < TAMANO; i++){
        cin >> numeros[i];
    }
}

int encontrar_maximo(const array<int,TAMANO>& numeros, const array<bool,TAMANO>& procesados){
    int max_valor = -999999;
    bool encontrado = false;
    
    for(int i = 0; i < TAMANO; i++){
        if(!procesados[i]){
            if(!encontrado || numeros[i] > max_valor){
                max_valor = numeros[i];
                encontrado = true;
            }
        }
    }
    return max_valor;
}

void procesar_y_mostrar(const array<int,TAMANO>& numeros){
    array<bool,TAMANO> procesados = {};
    
    while(true){
        bool hay_pendientes = false;
        for(int i = 0; i < TAMANO; i++){
            if(!procesados[i]){
                hay_pendientes = true;
                break;
            }
        }
        
        if(!hay_pendientes){
            break;
        }
        
        int valor_max = encontrar_maximo(numeros, procesados);
        int contador = 0;
        array<int,TAMANO> posiciones;
        
        for(int i = 0; i < TAMANO; i++){
            if(!procesados[i] && numeros[i] == valor_max){
                procesados[i] = true;
                posiciones[contador] = i + 1;
                contador++;
            }
        }
        
        cout << valor_max << " aparece ";
        if(contador == 1){
            cout << "1 vez, en posicion";
        } else {
            cout << contador << " veces, en posiciones";
        }
        
        for(int i = 0; i < contador; i++){
            cout << " " << posiciones[i];
        }
        cout << endl;
    }
}

int main(){
    array<int,TAMANO> numeros;
    leer_numeros(numeros);
    procesar_y_mostrar(numeros);
    return 0;
}
