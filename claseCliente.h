#ifndef CLASECLIENTE_H_INCLUDED
#define CLASECLIENTE_H_INCLUDED
class fecha{
private:
    int dia,mes,anio;
public:
    fecha(int d=0, int m=0, int a=0){
        dia=d;
        mes=m;
        anio=a;
    }
    void setDia(int x){if(x>0 && x<32)dia=x;}
    void setMes(int x){if(x>0 && x<13)mes=x;}
    void setAnio(int x){if(x>1900)anio=x;}

    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void cargar(){
    int d=-1, m=-1,a=-1;
     while(d<1 || d>31){
     cout<<"INGRESE EL DIA: ";
     cin>>d;
     if(d<1 || d>31)cout<<"INGRESE UN DIA VALIDO"<<endl;
     }
     setDia(d);
     while(m<1 || m>13){
     cout<<"INGRESE EL MES: ";
     cin>>m;
     if (m<1 || m>13)cout<<"INGRESE UN MES VALIDO"<<endl;
     }
     setMes(m);
     while(a<1990){
     cout<<"INGRESE EL ANIO: ";
     cin>>a;
     if(a<1990)cout<<"INGRESE UN ANIO A PARTIR DE 1990"<<endl;
     }
     setAnio(a);
    }
    void mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }

};
    class cliente{
    private:
        int dni;
        char nombre[25];
        char apellido[25];
        char email [30];
        fecha fechaIncorporacion;
        char telefono[20];
    public:
        void setDni(int x){dni=x;}
        void setNombre(const char *v){strcpy(nombre,v);}
        void setApellido(const char *v){strcpy(apellido,v);}
        void setEmail(const char *v){strcpy(email,v);}
        void setTelefono(const char *v){strcpy(telefono,v);}
        void setFechaIncorporacion(fecha f){fechaIncorporacion=f;}

        int getDni(){return dni;}
        const char *getNombre(){return nombre;}
        const char *getApellido(){return apellido;}
        const char *getEmail(){return email;}
        const char *getTelefono(){return telefono;}
        fecha getFechaIncorporacion(){return fechaIncorporacion;}

        void cargar(){
         cout<<"INGRESE EL DNI: ";
          cin>>dni;
          cout<<"INGRESE EL NOMBRE DEL CLIENTE: ";
          cin>>nombre;
          cout<<"INGRESE EL APELLIDO DEL CLIENTE: ";
          cin>>apellido;
          cout<<"INGRESE EL EMAIL DEL CLIENTE: ";
          cin>>email;
          cout<<"INGRESE LA FECHA DE NACIMIENTO DEL CLIENTE:"<<endl;
          fechaIncorporacion.cargar();
          cout<<"INGRESE EL NUMERO DE TELEFONO/CELULAR DEL CLIENTE: ";
          cin>>telefono;
        }
        void mostrar(){
            cout<<"DNI: "<<dni<<endl;
            cout<<"NOMBRE: "<<nombre<<endl;
            cout<<"APELLIDO: "<<apellido<<endl;
            cout<<"EMAIL: "<<email<<endl;
            cout<<"FECHA DE NACIMIENTO"<<endl;
            fechaIncorporacion.mostrar();
            cout<<"TELEFONO/CELULAR: "<<telefono<<endl;

        }
        bool grabarEnDisco();
        bool leerEnDisco(int pos);
    };
    bool cliente::grabarEnDisco(){
    FILE *pCliente;
    bool escribio;
    pCliente=fopen("clientes.dat","ab");
    if (pCliente==NULL){return false;}
    escribio=fwrite(this,sizeof(cliente),1,pCliente);
    fclose(pCliente);
    return escribio;
}
bool cliente::leerEnDisco(int pos){
    FILE *pCliente;

    pCliente=fopen("clientes.dat","rb");

    if(pCliente==NULL){return false;}

    fseek(pCliente,pos*sizeof(cliente),0);
    bool leyo=fread(this,sizeof(cliente),1,pCliente);

    fclose(pCliente);
    return leyo;
}

    bool addCliente(cliente reg);
    bool listarClienteXdni(cliente reg);
    void listarClientes(cliente reg);
    int buscarCliente(int codigo);
    bool modificarEmail(cliente reg);

    void claseCliente(){
    int opc;
    cliente obj;
    while(true){
        system("cls");
        cout<<"MENU CLIENTE"<<endl;
        cout<<"------------------"<<endl;
        cout<<endl;
        cout<<"1) AGREGAR CLIENTE"<<endl;
        cout<<"2) LISTAR CLIENTE POR DNI"<<endl;
        cout<<"3) LISTAR TODOS LOS CLIENTES"<<endl;
        cout<<"4) MODIFICAR EMAIL"<<endl;
        cout<<"5) ELIMINAR CLIENTE"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        switch(opc){
          case 1: if(addCliente(obj)==false){
                    cout<<"ERROR DE ARCHIVO"<<endl;
                    }
                    else{
                        cout<<"CLIENTE AGREGADO"<<endl;
                    }
                    system("pause");
                break;
            case 2: if(listarClienteXdni(obj)==false){
                    cout<<"ERROR DE ARCHIVO"<<endl;
                    }
                    system("puase");
                break;
            case 3: listarClientes(obj);
                break;
            case 4:if (modificarEmail(obj)==false){
                    cout<<"EL DNI NO EXISTE"<<endl;
                    }
                    else{
                        cout<<"EMAIL CAMBIADO CON EXITO"<<endl;
                    }
                break;
            /*case 5: eliminar();
                break;*/
            case 0:return;
                break;
        }
        system("puase");
        system("cls");
    }


}


#endif // CLASECLIENTE_H_INCLUDED
