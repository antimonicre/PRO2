#include <cassert>
#include <stack>
#include <iostream>

using namespace std;

int main() {
	char x;
	stack<char> pila;
	bool ok = true;
	
	while (cin >> x && x!= '.') {
		if (x== '(' ||x == '[') pila.push(x);
		else if (!pila.empty() && pila.top()=='(' && x== ')') pila.pop();
		else if (!pila.empty() && pila.top() == '[' && x==']') pila.pop();
		else ok=false;
	}
	
	if (ok && pila.empty()) cout << "Correcte" << endl;
	else cout << "Incorrecte" << endl;
}
