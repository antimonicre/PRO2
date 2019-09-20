#include <list>
#include <iostream>
using namespace std;

void seleccio(const list<double>& l, list<double>& sel)
 /* Pre: l no es vacia, sol es vacia */
 /* Post: sel es el resultado de extraer de l los elementos debiles en media */
 {
 	int n=1;
 	list<double>::const_iterator it = l.begin();
 	sel.push_back(*it);
 	double count = *it;
	double x = *it;
	it++;
	if (!l.empty()) {
		while(it!=l.end()) {
			x = *it;
			count += x;
			++n;
			++it;
			if(count/n <= x) sel.push_back(x);
		}	
	}
 }
 
