#include <iostream>
#include <array>
using namespace std;

const int N = 5;

void leer_vector(array<int,N>& V){
    cout << "Introduzca 5 numeros enteros:" << endl;
    for(int i = 0; i < N; i++){
        cin >> V[i];
    }
}

int calcular_suma_izquierda(const array<int,N>& V, int centro){
    int suma = 0;
    for(int i = 0; i <= centro - 1; i++){
        suma += (centro - i) * V[i];
    }
    return suma;
}

int calcular_suma_derecha(const array<int,N>& V, int centro){
    int suma = 0;
    for(int j = centro + 1; j <= N - 1; j++){
        suma += (j - centro) * V[j];
    }
    return suma;
}

void centroVector(const array<int,N>& V, bool& existe, int& indice){
    existe = false;
    
    for(int c = 1; c <= N - 2; c++){
        int suma_izq = calcular_suma_izquierda(V, c);
        int suma_der = calcular_suma_derecha(V, c);
        
        if(suma_izq == suma_der){
            existe = true;
            indice = c;
            return;
        }
    }
}

int main(){
    array<int,N> V;
    leer_vector(V);
    
    bool existe;
    int indice;
    
    centroVector(V, existe, indice);
    
    if(existe){
        cout << "El centro de este vector es el indice " << indice << endl;
    } else {
        cout << "Este vector no tiene centro" << endl;
    }
    
    return 0;
}
