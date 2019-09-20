/**
 * @mainpage Practica PRO2 Primavera 2019

Se construye un programa modular que ofrece un menu de opciones para codificar y decodificar texto. Se introducen las clases <em>Idioma</em>, <em>TablaFrec</em> y <em>TreeCode</em>.

*/

/** @file program.cc
    @brief Programa principal para la <b>practica</b>.
*/

#include "Idioma.hh"
#include "TablaFrec.hh"
#include "TreeCode.hh"
#include <map>

/** @brief Programa principal para la <b>practica</b>.
*/
int main ()
{
	//SE INTRODUCEN LOS IDIOMAS INICIALES AL MAP
	map<string,Idioma> I;
	int num_idiomas;
	string id;

	cin >> num_idiomas;

	while (num_idiomas > 0) {
		Idioma idioma;
		cin >> id;
		idioma.leer_idioma(id);  //se lee un idioma
		I.insert(make_pair(idioma.consultar_id(),idioma)); //se inserta en el map de idiomas
		--num_idiomas;
	}

	//SE LEEN LAS INSTRUCCIONES
	string elemento; //que se quiere consultar
	string caracter; //caracter que se va a utilizar

		//Se leen el atributo y la id del idioma que se van a tratar
	cin >> elemento >> id;
	while (elemento != "fin") {

		map<string, Idioma>::iterator it = I.begin();
		it = I.find(id);

		//SI EXISTE:

			//CONSULTAR TABLA DE FRECUENCIA
			if (elemento == "tabla_frec") {
				cout << "Tabla de frecuencias de " << id << ":" << endl;
				if (it==I.end()) {
					cout << "El idioma no existe" << endl;
				}
				else {
					TablaFrec tabla_frecuencias = (it->second.consultar_tabla_frecuencias());
					tabla_frecuencias.escribir_tf();
				}
			}


			//CONSULTAR TREECODE
			else if (elemento == "treecode") {
				cout << "Treecode de " << id << ":" << endl;
				if (it==I.end()) {
					cout << "El idioma no existe" << endl;
				}
				else {
					TreeCode treecode = (it->second.consultar_treeCode());
					treecode.escribir_tree();
				}
			}


			//CONSULTAR CODIGOS
			else if (elemento == "codigos") {
				cin >> caracter;

				if (it==I.end()) {
					if (caracter== "todos") {
						cout << "Codigos de " << id << ":" << endl;
						cout << "El idioma no existe" << endl;
					}
					else {
						cout << "Codigo de " << caracter << " en " << id << ":" << endl;
						cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
					}
				}

				else {
					string s = "";
					BinTree<pair<string,int> > nodo = it->second.consultar_treeCode().consultar_nodo();
					it->second.crear_codigos(nodo,s);
					it->second.escribir_cods(id,caracter);
				}
			}

			//ANADIR O MODIFICAR IDIOMA
			else if (elemento == "anadir/modificar") {
				map<string, Idioma>::iterator ite = I.find(id);

				//No existe el idioma -> ANADIR
				if (ite==I.end()) {
					Idioma idioma2;
					idioma2.leer_idioma(id);
					I.insert(make_pair(id,idioma2));
					cout << "Anadido " << id << endl;
				}

				//Existe el idioma -> MODIFICAR
				else {
					Idioma idioma2 = (ite->second);
					idioma2.leer_idioma(id);
					BinTree<pair<string,int> > nodo = idioma2.consultar_treeCode().consultar_nodo();
					string s = "";
					idioma2.crear_codigos(nodo,s);
					I[id] = idioma2;
					cout << "Modificado " << id << endl;
				}
			}

			//CODIFICAR
			else if (elemento == "codifica") {
				string result, texto;
				cin >> texto;
				cout << "Codifica en " << id << " el texto:" << endl << texto << endl;

				if (it==I.end()) {
					cout << "El idioma no existe" << endl;
				}
				else {
					result = (it->second).codificar(texto);
					cout << result << endl;
				}
			}

			//DECODIFICAR
			else if (elemento == "decodifica") {
				string codigo, resultado;
				cin >> codigo;
				cout << "Decodifica en " << id << " el texto:" << endl << codigo << endl;

				if (it==I.end()) {
					cout << "El idioma no existe" << endl;
				}
				else {
					TreeCode treecode = it->second.consultar_treeCode();
					treecode.decodificar(codigo);
				}
			}

			cout << endl;
			cin >> elemento >> id;
		}
}
