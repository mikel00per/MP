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

    //Mio
    destruir();

    nfilas = filas;
    ncolumnas = columnas;

    this->datos = new byte[nfilas*ncolumnas];

    for (int i = 0; i < columnas*filas; i++)
      datos[i] = 0;
  }

// _____________________________________________________________________________

  Imagen::Imagen(const Imagen &otra){
    copiarImagen(otra);
  }

// _____________________________________________________________________________

  void Imagen::copiarImagen(const Imagen &otra){
    if(this != &otra){
      destruir(); //podríamos eliminarlo porque ya destruimos en crear
      crear(otra.nfilas,otra.ncolumnas);

      for (int i = 0; i < ncolumnas*nfilas; i++)
        this->datos[i] = otra.datos[i];
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
    Imagen resultado_f;
    if(otra.datos != 0){
      if(this->datos != 0){
        int resultado_filas;
        int resultado_columnas = ncolumnas + otra.ncolumnas;

        if(nfilas < otra.nfilas){
          resultado_filas = otra.nfilas;
        }
        else{
          resultado_filas = nfilas;
        }

        Imagen resultado(resultado_filas, resultado_columnas);

        //Copio la de la memoria
        for (int i = 0; i < nfilas; i++) {
          for(int j = 0; j < ncolumnas; j++){
            resultado.set(i,j,get(i,j));
          }
        }

        //Sumo otra
        for (int i = 0; i < otra.nfilas; i++) {
          for(int j = ncolumnas, x=0; j < resultado.ncolumnas; j++,x++){
            resultado.set(i,j,otra.get(i,x));
          }
        }
        resultado_f=resultado;
        //En caso contrario es la misma.
      }
    }
    //Si no hago nada, devuelvo un resultado nulo.
    return resultado_f;
  }

// _____________________________________________________________________________

 int Imagen::filas(){
    return this->nfilas;
  }

// _____________________________________________________________________________

int Imagen::columnas(){
    return this->ncolumnas;
  }

// _____________________________________________________________________________

  void Imagen::set(int y, int x, byte v){
    int posicion=y*ncolumnas+x;
    datos[posicion]=v;
  }

// _____________________________________________________________________________

  byte Imagen::get(int y, int x)const{
    return datos[y*ncolumnas+x];
  }

// _____________________________________________________________________________

  void Imagen::setPos(int i, byte v){
    datos[i]=v;
  }

// _____________________________________________________________________________

 byte Imagen::getPos(int i){
    return datos[i];
  }

// _____________________________________________________________________________

   Imagen::~Imagen (){
     destruir();
   }
   
// ____________________________________________________________________________
   
  void Imagen::destruir(){
    if(datos != 0)
      delete [] datos;
    datos = 0;
    nfilas = 0;
    ncolumnas = 0;
  }

// _____________________________________________________________________________

  bool Imagen::leerImagen(const char nombreFichero[]){
    bool resultado = false;
    TipoImagen mi_tipo;

    int nf =0,nc = 0;
    mi_tipo = infoPGM(nombreFichero, nf, nc);

    if(mi_tipo == IMG_PGM_BINARIO){
      crear(nf,nc);
      resultado = leerPGMBinario(nombreFichero, datos, nf, nc);
    }
    else if(mi_tipo == IMG_PGM_TEXTO){
      crear(nf,nc);
      resultado = leerPGMTexto(nombreFichero, datos, nf, nc);
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

//* _____________________________________________________________________________
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
