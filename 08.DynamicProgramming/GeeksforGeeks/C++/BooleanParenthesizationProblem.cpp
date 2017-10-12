#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * char middleOperator;
   if (middleOperator == '&') {
        T[i][j] += T[i][k] * T[k + 1][j];
   } else if (middleOperator == '|') {
        T[i][j] += (F[i][k] * T[k + 1][j]) 
                +  (T[i][k] * F[k + 1][j])
                +  (T[i][k] * T[k + 1][j]);
   } else if (middleOperator == '^') {
        T[i][j] += (F[i][k] * T[k + 1][j]) 
                +  (T[i][k] * F[k + 1][j]);
   }
 * */
 
int CountParenthesization(vector<char> symbols, vector<char> operators) {
    int slen = symbols.size();

    vector<vector<int> > T(slen, vector<int>(slen, 0));
    vector<vector<int> > F(slen, vector<int>(slen, 0));

    // base case
    for (int i = 0; i < slen; ++i) {
        if (symbols[i] == 'T') {
            T[i][i] = 1;
        } else if (symbols[i] == 'F') {
            F[i][i] = 1;
        }
    }

    for (int l = 1; l <= slen; ++l) {
        for (int begin = 0; begin <= slen - l; ++begin) {
            int end = begin + l - 1;

            for (int k = begin; k <= end && k < slen - 1; ++k) {

                char symbol = symbols[k];

                if (symbol == '&') {
                    T[begin][end] += T[begin][k] * T[k + 1][end];

                    F[begin][end] += F[begin][k] * T[k + 1][end]
                                   + T[begin][k] * F[k + 1][end];
                } 

                else if (symbol == '|') {
                    T[begin][end] += (F[begin][k] * T[k + 1][end]) 
                                  +  (T[begin][k] * F[k + 1][end])
                                  +  (T[begin][k] * T[k + 1][end]);

                    F[begin][end] += F[begin][k] * F[k + 1][end];
                }

                else if (symbol == '^') {
                    T[begin][end] += (F[begin][k] * T[k + 1][end]) 
                                  +  (T[begin][k] * F[k + 1][end]);

                    F[begin][end] += (F[begin][k] * F[k + 1][end]) 
                                  +  (F[begin][k] * T[k + 1][end]);
                }
            }
        }
    }

    return T[slen - 1][slen - 1];
}
