// Lab14-2.cpp

#include <iostream>
#include <string>
#include <vector>
#include <Film.h>
#include <MyUtils.h>
#include<windows.h>

using namespace std;

void sortMenu(vector<Film>& films);

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bool a = true;
    vector<Film> films;
    films = creatFilms();
    print(films);
    cout << endl;

    while (a) {
        cout << "0 - Сортировать" << endl;
        cout << "1 - Создать массив данных" << endl;
        cout << "2 - Считать данные из файла" << endl;
        cout << "3 - Записать в файл" << endl;
        cout << "4 - Удалить фильм" << endl;
        cout << "5 - Добавить фильм" << endl;
        cout << "6 - Поиск по стране" << endl;
        cout << "7 - Выход" << endl;
        string n_line;
        getline(cin, n_line);
        int n = stoi(n_line);
        switch (n)
        {
        case 0: {
            sortMenu(films);

            break;
        }
        case 1: {
            cout << "Введите количество фильмов: ";
            string m_line;
            getline(cin, m_line);
            cout << endl;
            int m = stoi(m_line);

            films = readFilmsFromConsole(m);

            break;
        }
        case 2: {
            string name;
            cout << "Введите имя файла: ";
            getline(cin, name);
            cout << endl;

            films = readFilmsFromFileAndCout(name);

            break;
        }
        case 3: {
            string name;
            cout << "Введите имя файла: ";
            getline(cin, name);
            cout << endl;

            writeFilmsIntoFile(films, name);

            break;
        }
        case 4:
        {
            cout << "Введите позицию фильма: ";
            string position_line;
            getline(cin, position_line);
            cout << endl;

            int position = stoi(position_line);
            films = deleteFilm(films, position);

            cout << "\n>>> Остались фильмы <<<";
            print(films);

            break;
        }
        case 5:
        {
            cout << "\nДобавить фильм: \n";
            films = addFilm(films);

            cout << endl;
            print(films);

            break;

        }

        case 6:
        {
            string country;
            cout << "\nВведите часть страны для поиска: ";
            getline(cin, country);

            searchFilmByCountry(films, country);

            break;
        }

        case 7: {
            a = false;
            break;
        }
        default:
            cout << "Такого действия нет. Повторите ввод!" << endl;
            break;
        }
    }
    return 0;
}