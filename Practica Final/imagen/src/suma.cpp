#include "imagen.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
	if(argc != 5 )
			cout<<("\nIntroduzca exactamente los 5 datos de entada: ./suma img1.pgm img2.pgm img_out.pgm t\n");
	else{
		Imagen img1;
		Imagen img2;
		Imagen img_out;
		bool es_binario;

		if (!img1.leerImagen(argv[1])){
			cerr << "Error leyendo imagen1 " << argv[1] << endl;
			return 1;
	    }

	    if (!img2.leerImagen(argv[2])){
			cerr << "Error leyendo imagen2 " << argv[2] << endl;
			return 1;
	    }

	    img_out = img1+img2;

	    if (*argv[4] == 't' || *argv[4] == 'b'){
	    	if(*argv[4] == 't'){
	    		es_binario = false;
	    	}
	    	else if(*argv[4] == 'b'){
	    		es_binario = true;
	    	}
	    }
	    else{
	    	cout << "\nEl 5to parametro ha de ser t o b" << endl;
	    }

	    if(!img_out.escribirImagen(argv[3] , es_binario)){
	    	cout << "\nError escribiendo imagen" << argv[3] << endl;
	    	return 1;
	    }
	}
	return 0;
}
