// MenuUtils.cpp

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
    cout << "\nСортировать фильмы:\n"
        << "1. Возрастание A-Z\n"
        << "2. Убывание Z-A\n"
        << "3. Год\n"
        << "4. Страна\n"
        << "5. Рейтинг по возрастанию 1-10\n"
        << "6. Рейтинг по убыванию 10-1\n"
        << "Введите номер действия: ";

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
        cout << "Такого действия нет. Повторите ввод!\n" << endl;
        return;
    }
    cout << "\nФильмы отсортированы." << endl;
    print(films);
}