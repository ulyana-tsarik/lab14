// StringUtils.cpp

#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string> getParts(string line)
{
    vector<string> parts;
    size_t start = 0;
    size_t end = line.find(';');

    while (end != string::npos) {
        parts.push_back(line.substr(start, end - start));
        start = end + 1;
        end = line.find(';', start);
    }
    parts.push_back(line.substr(start));

    return parts;
}