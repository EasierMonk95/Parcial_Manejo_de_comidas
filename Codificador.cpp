#include "Definer.h"


void seleccionar(){
    int m;
    unsigned long long int n;
    bool metodo;
    cout << "Ingrese un 1 para ejecutar el metodo 1, 2 para metodo 2 o aplicacion en otro caso: ";
    cin >> m;
    switch (m) {
        case 1:
            cout << "Ingrese 1 si desea codificar o 0 si desea decodificar: ";
            cin >> metodo;
            cout << "Ingrese la semilla: ";
            cin >> n;
            metodo1(metodo,n);
        break;

        case 2:
        cout << "Ingrese 1 si desea codificar o 0 si desea decodificar: ";
        cin >> metodo;
        cout << "Ingrese la semilla: ";
        cin >> n;
            //metodo2(metodo,n,);
        break;

        default:
            cout << "aplicacion" << endl;
            //aplicacion();
    }
}

void metodo1(bool metodo, unsigned long long int semilla){
    string texto;
    //texto=leer_Txt(metodo);
    bool *cod= new bool [8*texto.length()];
    text2bin(texto,cod);
    separacion(semilla,cod,8*texto.length(), metodo);
    texto=bin2text(texto,cod);
    escribir_Txt(texto,metodo);
//    for(unsigned long long int i=0; i<8*texto.length();i++){

//        cout << cod[i];
//        if((i+1)%8==0)      cout << endl;
//    }

}
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

string leer_Txt(bool metodo, string text){
    long long int tam;
    string texto;
    char s;
    /*if(metodo) text="Key_admin.txt";
    else text="Admin_key.dat";*/
    cout<<"El nombre del archivo es: "<<text<<endl;
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

void separacion(unsigned long long int semilla, bool *cod, unsigned long long int tam, bool codify){
  short *seg = new short[semilla];
  long long int j=0;
  unsigned short tp=0;
  for(unsigned long long int i=0;i<semilla;i++) seg[i]=-1;
  for(unsigned long long int i=0,l=0; i<tam; i++,j++){
      seg[j]=cod[i];
      if((i+1)%semilla==0 || i==(tam-1)){
          tp=reglas(seg,&cod[semilla*l],tp,semilla,codify);
          for(unsigned long long int k=0;k<semilla;k++) seg[k]=-1;
          l++;
          j=-1;
      }
  }
}

unsigned short reglas(short *seg, bool *data, unsigned short regla, unsigned long long int semilla, bool codify){
    int contador[2]={0,0};
    unsigned short reg=0;
    for(unsigned long long int i=0; i<semilla; i++){
        if(seg[i]!=-1){
            switch (regla){
                case 0: data[i]=1-seg[i];

                break;

                case 1: if(i%2!=0) data[i]=1-seg[i];

                break;

                default: if((i+1)%3==0) data[i]=1-seg[i];
            }

          if(codify) contador[seg[i]]++;
          else contador[data[i]]++;
        }
    }
    if(contador[0]>contador[1]) reg=1;
    else if(contador[0]<contador[1]) reg=2;
    return reg;
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
    ofstream k2(text,  ios::out | ios::binary);
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

