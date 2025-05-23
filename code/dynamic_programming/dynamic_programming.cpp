
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "algorithm/sequence_difference.h"

using namespace std;

int main(){

    ifstream entrada("data/dynamic_programming_input/inputs.txt");
    ofstream salida("data/dynamic_programming_output/outputs.txt");

    size_t K;
    entrada >> K;
    salida << K << "\n";

    for (size_t caso = 0; caso < K; ++caso){
        size_t n, m;
        string s, t;

        entrada >> n;
        entrada.ignore();
        getline(entrada, s);

        entrada >> m;
        entrada.ignore();
        getline(entrada, t);

        auto diff = pd::sequenceDifference(s, t);

        salida << diff.size() << "\n";
        for (auto& [a, b] : diff){
            salida << a;
            if (!b.empty()) salida << " " << b;
            salida << "\n";
        }
    }

    return 0;
}
