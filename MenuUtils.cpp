#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm> 
#include<string>
#include<windows.h>
#include<Film.h>
#include<MyUtils.h>

using namespace std;

void sortMenu(vector<Film>& films) {
    cout << "\nВыберите сортировку:\n"
        << "1. Название A-Z\n"
        << "2. Название Z-A\n"
        << "3. Год\n"
        << "4. Страна\n"
        << "5. Средняя оценка 1-10\n"
        << "6. Средняя оценка 10-1\n"
        << "Выберите действие: ";

    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 1:
        sort(films.begin(), films.end(), compareByNameAscending);
        break;
    case 2:
        sort(films.begin(), films.end(), compareByNameDescending);
        break;
    case 3:
        sort(films.begin(), films.end(), compareByYear);
        break;
    case 4:
        sort(films.begin(), films.end(), compareByCountry);
        break;
    case 5:
        sort(films.begin(), films.end(), compareByAverageRatingAscending);
        break;
    case 6:
        sort(films.begin(), films.end(), compareByAverageRatingDescending);
        break;
    default:
        cout << "Некорректный выбор." << endl;
        return;
    }
    cout << "Фильмы отсортированы." << endl;
    print(films);
}
