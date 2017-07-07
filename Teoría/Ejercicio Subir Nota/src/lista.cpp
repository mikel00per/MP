#include "lista.h"

Celda::Celda(){
    valor=0;
    siguiente=NULL;
}

Celda::Celda(int valor){
    this->valor=valor;
}

void Celda::insertarValor(int valor){
    this->valor=valor;
}

void Celda::asignarSiguiente(Celda * siguiente){
    this->siguiente=siguiente;
}

int Celda::obtenerValor(){
    return valor;
}

Celda * Celda::obtenerSiguiente(){
    return siguiente;
}

Lista::Lista(){
    this->cabecera=NULL;
    insertarLongitud(0);
}

Lista::Lista(Lista &lista){
    copiarLista(lista);
}

void Lista::insertarCelda(int indice=0, int valor=0){
    Celda *pCelda = new Celda(valor);
    //insercion al inicio
    if(indice==0 || cabecera==0){
        if(cabecera==0){             //la lista esta vacia
            cabecera=pCelda;
        }
        else{                       //la lista no esta vacia
            pCelda->asignarSiguiente(cabecera);
            cabecera=pCelda;
        }
    }
    else{                           //caso general
        if(indice>obtenerLongitud()){
            indice=obtenerLongitud();
        }
        Celda * pUltima = obtenerCelda(indice -1);  //Obtenemos la posicion del indice señalado
        pCelda->asignarSiguiente(pUltima->obtenerSiguiente()); //Asignamos el valor de pUltima al siguiente de pCelda
        pUltima->asignarSiguiente(pCelda);  //Asigna a pUltima el valor de pCelda
    }
    longitud++;
}

Celda *Lista::obtenerCelda(int indice){
  Celda * pCelda;

  if(cabecera != 0 && indice >= 0 && indice < obtenerLongitud()){
    pCelda = cabecera;
    for (int i = 0; i < indice; ++i)
      pCelda = pCelda->obtenerSiguiente();
  }

  return pCelda;
}

Celda *Lista::obtenerCabecera(){
    return cabecera;
}

int Lista::obtenerLongitud(){
    return longitud;
}

Celda * Lista::reservarCeldas(const int longitud, int valor){
    Celda * pCelda;
    Lista * pLista;
    for (int i = 0; i < longitud; ++i){
        pLista->insertarCelda(i, valor);
    }
    pCelda = pLista->cabecera;
    return pCelda;
}

void Lista::concatenar(Lista &otra){
    if(otra.obtenerCabecera() !=0 && obtenerCabecera() != 0){//Si la lista que le pasamos no esta vacia, entonces concatena las listas
        Celda *pCelda  = reservarCeldas(otra.obtenerLongitud(), 0);
        Celda * pPrimera = pCelda;  //pPrimera es un puntero auxiliar
        for (int i = 0; i < otra.obtenerLongitud(); ++i){
            pPrimera->insertarValor(pPrimera->obtenerValor());
            pPrimera=pPrimera->obtenerSiguiente();
        }
        Celda *pUltima = obtenerCelda(obtenerLongitud() -1);    //Creamos un puntero que apuntara a la ultima direccion de memoria de la primera lista(this)
        pUltima->asignarSiguiente(pCelda);  // Fusion de las dos listas en el punto de fusion de pCelda
        longitud+=otra.longitud;    //Sumamos la longitud de las dos
    }
    else if(otra.cabecera !=0 && cabecera == 0){    //Si la lista que le pasamos no esta vacia, pero la primera si
        copiarLista(otra);
    }
    //En otro caso la lista secundaria estaria vacia y no habria que hacer nada
}

void  Lista::copiarLista(Lista &otra){
    Lista * pLista;
    if(otra.cabecera != 0){
        Celda * pCelda;
        for (int i = 0; i < otra.longitud; ++i){
            pCelda=otra.obtenerCelda(i);
            pLista->insertarCelda(i, pCelda->obtenerValor());
        }
    }
    this->cabecera=pLista->cabecera;
}


bool Lista::borrarElemento(int indice){

  bool resultado = false;
  //Recupero la celda a borrar
  Celda *pCelda = obtenerCelda(indice);
  //Comprobar que el indice exista
  if(indice > 0 && indice < longitud){
    if(pCelda != 0){
      //Considerar que sea la primera celda
      if(pCelda == cabecera)
        cabecera = pCelda -> obtenerSiguiente();
      else{
        Celda *pCeldaPrecia = obtenerCelda(indice-1);
        pCeldaPrecia ->asignarSiguiente(pCelda -> obtenerSiguiente());
      }

      delete pCelda;
      longitud--;
      resultado = true;
    }
  }

  return resultado;
}

void Lista::destruir(){

}

Lista::~Lista(){
    destruir();
}
