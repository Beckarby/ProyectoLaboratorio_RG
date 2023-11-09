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
    int ci;
    string client;
    int account_number;
    string account_type;
    string suspend;

}cliente[2000];

ifstream data_client("C:/Users/HOME/Desktop/trabajos/programas/ProyectoLaboratorio_RG/datos/clients.csv");

int main(){
    int menu = 0;
    int count = 0;
    int nline = 0;
    string line, word;
    int num_cliens;
    int filtro = 0;
    int filtro_codigo;
    int filtro_nombre;
    int filtro_cedula;

    if(!data_client.is_open()){
        cout << "El archivo no ha sido encontrado" << endl;
    }

    while (getline(data_client,line))
    {
        stringstream str(line);

        while (getline (str, word, ','))
        {
            switch (count)
            {
            case 0:
                cliente[nline].ci = stoi(word);
                break;
            case 1:
                cliente[nline].client = word;
                break;
            case 2:
                cliente[nline].account_number = stoi(word);
                break;
            case 3:
                cliente[nline].account_type = word;
                break;
            case 4:
                cliente[nline].suspend = word;
                break;
            }
            count++;
        }
        nline++;
        count = 0;
        num_cliens++;
    }
    

    cout << "|      MENU       |" << endl;
    cout << "1.- Cuentas clientes" << endl;
    cout << "2.- Busqueda de clientes" << endl;

    cin >> menu;
    switch (menu)
    {
    case 1:
        cout << "A continuacion se visualizara la data de los clientes" << endl;
        cout << "num de cuenta - nombre - tipo de cuenta" << endl;
        for (int i = 0; i < num_cliens; i++)
        {
            cout << cliente[i].account_number << " ";
            cout << cliente[i].client << " ";
            cout << cliente[i].account_type << " ";
            cout << endl;
        }
        break;
    
    case 2:
        cout << "elija modo de busqueda" << endl;
        cout << "1.-codigo de cuenta" << endl;
        cout << "2.-nombre de cliente" << endl; 
        cout << "3.-cedula" << endl;
        switch (filtro)
        {
        case 1:
            cout << "ha elegido buscar por codigo de cuenta" << endl;
            cout << "ingrese la cuenta a buscar" << endl;
            cin >> filtro_codigo;
            break;
        
        case 2:
            cout << "ha elegido buscar por nombre de cliente" << endl;
            cout << "ingrese el nombre a buscar" << endl;
            cin >> filtro_nombre;
            break;
        case 3:
            cout << "ha elegido el filtro por cedula" << endl;
            cout << "ingrese la cedula a buscar" << endl;
            cin >> filtro_cedula;
        }
        break;
    }



    




}
