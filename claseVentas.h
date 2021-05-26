#ifndef CLASEVENTAS_H_INCLUDED
#define CLASEVENTAS_H_INCLUDED
class venta{
private:
    int numeroVenta;
    int idArticulo;
    int dniCliente;
    float importeVenta;
    int cantidadVendida;
    fecha fechaVenta;
public:
    void setNumeroVenta(int x){numeroVenta=x;}
    void setIdArticulo(int x){idArticulo=x;}
    void setdniCliente(int x){dniCliente=x;}
    void setImporteVenta(float x){importeVenta=x;}
    void setCantidadVendida(int x){cantidadVendida=x;}
    void setFechaVenta(fecha f){fechaVenta=f;}

    int getNumeroVenta(){return numeroVenta;}
    int getIdArticulo(){return idArticulo;}
    int getdniCliente(){return dniCliente;}
    float getImporteVenta(){return importeVenta;}
    int getCantidadVendida(){return cantidadVendida;}
    fecha getFechaVenta(){return fechaVenta;}

    void cargar();
    void mostrar();

};
void venta::cargar(){
    int x=-1;
    cout<<"INGRESE EL NUMERO DE VENTA: ";
    cin>>numeroVenta;
    cout<<"INGRESE EL ID DEL ARTICULO: ";
    cin>>idArticulo;
    cout<<"INGRESE EL DNI DEL CLIENTE: ";
    cin>>dniCliente;
    while(x<=0){
        cout<<"INGRESE LA CANTIDAD VENDIDA: ";
        cin>>x;
        if(x<=0)cout<<"INGRESE UN NUMERO DE VENTA VALIDO"<<endl;
    }
    setCantidadVendida(x);
    cout<<"INGRESE LA FECHA DE VENTA:"<<endl;
    fechaVenta.cargar();
    cout<<endl;
}
void venta::mostrar(){
    cout<<"NUMERO DE VENTA: "<<numeroVenta<<endl;
    cout<<"ID DEL ARICULO: "<<idArticulo<<endl;
    cout<<"DNI DEL CLIENTE: "<<dniCliente<<endl;
    cout<<"CATIDAD VENDIDA: "<<cantidadVendida<<endl;
    cout<<"IMPORTE DE LA VENTA: "<<importeVenta<<endl;
    cout<<"FECHA DE VENTA"<<endl;
    fechaVenta.mostrar();
    cout<<endl;
}
bool cargarVenta(venta obj);
bool listarVentas(venta reg);
bool listarVentaPorNumero(venta reg);

void claseVentas(){
int opc;
venta obj;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"--------------------"<<endl;
        cout<<endl;
        cout<<"1) AGREGAR VENTA"<<endl;
        cout<<"2) LISTAR VENTA POR NUMERO DE VENTA"<<endl;
        cout<<"3) LISTAR TODAS LAS VENTAS"<<endl;
        cout<<"4) ELIMINAR VENTA"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) FIN DEL PROGRAMA"<<endl;
        cout<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:if(cargarVenta(obj)==true){
                    cout<<endl;
                        cout<<"VENTA REGISTRADA"<<endl;
                    }

                break;
           case 2:if(listarVentaPorNumero(obj)==false){
                    cout<<"ERROR DE ARCHIVO"<<endl;
                    }
                break;
            case 3:if(listarVentas(obj)==false){
                    cout<<"ERROR DE ARCHIVO"<<endl;
                    }
                break;
            case 0: return;
                break;
        }
        system("pause");
        system("cls");

    }

}
#endif // CLASEVENTAS_H_INCLUDED
