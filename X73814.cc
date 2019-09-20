#include "Estudiant.hh"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<Estudiant> v(n);
	int c = 1;
	for (int i = 0; i < n; i++){
	    v[i].llegir();
	    if (i != 0 && v[i].consultar_DNI() != v[i-1].consultar_DNI()) {c++;}
    }
	vector<Estudiant> res(c);
    int j = 0;
	for (int i = 0; i < n; i++) {
	    if (i==0) {res[0] = v[0];}
		else {
			if (v[i].consultar_DNI() != v[i-1].consultar_DNI()) {++j; res[j] = v[i];}
			else {
				if (res[j].te_nota()) {
					if (v[i].te_nota() && v[i].consultar_nota() > res[j].consultar_nota()) {
						res[j] = v[i];
					}
				}
				else {res[j] = v[i];}
			}
		}
	}
	
	for (int i = 0; i < c; i++) {
	    res[i].escriure();
    }
	
}