
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <sys/resource.h>
#include "algorithm/sequence_difference.h"

using namespace std;

long memoria_utilizadaKB(){
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;
}

int main(){

    ifstream entrada("data/dynamic_programming_input/inputs.txt");
    ofstream salida("data/dynamic_programming_output/outputs.txt");

    size_t K;
    entrada >> K;
    salida << K << "\n";

    size_t sumaLongitudes = 0;

    long memoriaAntes = memoria_utilizadaKB();
    auto inicio = chrono::high_resolution_clock::now();

    for (size_t caso = 0; caso < K; ++caso){
        size_t n, m;
        string s, t;

        entrada >> n;
        entrada.ignore();
        getline(entrada, s);

        entrada >> m;
        entrada.ignore();
        getline(entrada, t);

        sumaLongitudes += s.size();

        auto diff = pd::sequenceDifference(s, t);

        salida << diff.size() << "\n";
        for (auto& [a, b] : diff){
            salida << a;
            if (!b.empty()) salida << " " << b;
            salida << "\n";
        }
    }
    
    auto fin = chrono::high_resolution_clock::now();
    long memoriaDespues = memoria_utilizadaKB();

    long memoriaUtilizada = memoriaDespues - memoriaAntes;
    chrono::duration<double> duracion = fin - inicio;

    double promedio_longitud = static_cast<double> (sumaLongitudes) / K;

    ofstream mediciones("data/measurements/measurements.txt", ios::app);

    mediciones << promedio_longitud << ", " << duracion.count() << "\n";

    return 0;
}
