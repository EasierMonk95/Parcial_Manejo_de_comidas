#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

string leer_Txt(bool metodo, string text);
void text2bin(string texto,bool *cod);
string bin2text(string texto,bool *cod);
void escribir_Txt(string texto, bool metodo);
long long int tamano(char *name);
int mover(short *seg, unsigned long long int semilla, bool *data);
int moverdevuelta(short *seg,unsigned long long int semilla, bool *data);
string metodo2(bool metodo, unsigned long long int semilla, string text);
string metodo2mod(bool metodo, unsigned long long int semilla, string text);
void separacion2(unsigned long long int semilla, bool *cod, unsigned long long int tam, bool metodo);
