#include "Menu_definer.h"

Admin::Admin(){

}

Admin::~Admin(){

}

void Admin::Menu(){
    string temp_key;
    bool truth=true;
    int i, choice;
    cout<<"Coloque clave de administrador: ";
    cin>>password; //clave: 1000409965
    //cout<<endl<<password<<endl;
    temp_key = metodo2(0,4, "Admin_key.dat");
    cout<<temp_key<<endl;
    if(temp_key != password){
    for(i=0;i<3;i++){
        if(temp_key != password){
            cout<<"Clave incorrecta, pruebe nuevamente "<<i+1<<" de 3 intentos realizados: ";
            cin>>password;
        }
    }
    if(i==3)cout<<"Has excedido tus intentos. "<<endl<<endl;
    }
    else{
       while(truth){
        cout<<endl<<"Administrador de inventario"<<endl;
        cout<<"1.Ingresar productos al inventario"<<endl;
        cout<<"2.Armar combos"<<endl;
        cout<<"3.Generar reporte de ventas"<<endl;
        cout<<"4.Ingresar nuevo usuario"<<endl;
        cout<<"5.Salir";
        cin>>choice;
        switch(choice){

        case 1: AddProductos();
            break;

        case 2: MakeCombos();
            break;

        case 3: GenerarVentas();

        case 4: RegistrarUser();

        case 5: cout<<"Volviendo al menu inicial"<<endl;
            truth=false;
            break;

        default: cout<<"Opcion invalida, prueba nuevamente. "<<endl;
              }
            }

    }
}

void Admin::AddProductos(){

}

void Admin :: MakeCombos(){}
void Admin :: GenerarVentas(){}
void Admin :: RegistrarUser(){}

