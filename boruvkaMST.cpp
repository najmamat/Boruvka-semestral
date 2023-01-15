//
// Created by Matouš Najman on 13.01.2023.
//

#include "boruvkaMST.h"
#include <vector>

using namespace std;

ResultType BoruvkaKostra(const vector<Hrana>& hrany, int numVrcholy){
    vector<Komponenta> komponenty(numVrcholy);
    vector<Hrana> kostra;
    //Inicializace komponent
    for (int i = 0; i < numVrcholy; i++) {
        komponenty[i].vrcholy.push_back(i);
    }

    int numKomponenty = numVrcholy;
    int kostraVáha = 0;
    while (numKomponenty > 1) {
        vector<Hrana> minHrany(numVrcholy, {0, 0, 1000000});
        //Hledání minimálních hran
        for (Hrana hrana : hrany) {
            int koren_1 = komponenty[hrana.v1].vrcholy[0];
            int koren_2 = komponenty[hrana.v2].vrcholy[0];
            if (koren_1 == koren_2) {
                continue;
            }
            if (hrana.hodnota < minHrany[koren_1].hodnota) {
                minHrany[koren_1] = hrana;
            }
            if (hrana.hodnota < minHrany[koren_2].hodnota) {
                minHrany[koren_2] = hrana;
            }
        }
        //Sloučení vrcholů do komponent a přidání hran do kostry
        for (int i = 0; i < numVrcholy; i++) {
            Hrana hrana = minHrany[i];
            if (hrana.hodnota == INT_MAX) {
                continue;
            }
            int koren_1 = komponenty[hrana.v1].vrcholy[0];
            int koren_2 = komponenty[hrana.v2].vrcholy[0];
            if (koren_1 == koren_2) {
                continue;
            }
            if (find(kostra.begin(), kostra.end(), hrana) == kostra.end()) {
                kostra.push_back(hrana);
                kostraVáha += hrana.hodnota;
            }
            for (int vertex : komponenty[koren_2].vrcholy) {
                komponenty[vertex] = komponenty[koren_1];
                komponenty[koren_1].vrcholy.push_back(vertex);
            }
            numKomponenty--;
        }
    }
    return {kostra, kostraVáha};
};