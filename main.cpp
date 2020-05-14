//Trabajo hecho por Simon Sanchez Rua
//Observar practica 3 para ver que puede ser usado
#include "Menu_definer.h"
#include "Codificador.cpp"
int main(){
    bool fake=false;
    Admin Var_Admin;
    User Var_User;
    int a;
    while(!fake){
      cout<<"Bienvenido al cinema Simon's"<<endl;
      cout<<"1. Ingresar como administrador"<<endl<<"2. Ingresar como usuario"<<endl<<"3. Salir"<<endl;
      cin>>a;
      switch(a){

      case 1: Var_Admin.Menu();
          break;

      case 2: Var_User.Menu();
          break;

      case 3: cout<<"Apagando sistema, las ventas de hoy fueron..."<<endl;
          fake=true;
          break;

      default: cout<<"Opcion invalida, prueba nuevamente. "<<endl;
      }
    }
    return 1;
}
