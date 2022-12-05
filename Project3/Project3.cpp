// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

void ReadFromFile(int year, string filename, map<int, vector<pair<string, pair<string, string>>>>& map) {
    ifstream inFile(filename, ios_base::binary);
    //for testing purposes
    if (inFile.is_open()) {
        //check if the file is open
        cout << "File " << filename << " is open" << endl;
    }
    else {
        cout << "File is closed" << endl;
    }
    //variable to store current line read
    string currentline = "";
    while (getline(inFile, currentline)) {
        //Sample Line from .txt file: Mary,F,7065
        //keep reading until there are no more lines to get
        //read current line and store to variable
        //variable definitions needed for parsing lines
        int comma = 0;
        string name = "";
        string gender = "";
        string frequency = "";
        // for loop to iterate through line read and extract name, gender, frequency
        for (int i = 0; i < currentline.size(); i++) {
            if (currentline.at(i) != ',') {
                //if the current char has no comma
                if (currentline.at(i) != '\r') {
                    //or '\r' go ahead and extract
                    if (comma == 0) {
                        //before first comma store to string name
                        name = name + currentline.at(i);
                    }
                    else if (comma == 1) {
                        //after first comma store to string gender
                        gender = gender + currentline.at(i);
                    }
                    else if (comma == 2) {
                        //after second comma store to string frequency
                        frequency = frequency + currentline.at(i);
                    }
                }
            }
            else {
                //if a comma is reached increment variable
                comma++;
            }
        }
        //add to map
        map[year].push_back(make_pair(name, make_pair(gender, frequency)));
    }
}
int main()
{
    //reading of files
    //int year, string name, string sex, string frequency
    map<int, vector<pair<string, pair<string, string>>>> mapofData;
    for (int i = 1880; i != 2011; i++) {
        string nameoffile = ""; 
        nameoffile = "archive/yob" + to_string(i) + ".txt";
        ReadFromFile(i, nameoffile, mapofData);
    }
    //access like so
    /*
    cout << myvec[i].first << ", " << myvec[i].second.first
              << ", " << myvec[i].second.second << endl;
    */

    //menu driven program
}
