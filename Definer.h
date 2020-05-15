#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

void seleccionar();
void metodo1(bool metodo, unsigned long long int semilla);
string leer_Txt(bool metodo, string text);
void text2bin(string texto,bool *cod);
void separacion(unsigned long long int semilla, bool *cod, unsigned long long int tam, bool codify);
unsigned short reglas(short *seg, bool *data, unsigned short regla, unsigned long long int semilla, bool codify);
string bin2text(string texto,bool *cod);
void escribir_Txt(string texto, bool metodo);
long long int tamano(char *name);
int mover(short *seg, unsigned long long int semilla, bool *data);
int moverdevuelta(short *seg,unsigned long long int semilla, bool *data);
string metodo2(bool metodo, unsigned long long int semilla, string text);
void separacion2(unsigned long long int semilla, bool *cod, unsigned long long int tam, bool metodo);
