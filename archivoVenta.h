#ifndef ARCHIVOVENTA_H_INCLUDED
#define ARCHIVOVENTA_H_INCLUDED

bool comprobarDni(int Dni){
    cliente reg;
    FILE *pCliente;
    pCliente=fopen("clientes.dat","rb");
    if (pCliente==NULL){return false;}
    while(fread(&reg,sizeof reg,1,pCliente)==1){
        if(reg.getDni()==Dni){
            fclose(pCliente);
            return true;

        }

    }
    fclose(pCliente);
    return false;
}

bool comprobarArticulo(int art,int cv){
    int p;
    articulo reg;
    FILE *pArticulo;
    pArticulo=fopen("articulos.dat","rb");
    if(pArticulo==NULL){return false;}
    while(fread(&reg,sizeof reg,1,pArticulo)==1){
        if(reg.getIdArticulo()==art && reg.getStock()>=cv){
            p=reg.getStock()-cv;
            reg.setStock(p);
            fclose(pArticulo);
            return true;
        }
    }
    fclose(pArticulo);
    return false;
}

float calcularImporte(int id,int cv){
    float total;
    articulo reg;
    FILE *pArticulo;
    pArticulo=fopen("articulos.dat","rb");
    if(pArticulo==NULL){return -1;}
    while(fread(&reg,sizeof reg,1,pArticulo)==1){
        if (reg.getIdArticulo()==id){
            total=reg.getPrecioUnitario()*cv;
            fclose(pArticulo);
            return total;
        }
    }
}
int comprobarVenta(int codigo){

    venta reg;
    int pos=0;
    FILE *pVentas;
    pVentas=fopen("ventas.dat", "rb");

    if(pVentas==NULL){return -2;}

    while(fread(&reg,sizeof reg,1,pVentas)==1){
        if(reg.getNumeroVenta()==codigo){
         fclose(pVentas);
         return pos;
        }
        pos++;
    }
    fclose(pVentas);
    return -1;

}

bool cargarVenta(venta reg){
    float p;
    int v;
    FILE *pVenta;
    reg.cargar();
    pVenta=fopen("ventas.dat","ab");
    if(pVenta==NULL){return false;}
    v=comprobarVenta(reg.getNumeroVenta());
    if (v<0&& comprobarDni(reg.getdniCliente())==true && comprobarArticulo(reg.getIdArticulo(),reg.getCantidadVendida())==true){
            p=calcularImporte(reg.getIdArticulo(),reg.getCantidadVendida());
            reg.setImporteVenta(p);
            reg.mostrar();
             fwrite(&reg,sizeof reg,1,pVenta);
             fclose(pVenta);
            return true;
            system("pause");
            system("cls");

        }
        else{
            cout<<"DATOS INVALIDOS"<<endl;
            fclose(pVenta);
            return false;
            system("pause");
            system("cls");

        }
}
bool listarVentaPorNumero(venta reg){
 system("cls");
 int codigo;
 bool cortar=false;

    FILE *pVenta;

    pVenta=fopen("ventas.dat", "rb");
    if(pVenta==NULL){return false;}
    cout<<"INGRESE EL NUMERO DE ARTICULO A BUSCAR: ";
    cin>>codigo;
    while(fread(&reg,sizeof reg,1,pVenta)==1){
        if (reg.getNumeroVenta()==codigo){
          reg.mostrar();
          cortar=true;
        }
    }
    fclose(pVenta);
    if(cortar==false){
        cout<<"NO SE ENCONTRO EL NUMERO DE ARTICULO"<<endl;
    }
    system("pause");
    system("cls");
    return true;

}

bool listarVentas(venta reg){
    FILE *pVenta;
    pVenta=fopen("ventas.dat","rb");
    if(pVenta==NULL){return false;}
    while(fread(&reg,sizeof reg,1,pVenta)==1){
        reg.mostrar();
    }
    fclose(pVenta);
    return true;
}


#endif // ARCHIVOVENTA_H_INCLUDED
