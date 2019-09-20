#include "Idioma.hh"

/** @file Idioma.hh
    @brief Implementacion de la clase Idioma
*/
Idioma::Idioma(){}

string Idioma::consultar_id()
{
	return id;
}

TablaFrec Idioma::consultar_tabla_frecuencias()
{
	return tablafrec;
}

TreeCode Idioma::consultar_treeCode()
{
	return treecode;
}

void Idioma::crear_codigos(BinTree<pair<string,int> > nodo, string& s0)
{

		if(nodo.left().empty() and nodo.right().empty()) {
			pair<string,string> p = make_pair(nodo.value().first,s0);
			codigos.insert(p);
		}
		else {
			string s1 = s0 + "0";
			crear_codigos(nodo.left(),s1);
			string s2 = s0 + "1";
			crear_codigos(nodo.right(),s2);
		}
}

void Idioma::comprobar(string& texto, int& i, string& res){
	if (texto[i]>=0) {
		res = string(1, texto[i]);
		++i;
	}
	else {
		res = string(texto, i, 2);
		i+=2;
	}
}

string Idioma::codificar(string texto) {
	map<string,string>::iterator it = codigos.begin();
	string resultado="";

		int i=0;
		while (i < texto.length()) {
			string res="";
			comprobar(texto,i,res);
			it = codigos.find(res);

			if(it == codigos.end()) {
				string aux = "El texto no pertenece al idioma; primer caracter que falla: ";
				aux += res;
				return aux;
			}

			else {
				resultado += it->second;
			}
		}
		return resultado;
}

void Idioma::leer_idioma(string id)
{
	this->id = id;
	tablafrec.leer_tf();
	treecode.construir(tablafrec);
	codigos.clear();
}

void Idioma::escribir_cods(string id, string caracter)
{
	if (caracter == "todos") {
		map<string,string>::iterator it = codigos.begin();
		cout << "Codigos de " << id << ":" << endl;
		while (it != codigos.end()) {
			cout << it->first << " " << it->second << endl;
			++it;
		}
	}
	else {
		map<string,string>::iterator it = codigos.find(caracter);
		cout << "Codigo de " << caracter << " en " << id << ":" << endl;
		if (it==codigos.end()) cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
		else cout << it->first << " " << it->second << endl;
	}
}
