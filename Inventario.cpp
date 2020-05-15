#include "Menu_definer.h"

// Definición del constructor, fuera de la estructura. Inicialización básica
Info_Combo::Info_Combo( ){
    nombre = " ";
    valor = 0;
}

// Definición de función para asignar producto y precio con la estructura combo
void Info_Combo::Set_Combo(string str_producto, int precio, int n_ing, int *ID, int *IDC){
    int i=0, cont = 0;
    nombre = str_producto;
    valor = precio;
    cantidad_total_ingredientes = n_ing;
    while (cont<n_ing){
       cantidad_producto[ID[i]] = IDC[i];
       cont = cont + IDC[i];
       i++;
    }
}

//Funcion que adiciona un combo nuevo al mapa
void Inventario::Adicionar_Combo(int ID, Combo var_combo){
    map<int ,Combo >::iterator iter;

    iter = Combos.find(ID);
    if(iter == Combos.end()){
        Combos[ID] = var_combo;
        Total_Combos++;
    } else {
        cout<<"Combo no adicionado, el ID se encuentra asignado"<<endl;
    }
}

//Funcion que elimina un combo del mapa
void Inventario::Eliminar_Combo(int ID){
    map<int ,Combo >::iterator iter;

    iter = Combos.find(ID);
    if(iter != Combos.end()){
        Combos.erase(ID);
        Total_Combos--;
    } else {
        cout<<"Combo no encontrado"<<endl;
    }
}

//Lista en pantalla los combos disponibles
void Inventario::Mostrar_Combos_Disponibles(){
    map<int ,Combo >::iterator iter;
    Combo var_combo;

    for(iter=Combos.begin(); iter!=Combos.end(); iter++){
        var_combo = iter->second;
        cout<<"Combo"<<iter->first<<" : "<<var_combo.nombre<<" $"<<var_combo.valor<<endl;
    }

}

// Constructor: Inicialización básica
Inventario::Inventario(){
    Total_Productos = 0;
    Total_Combos = 0;
    Productos = {};
    Combos = {};
}

// Destructor: Libera memoria
Inventario::~Inventario(){
   if (Productos.size() != 0) Productos.clear();
   if (Combos.size() != 0) Combos.clear();
   Total_Productos = 0;
   Total_Combos = 0;
   Productos = {};
   Combos = {};
}

// Definicion del constructor, fuera de la estructura. Inicializacion basica
Info_Producto::Info_Producto(){
    nombre = " ";
    unidad = " ";
    cant_unidad = 0;
    cant_unidad_variable = 0;
    cant_total = 0;
    valor = 0;
}

// Definicion de funcion para asignar valores e variable con la estructura producto
void Info_Producto::Set_Info_Producto(string str_producto,string str_unidad, int cant_u, int cant_t, int precio){
    nombre = str_producto;
    unidad = str_unidad;
    cant_unidad = cant_u;
    cant_unidad_variable = cant_unidad;
    cant_total = cant_t;
    valor = precio;
}


//Funcion que adiciona un producto nuevo al mapa
void Inventario::Adicionar_Producto(int ID, Producto var_producto){
    Productos[ID] = var_producto;
    Total_Productos++;
}

//Funcion que elimina un producto del mapa
void Inventario::Eliminar_Producto(int ID){
    map<int ,Producto >::iterator iter;

    iter = Productos.find(ID);
    if(iter != Productos.end()){
        Productos.erase(ID);
        Total_Productos--;
    } else {
        cout<<"Producto no encontrado"<<endl;
    }
}

//Funcion que retorna el producto con clave ID del mapa
Producto Inventario::Retornar_Producto(int ID){
    return Productos[ID];
}

//Funcion que retorna el total de productos en el mapa
int Inventario::Retorna_Total_Productos(){
    return Total_Productos;
}

//Lista en pantalla los productos disponibles
void Inventario::Mostrar_Productos_Disponibles(){
    map<int ,Producto >::iterator iter;
      Producto var_producto;
    for(iter=Productos.begin();iter!=Productos.end();iter++){
        var_producto=iter->second;
        cout<<iter->first<<" "<<var_producto.nombre<<" "<<var_producto.cant_unidad_variable<<endl;
    }

}




/*Esta funcion lee el archivo inventario y asigna cada producto al mapa de la clase inventario.
El formato del archivo es:
ID Producto ; Cantidad_Unitaria_Producto Unidad_Medida Cantidad_Total_Producto Valor_Producto
Para la base de dados del ejemplo de inventario dado el archivo es:
1 Vasos Plasticos de 9oz ; 9 Unds 7 84000
2 Paquete de Pan Perro ; 6 Unds 7 18550
3 Salchicha para Perro ; 20 Unds 3 37500
4 Paquete de Carne para Hamburguesa ; 4 Unds 4 46200
5 Bolsa de Salsa Roja ; 150 ml 3 21600*/
void Inventario::Inventario_File_Reader(string filename){
    ifstream FileIn(filename.c_str(), ios::in);
    string str, str_producto, str_unidad;
    int i = 0, var, ID_producto, cant_unidad, cant_total, valor;
    Producto var_producto;
    map<int , Producto >::iterator iter;

  if ( FileIn.is_open() ){
    while (!FileIn.eof()){
       FileIn>>ID_producto;
       FileIn>>str;
       str_producto = str;
       FileIn>>str;
       while (str != ";"){
          str_producto = str_producto + " ";
          str_producto = str_producto + str;
          FileIn>>str;
       }
       FileIn>>cant_unidad;
       FileIn>>str_unidad;
       FileIn>>cant_total;
       FileIn>>valor;

       var_producto.Set_Info_Producto(str_producto,str_unidad,cant_unidad,cant_total,valor);

       iter = Productos.find(ID_producto); //La clave solo se inserta una vez, si se insero previamente ignora el nuevo producto
       if ( iter == Productos.end()){
                 Productos[ID_producto] = var_producto; //Inserta el producto en el mapa, usando como clave ID_Producto
                 i++;
                 Total_Productos = i;
              }
       //cout<<"Id = "<<ID_producto<<", "<<str_producto<<" por "<<cant_unidad<<" "<<str_unidad<<" "<<cant_total<<" $"<<valor<<endl;
    }
    FileIn.close();
  } else {
           cout<<"Error de apertura del archivo."<<endl;
        }
}

//Funcion que aumenta la cantidad total de un producto, agregando la nueva cantidad adquirida del producto
void Inventario::Agregar_Cantidad_Producto(int ID, int cant_total){
    map<int ,Producto >::iterator iter;
    Producto var_producto;

    iter = Productos.find(ID);
    if(iter != Productos.end()){
        var_producto = iter->second;
        var_producto.cant_total = var_producto.cant_total + cant_total;
        iter->second = var_producto;
    } else {
        cout<<"El ID no se encuentra asignado a ningun producto"<<endl;
    }
}

//Funcion que reduce la cantidad de un producto. Retorna -1 sino hay producto disponible o no existe, y 1 en caso contrario
int Inventario::Disminuir_Cantidad_Producto(int ID, int cant_disminuir){
    map<int ,Producto >::iterator iter;
    Producto var_producto;
    int dis = -1;

    iter = Productos.find(ID);
    if(iter != Productos.end()){
        var_producto = iter->second;
        if (var_producto.cant_unidad_variable > cant_disminuir){
            var_producto.cant_unidad_variable = var_producto.cant_unidad_variable - cant_disminuir;
            iter->second = var_producto;
        } else {
            if (var_producto.cant_unidad_variable == cant_disminuir){
                if (var_producto.cant_total > 1){ //Todavia hay existencia del producto para una siguiente venta
                   var_producto.cant_unidad_variable = var_producto.cant_unidad;
                   var_producto.cant_total = var_producto.cant_total - 1;
                   dis = 1;
                } else {
                   var_producto.cant_unidad_variable = 0;
                   var_producto.cant_total = 0;
                   dis = 1;
                   cout<<"Advertencia el producto "<<var_producto.nombre<<" se ha agotado. "<<endl;
                }
            } else {
                int factor;
                factor = cant_disminuir/var_producto.cant_unidad;
                if (factor < var_producto.cant_total) {
                    var_producto.cant_unidad_variable = var_producto.cant_unidad*factor - cant_disminuir +  var_producto.cant_unidad_variable;
                    var_producto.cant_total = var_producto.cant_total - factor;
                    dis = 1;
                } else {
                    cout<<"No disponible la cantidad del producto solicitada. El inventario actual es: "<<endl;
                    cout<<var_producto.nombre<<" por "<<var_producto.cant_unidad<<" "<<var_producto.unidad;
                    cout<<" y cantidad "<<var_producto.cant_total<<endl;
                }
            }
        }
    } else {
        cout<<"El ID no se encuentra asignado a ningun producto"<<endl;
    }
    return dis;
}

void Inventario::Inventario_File_Writer(string filename){
    ofstream FileOut(filename.c_str(), ios::out);
    Producto var_producto;
    map<int , Producto >::iterator iter;

  if ( FileOut.is_open() ){
    for(iter = Productos.begin(); iter != Productos.end(); iter++){
       var_producto = iter->second;
       FileOut<<iter->first<<"  "; //ID del producto
       FileOut<<var_producto.nombre<<" ; "; //Nombre o descripcion del producto
       FileOut<<var_producto.cant_unidad<<" "; //Cantidad por paquete o medida
       FileOut<<var_producto.unidad<<" "; //Unidad de medida
       FileOut<<var_producto.cant_total<<" "; //Cantidad disponible del producto
       FileOut<<var_producto.valor<<endl;  //Precio
    }
    FileOut.close();
  } else {
           cout<<"Error de apertura del archivo."<<endl;
        }
}

//Funcion que retorna el total de combos en el mapa
int Inventario::Retorna_Total_Combos(){
    return Total_Combos;
}

//Esta funcion escribe en el archivo los combos actuales
void Inventario::Combo_File_Writer(string filename){
    ofstream FileOut(filename.c_str(), ios::out);
    int i=0, cont=0;
    Combo var_combo;
    map<int , Combo >::iterator iter;
    map<int , int > mapa_CP; //mapa cantidad de productos
    map<int , int >::iterator iter_CP;

  if ( FileOut.is_open() ){
    for(iter = Combos.begin(); iter != Combos.end(); iter++){
       var_combo = iter->second;
       FileOut<<iter->first<<"  "; //ID del combo
       FileOut<<var_combo.nombre<<" ; "; //Nombre o descripcion del combo
       FileOut<<var_combo.valor<<" ";  //Precio
       FileOut<<var_combo.cantidad_total_ingredientes<<" "; //numero total de ingredientes
       cont = var_combo.cantidad_producto.size();
       mapa_CP = var_combo.cantidad_producto;
       for (iter_CP = mapa_CP.begin(); iter_CP != mapa_CP.end(); iter_CP++){
          FileOut<<iter_CP->first<<" "<<iter_CP->second;
       }
       FileOut<<endl;
    }
    FileOut.close();
  } else {
           cout<<"Error de apertura del archivo."<<endl;
        }
}


/*Esta función lee el archivo de Combo y asigna cada uno de estos al mapa de la clase inventario.
El formato del archivo es:
ID Combo ; Valor_Combo cantidad_total_ingredientes ID_producto1 cantidad_producto1 ID_producto2 cantidad_producto2 ... ID_productok cantidad_productok
Para la base de dados del ejemplo de inventario dado el archivo es:
1 Dos perros y dos gaseosas ; 35000
2 Dos gaseosas con nachos ; 17900
3 Hamburguesa mas gaseosa ; 16500
*/
void Inventario::Combo_File_Reader(string filename){
    ifstream FileIn(filename.c_str(), ios::in);
    string str, str_combo;
    int i = 0, var, ID_combo, valor, n_ing, cont = 0;
    Combo var_combo;
    map<int , Combo >::iterator iter;
    int *ID, *IDC;

  if ( FileIn.is_open() ){
    while (!FileIn.eof()){
       FileIn>>ID_combo;
       FileIn>>str;
       str_combo = str;
       FileIn>>str;
       while (str != ";"){
          str_combo = str_combo + " ";
          str_combo = str_combo + str;
          FileIn>>str;
       }
       FileIn>>valor;
       FileIn>>n_ing;
       ID = new int [n_ing];
       IDC = new int [n_ing];
       i = 0;
       cont=0;
       while(cont<n_ing){
          FileIn>>ID[i];
          FileIn>>IDC[i];
          cont = cont + IDC[i];
          i++;
       }
       var_combo.Set_Combo(str_combo,valor,n_ing,ID,IDC);

       iter = Combos.find(ID_combo); //La clave solo se inserta una vez, si se inserto previamente ignora ese combo
       if ( iter == Combos.end()){
          Combos[ID_combo] = var_combo; //Inserta el combo en el mapa, usando como clave ID_Combo
          i++;
          Total_Combos = i;
       }
    }
    FileIn.close();
  } else {
           cout<<"Error de apertura del archivo."<<endl;
        }
}

/*int main(){
   Inventario var_inventario;
   string fileInventario;
   fileInventario = "Info_Inventario.txt";

   var_inventario.Inventario_File_Reader(fileInventario);*/

   /*string prueba1, prueba2;
   cout<<"Total lineas "<<Total_Lines_File(fileInventario)<<endl;
   cout<<"Total de caracteres "<<Total_String_Line_File(fileInventario, 2)<<" en la linea 2"<<endl;
   cout<<"Total de caracteres "<<Total_String_Line_File(fileInventario, 6)<<" en la linea 6"<<endl;
   cout<<"Total de caracteres "<<Total_String_Line_File(fileInventario, 7)<<" en la linea 7"<<endl;
   prueba1 = "Prueba para verificar si se inserta totalmente bien";
   Insert_Line_File(fileInventario, 3, prueba1);
   prueba2 = "Inserta en el final del archivo";
   Insert_Line_File(fileInventario, Total_Lines_File(fileInventario)+1, prueba2);*/


/*    std::string str = "Hello Casa Tia";
    std::istringstream in(str);
    std::string word;
    in >> word;
    cout<<word<<endl;
    std::cout << "After reading the word \"" << word
              << "\" tellg() returns " << in.tellg() << '\n';*/

/*    cout<<prueba1<<" -> Tiene "<<prueba1.length()<<" caracteres"<<endl;
    prueba1 = prueba1 + 'c';
    prueba1 = prueba1 + ' ';
    prueba1 = prueba1 + 'a';
    cout<<prueba1<<" -> Tiene "<<prueba1.length()<<" caracteres"<<endl;  */
//}
