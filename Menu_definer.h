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

class Inventario{
public:
   Inventario(); // Constructor
   ~Inventario(); // Destructor
   void Inventario_File_Reader(string ); //Funci�n para leer la base de datos de inventario de un archivo.
   void Adicionar_Producto( );
private:
    map<int , Producto > Productos; //Clave Id del producto y Producto como la estructura
    int Total_Productos;
};

class Admin{
public:
   Admin(); // Constructor
   ~Admin(); // Destructor
   void Menu();
private:
    string password;
    Inventario Var_Productos;
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
private:
   string password;

 map<int, string > Usuarios;
};
