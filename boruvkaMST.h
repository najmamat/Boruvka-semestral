//
// Created by Matouš Najman on 13.01.2023.
//

#ifndef SCHOOL_BORUVKAMST_H
#define SCHOOL_BORUVKAMST_H
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct Hrana {
    int v1, v2, hodnota;
    bool operator<(const Hrana& other) const {
        return hodnota < other.hodnota;
    }
    bool operator==(const Hrana& other) const
    {
        return (v1 == other.v1) && (v2 == other.v2) && (hodnota == other.hodnota);
    }
};

struct Komponenta {
    vector<int> vrcholy;
    int size() const {
        return vrcholy.size();
    }
};

struct ResultType {
    vector<Hrana> hrany;
    int hodnota;
};

struct InputType {
    int pocetVrcholu, pocetHran;
    vector<Hrana> hrany;
};

ResultType BoruvkaKostra(const vector<Hrana>& hrany, int numVrcholy);


#endif //SCHOOL_BORUVKAMST_H
