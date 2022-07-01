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


//useing the adj close part of the data to look for the minimum
float min(vector<vector <string>> currData)
{
    //string current = currData[1][4];
    float result = stof(currData[1][5]);
    for (int i = 2; i < currData.size(); ++i)
    {
        float curr = stof(currData[i][5]);
        if (result > curr)
        {
            result = curr;
        }
    }

    return result;
}
//caculates the maximum value from the adjusted closed collumn assuming n
float max(vector<vector <string>> currData)
{
    //string current = currData[1][4];
    float result = stof(currData[1][5]);
    for (int i = 2; i < currData.size(); ++i)
    {
        float curr = stof(currData[i][5]);
        if (result < curr)
        {
            result = curr;
        }
    }

    return result;
}
// calculates the mean of the data form the adjusted close value, assuming that the vector has data
float mean(vector<vector<string>> data)
{
    float result = stof(data[1][5]);
    int count = 1; 
    for (int i = 2; i < data.size(); ++i)
    {
        result += stof(data[i][5]);
        ++count;
    }
    result = result / count; 
    return result;
}
//gets number of days in the dataset ignoring the first array which contains the names of the data
int get_number_of_days(vector<vector<string>> dataset)
{
    
    int count = 0;
    for (int i = 1; i < dataset.size(); ++i)
    {
        ++count;
    }
    return count;
}
// tryed to set this Function up to get the values like x^2 for corrilation
float raw()
{
    return 0;

}

// main has the code for converting data into strings to be stored in the vectors because of lack of time to try and turn it into a function.
//NOTE: sregex_token_iterator is something I am not to familiar with, in the future look into this
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
    cout << "Number of days in Cvx's data: " << dayCvx << endl;
    cout << endl;
    cout << endl;
    
    float minShel = min(shel);
    float minCvx = min(cvx);
    float maxShel = max(shel);
    float maxCvx= max(cvx);
    cout << " minimum of Shel: " << minShel << endl;
    cout << " minimum of CVX: " << minCvx << endl;
    cout << " maximum of Shel: " << maxShel << endl;
    cout << " maximum of CVX: " << maxCvx << endl;

    float meanShel = mean(shel);
    cout << " Shel's mean : " << meanShel << endl;
    float meanCvx = mean(cvx);
    cout << " CVX's mean : " << meanCvx << endl;
    return 0;
}


