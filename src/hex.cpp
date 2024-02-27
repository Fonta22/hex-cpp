#include <iostream>

using namespace std;

const int N_LLETRES = 6;
const char LLETRES[N_LLETRES] = { 'A', 'B', 'C', 'D', 'E', 'F' };

int potencia(int base, int exp) {
    int total;

    if (exp == 0) total = 1;
    else {
        total = base;
        for (int i = 0; i < exp - 1; i++)
            total *= base;
    }
    
    return total;
}

int main() {
    cout << "Llargada del numero: ";
    int n;
    cin >> n;
    n--;
    cin.ignore();

    int total = 0;
    bool valid = true;

    cout << "Introdueix el numero:" << endl << "0x";
    char c = cin.get();

    while (n >= 0 and valid) {
        int num = -1;
        if (c >= '0' and c <= '9') num = c - '0';
        else {
            for (int i = 0; i < N_LLETRES; i++) {
                if (c == LLETRES[i]) num = i + 10;
            }
        }
        if (num == -1) valid = false;
        else {
            total += num * potencia(16, n);
            c = cin.get();
        }
        n--;
    }

    if (not valid) cout << "Nombre invalid" << endl;
    else cout << "Decimal: " << total << endl;
    
    return 0;
}