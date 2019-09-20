/** @file Idioma.hh
    @brief Especificacion de la clase Idioma
*/
#ifndef CLASS_Idioma
#define CLASS_Idioma

#include "TablaFrec.hh"
#include "TreeCode.hh"
#include "BinTree.hh"
#include <string>
#include <iostream>
#include <map>

using namespace std;

/** @class Idioma
    @brief Representa un idioma.

	contiene un identificador, que es un string, una TablaFrec y un Treecode, que son tipos de datos propios.
*/

class Idioma {

private:
    /** @brief Nombre del idioma*/
	string id;
	/** @brief Tabla de frecuencias*/
	TablaFrec tablafrec;
	/** @brief TreeCode*/
	TreeCode treecode;
	/** @brief String donde se guarda el codigo*/
	string codigo;
	/** @brief Contiene el codigo de cada caracter*/
	map<string,string> codigos;

public:

		// Constructoras
		/** @brief Creadora por defecto.

      Se ejecuta automaticamente al declarar un idioma.
      \pre <em>cierto</em>
      \post se ha creado un idioma nuevo vacio
  	*/
		Idioma();


		// Modificadoras
		/** @brief Creadora de codigos

      \pre <em>s0 es una string vacia</em>
      \post se rellena el map de codigos creados a partir de la posicion de los nodos que se recorren.
  	*/
		void crear_codigos(BinTree<pair<string,int> > nodo, string& s0);


		// Consultoras
		/** @brief Consultora del identificador

      \pre <em>cierto</em>
      \post se devuelve la id del idioma.
  	*/
		string consultar_id();

		/** @brief Consultora de la tabla de frecuencias

      \pre <em>cierto</em>
      \post devuelve la tabla de frecuencias del idioma.
  	*/
		TablaFrec consultar_tabla_frecuencias();

		/** @brief Consultora del treecode

      \pre <em>cierto</em>
      \post devuelve el treecode del idioma.
  		*/
		TreeCode consultar_treeCode();

		/** @brief Consulta si el caracter es especial

			 \pre <em>i es la primera posicion de un string texto</em>
			 \post res es el caracter que comienza en texto[i]; si res es normal i=I+1, si es especial i=I+2.
		*/
		void comprobar(string& texto, int& i, string& res);

		/** @brief Codifica un texto

      \pre <em>cierto</em>
      \post si el texto pertenece al idioma devuelve el texto codificado, si el texto
	  	\ no pertenece al idioma salta un mensaje.
 		*/
		string codificar(string texto);


		// Lectura
		/** @brief Operacion de lectura

      \pre <em>cierto</em>
      \post lee el contenido del idioma por el canal estandar de entrada, y en caso de ya existir lo actualiza.
    */
  	void leer_idioma(string id);

  	/** @brief Operacion de escritura

      \pre <em>cierto</em>
      \post escribe el contenido del parametro implicito por el canal estandar de salida.
    */
  	void escribir_cods(string id, string caracter);

};
#endif
