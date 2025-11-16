#include <iostream>
#include <array>
using namespace std;

const int MAX = 20;

struct TEstaturas{
    array<double,MAX> estaturas;
    int total;
};

void leer_estaturas(TEstaturas& datos){
    cout << "Cuantas estaturas va a introducir (maximo 20): ";
    cin >> datos.total;
    cout << "Introduzca las " << datos.total << " estaturas: ";
    for(int i = 0; i < datos.total; i++){
        cin >> datos.estaturas[i];
    }
}

double media(const TEstaturas& datos){
    double suma = 0.0;
    for(int i = 0; i < datos.total; i++){
        suma = suma + datos.estaturas[i];
    }
    return suma / datos.total;
}

int contar_mas_altos(const TEstaturas& datos, double media_calculada){
    int contador = 0;
    for(int i = 0; i < datos.total; i++){
        if(datos.estaturas[i] > media_calculada){
            contador++;
        }
    }
    return contador;
}

int contar_mas_bajos(const TEstaturas& datos, double media_calculada){
    int contador = 0;
    for(int i = 0; i < datos.total; i++){
        if(datos.estaturas[i] < media_calculada){
            contador++;
        }
    }
    return contador;
}

int main(){
    TEstaturas datos;
    leer_estaturas(datos);
    
    double media_estaturas = media(datos);
    cout << "La media es: " << media_estaturas << endl;
    
    int altos = contar_mas_altos(datos, media_estaturas);
    cout << "Numero de alumnos mas altos que la media: " << altos << endl;
    
    int bajos = contar_mas_bajos(datos, media_estaturas);
    cout << "Numero de alumnos mas bajos que la media: " << bajos << endl;
    
    return 0;
}
