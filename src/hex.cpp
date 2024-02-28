#include <iostream>

using namespace std;

const int N_LLETRES = 6;
const char LLETRES[N_LLETRES] = { 'A', 'B', 'C', 'D', 'E', 'F' };

const int NOT_FOUND = -1;

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

void cercarLletra(char c, bool& trobat, int& pos) {
    int a = 0, b = N_LLETRES - 1, m;
    trobat = false;
    while (a <= b and not trobat) {
        m = (a + b) / 2;
        if (c == LLETRES[m]) trobat = true;
        else if (c < LLETRES[m]) b = m - 1;
        else a = m + 1;
    }
    pos = m;
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
        int num = NOT_FOUND;
        if (c >= '0' and c <= '9') num = c - '0';
        else {
            bool trobat;
            int pos;
            cercarLletra(c, trobat, pos);
            if (trobat) num = pos + 10;
        }
        if (num == NOT_FOUND) valid = false;
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