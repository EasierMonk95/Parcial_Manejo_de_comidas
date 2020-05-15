#include "Menu_definer.h"

Admin::Admin(){

}

Admin::~Admin(){

}

void Admin::Menu(){
    string temp_key;
    bool truth=true, rather=false;
    int i=0, choice;
    cout<<"Coloque clave de administrador: ";
    cin>>password; //clave: 1000409965
    //cout<<endl<<password<<endl;
    temp_key = metodo2(0,4, "Admin_key.dat");
    cout<<temp_key<<endl;
    while(temp_key != password && i<3){
        cout<<"Clave incorrecta, pruebe nuevamente "<<i+1<<" de 3 intentos realizados: ";
        cin>>password;
        i++;
    }
    if(temp_key!=password)cout<<"Has excedido tus intentos. "<<endl<<endl;

    else{
       while(truth){
        cout<<endl<<"Administrador de inventario"<<endl;
        cout<<"1.Ingresar productos al inventario"<<endl;
        cout<<"2.Armar combos"<<endl;
        cout<<"3.Generar reporte de ventas"<<endl;
        cout<<"4.Ingresar nuevo usuario"<<endl;
        cout<<"5.Salir"<<endl;
        cin>>choice;
        switch(choice){

        case 1: AddProductos();
            break;

        case 2: MakeCombos();
            break;

        case 3: GenerarVentas();
            break;

        case 4: RegistrarUser();
            break;

        case 5: cout<<"Volviendo al menu inicial"<<endl<<endl;
            truth=false;
            break;

        default: cout<<"Opcion invalida, prueba nuevamente. "<<endl;
            break;
              }
            }

    }
}

void Admin::AddProductos(){

}

void Admin :: MakeCombos(){}
void Admin :: GenerarVentas(){}
void Admin :: RegistrarUser(){}

