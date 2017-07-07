#include "byte.h"

using namespace std;

void on(byte &b, int pos){

    unsigned char mask=1;
    mask = mask << pos;
    b = (mask | b);

}

void off(byte &b, int pos){

    unsigned char mask=1;
    mask = mask << pos;
    b = (mask & b);

}

bool getbit(byte b, int pos){

    unsigned char mask=1;
    mask = (mask<<pos);
    bool salida;

    if (mask & b)
    salida = 1;
    else
    salida = 0;

    return salida;

}

void print(byte b){
    for (int i = 0; i < 8; ++i)
            if(getbit(b, i))
                    cout << "1" << " ";
            else
                    cout << "0" << " ";
    cout << endl;
}

void encender(byte &b){
    unsigned char mask=0;
    mask = mask ^ mask;
    b = (b | mask);
}

void apagar(byte &b){
    unsigned char mask=0;
    b = (b & mask);
}

void asignar(byte &b, const bool v[]){
    apagar(b);
    bool valor;

    //b = (b | v[])
    for(int i=0; i <= 7; i++){
        valor = v[i];
    if(valor == 1)
        on(b,i);
    }
}

void volcar(byte b, bool v[]){
    for(int i=0; i<=7;i++){
        v[i] = getbit(b,i);
    }
}

void encendidos(byte b, int posic[], int &cuantos){

    for(int i=0; i<=7; i++){
        if(getbit(b,i)){
            posic[i]=1;
            cuantos++;
        }
        else{
            posic[i]=0;
            cuantos++;
        }
    }
}

string byteToString (byte b){

    string salida;
    for (int i = 7; i <= 0; ++i)
        if(getbit(b, i))
            salida += '1';
        else
            salida += '0';

    return salida;
}
