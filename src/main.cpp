#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <string>
#include <quicksort.h>
#include <binarySearch.h>
#include <linearSearch.h>
#include <cassert>
#define NDEBUG

using namespace std;

void agregar_cliente();
void eliminar_cliente();

struct Cuenta {
    long long int ci;
    string client;
    long long int account_number;
    string account_type;
    string suspend;
    float dinero_cliente = 0.0;

}cliente[2000];

fstream registro;
fstream createfile("Registro.csv", ios::out);
    
ifstream data_client("../../datos/clients.csv");
void TestLinearSearch();
void TestQuicksort();
void testBinarySearch();

int main(){
    int menu = 0;
    int cont_nuevo = 0;
    int count = 0;
    int nline = 0;
    string line, word;
    int filtro = 0;
    long long int filtro_codigo;
    string filtro_nombre;
    long long int filtro_cedula;
    int result = 0;
    int N;
    int n;
    int size;
    int c1 = 0;
    int c2 = 0;
    int resp_2 = 0;
    long long int resp = 0;
    float deposito = 0;
    long long int OrderByNumAccount[1000];
    long long int UnOrderedNumAccount[1000];
    string OrderByNameClient[1000];
    string UnOrderedNameClient[1000];
    long long int OrderByID[1000];
    long long int UnOrderedClientID[1000];
    
    createfile << "Nombre,C.I,Cuenta,Cuenta del deposito,Monto" << endl;

    registro.open("registro.csv", ios::app);

    if(!data_client.is_open()){
        std::cout << "El archivo no ha sido encontrado" << endl;
    }

    while (getline(data_client,line))
    {
        stringstream str(line);

        while (getline (str, word, ','))
        {

            switch (count)
            {
            case 0:
                cliente[nline].ci = stoll(word);
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
            break;
            }
            count++;
        }
        nline++;
        count = 0;
        
    }
    for (int i = 0; i < 1000; i++)
     {

        OrderByID[i] = cliente[i].ci;
        UnOrderedClientID[i] = cliente[i].ci;
        OrderByNameClient[i] = cliente[i].client; 
        UnOrderedNameClient[i] = cliente[i].client;
        OrderByNumAccount[i] = cliente[i].account_number;
        UnOrderedNumAccount[i] = cliente[i].account_number;
    }
    n = sizeof(OrderByID) / sizeof(OrderByID[0]);
    N = sizeof(OrderByNumAccount) / sizeof(OrderByNumAccount[0]);
    size = sizeof(OrderByNameClient) / sizeof(OrderByNameClient[0]);

    quicksort(OrderByNumAccount, 0, N - 1);
    quicksort(OrderByID, 0, n - 1);
    quicksort(OrderByNameClient, 0, size - 1);

    
    //here are gonna be the tests
    TestLinearSearch();
    TestQuicksort();
    testBinarySearch();

    do{

    std::cout << "|      MENU       |" << endl;
    std::cout << "1.- Cuentas clientes" << endl;
    std::cout << "2.- Busqueda de clientes" << endl;
    std::cout << "3.- Realizar Transferencias" << endl;
    std::cout << "4.-Agregar nuevo cliente" << endl;
    std::cout << "5.-Eliminar un cliente" << endl;

    std::cin >> menu;
    switch (menu){

    case 1:
        std::cout << "A continuacion se visualizara la data de los clientes" << endl;
        std::cout << "| numero de cuenta |  nombre  |  tipo de cuenta    |" << endl;
        for (int i = 0; i < 1000; i++)
        {
            std::cout << " " << cliente[i].account_number << "  |";
            std::cout << " " << cliente[i].client << " | ";
            std::cout << " " << cliente[i].account_type << " ";
            std::cout << endl;
        }
        std::cout << "Escribe tu numero de cuenta selecionar la cuenta bancaria" << endl;
        std::cin >> resp;
       
       c1 = linearSearch(UnOrderedNumAccount, N, resp);
       std::cout << c1 << endl;

        std::cout << "Tu tipo de cuenta es:" << cliente[c1].account_type << endl;
        if (cliente[c1].dinero_cliente == 0){
            std::cout << "No tiene dinero suficiente en su cuenta has un deposito inicial" << endl;
            std::cout << "Ingrese la cantidad del deposito" << endl;
            std::cin >> deposito;

            cliente[c1].dinero_cliente = deposito;

        }else if(cliente[c1].dinero_cliente > 0){
            std::cout << "Quieres hacer un deposito o un retiro...Selecione la opcion:" << endl;
            std::cout << "1-hacer un deposito en tu cuenta" << endl;
            std::cout << "2-hacer un retiro" << endl;

            do{
             std::cin >> resp;

                if(resp == 1){
                 std::cout << "Tu saldo actual es: " << cliente[c1].dinero_cliente << endl;
                 std::cout << "Ingrese la cantidad del deposito: " << endl;
                 std::cin >> deposito;

                 cliente[c1].dinero_cliente = cliente[c1].dinero_cliente + deposito;
                 
                }else if (resp == 2 ){
                 std::cout << "Tu saldo actual es: " << cliente[c1].dinero_cliente << endl;
                 std::cout << "Ingrese la cantidad a retirar: " << endl;
                 std::cin >> deposito; // se usa la misma variable deposito para el retiro

                   if(cliente[c1].dinero_cliente < deposito){
                       do{
                         std::cout << "Debe colocar una cantidad menor o igual a la actual " << endl;
                         std::cout << "Ingrese valor valido: " << endl;
                         std::cin >> deposito;

                        }while(cliente[c1].dinero_cliente < deposito);

                    }else{
                        cliente[c1].dinero_cliente = cliente[c1].dinero_cliente - deposito;

                        std::cout << "Tu saldo actual ahora es de : " << cliente[c1].dinero_cliente << endl;
                    }

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
        std::cin >> filtro;
        switch (filtro)
        {
        case 1:

            std::cout << "ha elegido buscar por codigo de cuenta" << endl;
            std::cout << "ingrese la cuenta a buscar" << endl;
            std::cin >> filtro_codigo;
            
            result = binarySearch(OrderByNumAccount, N, filtro_codigo);
            if (result == -1)
            {
                std::cout << "el codigo de cuenta ingresado no esta presente en la base de datos" << endl;
                return 0;
            } else {
                std::cout << "CLIENTE ENCONTRADO" << endl;
                result = linearSearch(UnOrderedNumAccount, N, filtro_codigo);
                std::cout << "Nombre: " << cliente[result].client << endl;
                std::cout << "tipo de cuenta: " << cliente[result].account_type << endl;
                std::cout << "cedula: " << cliente[result].ci << endl;
                if (cliente[result].suspend == "TRUE"){
                    std::cout << "CUENTA SUSPENDIDA" << endl;

                }
            }

            
            break;
        
        case 2:
            std::cout << "ha elegido buscar por nombre de cliente" << endl;
            std::cout << "ingrese el nombre a buscar" << endl;
            cin >> ws;
            std::getline(std::cin, filtro_nombre);
            result = binarySearch(OrderByNameClient, size, filtro_nombre);
            if (result == -1){
                std::cout << "El nombre ingresado no esta en la base de datos" << endl;
                return 0;
            } else {
                std::cout << "CLIENTE ENCONTRADO" << endl;

                result = linearSearch(UnOrderedNameClient, size, filtro_nombre);
                cout << result << endl;
                std::cout << "Nombre: " << cliente[result].client << endl;
                std::cout << "Cedula: " << cliente[result].ci << endl;
                std::cout << "Tipo de Cuenta: " << cliente[result].account_type << endl;
                std::cout << "Numero de Cuenta: " << cliente[result].account_number << endl;
                if(cliente[result].suspend == "TRUE"){
                    std::cout << "CUENTA SUSPENDIDA" << endl;
                }

            }
            break;
        case 3:
            std::cout << "ha elegido el filtro por cedula" << endl;
            std::cout << "ingrese la cedula a buscar" << endl;
            std::cin >> filtro_cedula;
            result = binarySearch(OrderByID, n, filtro_cedula);
            if (result == -1)
            {
                std::cout << "La cedula ingresada no esta presente en la base de datos" << endl;
            } else {
                std::cout << "CLIENTE ENCONTRADO" << endl;
                result = linearSearch(UnOrderedClientID, n, filtro_cedula);
                std::cout << "Nombre:" << cliente[result].client << endl;
                std::cout << "Cedula: " << cliente[result].ci << endl;
                std::cout << "Tipo de cuenta: " << cliente[result].account_type << endl;
                std::cout << "Numero de cuenta: " << cliente[result].account_number << endl;
                if(cliente[result].suspend == "TRUE") {
                    std::cout << "CUENTA SUSPENDIDA" << endl;
                }
                
            }    
        }
        break;
    case 3:
        std::cout<< "Vamos a realizar transferencias " << endl;
        std::cout<< "coloque cual es nu numero de cuenta para realizar la transferencia" << endl;
        std::cin>> resp;

        c1 = linearSearch(UnOrderedClientID, N, resp);

        std::cout << "A que cuenta quieres realizar la transferencia?? " << endl;
        std::cout << "Coloque el numero de cuenta: " << endl;
        std::cin>> resp;

        c2 = linearSearch(UnOrderedClientID, N, resp);
        /*Tiene que buscar el valor de la segunda persona al quien pertenece la segunda cuenta
        
        se debe guardar el numero de posicion que estan los 2 en 2 variables diferentes para hacer la comparacion
        se puede utilizar c1 y c2 para cuenta 1 y cuenta 2 */

        std::cout << "Cual es la cantidad a depositar: " << endl;

        do{
            std::cin >> deposito; // se usa la misma variable deposito para el retiro

            if(cliente[c1].dinero_cliente == 0){
                std::cout << "No tienes dinero " << endl;
                std::cout << "Para hacer una tranferencia haga un deposito previo" << endl;
                resp_2 = 1;

            }else if(cliente[c1].dinero_cliente < deposito){
                std::cout << "Tu saldo actual es: " << cliente[c1].dinero_cliente << endl;
                std::cout << "Debe colocar una cantidad menor o igual a la actual " << endl;
                std::cout << "Ingrese valor valido: " << endl;

            }else {
                cliente[c1].dinero_cliente = cliente[c1].dinero_cliente - deposito ;
                cliente[c2].dinero_cliente = cliente[c2].dinero_cliente + deposito;

                std::cout << "Tu saldo actual es: " << cliente[c1].dinero_cliente << endl;
            }

        }while(cliente[c1].dinero_cliente < deposito && resp_2 != 1);

        registro << cliente[c1].client +","<<+cliente[c1].ci + "," <<cliente[c1].account_number + "," 
        <<cliente[c2].account_number + "," <<+deposito << endl;
        break;
     case 4:    
       
        agregar_cliente();
        
        break;

     case 5:

     eliminar_cliente();

      break;
       
       
        std::cout << "Quieres seguir ??:" << endl;
        std::cout << "1-Para si " << endl;
        std::cout << "2-Para no " << endl;
        std::cin >> resp_2;
     }
     
     cout << "Quieres seguir:" << endl;
     cout << "1.-Para si" << endl;
     cout << "2.-para no" << endl;
     cin >> resp_2;

      system("cls");
    }while(resp_2 != 2);

    data_client.close();
    registro.close();

}



void agregar_cliente(){
    ofstream infile;
    string agg;
    int cont_clientes_agg = 1000 ;
    int resp_f = 0;

    infile.open("../datos/clients.csv", ios::app);
    infile.seekp(1001);
    infile << endl;

    do{
      cont_clientes_agg = cont_clientes_agg + 1 ;
     cout << "Vamos a agregar a un nuevo cliente " << endl;
     cout << "Ingrese el numero de Ci:" << endl;
     cin >> agg;

     cliente[cont_clientes_agg].ci = stoi(agg);

     cout << "Ingrese el nombre del cliente:" << endl;
     cin.get();
     getline(cin,agg);

     cliente[cont_clientes_agg].client = agg;

     cout << "Ingrese el numero de cuenta:" << endl;
     cin >> agg;

     cliente[cont_clientes_agg].account_number = stoi(agg);

     cout << "Ingrese el tipo de cuenta:" << endl;
     cin >> agg;

     cliente[cont_clientes_agg].account_type = agg;

     cout << "Ingrese si esta suspendida con true o false:" << endl;
     cin >>agg;

     cliente[cont_clientes_agg].suspend = agg;

     infile <<  cliente[cont_clientes_agg].ci << ";" <<  cliente[cont_clientes_agg].client << ";"
     <<  cliente[cont_clientes_agg].account_number << ";" <<  cliente[cont_clientes_agg].account_type << ";"
     <<  cliente[cont_clientes_agg].suspend << endl;

     cout << "Quieres agregar a otro:" << endl;
     cout << "1.-Para si" << endl;
     cout << "2.-para no" << endl;
     cin >> resp_f;

    }while (resp_f != 2);

    infile.close();

}

void eliminar_cliente(){
    ofstream infile;
    int cont = 1001;
    int ci = 0;
    bool existe = false;

    infile.open("../datos/clients.csv", ios::out);

    std::cout << "Ingrese la c.i del cliente a eliminar " << endl;
    std::cin >> ci;

    for(int i = 0; i < cont ; i++){

        if(cliente[i].ci == ci){
            existe = true;
        }else{
             infile <<  cliente[i].ci << ";" <<  cliente[i].client << ";"
              <<  cliente[i].account_number << ";" <<  cliente[i].account_type << ";"
              <<  cliente[i].suspend << endl;
        }


    }
}

void TestLinearSearch(){
    // The function returns the index of the element if it is present in the array.
     
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    
    int resultado = linearSearch(arr, n, x);
    
    assert(resultado == 2);
    
    // The function returns -1 when the element is not present in the array
    x = 6;

    resultado = linearSearch(arr, n, x);

    assert(resultado = -1);
}

void TestQuicksort(){

    //the function should sort an array of random numbers in ascending order
    int arr[] = {5,2,8,1,9};
    int expected[] = {1,2,5,8,9};
    quicksort(arr,0,4);
    for (int i = 0; i < 5; i++)
    {
        assert(arr[i] == expected[i]);
    }    
    
}

void testBinarySearch(){
    //the function should return the index of a element when it finds it
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    int resultado = binarySearch(arr, n, x);
    assert(resultado == 2);

    //if element is not present it should return -1
    x = 6;
    resultado = binarySearch(arr, n, x);
    assert(resultado == -1);
}






















