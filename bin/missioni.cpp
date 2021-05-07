/**
 * @file missioni.cpp
 *
 * @version 01.01 202156
 *
 * @brief
 *
 * @ingroup missioni
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */

// Includes
#include <bits/stdc++.h>
using namespace std;

struct missione
{
    int tempo;
    int scadenza;
};

// Variabiles
int N;
vector <missione> missioni;
int soluzioni[366];

// Main code
int main()
{
    // Cncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Input
    cin >> N;
    missioni.resize(N);

    for(size_t i = 0; i < N; ++i)
        cin >> missioni[i].tempo >> missioni[i].scadenza;

    for(size_t i = 0; i < N; ++i)
    {
        for (size_t j = missioni[i].scadenza - missioni[i].tempo; j >= 0 && j != -1; --j)
        {
            if (soluzioni[j] + 1 > soluzioni[j + missioni[i].tempo])
                soluzioni[j + missioni[i].tempo] = soluzioni[j] + 1;
        }
    }

    int sol = INT_MIN;
    for (size_t i =0; i < 366; ++i)
        if(soluzioni[i] > sol)
            sol = soluzioni[i];

    cout << sol << endl;

    // End
    return 0;
}
