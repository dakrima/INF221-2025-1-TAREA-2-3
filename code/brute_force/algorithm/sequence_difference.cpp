
#include <string>
#include <vector>
#include <utility>

using namespace std;
namespace fuerza_bruta
{
namespace detalle
{
    void lcsBT(const string& s, size_t i, const string& t, size_t j, string& actual, string& mejor){

        if (i == s.size() || j == t.size()){
            if (actual.size() > mejor.size())
                mejor = actual;
            return;
        }
        if (s[i] == t[j]){
            actual.push_back(s[i]);
            lcsBT(s, i + 1, t, j + 1, actual, mejor);
            actual.pop_back();
        }

        lcsBT(s, i + 1, t, j, actual, mejor);

        lcsBT(s, i, t, j + 1, actual, mejor);
    }

    string lcsFuerzaBruta(const string& s, const string& t){
        string actual, mejor;
        lcsBT(s, 0, t, 0, actual, mejor);
        return mejor;
    }
}

vector<pair<string, string>>

sequenceDifference(const string& s, const string& t){

    const string lcs = detalle::lcsFuerzaBruta(s, t);

    vector<pair<string, string>> diferencias;

    size_t i = 0, j = 0, k = 0;

    while (i < s.size() || j < t.size()){

        if (k < lcs.size() && i < s.size() && j < t.size() && s[i] == t[j] && s[i] == lcs[k]){
            ++i; ++j; ++k;
        }
        else{

            string bloqueS, bloqueT;

            while (i < s.size() && (k >= lcs.size() || s[i] != lcs[k]))
                bloqueS.push_back(s[i++]);

            while (j < t.size() && (k >= lcs.size() || t[j] != lcs[k]))
                bloqueT.push_back(t[j++]);

            if (!bloqueS.empty() || !bloqueT.empty())
                diferencias.emplace_back(move(bloqueS), move(bloqueT));
        }
    }

    return diferencias;
}

}

