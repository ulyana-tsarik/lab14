// MyUtils.h

#ifndef MYUTILS_H
#define MYUTILS_H

#include <string>
#include <film.h>

using namespace std;

void count_average_rating(Film& film);
void print(Film& film);
void print(vector<Film>& films);
vector<string> getParts(string line);
void writeFilmsIntoFile(vector<Film> films, string name);
vector<Film> readFilmsFromFileAndCout(string name);
vector<Film> readFilmsFromConsole(int m);
void sortMenu(vector<Film>& films);
bool compareByNameAscending(const Film& a, const Film& b);
bool compareByNameDescending(const Film& a, const Film& b);
bool compareByYear(const Film& a, const Film& b);
bool compareByCountry(const Film& a, const Film& b);
bool compareByAverageRatingAscending(const Film& a, const Film& b);
bool compareByAverageRatingDescending(const Film& a, const Film& b);
vector<Film> deleteFilm(vector<Film> films, int position);
void searchFilmByCountry(vector<Film>& films, string country);
vector<Film> inputFilm(vector<Film> films, string name);

#endif