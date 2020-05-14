#include "Menu_definer.h"


User::User(){

}

User::~User(){

}

void User::Menu(){
    cout<<"Menu de Usuario"<<endl;
    //Usuarios[cedula]=password;
    string temp_key;
    bool truth=true;
    int i, choice;
    cout<<"Coloque clave de usuario: ";
    cin>>password; //clave: 1000409965
    //cout<<endl<<password<<endl;
    temp_key = metodo2(0,4, "User_key.dat");
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
    //Mostrar los combos disponibles
        }
    }
