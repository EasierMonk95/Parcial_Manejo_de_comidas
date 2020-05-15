#include "Definer.h"

string metodo2(bool metodo, unsigned long long int semilla, string text){
    string texto;
    texto=leer_Txt(metodo,text);
    bool *cod= new bool [8*texto.length()];
    text2bin(texto,cod);
    separacion2(semilla,cod,8*texto.length(),metodo);
    texto=bin2text(texto,cod);
    escribir_Txt(texto,metodo);
    return texto;
}

string metodo2mod(bool metodo, unsigned long long int semilla, string texto){
    bool *cod= new bool [8*texto.length()];
    text2bin(texto,cod);
    separacion2(semilla,cod,8*texto.length(),metodo);
    texto=bin2text(texto,cod);
    escribir_Txt(texto,metodo);
    return texto;
}
string leer_Txt(bool metodo, string text){
    long long int tam;
    string texto;
    char s;
    /*if(metodo) text="Key_admin.txt";
    else text="Admin_key.dat";*/
    //cout<<"El nombre del archivo es: "<<text<<endl;
    /////////////////////////////Tamano
    fstream k(text, ios::in | ios::ate);
    tam=k.tellg();
    k.close();    
    //////////////////////////////////////
    fstream k1(text, ios::in | ios::binary);
    for(long long int i=0;i<tam;i++){
        k1.get(s);
        texto.push_back(s);
    }
    k1.close();
    return texto;
}

void text2bin(string texto,bool *cod){
    char s;
    for(unsigned long long int i=0; i<(texto.length()); i++){
        s=char(texto[i]);
        for(unsigned long long int j=0;j<8;j++) cod[8*i+j]=(((s<<j)&0x80)==0x80);
    }
}


string bin2text(string texto,bool *cod){
    int a,pot=1;
    for(unsigned long long int i=0; i<(texto.length()); i++){
        a=0;
        pot=1;
        for(unsigned long long int j=0;j<8;j++){
            a+=(cod[j+8*i]*128)/pot;
            pot*=2;
        }
        texto[i]=char(a);
    }

    return texto;
}

void escribir_Txt(string texto, bool metodo){
    string text;
    if(!metodo) text="Key_admin.txt";
    else text="Admin_key.dat";
    ofstream k2(text,  ios::out | ios::app);
    k2 << texto;
    k2.close();
}

void separacion2(unsigned long long int semilla, bool *cod, unsigned long long int tam, bool metodo){
  short *seg = new short[semilla];
  long long int j=0;
  unsigned short tp=0;
  for(unsigned long long int i=0;i<semilla;i++) seg[i]=-1;
  for(unsigned long long int i=0,l=0; i<tam; i++,j++){
      seg[j]=cod[i];
      if((i+1)%semilla==0 || i==(tam-1)){
      if(metodo==true) tp=mover(seg,semilla,&cod[semilla*l]);
      else tp=moverdevuelta(seg,semilla,&cod[semilla*l] );
      j=-1;
      l++;
  }}
  //cout<<endl;
}
int mover(short *seg, unsigned long long int semilla, bool *data){
    short aux=seg[semilla-1];
    for(unsigned long long int i=semilla-1; i>0;i--){
        seg[i]=seg[i-1];
        data[i]=seg[i];
        //cout<<data[i]<<" ";
    }
    data[0]=aux;
    return *seg;

}

int moverdevuelta(short *seg,unsigned long long int semilla, bool *data){
    short aux=seg[0];
    for(unsigned long long int i=0; i<semilla-1;i++){
        seg[i]=seg[i+1];
        data[i]=seg[i];
        //cout<<data[i]<<" ";
    }
    data[semilla-1]=aux;
    return *seg;
}
