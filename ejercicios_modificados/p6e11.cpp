#include <iostream>
#include <array>
using namespace std;

const int NELMS = 10;

void leer_array(array<int,NELMS>& arreglo){
    cout << "Introduzca 10 numeros enteros: ";
    for(int i = 0; i < NELMS; i++){
        cin >> arreglo[i];
    }
}

int buscar_numero(const array<int,NELMS>& arreglo, int numero_buscado){
    for(int i = 0; i < NELMS; i++){
        if(arreglo[i] == numero_buscado){
            return i;
        }
    }
    return -1;
}

int main(){
    int numero_buscado;
    cout << "Introduzca el numero a buscar: ";
    cin >> numero_buscado;
    
    array<int,NELMS> arreglo;
    leer_array(arreglo);
    
    int posicion = buscar_numero(arreglo, numero_buscado);
    
    if(posicion == -1){
        cout << "El numero " << numero_buscado << " NO esta en la coleccion" << endl;
    } else {
        cout << "El numero " << numero_buscado << " SI esta en la coleccion, en la posicion " << posicion << endl;
    }
    
    return 0;
}
