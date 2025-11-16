#include <iostream>
#include <array>
using namespace std;

using Vector = array<double,5>;

void leer_vector(Vector& vec){
    cout << "Introduzca 5 numeros: ";
    for(unsigned int idx = 0; idx < vec.size(); idx++){
        cin >> vec[idx];
    }
}

double buscar_mayor(const Vector& v){
    double mayor = v[0];
    for(unsigned int idx = 1; idx < v.size(); idx++){
        if(v[idx] > mayor){
            mayor = v[idx];
        }
    }
    return mayor;
}

void imprimir_vector(const Vector& v){
    cout << "Lista: ";
    for(unsigned int idx = 0; idx < v.size(); idx++){
        cout << v[idx];
        if(idx + 1 < v.size()){
            cout << " ";
        }
    }
    cout << endl;
}

int main(){
    Vector numeros;
    leer_vector(numeros);
    double elemento_mayor = buscar_mayor(numeros);
    cout << "El mayor elemento de la lista es " << elemento_mayor << endl;
    imprimir_vector(numeros);
    return 0;
}
