#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED
int buscarCliente(int codigo){
    cliente reg;
    int pos=0;
    FILE *pCliente;
    pCliente=fopen("clientes.dat", "rb");

    if(pCliente==NULL){return -2;}

    while(fread(&reg,sizeof reg,1,pCliente)==1){
        if(reg.getDni()==codigo){
         fclose(pCliente);
         return pos;
        }
        pos++;
    }
    fclose(pCliente);
    return -1;
}

bool addCliente(cliente reg){
    int p;
    system("cls");
    reg.cargar();
    p=buscarCliente(reg.getDni());
    if(p<0){
        bool afirmativo=reg.grabarEnDisco();
        return afirmativo;
    }
    else{
        cout<<"EL DNI DEL CLIENTE YA EXISTE EN EL SISTEMA"<<endl;
    }

}

bool listarClienteXdni(cliente reg){
 system("cls");
 int codigo;
 bool cortar=false;

    FILE *pCliente;

    pCliente=fopen("clientes.dat", "rb");
    if(pCliente==NULL){return false;}
    cout<<"INGRESE EL DNI A BUSCAR :";
    cin>>codigo;
    while(fread(&reg,sizeof reg,1,pCliente)==1){
        if (reg.getDni()==codigo){
          reg.mostrar();
          cortar=true;
        }
    }
    fclose(pCliente);
    if(cortar==false){
        cout<<"NO SE ENCONTRO EL DNI"<<endl;
    }
    system("pause");
    system("cls");
    return true;

}

void listarClientes(cliente reg){
    system("cls");
    int pos=0;
    while(reg.leerEnDisco(pos++)){
        reg.mostrar();
        system("pause");
        system("cls");
    }
}

cliente leerClientes(int pos){
    cliente reg;
    FILE *pCliente;
    pCliente=fopen("clientes.dat", "rb");


    fseek(pCliente, pos*sizeof reg, 0);
    fread(&reg,sizeof reg,1,pCliente);
    fclose(pCliente);
    return reg;
}

bool modificarEnDisco(cliente reg, int pos){
    FILE *pCliente;

    pCliente=fopen("clientes.dat", "rb+");

    if(pCliente==NULL){return false;}

    fseek(pCliente,pos*sizeof reg, 0);
    bool escribio=fwrite(&reg, sizeof reg, 1, pCliente);
    fclose(pCliente);
    return escribio;
}

bool modificarEmail(cliente reg){
    system("cls");
    char email[30];
    int dni;
    bool modifico=false;

    cout<<"INGRESE EL DIA DEL CLIENTE A MODIFICAR: ";
    cin>>dni;

    int pos=buscarCliente(dni);
    if(pos<0){
            return modifico;
    }


    cout<<"INGRESE EL NUEVO VALOR EMAIL: ";
    cin>>email;


    reg=leerClientes(pos);
    reg.setEmail(email);

    modifico=modificarEnDisco(reg, pos);
    modifico=true;
    return modifico;
}

#endif // ARCHIVOCLIENTE_H_INCLUDED
