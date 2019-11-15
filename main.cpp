#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include "Data.h"

using namespace std;

int main() {

    //declare fstream type variables
    ifstream dataFile;
    ofstream stackOutFile;
    ofstream queueOutFile;
    ofstream sortedOutFile;


    //Link csv file
    dataFile.open("../MovieData.csv");
    if (!dataFile.is_open()) {
        cout << "File not open!" << endl;
        return 1;
    } else {
        cout << "Reading MovieData.csv..." << endl;
    }

    //open  files with relative address
    stackOutFile.open("../stacked.txt");
    queueOutFile.open("../queue.txt");
    sortedOutFile.open("../sorted.txt");

    //Create new objects for each container
    stack<Data> Stack;
    queue<Data> Queue;
    priority_queue<Data> priorityQueue;

    //read the first line with column titles separately
    string titleHeader;
    getline(dataFile, titleHeader, ',');

    string yearHeader;
    getline(dataFile, yearHeader, ',');

    string scoreHeader;
    getline(dataFile, scoreHeader, ',');

    string runtimeHeader;
    getline(dataFile, runtimeHeader, ',');

    string genreHeader;
    getline(dataFile, genreHeader, ',');

    string ratingHeader;
    getline(dataFile, ratingHeader);


    //Print Headers
    stackOutFile << titleHeader << "\t" << yearHeader << "\t" << scoreHeader << "\t" << runtimeHeader << "\t"
                 << genreHeader << "\t"
                 << ratingHeader << endl << endl;
    queueOutFile << titleHeader << "\t" << yearHeader << "\t" << scoreHeader << "\t" << runtimeHeader << "\t"
                 << genreHeader << "\t"
                 << ratingHeader << endl << endl;
    sortedOutFile << titleHeader << "\t" << yearHeader << "\t" << scoreHeader << "\t" << runtimeHeader << "\t"
                  << genreHeader << "\t"
                  << ratingHeader << endl << endl;

    //read the file by each variable line
    while (!dataFile.eof()) {

        string title;
        getline(dataFile, title, ',');

        string yearString;
        getline(dataFile, yearString, ',');

        string scoreString;
        getline(dataFile, scoreString, ',');

        string runtimeString;
        getline(dataFile, runtimeString, ',');

        string genre;
        getline(dataFile, genre, ',');

        string rating;
        getline(dataFile, rating);

        //Convert from strings to correct data type
        int year = stoi(yearString);
        double score = stod(scoreString);
        int runtime = stoi(runtimeString);

        //Stores each item in to a Data class object
        Data newData = Data(title, year, score, runtime, genre, rating);



        //Repeatedly places the Data objects into an STL stack container
        Stack.push(newData);
        //Repeatedly places the Data objects into an STL queue container
        Queue.push(newData);
        //Repeatedly places the Data objects into an STL priority_queue container
        priorityQueue.push(newData);
    }

    cout << "Printing data to stack.txt..." << endl;
    while (!Stack.empty()) {
        //Writing the data into a file named “stacked.txt”
        stackOutFile << Stack.top();
        //Removing each Data object until the container is empty
        Stack.pop();
    }

    cout << "Printing data to queue.txt..." << endl;
    while (!Queue.empty()) {
        //Writing the data into a file named “stacked.txt”
        queueOutFile << Queue.front();
        //Removing each Data object until the container is empty
        Queue.pop();
    }

    cout << "Printing data to sorted.txt sorted by score ..." << endl << endl;
    while (!priorityQueue.empty()) {
        //Writing the data into a file named “stacked.txt”
        sortedOutFile << priorityQueue.top();
        //Removing each Data object until the container is empty
        priorityQueue.pop();
    }


    //close all files
    dataFile.close();
    stackOutFile.close();
    queueOutFile.close();
    sortedOutFile.close();

    return 0;
}