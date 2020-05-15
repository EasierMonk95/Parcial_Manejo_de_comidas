#include "Definer.h"

struct Info_Producto
{   string nombre;  //nombre del producto
    string unidad;  //unidad de medida del producto, ejemplo ml para gaseosa, unds para cantidad que trae un paquete
    int cant_unidad; //cantidad que trae un producto, ejemplo el paquete trae 6 unidades
    int cant_unidad_variable; //cantidad que esta disponible del producto por paquete o unidad de medida despues de
                              //la venta. Cuando se vende la cant_unidad disminuye en uno la cant_total de productos
                              //del inventario
    int cant_total; //cantidad total de paquetes del producto en el inventario
    int valor; //Precio Total

    Info_Producto( ); //Constructor
    void Set_Info_Producto(string ,string , int , int , int ); //funcion para asignar valores
};
typedef struct Info_Producto Producto;

struct Info_Combo
{   string nombre;  //nombre del producto
    int valor; //Precio Total
    int cantidad_total_ingredientes; //cantidad total de  ingredientes en el combo.
    map<int , int > cantidad_producto; //cantidad total de por cada producto.
                                      //La clave del mapa es el ID en inventario de cada producto


    Info_Combo( ); //Constructor
    void Set_Combo(string , int, int, int *, int * ); //función para asignar valores
};
typedef struct Info_Combo Combo;


class Inventario{
public:
   Inventario(); // Constructor
   ~Inventario(); // Destructor
   void Inventario_File_Reader(string ); //Funcion para leer la base de datos de inventario de un archivo.
   void Adicionar_Producto(int, Producto);//Clave Id del producto y Producto para adicionar
   void Eliminar_Producto(int);
   Producto Retornar_Producto(int ); //Clave Id del producto a retornar
   int Retorna_Total_Productos(); //Total de productos
   void Mostrar_Productos_Disponibles(); //Productos disponibles
   void Agregar_Cantidad_Producto(int , int ); //Aumentar cantidad de un producto
   int Disminuir_Cantidad_Producto(int , int ); //Disminuir cantidad de un producto
   void Inventario_File_Writer(string filename); //Esta funcion escribe en el archivo el inventario actual
   void Adicionar_Combo(int ,Combo ); //Clave Id del combo y Combo para adicionar
   void Eliminar_Combo(int ); //Clave Id del combo a eliminar
   void Mostrar_Combos_Disponibles();
   void Combo_File_Writer(string );
   void Combo_File_Reader(string ); //Función para leer la base de datos de combos de un archivo.
   int Retorna_Total_Combos(); //Total de combos
  //int Disminuir_Cantidad_combo(int , int ); //Disminuir cantidad de un producto por venta de combo
private:
   map<int , Producto > Productos; //Clave Id del producto y Producto como la estructura
   map<int , Combo > Combos; //Clave Id del Combo y combo como la estructura creada
   int Total_Productos;
   int Total_Combos;
   };


class Admin{
public:
   Admin(); // Constructor
   ~Admin(); // Destructor
   void Menu();
private:
    string password;
    Inventario Var_Inventario;
    void AddProductos();
    void MakeCombos();
    void GenerarVentas();
    void RegistrarUser();
};


class User{
public:
   User(); // Constructor
   ~User(); // Destructor
   void Menu();
   int verificar_usuario(int CC, string clave);
   void User_File_Reader(string filename);
   void Registrar_Usuario(int Cedula, string password);
   void User_File_writer(string filename);
private:  
   //string password;
   map<int, string > Usuarios;
};


