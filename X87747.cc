#include <iostream>
#include <vector>
using namespace std;

int solitaris(const vector<int> &v)
 /* Pre: v.size() > 0 */
 /* Post: el resultat es el nombre de solitaris a v */
 {
 	int ant, here, next, count=0;
 	if (v.size() == 1) return 1;
 	if (v[0]!=v[1]) ++count;
 	if (v[v.size()-1] != v[v.size()-2]) ++count;
 		for (int i=1; i<v.size()-1;i++) {
 		ant = v[i-1];
 		here = v[i];
 		next= v[i+1];
 		if (ant != here and here != next) ++count;
	 }	
	 return count;
 }
 
