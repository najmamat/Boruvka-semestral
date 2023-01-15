#include <iostream>
#include <vector>
#include <cstring>
#include "boruvkaMST.h"

using namespace std;

void printHelp(){
    cout << "Zkopírujte input z textového souboru a vložte do terminálu.\n"
            "Hranu znázorňují 3 čísla, která oddělujte mezerou.\n"
            "#a #b #c\n"
            "a = id vrcholu odkud hrana vychází\n"
            "b = id vrcholu kam hrana směřuje\n"
            "c = hodnota hrany\n"
            "Podmínky:\n"
            "- Graf musí být spojitý\n"
            "- Počet vrcholů začíná od 0, tzv. když zadáte počet vrcholů 4, graf by měl obsahovat 5 vrcholů:\n"
            "- 0, 1, 2, 3, 4\n\n"
            "Příklad vstupu:\n"
            "6 4\n"
            "0 1 2\n"
            "0 2 5\n"
            "0 3 3\n"
            "1 2 1\n"
            "1 3 1\n"
            "2 3 2\n\n"
            "Tento graf má 4 vrcholy spojené 6 hranami.\n"
            "Hrany jsou:\n"
            "(0 -> 1), 2\n"
            "(0 -> 2), 5\n"
            "(0 -> 3), 3\n"
            "(1 -> 2), 1\n"
            "(1 -> 3), 1\n"
            "(2 -> 3), 2\n\n"
            "Argumenty:\n"
            "--help - Zobrazí tuhle --help informaci \n" << endl;
}
void printEdge(const Hrana& hrana) {
    cout << "(" << hrana.v1 << ", " << hrana.v2 << ") -> " << hrana.hodnota << endl;
}

InputType readInput() {
    int pocetHran, pocetVrcholu;
    cin >> pocetHran >> pocetVrcholu;

    vector<Hrana> hrany;
    int v1, v2, hodnota;

    for (int i = 0; i < pocetHran; i++) {
        cin >> v1 >> v2 >> hodnota;
        hrany.push_back({v1, v2, hodnota});
    }
    return {pocetVrcholu, pocetHran, hrany};
}

void getInputAndUseAlgorithm() {
    InputType input = readInput();
    ResultType result = BoruvkaKostra(input.hrany, input.pocetVrcholu);
    cout << "Vaha kostry " << result.hodnota << endl;
    for (Hrana hrana : result.hrany) {
        printEdge(hrana);
    }
};

int main(int argc, char** argv) {
    if(argc == 2 && strcmp(argv[1], "--help")==0) {
        printHelp();
    } else {
        cout << "Zadejte graf: (pro návod zadejte --help)" << endl;
        getInputAndUseAlgorithm();
    }
    return 0;
}
