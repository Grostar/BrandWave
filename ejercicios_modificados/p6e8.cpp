#include <iostream>
#include <string>
using namespace std;

void leer_cadena(string& texto){
    cout << "Introduzca una cadena: ";
    getline(cin, texto);
    if(texto.size() == 0){
        getline(cin, texto);
    }
}

bool es_vocal(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void eliminar_vocales(string& cadena){
    string resultado = "";
    
    for(unsigned int i = 0; i < cadena.size(); i++){
        char caracter = cadena[i];
        if(!es_vocal(caracter)){
            resultado += caracter;
        }
    }
    
    cadena = resultado;
}

void mostrar_resultados(const string& original, const string& resultado){
    cout << "Cadena original: " << original << endl;
    cout << "Cadena resultado: " << resultado << endl;
}

int main(){
    string texto;
    leer_cadena(texto);
    
    string texto_original = texto;
    eliminar_vocales(texto);
    
    mostrar_resultados(texto_original, texto);
    
    return 0;
}
