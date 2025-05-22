
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
namespace pd

{

static string lcsDP(const string& s, const string& t){

    const size_t n = s.size();
    const size_t m = t.size();

    vector<vector<int>> matrizDP(n + 1, vector<int>(m + 1, 0));

    for (size_t i = 1; i <= n; ++i)
        for (size_t j = 1; j <= m; ++j)
            matrizDP[i][j] = (s[i - 1] == t[j - 1]) ? matrizDP[i - 1][j - 1] + 1 : max(matrizDP[i - 1][j], matrizDP[i][j - 1]);

    string lcs;
    lcs.reserve(matrizDP[n][m]);

    size_t i = n, j = m;
    while (i > 0 && j > 0){

        if (s[i - 1] == t[j - 1]){
            lcs.push_back(s[i - 1]);
            --i; --j;
        }
        else if (matrizDP[i - 1][j] >= matrizDP[i][j - 1])
            --i;
        else
            --j;
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

vector<pair<string, string>>
sequenceDifference(const string& s, const string& t){
    const string lcs = lcsDP(s, t);

    vector<pair<string, string>> diferencias;

    size_t i = 0, j = 0, k = 0;

    while (i < s.size() || j < t.size()){

        if (k < lcs.size() && i < s.size() && j < t.size() && s[i] == t[j] && s[i] == lcs[k]){
            ++i; ++j; ++k;
        }
        else{
            string bloqueS, bloqueT;

            while (i < s.size() && (k >= lcs.size() || s[i] != lcs[k])){
                bloqueS.push_back(s[i++]);
            }

            while (j < t.size() && (k >= lcs.size() || t[j] != lcs[k])){
                bloqueT.push_back(t[j++]);
            }

            if (!bloqueS.empty() || !bloqueT.empty())
                diferencias.emplace_back(move(bloqueS), move(bloqueT));
        }
    }

    return diferencias;
}

}
