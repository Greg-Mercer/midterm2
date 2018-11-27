#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "MyMap.hpp"
#include "standardDeviation.hpp"

using namespace std;

void read_file() {

    ifstream file;
    file.open("../studentMarks.txt");
    string word;
    string line;
    MyMap<string, double> studentMap;

    while (getline(file, line)) {
        istringstream iss(line);
        string student, curr;
        double gpa;
        iss >> student;
        iss >> gpa;

        studentMap.add(student, gpa);
    }

    cout << studentMap << endl;

    cout << "Standard deviation: " << studentMap.standard_deviation() << endl;

    cout << studentMap[5].first << " " << studentMap[5].second << endl;

    cout << studentMap["Wiggim"];
}

int main() {

    read_file();

    return 0;

}