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

template <typename T>
int partition(T arr[], int start, int end);
template <typename T>
void Quicksort(T arr[], int start, int end);
template <typename T>
int binarySearch(T arr[],int n,T x);


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
    //int num_cliens;
    int filtro = 0;
    float filtro_codigo;
    int filtro_nombre;
    float filtro_cedula;
    int result = 0;
    float N;
    float n;
    float OrderByNumAccount[2000];
    string OrderByNameClient[2000];
    float OrderByID[2000];

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
                cliente[nline].ci = stof(word);
                break;
            case 1:
                cliente[nline].client = word;
                break;
            case 2:
                cliente[nline].account_number = stof(word);
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
    for (int i = 0; i < nline; i++)
    {
        OrderByID[i] = cliente[i].ci;
        OrderByNameClient[i] = cliente[i].client;
        OrderByNumAccount[i] = cliente[i].account_number;
    }
    n = sizeof(OrderByID) / sizeof(OrderByID[0]);
    N = sizeof(OrderByNumAccount) / sizeof(OrderByNumAccount[0]);
    
    Quicksort(OrderByNumAccount, 0, N -1);
    Quicksort(OrderByID, 0, n -1);

    

    cout << "|      MENU       |" << endl;
    cout << "1.- Cuentas clientes" << endl;
    cout << "2.- Busqueda de clientes" << endl;

    cin >> menu;
    switch (menu)
    {
    case 1:
        cout << "A continuacion se visualizara la data de los clientes" << endl;
        cout << "| numero de cuenta |  nombre  |  tipo de cuenta    |" << endl;
        for (int i = 0; i < nline; i++)
        {
            cout << " " << cliente[i].account_number << "  |";
            cout << " " << cliente[i].client << " | ";
            cout << " " << cliente[i].account_type << " ";
            cout << endl;
        }
        break;
    
    case 2:
        cout << "elija modo de busqueda" << endl;
        cout << "1.-codigo de cuenta" << endl;
        cout << "2.-nombre de cliente" << endl; 
        cout << "3.-cedula" << endl;
        cin >> filtro;
        switch (filtro)
        {
        case 1:

            cout << "ha elegido buscar por codigo de cuenta" << endl;
            cout << "ingrese la cuenta a buscar" << endl;
            cin >> filtro_codigo;
            
            result = binarySearch(OrderByNumAccount, N, filtro_codigo);
            if (result == -1)
            {
                cout << "el codigo de cuenta ingresado no esta presente en la base de datos" << endl;
                return 0;
            } else {
                cout << "CLIENTE ENCONTRADO" << endl;
                cout << "Posicion del cliente: " << result << endl;
                cout << "Nombre: " << cliente[result].client << endl;
                cout << "tipo de cuenta " << cliente[result].account_type << endl;
                cout << "cedula: " << cliente[result].ci << endl;
                cout << "estado de cuenta: " << cliente[result].suspend << endl;
            }
            

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
            result = binarySearch(OrderByID, n, filtro_cedula);
            if (result == -1)
            {
                cout << "La cedula ingresada no esta presente en la base de datos" << endl;
            } else {
                cout << "CLIENTE ENCONTRADO" << endl;
                cout << "Nombre:" << cliente[result].client << endl;
                cout << "Tipo de cuenta: " << cliente[result].account_type << endl;
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
void Quicksort(T arr[], int start, int end ){

	if(start<end){
		int p = partition(arr,start,end);
        Quicksort(arr,start,p-1);
        Quicksort(arr,p+1,end);
	}
	
}

template<typename T>
int binarySearch(T arr[],int n,T x)
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