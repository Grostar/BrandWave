#include <iostream>
#include <string>
#include <array>
using namespace std;

const int MAXP = 20;

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

struct LPedidos{
    array<Pedido,MAXP> pedidos;
    int total;
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

void leer_pedidos(LPedidos& lista){
    cout << "Introduzca total de pedidos: ";
    cin >> lista.total;
    
    for(int i = 0; i < lista.total; i++){
        cout << endl;
        leer_pedido(lista.pedidos[i]);
    }
}

void mostrar_pedido(const Pedido& pedido){
    cout << "Codigo del producto: " << pedido.codigo << endl;
    cout << "Nombre del producto: " << pedido.nombre << endl;
    cout << "Precio del producto: " << pedido.precio << endl;
    cout << "Cantidad pedida: " << pedido.cantidad << endl;
    cout << "Fecha del pedido: " << pedido.fecha.dia << " " 
         << pedido.fecha.mes << " " << pedido.fecha.anio << endl;
    cout << endl;
}

void mostrar_pedidos(const LPedidos& lista){
    for(int i = 0; i < lista.total; i++){
        mostrar_pedido(lista.pedidos[i]);
    }
}

double calc_precio_total(const LPedidos& lista){
    double suma_total = 0.0;
    
    for(int i = 0; i < lista.total; i++){
        double precio_pedido = lista.pedidos[i].precio * lista.pedidos[i].cantidad;
        suma_total += precio_pedido;
    }
    
    return suma_total;
}

int main(){
    LPedidos lista;
    
    leer_pedidos(lista);
    cout << endl;
    cout << "Pedidos:" << endl << endl;
    mostrar_pedidos(lista);
    
    double total = calc_precio_total(lista);
    cout << "El precio total de los pedidos es: " << total << endl;
    
    return 0;
}
