#include <map>
#include <iostream>
#include <string>

using namespace std;

int main() {
    char c; int count=0; string partit;
    map<string, int> m;
    map<string, int>::iterator i;
    
    while (cin >> c >> partit) {
         i = m.find(partit);
         if (c == 'a') {
             if (i == m.end()) {
                count = 1;
                m.insert(make_pair(partit, count));
            }
             else (*i).second++;
         }
         
         else if (c == 'f') {
             if (i == m.end()) cout << 0 << endl;
             else cout <<  (*i).second << endl; 
        }
         
    }
    
}
