#include <cassert>
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

void escriure (stack<string> p) {
    while (!p.empty()) {
        cout << p.top() << endl;
        p.pop();
    }
}

int main() {
    int n, categ, num;
    string titulo;
    cin >> n;
    vector<stack<string>> vec(n);

    int x;
    while (cin >> x && x!= -4) {
        
        if (x==-1) {
            cin >> titulo >> categ;
            vec[categ-1].push(titulo);
        }
        else if (x==-2) {
            cin >> num >> categ;
            if (num<=vec[categ-1].size()) {
               while (num>0) {
                    vec[categ-1].pop();
                    --num;
                
                } 
            }
        }
        else if (x==-3) {
            cin >> categ;
            cout << "Pila de la categoria " << categ << endl;
            escriure(vec[categ-1]);
            cout << endl;
        }
        
        
    }
}
