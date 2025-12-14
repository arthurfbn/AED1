#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    
    while (N--) {
        string linha;
        getline(cin, linha);
        
        int len = linha.length();
        int meio = len / 2;
        
        for (int i = meio - 1; i >= 0; i--) {
            cout << linha[i];
        }
        
        for (int i = len - 1; i >= meio; i--) {
            cout << linha[i];
        }
        
        cout << endl;
    }
    
    return 0;
}