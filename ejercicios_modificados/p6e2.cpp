#include <iostream>
#include <array>
using namespace std;

using Vector = array<int,5>;

void leer_datos(Vector& v){
    cout << "Introduzca 5 numeros: ";
    for(unsigned int i = 0; i < v.size(); i++){
        cin >> v[i];
    }
}

int buscar_pos_menor_impar(const Vector& v){
    int posicion_menor = -1;
    int valor_menor;
    
    for(unsigned int i = 0; i < v.size(); i++){
        if(v[i] % 2 != 0){
            if(posicion_menor == -1){
                posicion_menor = i;
                valor_menor = v[i];
            } else if(v[i] < valor_menor){
                posicion_menor = i;
                valor_menor = v[i];
            }
        }
    }
    return posicion_menor;
}

void imprimir_vector(const Vector& v){
    cout << "Lista: ";
    for(unsigned int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i + 1 < v.size()){
            cout << " ";
        }
    }
    cout << endl;
}

int main(){
    Vector datos;
    leer_datos(datos);
    int resultado = buscar_pos_menor_impar(datos);
    
    if(resultado == -1){
        cout << "No hay ningun numero impar en la lista" << endl;
    } else {
        cout << "El menor numero impar se encuentra en la posicion " << resultado << endl;
    }
    
    imprimir_vector(datos);
    return 0;
}
