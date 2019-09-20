/** @file TreeCode.hh
    @brief Especificacion de la clase TreeCode
*/
#ifndef CLASS_TreeCode
#define CLASS_TreeCode

#include "BinTree.hh"
#include "TablaFrec.hh"
#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;

/** @class TreeCode
    @brief Representa un treecode

	contiene un BinTree cuyos nodos se corresponden con un pair de un string (caracter) y un int (su frecuencia). Se construye a partir de la tabla de frecuencia del idioma correspondiente.
*/

class TreeCode {

private:
	/** @brief Contiene los nodos individuales ordenados por frecuencia*/
	set< BinTree < pair<string,int> > > nodos;
	/** @brief Imprime Inorden

      Imprime el arbol en inorden.

      \pre <em>cierto</em>
      \post se ha impreso el arbol.
  	*/
	void inorden (const BinTree<pair<string,int> >& a); //imprime el arbol en orden inorden
	/** @brief Imprime Preorden

      Imprime el arbol en preorden

      \pre <em>cierto</em>
      \post se ha impreso el arbol.
  	*/
	void preorden (const BinTree<pair<string,int> >& a); //imprime el arbol en orden preorden

public:

	// Constructoras
	/** @brief Creadora por defecto

      Se ejecuta automaticamente al declarar un TreeCode.

      \pre <em>cierto</em>
      \post se crea un TreeCode vacio.
  	*/
	TreeCode();


	// Modificadoras
	/** @brief Modificadora constructora

      \pre <em>cierto</em>
      \post el set contiene el arbol de nodos colocados en la posición adecuada.
  	*/
	void construir(TablaFrec tabla);

	/** @brief Decodifica un codigo

	 \pre <em>it<codigo.length()</em>
	 \post se recorre el arbol a hasta llegar a una hoja, en cuyo caso le suma el valor del nodo a resultado y fallo es false, si el codigo
	 \ no pertenece al idioma fallo es true. si el caracter consultado es 1 llama recursivamente a la funcion con el arbol derecho,
	 \ y si es 0 la llamada la hace con el izquierdo.
	*/
	void i_decodificar(BinTree<pair<string,int> > a, string codigo, string& resultado, int& it, bool& fallo);

	/** @brief Decodifica un codigo

	 \pre <em>cierto</em>
	 \post si el codigo procede de una codificacion del idioma se ha decodificado, si el codigo
	 \ no es valido salta un mensaje. utiliza de forma immersiva la funcion i_decodificar
	*/
	void decodificar(string codigo);


	// Consultoras
	/** @brief Consultora de nodo

			\pre <em>cierto</em>
			\post devuelve el primer nodo del arbol almacenado en el set
		*/
	BinTree<pair<string,int> > consultar_nodo();


	// Escritura
	/** @brief Operacion de escritura

      \pre <em>cierto</em>
      \post escribe el contenido del parametro implicito por el canal estandar de salida.
  */
  void escribir_tree();
};
#endif
