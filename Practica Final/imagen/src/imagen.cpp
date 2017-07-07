#include "imagen.h"

using namespace std;

typedef unsigned char byte; ///< byte = 8bits almacenado en un unsigned char


  Imagen::Imagen(){
    //Mio
    this->datos = 0;
    ncolumnas = 0;
    nfilas = 0;
  }

// _____________________________________________________________________________

  Imagen::Imagen(int filas, int columnas){
    this->datos = 0;
    crear(filas, columnas);
  }

// _____________________________________________________________________________

  void Imagen::crear(int filas, int columnas){

    destruir();

    nfilas=filas;
  	ncolumnas=columnas;

    datos = new byte*[filas];
    datos[0] = new byte[filas*columnas];


  	for(int i = 1; i < filas; i++)	//Recorremos la imagen
		    datos[i] = datos[i-1] + columnas;

    for(int i=0; i < nfilas; i++)
  		for(int j = 0; j < ncolumnas; j++)
			  datos[i][j] = 0;

  }
// _____________________________________________________________________________

  Imagen::~Imagen(){
    destruir();
  }

// _____________________________________________________________________________

  Imagen::Imagen(const Imagen &otra){
    copiarImagen(otra);
  }

// _____________________________________________________________________________

  void Imagen::copiarImagen(const Imagen &otra){
    if(this != &otra){
      destruir();

      crear(otra.nfilas,otra.ncolumnas);

      for(int i = 0; i < nfilas; i++)
        for (int j = 0; j < ncolumnas; j++)
          datos[i][j] = otra.datos[i][j];
    }
  }

// _____________________________________________________________________________

    // & es .
    // * es ->
  Imagen &Imagen::operator=(const Imagen &otra){
      if(this != &otra){
        destruir();
        copiarImagen(otra);
      }

      return *this;
    }

  // _____________________________________________________________________________

    Imagen Imagen::operator+(const Imagen &otra)const{

      int resultado_filas;
      int resultado_columnas = ncolumnas + otra.ncolumnas;

      if(nfilas < otra.nfilas){
        resultado_filas = otra.nfilas;
      }
      else{
        resultado_filas = nfilas;
      }

      Imagen resultado_f(resultado_filas, resultado_columnas);

      //Copio la de la memoria
      for (int i = 0; i < nfilas; i++) {
        for(int j = 0; j < ncolumnas; j++){
          resultado_f.set(i,j,get(i,j));
        }
      }

      //Sumo otra
      for (int i = 0; i < otra.nfilas; i++) {
        for(int j = ncolumnas, x=0; j < resultado_f.ncolumnas; j++, x++){
          resultado_f.set(i,j,otra.get(i,x));
        }
      }

      //Si no hago nada, devuelvo un resultado nulo.
      return resultado_f;
    }

// _____________________________________________________________________________

  const int Imagen::filas(){
    return nfilas;
  }

// _____________________________________________________________________________

  const int Imagen::columnas(){
    return ncolumnas;
  }

// _____________________________________________________________________________

  void Imagen::set(int y, int x, byte v){
    datos[y][x]=v;
  }

// _____________________________________________________________________________

void Imagen::setPos(int i, byte v){
  datos[0][i]=v;
}
// _____________________________________________________________________________

  const byte Imagen::get(int x, int y)const{
    return datos[x][y];
  }

// _____________________________________________________________________________

// revisar
  void Imagen::destruir(){
    if (datos != 0){
	    delete [] datos[0];
      delete [] datos;
      datos = 0;
      nfilas = 0;
      ncolumnas = 0;
    }
  }

// _____________________________________________________________________________

  bool Imagen::leerImagen(const char nombreFichero[]){
    bool resultado = false;

    if(infoPGM(nombreFichero, nfilas, ncolumnas) == IMG_PGM_BINARIO){
      crear(nfilas, ncolumnas);
      resultado = leerPGMBinario(nombreFichero, datos, nfilas, ncolumnas);
    }
    else if(infoPGM(nombreFichero, nfilas, ncolumnas) == IMG_PGM_TEXTO){
      crear(nfilas, ncolumnas);
      resultado = leerPGMTexto(nombreFichero, datos, nfilas, ncolumnas);
    }

    return resultado;
  }

// _____________________________________________________________________________

  bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario){

    bool result;
    if(esBinario)
      result = escribirPGMBinario (nombreFichero, datos, nfilas, ncolumnas);
    else
      result = escribirPGMTexto (nombreFichero, datos, nfilas, ncolumnas);

    return result;
  }

// _____________________________________________________________________________
/*
Imagen Imagen::plano (int k){
  Imagen plano_imagen(nfilas, ncolumnas);
  byte bit;
  for (int i = 0; i < ncolumnas*nfilas; ++i){
    apagar(bit);
    if(getbit(getPos(i), k)){
      on(bit, 7);
      plano_imagen.setPos(i, bit);
    }
    else{
      plano_imagen.setPos(i, bit);
    }
  }
  return plano_imagen;
  plano_imagen.destruir();
}
*/

// _____________________________________________________________________________

  bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong){
    bool correcto = true;
    int tamG = 0;
    int contador = 0;

    while (grises[tamG] != '\0'){
      tamG++;
    }

    if (maxlong >= nfilas*(ncolumnas+1)+1){
      for (int i = 0; i < filas(); i++){
        for (int j = 0; j < columnas(); j++){
          arteASCII[contador]=grises[get(i,j)*tamG/256];
          contador++;
        }
        arteASCII[contador] = '\n';
        contador++;
      }
    }
    else
      correcto = false;

    arteASCII[contador]='\0';
    return correcto;
  }

// _____________________________________________________________________________

bool Imagen::listaAArteASCII(const Lista &celdas){

  char nombre[]="ascii_X.txt";
  bool correcto = true;
  char *arteASCII = new char[nfilas*(ncolumnas+1)+1];
  cout << celdas.longitud() << endl;
  for(int i = 0; i<celdas.longitud(); i++){
    cout << celdas.getCelda(i) << endl;
    sprintf(nombre, "ascii_%d.txt", i+1);
    aArteASCII(celdas.getCelda(i).c_str(), arteASCII, nfilas*(ncolumnas+1)+1);
    ofstream file(nombre);
    if(file)
      file << arteASCII;

    file.close();
  }
  delete []arteASCII;
  return correcto;
}

// _____________________________________________________________________________
