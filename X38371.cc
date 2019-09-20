#include <cassert>
#include <queue>
#include <iostream>

using namespace std;

double calcular_media(queue<int> c) {
    double media = 0;
    int i=0;
    while (!c.empty()) {
        media += c.front();
        c.pop();
        ++i;
    }
    return media/i;
}
int calcular_min(queue<int> c, int min) {
    int j=0;
    while (!c.empty()) {
        if (c.front() < min) min = c.front();
        c.pop();
        ++j;
    }
    return min;
}
int calcular_max(queue<int> c,int max) {
    int k=0;
    while (!c.empty()) {
        if (c.front() > max) max = c.front();
        c.pop();
        ++k;
    }
    return max;
}


int main() {
    int x, min=10000, max=-1000, aux;
    double suma=0;
    queue<int> cola;
    while (cin >> x && -1001<=x && x<=1000) {
        if (x==-1001) {
            if (!cola.empty()) {
                aux = cola.front(); 
                cola.pop();
                suma -= aux;
                if ((aux == min || aux == max) and not cola.empty()) {
                    min= calcular_min(cola,min);
                    max= calcular_max(cola,max);
                }
                    
                
            }
        }
        else{
            cola.push(x);
            if (cola.size() == 1)  {suma =x; min=max=x;}
            else suma += x;
            if (x<min) min=x;
            if (x>max) max=x;
        }
           
            if (cola.empty()) cout << 0 << endl;
           else {cout << "min " << min << "; " << "max " << max << "; " << "media " << suma/cola.size() << endl; 
            }
            
        }
        
    }

