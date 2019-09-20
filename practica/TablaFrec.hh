/** @file TablaFrec.hh
    @brief Especificacion de la clase TablaFrec
*/
#ifndef CLASS_TablaFrec
#define CLASS_TablaFrec

#include <map>
#include <string>
#include <iostream>

using namespace std;

/** @class TablaFrec
    @brief Representa una tabla de frecuencias.

	contiene un map con cada caracter y la frecuencia con la que aparece en un idioma. Su funcion es la de construir el TreeCode.
*/

class TablaFrec {

private:
	/** @brief Caracter*/
	string caracter;
	/** @brief Frecuencia de cada caracter*/
	int frecuencia;
	/** @brief Contiene la frecuencia de cada caracter ordenado de menor a mayor segun la frecuencia*/
	map<string,int> tabla;


public:

		 // Constructoras
		 /** @brief Creadora vacia.

      Se ejecuta automaticamente al declarar una tabla de frecuencias.
      \pre <em>cierto</em>
      \post se crea una tabla de frecuencias nueva vacia.
  	 */
		 TablaFrec();


		 // Modificadoras


		 // Consultoras
		 /** @brief Consultora de la frecuencia de un caracter

      \pre <em>cierto</em>
      \post devuelve un caracter y su frecuencia.
  	 */
		 pair<string,int> consultar_caracter(map<string,int>::iterator it);

		 /** @brief Consultora del inicio del map

      \pre <em>cierto</em>
      \post devuelve un iterador que apunta al begin del map que contiene los caracteres y sus frecuencias.
  	 */
		 map<string,int>::iterator consultar_begin();

		 /** @brief Consultora del tamano de la tabla

      \pre <em>cierto</em>
      \post devuelve el valor del tamano del map que contiene los caracteres y sus frecuencias.
  	 */
		 int size();

		 // Lectura
		 /** @brief Operacion de lectura

      \pre <em>cierto</em>
      \post lee el contenido de la tabla de frecuencias por el canal estandar de entrada.
     */
  	 void leer_tf();

		 // Escritura
		 /** @brief Operacion de escritura

      \pre <em>cierto</em>
      \post escribe el contenido del parametro implicito por el canal estandar de salida.
     */
  	 void escribir_tf();

};
#endif
