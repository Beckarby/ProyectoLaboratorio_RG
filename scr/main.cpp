/* 
1.-Visualizacion de los datos de clientes y sus cuentas de ahorro o corriente
2.-Establecer un buscador por codigo de cuenta, nombre del cliente o cedula
6.-Suspender cuentas de clientes y dar aviso de ello

*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int N, int x);

struct Cuenta {
    int ci;
    string client;
    long long int account_number;
    string account_type;
    string suspend;
    int dinero_cliente;

}cliente[2000];

ifstream data_client("../datos/clients.csv");

int main(){
    int menu = 0;
    int count = 0;
    int nline = 0;
    string line, word;
    //int num_cliens;
    int filtro = 0;
    int filtro_codigo;
    int filtro_nombre;
    int filtro_cedula;
    int result = 0;
    int N = 0, c1 = 0 , c2 = 0;
    int resp = 0;
    float deposito = 0;
    fstream registro;

    fstream createfile("Registro.csv", ios::out);
    createfile<< "nombre,C.i,cuenta,cuenta del deposito,monto" << endl;

    registro.open("registro.csv", ios::app);

    if(!data_client.is_open()){
        std::cout << "El archivo no ha sido encontrado" << endl;
    }

    while (getline(data_client,line))
    {
        stringstream str(line);
        while (getline (str, word, ',')){
            switch (count){
            case 0:
                cliente[nline].ci = stof(word);
                break;
            case 1:
                cliente[nline].client = word;
                break;
            case 2:
                cliente[nline].account_number = stoll(word);
                break;
            case 3:
                cliente[nline].account_type = word;
                break;
            case 4:
                cliente[nline].suspend = word;
                break;
            case 5:
                cliente[nline].dinero_cliente = 0.0;    
            }
            count++;
        }
        nline++;
        count = 0;
        
    }
    

    std::cout << "|      MENU       |" << endl;
    std::cout << "1.- Cuentas clientes" << endl;
    std::cout << "2.- Busqueda de clientes" << endl;
    std::cout << "3.- realizar transferencias entre clientes" << endl;

    std::cin >> menu;
    switch (menu){
    case 1:
        std::cout << "A continuacion se visualizara la data de los clientes" << endl;
        std::cout << "| numero de cuenta |  nombre  |  tipo de cuenta    |" << endl;
        
        for (int i = 0; i < nline; i++){
            std::cout << " " << cliente[i].account_number << "  |";
            std::cout << " " << cliente[i].client << " | ";
            std::cout << " " << cliente[i].account_type << " ";
            std::cout << endl;
        }

        std::cout << "Escribe tu numero de cuenta selecionar la cuenta bancaria" << endl;
        std::cin >> resp;
        do{
            N = N + 1 ;
            cout << cliente[N].account_number << '\n';
        }while(cliente[N].account_number != resp);


        std::cout << N << endl;
        std::cout << "Tu tipo de cuenta es:" << cliente[N].account_type << endl;
        if (cliente[N].dinero_cliente == 0){
            std::cout << "No tienes dineron en la cuenta haci que haga un deposito inicial" << endl;
            std::cout << "Ingrese la cantidad del deposito" << endl;
            std::cin >> deposito;

            cliente[N].dinero_cliente = deposito;

        }else if(cliente[N].dinero_cliente > 0){
            std::cout << "Quieres hacer un deposito o un retiro...Selecione la opcion:" << endl;
            std::cout << "1-hacer un deposito en tu cuenta" << endl;
            std::cout << "2-hacer un retiro" << endl;

            do{
             std::cin >> resp;

                if(resp == 1){
                 std::cout << "Tu saldo actual es: " << cliente[N].dinero_cliente << endl;
                 std::cout << "Ingrese la cantidad del deposito: " << endl;
                 std::cin >> deposito;

                 cliente[N].dinero_cliente = cliente[N].dinero_cliente + deposito;
                 
                }else if (resp == 2 ){
                 std::cout << "Tu saldo actual es: " << cliente[N].dinero_cliente << endl;
                 std::cout << "Ingrese la cantidad a retirar: " << endl;
                 do{
                   std::cin >> deposito; // se usa la misma variable deposito para el retiro

                   if(cliente[N].dinero_cliente < deposito){
                     std::cout << "Debe colocar una cantidad menor o igual a la actual " << endl;
                     std::cout << "Ingrese valor valido: " << endl;

                    }else {
                        cliente[N].dinero_cliente = cliente[N].dinero_cliente - deposito;

                        std::cout << "Tu saldo actual ahora es de : " << cliente[N].dinero_cliente << endl;
                    }

                 }while(cliente[N].dinero_cliente < deposito);

                }else{
                 std::cout << "Error..." << endl;
                 std::cout << "numero invalido ingrese un valor correcto" << endl;
                }
            }while(resp != 1 || resp != 2);
        }


        break;
    
    case 2:
        std::cout << "elija modo de busqueda" << endl;
        std::cout << "1.-codigo de cuenta" << endl;
        std::cout << "2.-nombre de cliente" << endl; 
        std::cout << "3.-cedula" << endl;
        
        switch (filtro){
        case 1:
            std::cout << "ha elegido buscar por codigo de cuenta" << endl;
            std::cout << "ingrese la cuenta a buscar" << endl;
            std::cin >> filtro_codigo;
            N = sizeof(cliente) / sizeof(cliente[0].account_number);

            /*
            result = linearSearch(cliente->account_number, N, filtro_codigo);
            if (result == -1){
                cout << "el numero de cuenta no ha sido encontrado" << endl;
            } else {
                cout << "a continuacion se le mostrara los datos del usuario " << filtro_codigo << endl;
                cout << "cedula: " <<cliente[result].ci << " " << endl;
                cout << "nombre: " << cliente[result].client << " " << endl;
                cout << "tipo de cuenta: " << cliente[result].account_type << " " << endl;
            }
            */
            break;
        
        case 2:
           std::cout << "ha elegido buscar por nombre de cliente" << endl;
           std::cout << "ingrese el nombre a buscar" << endl;
           std::cin >> filtro_nombre;
            break;
        case 3:
            std::cout << "ha elegido el filtro por cedula" << endl;
            std::cout << "ingrese la cedula a buscar" << endl;
            std::cin >> filtro_cedula;
            
            
        }
        break;

    case 3:
     std::cout<< "Vamos a realizar transferencias " << endl;
     std::cout<< "coloque cual es nu numero de cuenta para realizar la transferencia" << endl;
     std::cin>> resp;

     /*Aqui tiene que buscar de quien pertenece la cuenta */

     std::cout << "Ha que cuenta quieres realizar la transferencia?? " << endl;
     std::cout << "Coloque el numero de cuenta: " << endl;
     std::cin>> resp;

     /*Tiene que buscar el valor de la segunda persona al quien pertenece la segunda cuenta
     
     se debe guardar el numero de posicion que estan los 2 en 2 variables diferentes para hacer la comparacion
     se puede utilizar c1 y c2 para cuenta 1 y cuenta 2 */

     std::cout << "Cual es la cantidad a depositar: " << endl;
     std::cin >> deposito;

     cliente[c1].dinero_cliente = cliente[c1].dinero_cliente - deposito ;
     cliente[c2].dinero_cliente = cliente[c2].dinero_cliente + deposito;

     registro << cliente[c1].client +","<<+cliente[c1].ci + "," <<cliente[c1].account_number + "," 
     <<cliente[c2].account_number + "," <<+deposito ;

     std::cout << "Tu saldo actual es: " << cliente[c1].dinero_cliente << endl;


    }

    registro.close();

}

int linearSearch(int arr[], int N, int x)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
    
}

