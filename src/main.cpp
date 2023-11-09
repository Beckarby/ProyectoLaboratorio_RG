/* 
1.-Visualizacion de los datos de clientes y sus cuentas de ahorro o corriente
2.-Establecer un buscador por codigo de cuenta, nombre del cliente o cedula
6.-Suspender cuentas de clientes y dar aviso de ello

*/
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Cuenta {
    double ci;
    string client;
    double account_number;
    char account_type;
    char suspend;

}cliente[2000];

ifstream data_client("C:/Users/HOME/Desktop/trabajos/programas/ProyectoLaboratorio_RG/datos/clients.csv");

int main(){

    cout << "|      MENU       |" << endl;
    cout << "1.- Cuentas clientes" << endl;
    cout << "2.- Busqueda de clientes" << endl;

    if(!data_client.is_open()){
        cout << "El archivo no ha sido encontrado" << endl;
    }




}
