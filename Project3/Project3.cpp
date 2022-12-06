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

struct Vertex
{
    string name;
    char gender;
    int popularity;
    Vertex(string _name, char _gender, int _popularity)
    {
        name = _name;
        gender = _gender;
        popularity = _popularity;
    }
};

bool isAlpha(Vertex a, Vertex b);

class Graph
{
private:
    vector<pair<Vertex, vector<Vertex>>> graph; // adjacency list
public:
    int numOfVertices;
    void insertEdge(Vertex from, Vertex to);
    void printVertex(Vertex v);
    void generateRandomName();
    void generateMaleName();
    void generateFemaleName();
    void generateNameLetter(char letter);
    void searchName(string name);
    void printGraph();
};

void Graph::insertEdge(Vertex from, Vertex to)
{
    for (auto it = graph.begin(); it != graph.end(); ++it)
    {
        if (it->first.name == from.name)
        {
            it->second.push_back(to);
            return;
        }
    }
    vector<Vertex> adj;
    adj.push_back(to);
    graph.push_back(make_pair(from, adj));
}

void Graph::generateRandomName()
{
    int min = 0;
    int max = 88000;
    
    // generate random number within range of database
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(min,max);
    auto random_integer = uni(rng);
    int index = 0;
    
    for (auto it = graph.begin(); it != graph.end(); ++it)
    {
        if (index == random_integer)
        {
            Vertex v = it->first;
            printVertex(v);
            return;
        }
        else
        {
            index++;
        }
    }
}

void Graph::printVertex(Vertex v)
{
    cout << "Name: " << v.name << std::endl;
    cout << "Gender: " << v.gender << std::endl;
    cout << "Popularity: " << v.popularity << std::endl;
}

void Graph::generateMaleName()
{
    int min = 0;
    int max = 88000;
    
    // generate random number within range of database
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(min,max);
    auto random_integer = uni(rng);
    int index = 0;
    
    for (auto it = graph.begin(); it != graph.end(); ++it)
    {
        if (index == random_integer)
        {
            if (it->first.gender == 'M')
            {
                Vertex v = it->first;
                printVertex(v);
                return;
            }
            else
            {
                random_integer++;
                index++;
            }
        }
    }
}

void Graph::generateFemaleName()
{
    int min = 0;
    int max = 88000;
    
    // generate random number within range of database
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(min,max);
    auto random_integer = uni(rng);
    int index = 0;
    
    for (auto it = graph.begin(); it != graph.end(); ++it)
    {
        if (index == random_integer)
        {
            if (it->first.gender == 'M')
            {
                Vertex v = it->first;
                printVertex(v);
                return;
            }
            else
            {
                random_integer++;
                index++;
            }
        }
    }
}

void Graph::generateNameLetter(char letter)
{
    int min = 0;
    int max = 88000;
    
    // generate random number within range of database
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(min,max);
    auto random_integer = uni(rng);
    int index = 0;
    
    for (auto it = graph.begin(); it != graph.end(); ++it)
    {
        if (index == random_integer)
        {
            if (it->first.name[0] == letter)
            {
                Vertex v = it->first;
                printVertex(v);
                return;
            }
            else
            {
                index++;
                random_integer++;
            }
        }
        else
        {
            index++;
        }
    }
}

void Graph::searchName(string name)
{
    for (auto it = graph.begin(); it != graph.end(); ++it)
    {
        if (it->first.name == name)
        {
            printVertex(it->first);
            return;
        }
    }
    cout << "Name not found in database!" << endl;
}

void Graph::printGraph()
{
    vector<Vertex> names;
    for (auto it = graph.begin(); it != graph.end(); ++it)
        names.push_back(it->first);
    
    sort(names.begin(), names.end(), isAlpha);
    
    for (int i = 0; i < names.size(); i++)
        printVertex(names.at(i));
}


bool isAlpha(Vertex a, Vertex b)
{
    return a.name < b.name;
}


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
