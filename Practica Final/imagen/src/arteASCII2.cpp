/**
 * lee cualquier imagen indicada por el usuario y un fichero con cadenas
 * de caracteres y crea ficheros de imagen transformadas, una por cadena
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include "imagen.h"
#include "lista.h"

using namespace std;

int main(int argc, char const *argv[]) {

	if(argc != 3){
    cout 	<< "Faltan elementos. Forma: ./testarteASCII.cpp <imagen.png> "
					<< "<grises.txt>" << endl;
		return 0;
  }

  Imagen origen;
  Lista celdas;


  // Leer la imagen desde fichero
  if (!origen.leerImagen(argv[1])){
		cerr << "Error leyendo imagen " << argv[1] << endl;
		return 1;
  }

	// Leer cadenas desde fichero
	if (celdas.leerLista(argv[2])){
		// realizar las
		if (origen.listaAArteASCII(celdas)){
			cout << "Exito en la conversion." << endl;
			cout << "Chequee los ficheros asciiX.txt" << endl;
			cout << endl;
		}else{
			cerr << "La conversion no ha sido posible" << endl;
			cerr << endl;
		}
	}else{
		cerr << "Error lista de grises " << argv[2] << endl;
	}

	return 0;
}
