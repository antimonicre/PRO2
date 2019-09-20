#include "Estudiant.hh"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(pair <int, double> par1, pair <int, double> par2) {
	if (par1.second == par2.second) {
		return par1.first < par2.first;
	}
		return par1.second > par2.second;
}

int main() {
    int M, N, S, dni, pos;
    cin >> M >> N >> S;
    vector <bool> v(N,false);
    pair<int, double> est;
    vector <pair <int, double> > vest(M);
    
    //Vector de asignaturas que cuentan en la media (tamaAao S)
    for (int x=0; x<S;x++) {
        cin >> pos;
        v[pos-1] = true;
    }
    
	//Leemos dni y notas de un alumno y devolvemos su media en cada vuelta del for
	for (int i=0; i<M; i++) {
		double media = 0;
		cin >> dni;
		cerr << dni << endl; 
		Estudiant e(dni);
		
        //Calcular media
		for (int j = 0; j < N; j++) {
		  double x;
			cin >> x;
			if (v[j]) {media+=x;}
		}
		
		media /= S;
		
		//Se añade la nota al estudiante e
		e.afegir_nota(media);
        
        //Añadir estudiante al vector de pairs
        est = make_pair(e.consultar_DNI(),e.consultar_nota());
        vest[i]= est;
        
	}
		
		//Ordenar vector
		sort(vest.begin(), vest.end(),comp);
		
		//Escribir el vector
		for (int k =0; k<M; k++) {
			cout << vest[k].first << " " << vest[k].second << endl;
		}
	
}
