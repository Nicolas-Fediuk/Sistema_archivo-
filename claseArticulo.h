#ifndef CLASEARTICULO_H_INCLUDED
#define CLASEARTICULO_H_INCLUDED

class articulo{
private:
    int c=0;
    int idArticulo,stock;
    char descripcion[25];
    float precioUnitario;
    bool estado;
public:
    void setIdArticulo(int x){idArticulo=x;}
    void setDescripcion(const char *v){strcpy(descripcion,v);}
    void setPrecioUnitario(float x){if (x>0)precioUnitario=x;}
    void setStock(int x){stock=x;}
    void setEstado (bool x){estado=x;}

    int getIdArticulo(){return idArticulo;}
    const char *getDescripcion(){return descripcion;}
    float getPrecioUnitario(){return precioUnitario;}
    int getStock(){return stock;}
    bool getEstado(){return estado;}

    void cargar(){
        int x=-1;
        cout<<"INGRESE EL CODIGO: ";
        cin>>idArticulo;
        cout<<"INGRESE LA DESCRIPCION: ";
        cin>>descripcion;
        while(x<=0){
        cout<<"INGRESE EL PRECIO UNITARIO: ";
        cin>>x;
        if (x<=0)cout<<"INGRESE UN NUMERO POSITIVO"<<endl;
        }
        setPrecioUnitario(x);
        cout<<"INGRESE EL STOCK: ";
        cin>>stock;
        estado=true;
        cout<<endl;
    }
    void mostrar(){
        if (estado==true){
        cout<<"CODIGO: "<<idArticulo<<endl;
        cout<<"DESCRIPCION: "<<descripcion<<endl;
        cout<<"PRECIO UNITARIO: "<<precioUnitario<<endl;
        cout<<"STOCK: "<<stock<<endl;
        cout<<endl;
        }
    }
    bool grabarEnDisco();
    bool leerEnDisco(int pos);
};
bool articulo::grabarEnDisco(){
    FILE *pArticulo;
    bool escribio;
    pArticulo=fopen("articulos.dat","ab");
    if(pArticulo==NULL){return false;}
    escribio=fwrite(this,sizeof(articulo),1,pArticulo);
    fclose(pArticulo);
    return escribio;
}
bool articulo::leerEnDisco(int pos){
    FILE *pArticulo;

    pArticulo=fopen("articulos.dat","rb");

    if(pArticulo==NULL){return false;}

    fseek(pArticulo,pos*sizeof(articulo),0);
    bool leyo=fread(this,sizeof(articulo),1,pArticulo);

    fclose(pArticulo);
    return leyo;
}

bool addArticulo(articulo reg);
bool listarXid(articulo reg);
void listarArticulo(articulo reg);
int buscarArticulo(int codigo);
bool modificarPu(articulo reg);
bool eliminar(articulo reg);

void claseArticulo(){
int opc;
articulo obj;

while(true){
    system("cls");
    cout<<"MENU ARTICULO"<<endl;
    cout<<"------------------"<<endl;
    cout<<endl;
    cout<<"1) AGREGAR ARTICULO"<<endl;
    cout<<"2) LISTAR ARTICULO POR ID"<<endl;
    cout<<"3) LISTAR TODOS LOS ARTICULOS"<<endl;
    cout<<"4) MODIFICAR PRECIO ARTICULO"<<endl;
    cout<<"5) ELIMINAR ARTICULO"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
    cout<<endl;
    cout<<"OPCION: ";
    cin>>opc;
    switch(opc){

        case 1:if(addArticulo(obj)==false){
                       cout<<"ERROR DE ARCHIVO"<<endl;
                    }
                    else{
                       cout<<"REGISTRO AGREGADO"<<endl;
                    }
                    system("pause");
            break;
        case 2:if (listarXid(obj)==false){
                cout<<"ERROR AL LISTAR EL ARTICULO"<<endl;
                system("pause");
                }
            break;
        case 3:listarArticulo(obj);
            break;
       case 4:if(modificarPu(obj)==false){
                cout<<"ID ARTICULO NO EXISTENTE"<<endl;
                }
                else{
                    cout<<"PRECIO MODIFICADO"<<endl;
                }
                system("pause");
            break;
        case 5:eliminar(obj);
            break;
        case 0:return;
            break;
    }
    system("pause");
    system("cls");
}



}







#endif // CLASEARTICULO_H_INCLUDED
