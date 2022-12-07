// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>
#include <random>
#include <chrono>
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
    void ReadFromFile2(string filename);
    void insertEdge(Vertex from, Vertex to);
    void printVertex(Vertex v);
    void generateRandomName();
    void generateMaleName();
    void generateFemaleName();
    void generateNameLetter(char letter);
    void searchName(string name);
    void printGraph();
};

void Graph::ReadFromFile2(string filename) {
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
    vector<Vertex> names;
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
        //add to graph here
        Vertex v(name, gender[0], stoi(frequency));
        names.push_back(v);
    }
    for (int i = 0; i < names.size(); i++)
    {
        if (i == names.size() - 1)
            break;

        Graph::insertEdge(names.at(i), names.at(i + 1));
    }
}

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
    //int min = 0;
    //int max = 88000;

    // generate random number within range of database
    //random_device rd;
    //mt19937 rng(rd());
    //uniform_int_distribution<int> uni(min, max);
    //auto random_integer = uni(rng);
    auto it = graph.begin();
    advance(it, rand() % graph.size());
    Vertex v = it->first;
    printVertex(v);
    //string random_key = it->first;
    //return random_key;

    /*int index = 0;

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
    */
}

void Graph::printVertex(Vertex v)
{
    cout << "Name: " << v.name << std::endl;
    cout << "Gender: " << v.gender << std::endl;
    cout << "Popularity: " << v.popularity << std::endl;
}

void Graph::generateMaleName()
{
    bool isMale = false;
    while (isMale == false) {
        auto it = graph.begin();
        advance(it, rand() % graph.size());
        //for (auto it = graph.begin(); it != graph.end(); ++it)
        //{
        if (it->first.gender == 'M')
        {
            isMale = true;
            Vertex v = it->first;
            printVertex(v);
        }
        //}
    }

    /*int min = 0;
    int max = 88000;

    // generate random number within range of database
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(min, max);
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
    */
}

void Graph::generateFemaleName()
{
    /*
    auto it = map.begin();
    advance(it, rand() % map.size());
    string random_key = it->first;
    return random_key;
    */
    //int min = 0;
    //int max = 88000;

    // generate random number within range of database
    bool isFemale = false;
    while (isFemale == false) {
        auto it = graph.begin();
        advance(it, rand() % graph.size());
        //for (auto it = graph.begin(); it != graph.end(); ++it)
        //{
        if (it->first.gender == 'F')
        {
            isFemale = true;
            Vertex v = it->first;
            printVertex(v);
        }
        //}
    }
}

void Graph::generateNameLetter(char letter)
{
    //int min = 0;
    //int max = 88000;

    //auto it = graph.begin();
    //advance(it, rand() % graph.size());
    //string random_key = it->first;
    //return random_key;
    // generate random number within range of database
    //random_device rd;
    //mt19937 rng(rd());
    //uniform_int_distribution<int> uni(min, max);
    //auto random_integer = uni(rng);
    //int index = 0;

    for (auto it = graph.begin(); it != graph.end(); ++it)
    {
        //if (index == random_integer)
        //{
        if (it->first.name[0] == letter)
        {
            Vertex v = it->first;
            printVertex(v);
            //return;
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

    auto start = std::chrono::high_resolution_clock::now();

    for (auto it = graph.begin(); it != graph.end(); ++it)
        names.push_back(it->first);

    sort(names.begin(), names.end(), isAlpha);

    for (int i = 0; i < names.size(); i++)
        printVertex(names.at(i));

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time for graph execution: " << duration.count() << endl;
    //cout << names.size() << endl;
}


bool isAlpha(Vertex a, Vertex b)
{
    return a.name < b.name;
}

void ReadFromFile(string filename, map<string, vector<pair<string, string>>>& map2) {
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
        map2[name].push_back(make_pair(gender, frequency));
    }
}
string GenerateRandom(map<string, vector<pair<string, string>>>& map) {
    //https://stackoverflow.com/questions/15425442/retrieve-random-key-element-for-stdmap-in-c
    auto it = map.begin();
    advance(it, rand() % map.size());
    string random_key = it->first;
    return random_key;
}
string GenerateMale(map<string, vector<pair<string, string>>>& map) {
    string randmale;
    bool isMale = false;
    while (isMale == false) {
        auto it = map.begin();
        advance(it, rand() % map.size());
        for (int j = 0; j < it->second.size(); j++) {
            if (it->second[j].first == "M") {
                isMale = true;
                randmale = it->first;
            }
        }
    }
    return randmale;
}
string GenerateFemale(map<string, vector<pair<string, string>>>& map) {
    string randfemale;
    bool isFemale = false;
    while (isFemale == false) {
        auto it = map.begin();
        advance(it, rand() % map.size());
        for (int j = 0; j < it->second.size(); j++) {
            if (it->second[j].first == "F") {
                isFemale = true;
                randfemale = it->first;
            }
        }
    }
    return randfemale;
}
string SearchName(string name, map<string, vector<pair<string, string>>>& map) {
    string result = "";
    if (map.find(name) != map.end()) {
        result = result + "successful";
    }
    else {
        result = result + "unsuccessful";
    }
    return result;
}
void SearchByLetter(vector<string>& name, char letter, map<string, vector<pair<string, string>>>& maps) {
    map<string, vector<pair<string, string>>>::iterator it;
    for (it = maps.begin(); it != maps.end(); ++it) {
        string found = "";
        string current = it->first;
        if (current.at(0) == letter) {
            found = it->first;
            name.push_back(found);
        }
    }
    for (int i = 0; i < name.size(); i++) {
        cout << name[i] << endl;
    }
}
void PrintMap(map<string, vector<pair<string, string>>>& maps) {
    map<string, vector<pair<string, string>>>::iterator it;
    auto start = std::chrono::high_resolution_clock::now();
    for (it = maps.begin(); it != maps.end(); ++it) {
        cout << it->first << endl;
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time for map execution: " << duration.count() << endl;
}

int main()
{
    Graph graph;

    //reading of files
    //int year, string name, string sex, string frequency
    map<string, vector<pair<string, string>>> map2;
    for (int i = 1800; i != 1916; i++) {
        //2008-2010
        string nameoffile = "";
        nameoffile = "archive/yob" + to_string(i) + ".txt";
        graph.ReadFromFile2(nameoffile);
        ReadFromFile(nameoffile, map2);
    }
    //cout << map2.size() << endl;

    //menu driven program
    while (true) {
        cout << "Welcome to the Name Generator!" << endl;
        cout << "------------------------------------" << endl;
        cout << "Please select an option: " << endl;
        cout << "1. Generate a random name" << endl;
        cout << "2. Generate a female name" << endl;
        cout << "3. Generate a male name" << endl;
        cout << "4. Search for a name" << endl;
        cout << "5. Generate names beginning with a letter" << endl;
        cout << "6. Print entire database" << endl;
        cout << "7. Exit" << endl;
        string random;
        string female;
        string male;
        vector<string> names;
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            //graph
            graph.generateRandomName();
            //map
            random = GenerateRandom(map2);
            cout << random << endl;
            break;

        case 2:
            //graph
            graph.generateFemaleName();
            //map
            female = GenerateFemale(map2);
            cout << female << endl;
            break;

        case 3:
            //graph
            graph.generateMaleName();
            //map
            male = GenerateMale(map2);
            cout << male << endl;
            break;

        case 4:
        {
            string name;
            cout << "Please input name to search for: ";
            cin >> name;
            //graph
            graph.searchName(name);
            //map
            string result = SearchName(name, map2);
            if (result == "successful") {
                cout << name << " exist in generator" << endl;
            }
            else {
                cout << name << " does not exist in generator" << endl;
            }
            break;

        }
        case 5:
            //graph
            char letter;
            cout << "Please input a letter to generate names with: " << endl;
            cin >> letter;
            graph.generateNameLetter(letter);
            //map
            SearchByLetter(names, letter, map2);
            break;

        case 6:
            //graph
            graph.printGraph();
            //map
            PrintMap(map2);
            //cout << map2.size() << endl;
            break;

        case 7:
            exit(0);
        }
    }
    return 0;
}
