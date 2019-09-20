#include <iostream>
#include <vector>
using namespace std;

int comptatge_frontisses(const vector<int> &v)
 /* Pre: cert */
 /* Post: el resultat es el nombre d'elements frontissa de v */
 
{	
	int sum2=0;
	for (int i=0; i<v.size(); ++i) {
		sum2 += v[i];
	}
	int sum1=0, count=0, num=0;
	for (int i=0; i<v.size(); ++i) {
		sum1 += num;
		num = v[i];
		sum2 -= num;
		if(sum2-sum1 == num) count++;
		
	}
	
	return count;
}
