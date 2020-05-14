#include "Definer.h"
class Admin{
public:
   Admin(); // Constructor
   ~Admin(); // Destructor
   void Menu();
private:
    string password;
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
