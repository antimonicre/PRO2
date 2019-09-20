#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Equipo {
    int eq, pt = 0, gm = 0, gr = 0;
};

void puntos (vector <Equipo>& v, int n) {
    pair <int, int> p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p.first >> p.second;
            if ( i!=j ) {
                if (p.first > p.second) { v[i].pt+= 3;}
                else if (p.first < p.second) { v[j].pt+= 3;}
                else {v[i].pt++; v[j].pt++;}
                v[i].gm += p.first;
                v[j].gm += p.second;
                v[i].gr += p.second;
                v[j].gr += p.first;
            }
        }
    }
}

bool compare (Equipo& a, Equipo& b) {
    if (a.pt == b.pt) {
        if (a.gm-a.gr == b.gm-b.gr) {
            return a.eq < b.eq;
        }
        else return (a.gm - a.gr) > (b.gm - b.gr);
    }
    return a.pt > b.pt;
    return a.eq < b.eq;
}

int main() {
    int N, x = 1;
    cin >> N;
    vector<Equipo> v(N);
    for (int f = 0; f < N; f++){
        v[f].eq = x++;
    }
    puntos(v,N);
    sort(v.begin(), v.end(), compare);
    for (int f = 0; f < N; f++){
        cout << v[f].eq << " " << v[f].pt << " " << v[f].gm << " " << v[f].gr << endl;
    }
}
