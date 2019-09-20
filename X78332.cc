#include <stack>
#include "BinTree.hh"
using namespace std;

int profundidad(const BinTree<int>& a){
	if(a.empty()) return 1;
	else return profundidad(a.left())+profundidad(a.right());
}

void cami_preferent(const BinTree<int>& a, stack<int>& c)
 /* Pre: c esta vacia */
 /* Post: c contiene el camino preferente de a; si no esta vacia, el primer
          elemento del camino esta en la cima de c */
{
	if(!a.empty()){
		BinTree<int> dreta = a.right();
		BinTree<int> esquerra = a.left();
		if(profundidad(esquerra)<profundidad(dreta)) cami_preferent(dreta,c);
		else cami_preferent(esquerra,c);
		c.push(a.value());
	}
}
