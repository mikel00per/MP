#include "lista.h"

int main(){
	Lista * lista1;
	Lista * lista2;

	for (int i = 0; i < 5; ++i){
		lista1.insertarCelda(i);
		lista2.insertarCelda(i);
	}

	lista1.concatenar(lista2);

	Celda * pCelda = lista1.obtenerCabecera();

	for (int i = 0; i < lista1.obtenerLongitud(); ++i){
		cout << pCelda->obtenerValor() << "->";
		pCelda = pCelda->obtenerSiguiente();
	}
}