// Film.h

#ifndef FILM_H
#define FILM_H
#include <string>
#include <vector>

using namespace std;

struct Film {
    string name;
    int year;
    string country;
    vector<int> rating;
    double average_rating;
};

#endif