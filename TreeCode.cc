#include "TreeCode.hh"

/** @file Idioma.hh
    @brief Implementacion de la clase TreeCode
*/
bool operator< (BinTree<pair<string,int> > a1, BinTree<pair<string,int> > a2) {
	if(a1.value().second == a2.value().second) return a1.value().first < a2.value().first;
	else return a1.value().second < a2.value().second;
}

TreeCode::TreeCode(){}

void TreeCode::construir(TablaFrec tablaf)
{
	nodos.clear(); //limpia el set para poder actualizarse correctamente en caso de modificar el idioma
	//CREA EL SET DE NODOS
	int tam = tablaf.size();
	map<string,int>::iterator i = tablaf.consultar_begin();

	while(tam > 0) {
		BinTree<pair<string,int> > nodo(tablaf.consultar_caracter(i));
		nodos.insert(nodo);
		 ++i;
		 --tam;
	 }

	//CREAR TREECODE
	set<BinTree<pair<string,int> > >::iterator it = nodos.begin(); //apunta a un nodo
	set<BinTree<pair<string,int> > >::iterator it2 = it; ++it2; //apunta al siguiente nodo
	while (it2 != nodos.end()) {

		pair<string,int> p;
		if((*it).value().first < (*it2).value().first) {
			p= make_pair((*it).value().first+(*it2).value().first, (*it).value().second+(*it2).value().second);
		}
		else {
			p = make_pair((*it2).value().first+(*it).value().first, (*it).value().second+(*it2).value().second);
		}

		BinTree<pair<string,int> > aux(p,*it,*it2); //se crea el nodo nuevo a partir de los otros dos

		nodos.erase(*it); //se borra el primer tree del set
		nodos.erase(*it2); //se borra el segundo tree del set
		nodos.insert(aux); //se inserta en el set el nodo nuevo

		it = nodos.begin();
		it2 = it; ++it2;
	}
}

void TreeCode::i_decodificar(BinTree<pair<string,int> > a, string codigo, string& resultado, int& it, bool& fallo) {
	if(a.left().empty()) { resultado += a.value().first;}
	else {

		if (it == codigo.size()) { fallo = true; }
		else {
			if(codigo[it] == '1') {
				i_decodificar(a.right(),codigo,resultado,++it,fallo);
			}
			else {
				i_decodificar(a.left(),codigo,resultado,++it,fallo);
			}
		}
	}
}

void TreeCode::decodificar(string codigo) {
	int it = 0, last = 0;
	set< BinTree < pair<string,int> > >::iterator it2 = nodos.begin(); //apunta al begin del arbol
	string resultado = "";

	bool fallo = false; //asegura que no hay fallos
	while(it < codigo.length()) {
		last = it;
		i_decodificar(*it2, codigo, resultado, it, fallo);
	}

	if (fallo) cout << "El texto no procede de una codificacion del idioma; ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: " << last << endl;
	else cout << resultado << endl;
}


BinTree<pair<string,int> > TreeCode::consultar_nodo()
{
	set<BinTree<pair<string,int> > >::iterator it = nodos.begin();
	return *it;
}

void TreeCode::preorden (const BinTree<pair<string,int> >& a)
{
	if(!a.left().empty()) {
		cout << a.value().first << " " << a.value().second << endl;
		preorden(a.left());
		preorden(a.right());
	}
	else {
		cout << a.value().first << " " << a.value().second << endl;
	}
}

void TreeCode::inorden (const BinTree<pair<string,int> >& a)
{
		if(!a.left().empty()) {
			inorden(a.left());
			cout << a.value().first << " " << a.value().second << endl;
			inorden(a.right());
		}
		else {
			cout << a.value().first << " " << a.value().second << endl;
		}
}

void TreeCode::escribir_tree()
{
	set<BinTree<pair<string,int> > >::iterator it = nodos.begin();
	BinTree<pair<string,int>> b = *it;
	cout << "recorrido en preorden:" << endl;
	preorden(b);

	cout << "recorrido en inorden:" << endl;
	inorden(b);
}
