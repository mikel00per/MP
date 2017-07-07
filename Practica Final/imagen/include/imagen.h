/**
 * @file
 * @author Antonio Miguel Morillo Chica
 * @date 8 Junio de 2016
 * @brief Clase imagen blanco y negro.
*/

#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include <fstream>
#include <cstring>
#include <string>
#include "lista.h"
#include "byte.h"
#include "pgm.h"

typedef unsigned char byte; ///< byte = 8bits almacenado en un unsigned char

/**
@brief Una imagen en blanco y negro. Cada píxel es un byte
*/
class Imagen{
private:
   int nfilas;                              ///< número de filas de la imagen
   int ncolumnas;                           ///< número de columnsa de la imagen
   byte **datos;                             ///< datos de la imagen

public:

/// Construye una imagen vacía (0 filas, 0 columnas)
   Imagen();


/**
@brief Construye una imagen negra de tamaño @a filas x @a columnas
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen

Construye una imagen de tamaño @a filas x @a columnas y pone todos
sus elementos a 0.
*/
   Imagen(const int filas, const int columnas);

/**
@brief Crea una imagen negra de tamaño @a filas x @a columnas
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen

Dimensiona la imagen a tamaño @a filas x @a columnas y pone todos
sus elementos a 0.
*/
   void crear(int filas, int columnas);

/**
@brief Devuelve el número de filas de las imagen
@return el número de filas de la imagen
*/
   const int filas();

/**
@brief Devuelve el número de columnas de las imagen
@return el número de columnas de la imagen
*/
   const int columnas();

/**
@brief Asigna el valor @a v a la posición (@a x,@a y) de la imagen
@param y 	fila de la imagen
@param x 	columna de la imagen
@param v 	valor a asignar

Asigna el valor @a v a la posición (@a x,@a y) de la imagen. Dado que la imagen
se guarda como un vector, la posición (@a x,@a y) corresponde a la posición
@a y * @c ncolumnas + @a x del vector.
*/
   void set(int y, int x, byte v);

/**
@brief Asigna el valor @a v a la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector
@param v 	valor a asignar

Asigna el valor @a v a la posición @a i de la imagen considerada como vector.
La posición @a i corresponde con la posición @c y * @c ncolumnas + @c x de la
imagen donde @c y representa la fila y @c x representa la columna.
*/
   void setPos(int i, byte v);

/**
@brief Devuelve el valor de la posición (@a x,@a y) de la imagen
@param y	 fila de la imagen
@param x	 columna de la imagen
@return el valor de la posición (@a x,@a y) de la imagen

Devuelve el valor de la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x
del vector.
*/
   const byte get(int y, int x)const;


/**
@brief Carga una imagen desde un fichero
@param nombreFichero nombre del fichero que contiene la imagen
@retval true 	si ha tenido éxito en la lectura
@retval false 	si se ha producido algún error en la lectura

Lee desde disco los datos de la imagen llamada @a nombreFichero y la guarda en la memoria. La función debe asegurarse de que la imagen es de un tipo de imagen conocido y de que su tamaño es menor del tamaño máximo permitido (@c MAXDATOS).
*/
   bool leerImagen(const char nombreFichero[]);

/**
@brief Guarda una imagen desde un fichero
@param nombreFichero nombre del fichero que contiene la imagen
@param esBinario toma el valor @c true si el fichero se escribe en formato binario o @c false en caso contrario.
@retval true 	si ha tenido éxito en la escritura
@retval false 	si se ha producido algún error en la escritura
*/
   bool escribirImagen(const char nombreFichero[], bool esBinario);

/**
@see plano
@brief Guarda un plano de imagen desde un fichero
@param plano plano que queremos explorar
@return plano imagen obtenida en el plano k
*/
   Imagen plano (int k);

/**
@see aArteASCII
@brief Guarda una imagen formada por caracteres desde un fichero
@param grises caracteres para formar la imagen
@param arteASCII nombre del fichero que contiene la imagen transformada en caracteres
@param maxlong maximo de caracteres que puede almacenar la imagen ASCII
@retval true si ha tenido éxito en la escritura
@retval false si se ha producido algún error en la escritura
*/
    bool aArteASCII(const char grises[], char arteASCII[], int maxlong);

/**
@brief Destructor por defecto de clase que llama a destruir()
*
*/
  ~Imagen();

/**
* @brief Destruye la reserva de memoria previamente reealizada y usada.
*
*/
   void destruir();

/**
* @brief Guarda en archivos de texto las imagnes resultantes de las cadenas
* contenidas en @ celdas
* @param celdas contiene un comentario, numero de cadenas, y cadenas.
* Guarda en archivos de texto las imagnes resultantes de las cadenas contenidas
* en @ celdas Además devuelve, true, o false si se ha realizado bien el guardado.
* esta función llama a aArteASCII()
*/
   bool listaAArteASCII(const Lista &celdas);

/**
* @brief Constructor de copia.
*
*/
   Imagen(const Imagen &otra);

/**
 * 
 * 
* @brief Copia @ otra en memoria
* @param otra Imagen que queremos copiar en memoria.
* Copia @ otra en memoria. Esta función es llamada por el constructor de copia.
*/
   void copiarImagen(const Imagen &otra);

/**
*
*
*
*/

   Imagen & operator=(const Imagen &otra);

/**
*
*
*
*/

   Imagen operator+(const Imagen &otra)const;

 };

#endif
