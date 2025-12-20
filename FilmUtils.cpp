// FilmUtils.cpp

#include <film.h>
#include <string>
#include <iostream>
#include <vector>

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

void searchFilmByCountry(vector<Film>& films, string country)
{
    cout << endl << ">>>> Фильмы <<<<" << endl;
    cout << "Страна: " << country << endl;
    for (int i = 0; i < films.size(); i++)
        if (films[i].country.find(country) != string::npos) {
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

vector<Film> addFilm(vector<Film> films)
{
    Film film;
    cout << "Введите название фильма: ";
    getline(cin, film.name);

    cout << "Введите год выхода фильма: ";
    cin >> film.year;
    cin.ignore();

    cout << "Введите страну производства фильма: ";
    getline(cin, film.country);

    film.rating.resize(5);
    cout << "Введите оценки (массив из пяти элементов, например, 6 5 7 6 8) фильма: ";
    for (int i = 0; i < 5; i++)
        cin >> film.rating[i];
    cin.ignore();
    count_average_rating(film);

    films.push_back(film);

    return films;
}

vector<Film> creatFilms()
{
    vector<Film> films;
    Film film;
    film.name = "1+1";
    film.year = 2011;
    film.country = "Франция";
    film.rating = { 5, 6, 8, 8, 9 };
    count_average_rating(film);
    films.push_back(film);

    film.name = "Джентельмены";
    film.year = 2019;
    film.country = "США";
    film.rating = { 7, 6, 8, 9, 9 };
    count_average_rating(film);
    films.push_back(film);

    film.name = "Брат";
    film.year = 1997;
    film.country = "Россия";
    film.rating = { 7, 9, 8, 8, 8 };
    count_average_rating(film);
    films.push_back(film);

    film.name = "Фишер";
    film.year = 2023;
    film.country = "Россия";
    film.rating = { 6, 5, 8, 9, 7 };
    count_average_rating(film);
    films.push_back(film);

    return films;
}
