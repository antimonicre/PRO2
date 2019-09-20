#include "Estudiant.hh"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int M, N, S, dni, pos;
    cin >> M >> N >> S;
    vector <bool> v(N,false);
    
    //Vector de asignaturas que cuentan en la media (tamaño S)
    for (int x=0; x<S;x++) {
        cin >> pos;
        v[pos-1] = true;
    }
    
	//Leemos dni y notas de un alumno y devolvemos su media en cada vuelta del for
	for (int i=0; i<M; i++) {
		double media = 0;
		cin >> dni;
		cerr << dni << endl; Estudiant e(dni);
		
        //Calcular media
		for (int j = 0; j < N; j++) {
		  double x;
			cin >> x;
			if (v[j]) {media+=x;}
		}
		
		media /= S;
		
		//Se añade la nota al estudiante e
		e.afegir_nota(media);
        
        //Se escribe la media
		e.escriure();
	}
	
}
