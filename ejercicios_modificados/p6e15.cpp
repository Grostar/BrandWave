#include <iostream>
#include <array>
using namespace std;

const int MAX = 20;

struct Lista{
    array<int,MAX> elementos;
    int tamano;
};

void anyadir_ord(Lista& lista, int valor){
    if(lista.tamano == MAX){
        return;
    }
    
    int posicion = lista.tamano - 1;
    
    while(posicion >= 0 && lista.elementos[posicion] > valor){
        lista.elementos[posicion + 1] = lista.elementos[posicion];
        posicion--;
    }
    
    lista.elementos[posicion + 1] = valor;
    lista.tamano++;
}

void eliminar_ord(Lista& lista, int valor){
    for(int i = 0; i < lista.tamano; i++){
        if(lista.elementos[i] == valor){
            for(int j = i; j < lista.tamano - 1; j++){
                lista.elementos[j] = lista.elementos[j + 1];
            }
            lista.tamano--;
            return;
        }
    }
}

void leer_lista(Lista& lista){
    lista.tamano = 0;
    
    cout << "Introduzca una secuencia de numeros terminada en cero:" << endl;
    
    int numero;
    while(cin >> numero && numero != 0){
        anyadir_ord(lista, numero);
        
        if(lista.tamano == MAX){
            while(cin >> numero && numero != 0){
            }
            break;
        }
    }
}

void mostrar_lista(const Lista& lista){
    cout << "Lista: [ ";
    for(int i = 0; i < lista.tamano; i++){
        cout << lista.elementos[i] << " ";
    }
    cout << "]" << endl;
}

int main(){
    Lista lista;
    leer_lista(lista);
    
    int numero_eliminar;
    cout << "Introduzca un numero a eliminar: ";
    cin >> numero_eliminar;
    
    mostrar_lista(lista);
    cout << "Eliminar: " << numero_eliminar << endl;
    
    eliminar_ord(lista, numero_eliminar);
    
    cout << "Resultado: [ ";
    for(int i = 0; i < lista.tamano; i++){
        cout << lista.elementos[i] << " ";
    }
    cout << "]" << endl;
    
    return 0;
}
