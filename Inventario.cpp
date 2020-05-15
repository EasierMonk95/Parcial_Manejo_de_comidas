#include "Menu_definer.h"

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

// Constructor: Inicializacion basica
Inventario::Inventario(){
    Total_Productos = 0;
    Productos = {};
}

// Destructor: Libera memoria
Inventario::~Inventario(){
   if (Productos.size() != 0) Productos.clear();
   Total_Productos = 0;
   Productos = {};
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
    cout<<"Ingreso la funcion"<<endl;
    ifstream FileIn(filename.c_str(), ios::in);
    string str, str_producto, str_unidad;
    int i = 0, var, ID_producto, cant_unidad, cant_total, valor;
    Producto var_producto;

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
       cout<<str_producto<<" por "<<cant_unidad<<" "<<str_unidad<<" "<<cant_total<<" $"<<valor<<endl;
       var_producto.Set_Info_Producto(str_producto,str_unidad,cant_unidad,cant_total,valor);

       Productos[ID_producto] = var_producto; //Inserta el producto en el mapa, usando como clave ID_Producto

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
