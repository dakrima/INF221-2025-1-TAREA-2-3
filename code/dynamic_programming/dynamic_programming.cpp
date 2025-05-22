
#include <iostream>
#include <string>
#include <vector>
#include "algorithm/sequence_difference.h"

using namespace std;

int main(){

    vector<pair<string, string>> casosPrueba = {
        { "ABCLGH", "AELFHR" },
        { "AGGJAB", "GZJZAMB" },
        {"Este es un texto", "Este es otro texto"}
    };

    cout << casosPrueba.size() << '\n';

    for (auto& [s, t] : casosPrueba){

        auto diferencias = pd::sequenceDifference(s, t);

        cout << diferencias.size() << '\n';

        for (auto& [a, b] : diferencias){
            cout << a;
            if (!b.empty())
                cout << " " << b;
        }
    }
            cout << '\n';
    return 0;
}
