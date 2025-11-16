#include <iostream>
#include <string>
using namespace std;

struct Fecha{
    int dia;
    int mes;
    int anio;
};

struct Pedido{
    int codigo;
    string nombre;
    double precio;
    int cantidad;
    Fecha fecha;
};

void leer_pedido(Pedido& pedido){
    cout << "Introduzca codigo del producto: ";
    cin >> pedido.codigo;
    
    cout << "Introduzca nombre del producto: ";
    string linea_vacia;
    getline(cin, linea_vacia);
    getline(cin, pedido.nombre);
    
    cout << "Introduzca precio del producto: ";
    cin >> pedido.precio;
    
    cout << "Introduzca cantidad pedida: ";
    cin >> pedido.cantidad;
    
    cout << "Introduzca fecha del pedido: ";
    cin >> pedido.fecha.dia >> pedido.fecha.mes >> pedido.fecha.anio;
}

void mostrar_pedido(const Pedido& pedido){
    cout << "Codigo del producto: " << pedido.codigo << endl;
    cout << "Nombre del producto: " << pedido.nombre << endl;
    cout << "Precio del producto: " << pedido.precio << endl;
    cout << "Cantidad pedida: " << pedido.cantidad << endl;
    cout << "Fecha del pedido: " << pedido.fecha.dia << " " 
         << pedido.fecha.mes << " " << pedido.fecha.anio << endl;
}

double calcular_precio_total(const Pedido& pedido){
    return pedido.precio * pedido.cantidad;
}

int main(){
    Pedido pedido;
    
    leer_pedido(pedido);
    cout << endl;
    mostrar_pedido(pedido);
    cout << endl;
    
    double total = calcular_precio_total(pedido);
    cout << "El precio total del pedido es: " << total << endl;
    
    return 0;
}
