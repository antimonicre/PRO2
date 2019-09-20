#include <iostream>
using namespace std;

int main() {
    int n, x, a, sum=0;
    string s;
    cin >> n >> x;
    
    for (int i=1; i<n+1; i++) {
        while (cin >> a) {
            if (a==x) {
                getline(cin,s);
                break;
            }
            else sum += a;
        }
        cout << "La suma de la secuencia " << i << " es " << sum << endl;
        sum = 0;
    }
    
}
