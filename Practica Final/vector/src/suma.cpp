#include <iostream>
#include "imagen.h"

using namespace std;

int main(int argc, char const *argv[]) {
  bool esBinario;
  if (argc !=5) {
    cerr << endl <<"Uso: ./suma <imagen_entrada_1> <imagen_entrada_2> <imagen_salida> <formato(t|d)> << endl";
    return -1;
  }
  Imagen imagen1, imagen2, imagen3;

  if(!imagen1.leerImagen(argv[1])){
    cerr << "error: apertura del fichero " << *argv[1] << endl;
    return -1;
  }
  if(!imagen2.leerImagen(argv[2])){
    cerr << "error: apertura del fichero " << *argv[2] << endl;
    return -1;
  }

  imagen3=imagen1+imagen2;

  if(*argv[4] != 't' && *argv[4] != 'b'){
    cerr << "error: opcion de formato incorrecta. Opciones: < t|b>"<< endl;
  }else{
    if(*argv[4] == 'b')
      esBinario=true;
      else
        esBinario=false;
  }

  if(!imagen3.escribirImagen(argv[3],esBinario)){
    cerr << "error: escribir la imagen de salida " << endl;
    return -1;
  }
}
