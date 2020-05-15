#include "Menu_definer.h"

Admin::Admin(){
   cant_ventas = 0;
}

Admin::~Admin(){
   cant_ventas = 0;
}

//Funcion en la cual se muestran las opciones del menu y son los accesos directos a cada funcion de inventario
void Admin::Menu(){
    string temp_key;
    bool truth=true;
    int i=0, choice;
    Var_Inventario.Inventario_File_Reader("Info_Inventario.txt");
    Var_Inventario.Combo_File_Reader("Info_Combo.txt");
    cout<<"Coloque clave de administrador: ";
    cin>>password; //clave: 1000409965
    //cout<<endl<<password<<endl;
    temp_key = metodo2(0,4, "Admin_key.dat");
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
        cout<<"4.Salir"<<endl;
        cin>>choice;
        switch(choice){

        case 1: AddProductos();
            break;

        case 2: MakeCombos();
            break;

        case 3: //GenerarVentas();
            break;

        case 4: cout<<"Volviendo al menu inicial"<<endl<<endl;
            truth=false;
            break;

        default: cout<<"Opcion invalida, prueba nuevamente. "<<endl;
            break;
              }
            }

    }
}

//Funcion que permite agregar productos
void Admin::AddProductos(){
    string str, str_producto, str_unidad;
    int  ID_producto, cant_unidad, cant_total, valor, opcion;
    Producto var_producto;
    map<int ,Producto >::iterator iter;

    cout<<endl<<"1. Agregar nuevo producto "<<endl;
    cout<<"2. Agregar mayor cantidad en producto existente "<<endl;
    cout<<"3. Listar Productos disponibles "<<endl;
    cout<<"4. Salir "<<endl;
    cin>>opcion;

    switch(opcion){
      case 1: cout<<"Ingrese nombre del producto: ";
       cin.ignore();
       getline(cin,str_producto);
       cout<<"Ingrese cantidad por paquete o medida: ";
       cin>>cant_unidad;
       cout<<"Ingrese unidad de medida (unds, ml): ";
       cin>>str_unidad;
       cout<<"Ingrese la cantidad total comprada del producto: ";
       cin>>cant_total;
       cout<<"Ingrese el costo: ";
       cin>>valor;
       var_producto.Set_Info_Producto(str_producto,str_unidad,cant_unidad,cant_total,valor);
       ID_producto = Var_Inventario.Retorna_Total_Productos() + 1;
       Var_Inventario.Adicionar_Producto(ID_producto, var_producto);
       Var_Inventario.Inventario_File_Writer("Info_Inventario.txt");
       break;

       case 2:
           cout<<"Ingrese el ID del producto a ingresar: ";
           cin>>ID_producto;
           cout<<"Ingrese la cantidad a adicionar del producto: ";
           cin>>cant_total;
           Var_Inventario.Agregar_Cantidad_Producto(ID_producto, cant_total);
           Var_Inventario.Inventario_File_Writer("Info_Inventario.txt");
       break;

       case 3:            
            Var_Inventario.Mostrar_Productos_Disponibles();

       break;

       case 4:

       break;

       default:
        cout<<"Opcion invalida, prueba nuevamente. "<<endl;
       break;

    }
}

void Admin::MakeCombos(){
    string str, str_combo;
    int  ID_combo, cant_unidad, valor, opcion, n_ing, i, cont = 0;
    Combo var_combo;
    map<int ,Combo >::iterator iter;
    int *ID, *IDC;

    cout<<endl<<"1. Agregar nuevo combo "<<endl;
    cout<<"2. Eliminar un combo existente "<<endl;
    cout<<"3. Listar combos disponibles "<<endl;
    cout<<"4. Salir "<<endl;
    cin>>opcion;

    switch(opcion){
      case 1: cout<<"Ingrese el nombre del combolos productos y cantidades del combo: ";
       cin>>str_combo;
       cout<<"Ingrese el costo del combo: ";
       cin>>valor;
       cout<<"Ingrese la cantidad total de ingredientes del combo del combo: ";
       cin>>n_ing;
       ID = new int [n_ing];
       IDC = new int [n_ing];

       i = 0;
       cont = 0;
       while(cont<n_ing){
          cout<<"Ingrese el ID del ingrediente o producto "<<i+1<<": ";
          cin>>ID[i];
          cout<<"Ingrese la cantidad necesaria de ese ingrediente: ";
          cin>>IDC[i];
          cont = cont + IDC[i];
          i++;
       }
       var_combo.Set_Combo(str_combo,valor,n_ing,ID,IDC);
       ID_combo = Var_Inventario.Retorna_Total_Combos() + 1;
       Var_Inventario.Adicionar_Combo(ID_combo, var_combo);

//       Var_Inventario.Combo_File_Writer("Info_Combo.txt");
       break;

       case 2:
           cout<<"Ingrese el ID del combo a eliminar: ";
           cin>>ID_combo;
           Var_Inventario.Eliminar_Combo(ID_combo);
//           Var_Inventario.Combo_File_Writer("Info_Combo.txt");
       break;

       case 3:
            Var_Inventario.Mostrar_Combos_Disponibles();

       break;

       case 4:

       break;

       default:
        cout<<"Opcion invalida, prueba nuevamente. "<<endl;
       break;

    }
}

