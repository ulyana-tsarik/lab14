// FilmUtils.cpp

#include <film.h>
#include <string>
#include <iostream>

using namespace std;

void count_average_rating(Film& film)
{
    double sum = 0.0;
    int n = film.rating.size();

    for (int i = 0; i < n; i++)
    {
        sum += film.rating[i];
    }

    film.average_rating = sum / n;
}

void print(Film& film)
{
    cout << "=== Фильм =======" << endl;
    cout << film.name << endl;
    cout << film.year << endl;
    cout << film.country << endl;
    cout << film.average_rating << endl;
    for (int i = 0; i < film.rating.size(); i++)
    {
        cout << film.rating[i] << " ";
    }
    cout << endl << endl;
}

void print(vector<Film>& films)
{
    cout << endl << "> Список фильмов <" << endl;
    for (int i = 0; i < films.size(); i++)
    {
        print(films[i]);
    }
}

bool compareByNameAscending(const Film& a, const Film& b) { return a.name < b.name; }
bool compareByNameDescending(const Film& a, const Film& b) { return a.name > b.name; }
bool compareByYear(const Film& a, const Film& b) { return a.year < b.year; }
bool compareByCountry(const Film& a, const Film& b) { return a.country < b.country; }
bool compareByAverageRatingAscending(const Film& a, const Film& b) { return a.average_rating < b.average_rating; }
bool compareByAverageRatingDescending(const Film& a, const Film& b) { return a.average_rating > b.average_rating; }

vector<Film> deleteFilm(vector<Film> films, int position)
{
    films.erase(films.begin() + position - 1);
    return films;
}