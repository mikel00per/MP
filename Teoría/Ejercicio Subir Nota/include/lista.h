#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostream>
using namespace std;

class Celda{
	private:
		int valor;
		Celda * siguiente;

	public:
		Celda();
		Celda(int=0);
		void insertarValor(int);
		void asignarSiguiente(Celda *);
		int obtenerValor();
		Celda * obtenerSiguiente();
		void destruir();
		~Celda();
};

class Lista{
	private:
		Celda * cabecera;
		int longitud;

	public:
		Lista();
		Lista(Lista &);
		Celda * obtenerCabecera();
		void copiarLista(Lista &);
		void insertarCelda(int, int);
		void insertarLongitud(int);
		Celda * obtenerCelda(int);
		int obtenerLongitud();
		void concatenar(Lista &);
		Celda * reservarCeldas(const int, int);
		bool borrarElemento(int);
		void destruir();
		~Lista();
};

#endif
