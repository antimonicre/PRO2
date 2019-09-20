#include <cassert>
#include <stack>
#include <iostream>

using namespace std;

int main() {
	int tam, x;
	cin >> tam;
	stack<int> pila;
	//Se construye la pila original
	int tam2 = tam/2;
	while (tam2>0) {
		cin >> x;
		pila.push(x);
		--tam2;
	}
	if (tam%2!=0) {
		cin >> x;
	}
	
	bool pal = true;
	
	//segunda parte de pila
	while (!pila.empty() and pal) {
		cin >> x;
		pal = pila.top() == x;
		pila.pop();
	}
	
	if (pal) cout << "SI" << endl;
	else cout << "NO" << endl;
}
