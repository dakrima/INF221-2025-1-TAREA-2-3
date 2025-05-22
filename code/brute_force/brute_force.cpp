
#include <iostream>
#include <string>
#include <vector>
#include "algorithm/sequence_difference.h"

using namespace std;

int main(){
    vector<pair<string, string>> testCases = {
        { "ABCLGH", "AELFHR" },
        {"AGGJAB", "GZJZAMB"}
    };

    cout << testCases.size() << "\n";

    for (auto& [s, t] : testCases){

        auto diff = brute_force::sequenceDifference(s, t);

        cout << diff.size() << "\n";

        for (auto& [a, b] : diff){
            cout << a;

            if (!b.empty())
                cout << " " << b;
            cout << "\n";
        }
    }

    return 0;
}
