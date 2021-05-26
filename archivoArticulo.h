#ifndef ARCHIVOARTICULO_H_INCLUDED
#define ARCHIVOARTICULO_H_INCLUDED
int buscarArticulo(articulo reg,int codigo){
    int pos=0;
    FILE *pArticulo;
    pArticulo=fopen("articulos.dat", "rb");

    if(pArticulo==NULL){return -2;}

    while(fread(&reg,sizeof reg,1,pArticulo)==1){
        if(reg.getIdArticulo()==codigo){
         fclose(pArticulo);
         return pos;
        }
        pos++;
    }
    fclose(pArticulo);
    return -1;
}

bool addArticulo(articulo reg){
    int p;
    system("cls");
    reg.cargar();
    p=buscarArticulo(reg,reg.getIdArticulo());
    if(p<0){
    bool afirmativo=reg.grabarEnDisco();
    return afirmativo;
    }
    else{
        cout<<"EL ID DEL ARTICULO YA EXISTE"<<endl;
    }
}

bool listarXid(articulo reg){
    system("cls");
 int codigo;
 bool cortar=false;

    FILE *pArticulo;

    pArticulo=fopen("articulos.dat", "rb");
    if(pArticulo==NULL){return false;}
    cout<<"INGRESE EL CODIGO A BUSCAR: ";
    cin>>codigo;
    while(fread(&reg,sizeof reg,1,pArticulo)==1){
        if (reg.getIdArticulo()==codigo){
          reg.mostrar();
          cortar=true;
        }
    }
    fclose(pArticulo);
    if(cortar==false){
        cout<<"NO SE ENCONTRO EL CODIGO"<<endl;
    }
    system("pause");
    system("cls");
    return true;

}

void listarArticulo(articulo reg){
    system("cls");
    int pos=0;
    while(reg.leerEnDisco(pos++)){
        reg.mostrar();
        system("pause");
        system("cls");
    }
}

articulo leerRegistro(int pos){
    articulo reg;
    FILE *pArticulo;
    pArticulo=fopen("articulos.dat", "rb");


    fseek(pArticulo, pos*sizeof reg, 0);
    fread(&reg,sizeof reg,1,pArticulo);
    fclose(pArticulo);
    return reg;
}

bool modificarEnDisco(articulo reg, int pos){
    FILE *pArticulo;

    pArticulo=fopen("articulos.dat", "rb+");

    if(pArticulo==NULL){return false;}

    fseek(pArticulo,pos*sizeof reg, 0);
    bool escribio=fwrite(&reg, sizeof reg, 1, pArticulo);
    fclose(pArticulo);
    return escribio;
}

bool modificarPu(articulo reg){
    system("cls");
    float pu;
    int codigo;

    bool modifico=false;

    cout<<"INGRESE EL CODIGO DEL ARTICULO A MODIFICAR: ";
    cin>>codigo;

    int pos=buscarArticulo(reg,codigo);
    if(pos<0){
            return modifico;
    }


    cout<<"INGRESE EL NUEVO VALOR DEL PRECIO: ";
    cin>>pu;


    reg=leerRegistro(pos);
    reg.setPrecioUnitario(pu);

    modifico=modificarEnDisco(reg, pos);
    modifico=true;
    return modifico;

}



bool eliminar(articulo reg){
    int id;
    bool escribio=false;
    FILE *pArticulo;
    pArticulo=fopen("articulos.dat", "rb+");

    if(pArticulo==NULL){return -2;}

    cout<<"INGRESE EL ID DEL ARTICULO QUE QUIERE ELIMINAR: ";
    cin>>id;

    while(fread(&reg,sizeof reg,1,pArticulo)==1){
            if(reg.getIdArticulo()==id){

                reg.setEstado(false);
                cout<<"CAMBIO DE ESTADO"<<endl;

                escribio=fwrite(&reg,sizeof reg,1,pArticulo);
                cout<<escribio<<endl;
                system("pause");
                fclose(pArticulo);
                return escribio;


        }

    }
}

#endif
