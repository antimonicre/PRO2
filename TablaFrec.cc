#include "TablaFrec.hh"

/** @file Idioma.hh
    @brief Implementacion de la clase TablaFrec
*/
TablaFrec::TablaFrec(){
	tabla = map<string,int>();
}

pair<string,int> TablaFrec::consultar_caracter(map<string,int>::iterator it)
{
	return *it;
}

map<string,int>::iterator TablaFrec::consultar_begin()
{
	return tabla.begin();
}


int TablaFrec::size()
{
	return tabla.size();

}

void TablaFrec::leer_tf()
{
	int num; //tamano tabla
	cin >> num;
	while (num > 0) {
		cin >> caracter;
		cin >> frecuencia;
		tabla[caracter] += frecuencia; //suma la frecuencia para actualizar la tabla correctamente en caso de modificar el idioma
		--num;
	}
}

void TablaFrec::escribir_tf()
{
	map<string,int>::iterator it;
	it = tabla.begin();
	while (it != tabla.end()) {
		cout << it->first << " " << it->second << endl;
		++it;
	}
}
