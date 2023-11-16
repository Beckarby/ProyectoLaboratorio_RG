/* 
1.-Visualizacion de los datos de clientes y sus cuentas de ahorro o corriente
2.-Establecer un buscador por codigo de cuenta, nombre del cliente o cedula
6.-Suspender cuentas de clientes y dar aviso de ello

NO RECONOCE NOMBRES NI NUMEROS DE CUENTA


*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

template <typename T>
int partition(T arr[], int start, int end);
template <typename T>
void quicksort(T arr[], int start, int end);
template <typename T>
int binarySearch(T arr[], int n, T x);
template <typename T>
int linearSearch(T arr[], int n, T x);


struct Cuenta {
    long long int ci;
    string client;
    long long int account_number;
    string account_type;
    string suspend;

}cliente[1000];

ifstream data_client("C:/Users/HOME/Desktop/trabajos/programas/ProyectoLaboratorio_RG/datos/clients.csv");

int main(){
    int menu = 0;
    int count = 0;
    int nline = 0;
    string line, word;
    //int num_cliens;
    int filtro = 0;
    long long int filtro_codigo;
    string filtro_nombre;
    long long int filtro_cedula;
    int result = 0;
    int N;
    int n;
    int size;
    long long int OrderByNumAccount[1000];
    long long int UnOrderedNumAccount[1000];
    string OrderByNameClient[1000];
    string UnOrderedNameClient[1000];
    long long int OrderByID[1000];
    long long int UnOrderedClientID[1000];

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

    

    std::cout << "|      MENU       |" << endl;
    std::cout << "1.- Cuentas clientes" << endl;
    std::cout << "2.- Busqueda de clientes" << endl;

    std::cin >> menu;
    switch (menu)
    {
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
                std::cout << "Posicion del cliente: " << result << endl;
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
    }

}

template <typename T>
int partition(T arr[], int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(arr[i]<arr[pivot]){
			swap(arr[i],arr[j]);
			++j;
		}
	}
	swap(arr[j],arr[pivot]);
	return j;
	
}

// template function to perform quick sort on array arr
template <typename T>
void quicksort(T arr[], int start, int end ){

	if(start<end){
		int p = partition(arr,start,end);
        quicksort(arr,start,p-1);
        quicksort(arr,p+1,end);
	}
	
}

template<typename T>
int binarySearch(T arr[], int n, T x)
{
	int start = 0;
	int end = n-1;
	while(start<=end)
	{
		int mid = (start+end)/2;
		if(arr[mid]==x)	
			return mid;
		else if(arr[mid]<x)	
			start = mid + 1;
		else	
			end = mid - 1;
	}
	return -1;
}

template <typename T>
int linearSearch(T arr[], int n, T x) {

	for (int i = 0; i < n; ++i) {

		if (arr[i] == x)
			return i;

	}

	return -1;

}
