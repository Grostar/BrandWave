#include <iostream>
#include <array>
using namespace std;

const int N = 10;

void leer_numeros(array<int,N>& arreglo){
    cout << "Introduzca 10 numeros enteros: ";
    for(int i = 0; i < N; i++){
        cin >> arreglo[i];
    }
}

void mostrar_numeros(const array<int,N>& arreglo){
    for(int i = 0; i < N; i++){
        cout << arreglo[i];
        if(i + 1 < N){
            cout << " ";
        }
    }
    cout << endl;
}

void invertir_iterativo(array<int,N>& arreglo){
    int inicio = 0;
    int fin = N - 1;
    
    while(inicio < fin){
        int temporal = arreglo[inicio];
        arreglo[inicio] = arreglo[fin];
        arreglo[fin] = temporal;
        inicio++;
        fin--;
    }
}

void invertir_recursivo(array<int,N>& arreglo, int izquierda, int derecha){
    if(izquierda >= derecha){
        return;
    }
    
    int temporal = arreglo[izquierda];
    arreglo[izquierda] = arreglo[derecha];
    arreglo[derecha] = temporal;
    
    invertir_recursivo(arreglo, izquierda + 1, derecha - 1);
}

int main(){
    array<int,N> arreglo;
    
    leer_numeros(arreglo);
    
    cout << "Esos numeros en orden original son: ";
    mostrar_numeros(arreglo);
    
    invertir_iterativo(arreglo);
    cout << "Esos numeros en orden inverso son: ";
    mostrar_numeros(arreglo);
    
    invertir_recursivo(arreglo, 0, N - 1);
    cout << "Esos numeros en orden original son: ";
    mostrar_numeros(arreglo);
    
    return 0;
}
