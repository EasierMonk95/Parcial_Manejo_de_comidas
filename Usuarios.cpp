#include "Menu_definer.h"


User::User(){

}

User::~User(){

}

void User::Menu(){
    int resultado, carnet,recibe;
    string password;
    cout<<endl<<"1.Registrarse como usuario"<<endl<<"2.Entrar como usuario ya registrado"<<endl;
    cin>>recibe;
    switch (recibe) {

    case 1:
       cout<<"Coloque su cedula: ";
       cin>>carnet;
       cout<<"Coloque la contraseña que desee: ";
       cin>>password;
       resultado = verificar_usuario(carnet, password);
       while(resultado!=-1){
           cout<<"La cedula o contraseña ya han sido usadas."<<endl;
           cout<<endl<<"Coloque su cedula: ";
           cin>>carnet;
           cout<<"Coloque la contraseña que desee: ";
           cin>>password;
           resultado = verificar_usuario(carnet, password);
       }
       Registrar_Usuario(carnet,password);
       User_File_writer("User_key.dat");
    break;

     case 2:
        User_File_Reader("User_key.dat");
        cout<<"Menu de Usuario"<<endl;
        //Usuarios[cedula]=password;
        int i=0;
        cout<<"Coloque su cedula: ";
        cin>>carnet;
        cout<<endl<<"Coloque clave de usuario: ";
        cin>>password;
        //cout<<endl<<password<<endl;
        resultado= verificar_usuario(carnet,password);
        while(resultado==-1 && i<3){
            cout<<"Clave incorrecta, pruebe nuevamente "<<i+1<<" de 3 intentos realizados: ";
            cin>>password;
            i++;
        }
        if(resultado==-1)cout<<"Has excedido tus intentos. "<<endl<<endl;
        else{

            }
        break;
          }
    }


void User::User_File_Reader(string filename){
    ifstream FileIn(filename.c_str(), ios::in);
    string password;
    int Cedula;

  if ( FileIn.is_open() ){
    while (!FileIn.eof()){
       FileIn>>Cedula;
       FileIn>>password;

       Usuarios[Cedula] = password; //Inserta el password en el mapa, usando como clave la cédula
    }
    FileIn.close();
  } else {
           cout<<"Error de apertura del archivo."<<endl;
        }
}

int User::verificar_usuario(int CC, string clave){
    string Cod_clave;
    map<int, string >::iterator iter;
    int Ok = -1; //-1 Usuario o clave invalidos y 1 Usuario valido


    Cod_clave = metodo2mod(0,4,clave);
    iter = Usuarios.find(CC);
    if (iter != Usuarios.end()){
        if (iter->second != Cod_clave){
            Ok = 1;
            cout<<"Clave correcta"<<endl;
        }
    }
    return Ok;
}

void User::Registrar_Usuario(int Cedula, string password){
  string Cod_clave;
  map<int, string > :: iterator iter;

  iter = Usuarios.find(Cedula);
  if(iter == Usuarios.end()){
    Cod_clave = metodo2mod(1,4,password);
    Usuarios[Cedula] = Cod_clave; //Inserta el password en el mapa, usando como clave la cédula
  } else {
        cout<<"El usuario ya esta registrado"<<endl;
   }
}

void User::User_File_writer(string filename){
    ofstream FileOut(filename.c_str(), ios::out);
    string password;
    map<int, string > :: iterator iter;

  if ( FileOut.is_open() ){
    for(iter = Usuarios.begin(); iter != Usuarios.end(); iter++){
       FileOut<<iter->first<<"\t"<<iter->second<<endl; //Cedula y password
    }
    FileOut.close();
   }
  else {
      cout<<"Error de apertura del archivo."<<endl;
    }
}
