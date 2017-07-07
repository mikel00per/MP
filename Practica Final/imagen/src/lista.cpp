#include <string>
#include <fstream>
#include <iostream>
#include "lista.h"

using namespace std;

//______________________________________________________________________________



// _____________________________________________________________________________

Lista::Lista(){
  cabecera = 0;
}

// _____________________________________________________________________________

Lista::Lista(string valor){
  insertar(valor);
}

// _____________________________________________________________________________

Lista::~Lista(){
  destruir();
}

// _____________________________________________________________________________

void Lista::destruir(){
    Celda *ptr = cabecera;
    while (cabecera != 0) {
      ptr=cabecera;
      cabecera=cabecera->siguiente;
      delete ptr;
    }
    delete cabecera;
}

// _____________________________________________________________________________

Lista::Lista(const Lista &otra){
    copiarLista(otra);
}

//______________________________________________________________________________

Lista & Lista::copiarLista(const Lista &otra){
  if(otra.cabecera != 0){
    destruir();
    Celda *aux = otra.cabecera;

    while(aux->siguiente != 0){
      insertar(aux->datos);
      aux = aux -> siguiente;
    }

    delete aux;
  }

  return *this;
}


// _____________________________________________________________________________

Lista & Lista::operator=(const Lista &otra){

  destruir();

  if(cabecera != 0)
    copiarLista(otra);

  return *this;
}

// _____________________________________________________________________________

Lista & Lista :: operator+(const string mi_string){

  this->insertar(mi_string);
  return *this;
}

// _____________________________________________________________________________

void Lista::insertar(string valor){
   Celda *celda = new Celda();
  Celda *puntero;

	celda -> datos = valor;
	celda -> siguiente = 0;

	if(cabecera == 0)
		cabecera=celda;
	else{
		puntero=cabecera;

		while(puntero->siguiente!=0)
			puntero = puntero->siguiente;

		puntero->siguiente = celda;
	}
}

// _____________________________________________________________________________

string Lista::getCelda(int pos) const{
  string cadena = "";
	int cnt=0;
	Celda *puntero = cabecera;

	if(puntero != 0){
		while(cnt != pos){
			puntero = puntero->siguiente;
			cnt++;
		}
		cadena = puntero->datos;
	}

	return cadena;
}

// _____________________________________________________________________________

int Lista::longitud() const{
  int cnt = 0;
	if(cabecera != 0){
		Celda *puntero = cabecera;
		cnt++;

		while(puntero->siguiente != 0){
			puntero = puntero->siguiente;
			cnt++;
		}
	}
	return cnt;
}

// _____________________________________________________________________________

bool Lista::leerLista(const char nombrefichero[]){
	ifstream fin;
	fin.open(nombrefichero);
	if(!fin){
		return false;
	}else{
		string grises;
		int lineas;
		getline(fin,grises); //la primera linea se ignora
		fin >> lineas; //leo el numero de datos de grises
		getline(fin,grises); //leer salto de linea
		if (!fin){
			return false;
		}else {
			int i = 0;
			getline(fin,grises); //leer cadena de caracteres
			while ((i < lineas)&&(fin)){
				if (grises != ""){
					insertar(grises);
					i++;
				}
				getline(fin,grises); //leer cadena de caracteres
			}
		}
		fin.close();
	}
	return true;
}


// _____________________________________________________________________________
