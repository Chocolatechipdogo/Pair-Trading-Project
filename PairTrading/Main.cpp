/*
Stephanie Becerra, Andrea Aguirre, Theresa Nguyen

Pair Trading Project

*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <regex>
using namespace std;

const regex comma(",");

int main()
{
    ifstream  data("SHEL.csv");
    string line{};
    vector<vector<string>> table;
    while (data && getline(data, line)) {
        // Tokenize the line and store result in vector. Use range constructor of std::vector
        vector<string> row{ sregex_token_iterator(line.begin(),line.end(),comma,-1), sregex_token_iterator() };
        table.push_back(row);
    }

    for (int i = 1; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++) {
            cout << table[i][j] << "\t";
        }
        cout << endl;
    }

    //cout << table[3][1];
}
