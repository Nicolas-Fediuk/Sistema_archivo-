#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>

using namespace std;
#include "claseArticulo.h"
#include "archivoArticulo.h"
#include "claseCliente.h"
#include "archivoCliente.h"
#include "claseVentas.h"
#include "archivoVenta.h"
#include "parcial_Fediuk.h"
#include "configuraciones.h"

int main(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"--------------------"<<endl;
        cout<<endl;
        cout<<"1) MENU ARTICULO"<<endl;
        cout<<"2) MENU CLIENTE"<<endl;
        cout<<"3) MENU VENTAS"<<endl;
        cout<<"4) REPORTES"<<endl;
        cout<<"5) CONFIGURACION"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) FIN DEL PROGRAMA"<<endl;
        cout<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:claseArticulo();
                break;
            case 2:claseCliente();
                break;
            case 3:claseVentas();
                break;
            case 4:reportes();
                break;
            case 5:configuracion();
                break;
            case 0: return 0;
                break;
        }
        system("pause");
        system("cls");

    }
    return 0;
}


