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


//I am going to use the close part of the data to look for the 
float min(vector<vector <string>> currData)
{
    //string current = currData[1][4];
    float result = stof(currData[1][4]);
    for (int i = 2; i < currData.size(); ++i)
    {
        float curr = stof(currData[i][4]);
        if (result > curr)
        {
            result = curr;
        }
    }

    return result;
}

float max(vector<vector <string>> currData)
{
    //string current = currData[1][4];
    float result = stof(currData[1][4]);
    for (int i = 2; i < currData.size(); ++i)
    {
        float curr = stof(currData[i][4]);
        if (result < curr)
        {
            result = curr;
        }
    }

    return result;
}

float mean(vector<vector<string>> data)
{
    float result = stof(data[1][4]);
    int count = 1; 
    for (int i = 2; i < data.size(); ++i)
    {
        result += stof(data[i][4]);
        ++count;
    }
    result = result / count; 
    return result;
}

int get_number_of_days(vector<vector<string>> dataset)
{
    
    int count = 0;
    for (int i = 1; i < dataset.size(); ++i)
    {
        ++count;
    }
    return count;
}

float raw()
{
    return 0;

}


int main()
{
    ifstream  data("SHEL.csv");
    string line{};
    vector<vector<string>> shel;
    
    while (data && getline(data, line)) {
        // Tokenize the line and store result in vector. Use range constructor of std::vector
        vector<string> row{ sregex_token_iterator(line.begin(),line.end(),comma,-1), sregex_token_iterator() };
        shel.push_back(row);
    }
    cout << "~ The Shell Data ~" << endl;
    for (int i = 1; i < shel.size(); i++) {
        for (int j = 0; j < shel[i].size(); j++) {
            cout << shel[i][j] << "\t";
        }
        cout << endl;
    } 

    cout << endl;
    int dayShell = get_number_of_days(shel);
    cout << "Number of days in shell's data: " << dayShell << endl;
    cout << endl;
    cout << endl;

    cout << "~ The chevron Data ~" << endl;
    ifstream  data2("CVX.csv");
    string line2{};
    vector<vector<string>> cvx;
    while (data2 && getline(data2, line2)) {
        // Tokenize the line and store result in vector. Use range constructor of std::vector
        vector<string> row{ sregex_token_iterator(line2.begin(),line2.end(),comma,-1), sregex_token_iterator() };
        cvx.push_back(row);
    }

    for (int i = 1; i < cvx.size(); i++) {
        for (int j = 0; j < cvx[i].size(); j++) {
            cout << cvx[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
    int dayCvx = get_number_of_days(cvx);
    cout << "Number of days in shell's data: " << dayCvx << endl;

    
    float minShel = min(shel);
    float minCvx = min(cvx);
    float maxShel = max(shel);
    float maxCvx= max(cvx);
    //cout << " Testing if this is right collumn : " << minShel << endl;
    //cout << " Testing if this is right collumn for cvx: " << minCvx << endl;
    //cout << " Testing if this is right collumn : " << maxShel << endl;
    //cout << " Testing if this is right collumn for cvx: " << maxCvx << endl;

    float meanShel = mean(shel);
   // cout << " Testing  : " << meanShel << endl;
    float meanCvx = mean(cvx);
    //cout << " Testing if this is right collumn : " << meanCvx << endl;
    return 0;
}


