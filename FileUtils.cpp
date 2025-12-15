// FileUtils.cpp

#include <film.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> getParts(string line);
void print(vector<Film>& films);

void writeFilmsIntoFile(vector<Film> films, string name)
{
    ofstream F;
    int m = films.size();

    F.open(name + ".txt");
    if (F) {
        for (int i = 0; i < m; i++)
        {
            F << films[i].name << ";" << films[i].year << ";" << films[i].country << ";" << films[i].average_rating << ";";
            for (int j = 0; j < 5; j++)
            {
                F << films[i].rating[j] << " ";
            }
            F << "\n";
        }
        cout << "Файл успешно создан" << endl;
    }
    else
    {
        cout << "Файл не удалось создать" << endl;
    }
    F.close();
}


vector<Film> readFilmsFromFileAndCout(string name)
{
    ifstream H;
    H.open(name + ".txt");
    int m = 0;
    if (H) {
        char* str = new char[256];
        while (!H.eof()) {
            H.getline(str, 256, '\n');
            ++m;
        }
        m--;
        delete str;
    }
    else
    {
        cout << "Файл не удалось открыть" << endl;
    }
    vector<Film> films(m);
    H.close();
    H.open(name + ".txt");

    int i = 0;
    while (!H.eof()) {
        char* str = new char[256];
        H.getline(str, 256, '\n');
        string tmp_line = str;
        delete str;

        if (tmp_line.size() > 1)
        {
            vector<string> parts = getParts(tmp_line);

            films[i].name = parts[0];
            films[i].year = stoi(parts[1]);
            films[i].country = parts[2];
            films[i].average_rating = stod(parts[3]);
            string rating_line = parts[4];

            vector<int> rating;
            stringstream ss(rating_line);
            string number;
            while (ss >> number) {
                rating.push_back(stoi(number));
            }
            films[i].rating = rating;
        }

        ++i;
    }

    print(films);

    H.close();
    return films;
}