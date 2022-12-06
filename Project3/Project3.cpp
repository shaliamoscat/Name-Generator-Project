// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>
using namespace std;

void ReadFromFile(int year, string filename, map<int, vector<pair<string, pair<string, string>>>>& map) {
    //if data key's are years of files
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
void ReadFromFile2(string filename, map<string, vector<pair<string, string>>>& map2) {
    //if data keys's are names
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
        /*if (map2.find(name) != map2.end()) {
            if (map2[name].size() == 2) {
                //do nothing we want no duplicates
                //if the name exist for both genders do not insert
            }
            else {
                map<string, vector<pair<string, string>>>::iterator it;
                for (it = map2.begin(); it != map2.end(); ++it) {
                    //cout << it->first << " ->";
                    if (it->first == name) {
                        //do not insert anymore
                        if (it->second[0].first == gender) {
                            //do nothing bc we dont want duplicate
                        }
                        else {
                            map2[name].push_back(make_pair(gender, frequency));
                        }
                        break;
                    }
                }
            }
        }
        else {
        */
            map2[name].push_back(make_pair(gender, frequency));
        //}
    }
}
int main()
{
    //reading of files
    //int year, string name, string sex, string frequency
    map<int, vector<pair<string, pair<string, string>>>> mapofData;
    map<string, vector<pair<string, string>>> map2;
    for (int i = 1880; i != 2011; i++) {
        string nameoffile = ""; 
        nameoffile = "archive/yob" + to_string(i) + ".txt";
        //ReadFromFile(i, nameoffile, mapofData);
        ReadFromFile2(nameoffile, map2);
    }
    //cout << mapofData.size() << endl;
    cout << map2.size() << endl;
    //access like so

    //menu driven program
}
