/**
 * @file
 * @author Antonio Miguel Morillo Chica
 * @date 12 Abril de 2016, 20:45
 * @brief Funciones de manejo de bytes
**/

#ifndef _byte_H_
#define	_byte_H_

#include <iostream>
#include <string>

using namespace std;

typedef unsigned char byte; ///< Un @c byte contiene el estado de 8 bytes

/**
    * @brief enciende el byte @p pos del @c byte @p b
    * @param b el @c byte cuyo byte se quiere activar
    * @param pos el byte dentro de @p b que se quiere activar (0 más a la derecha)
    */
void on(byte &b, int pos);

/**
    * @brief apaga el byte @p pos del  @c byte @p b
    * @param b el @c byte cuyo byte se quiere desactivar
    * @param pos el byte dentro de @p b que se quiere desactivar (0 más a la derecha)
    */
void off(byte &b, int pos);

/**
    * @brief devuelve el estado del byte (encendido = true, apagado = false) en la posición @p pos
    * @param b el @c byte que se quiere consultar
    * @param pos el byte dentro de @ b que se quiere consultar (0 más a la derecha)
    * @retval true	si el byte en la posición @p pos está encendido
    * @retval false si el byte en la posición @p pos está apagado
    */
bool getbit(byte b, int pos);

/**
    * @brief Muestra por la salida estándar una secuencia de 0s y 1s correspondiente  al estado de cada byte
    * @param b el @c byte que se quiere imprimir
    *
    * Muestra por la salida estándar una secuencia de 0s y 1s correspondiente  al estado de cada byte del byte donde un cero representa que un byte está apagado y un uno que el byte está encendido. Se implementa utilizando la función "get".
    *
    * Por ejemplo, si en el @c byte @c b están encendidos los bytes en posiciones 1 y 3 (0 más a la derecha), @c print(b); mostrará @c 00001010
    */
void print(byte b);

/**
    * @brief enciende todos los bytes
    * @param b el @c byte que se quiere encender completamente.
    */
void encender(byte &b);

/**
    * @brief apaga todos los bytes
    * @param b el @c byte que se quiere apagar completamente.
    */
void apagar(byte &b);

/**
    * @brief enciende los bytes según la configuración de @p v
    * @param b el @c byte sobre el que se quiere actuar
    * @param v vector de 8 elementos que contiene la secuencia de byteS que se quieren asignar
*
    * Asigna a @p b la configuración de bytes contenida en @p v. @p v es un vector de 8 booleanos donde @c true significa encendido y @c false significa apagado.
    */
void asignar(byte &b, const bool v[]);

/**
    * @brief recupera la configuración de todos los byte
    * @param b el @c byte que se quiere consultar
    * @param v vector de 8 elementos que contendrá el estado de cada uno de los bytes de @ b
    *
    * Vuelca en @p v la configuración de bytes contenida en @p b. @c true significa encendido y @c false significa apagado. El tamaño de @p v debe ser 8.
    */
void volcar(byte b, bool v[]);

/**
    * @brief devuelve las posiciones de los bytes encendidos
    * @param b el @c byte que se quiere consultar
    * @param posic vector de enteros (valores entre 0 a 7) que indican la posición de los bytes de @p b que están encendidos
    * @param cuantos número de bytes encendidos en @p b (número de elementos usados en el vector @p posic)
    */
void encendidos(byte b, int posic[], int &cuantos);

/**
    * @brief tranforma el valor de los bytes a string
    * @param byte b bloque de bytes que queremos convertir a string
    * @return devuelve el valor convertido en un string
    */
string byteToString (byte b);

#endif
