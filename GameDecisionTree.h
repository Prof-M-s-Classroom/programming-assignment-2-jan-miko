#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;


public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        cout << "loadStoryFromFile" << endl;
        ifstream MyFile(filename);
        // check if is able to open
        /*if (!MyFile.is_open()) {
            cout << "Error: Unable to open file " << filename << endl;
            return;
        } */
        string line, description, eventString, leftString, rightString;
        int eventNum, leftNum, rightNum;
        while (getline(MyFile, line)) {
            stringstream ss(line); // use a stringstream as a buffer

            // assume file is formatted correctly, get each chunk
            getline(ss, eventString, delimiter); // read until delimiter
            eventNum = stoi(eventString); // turn string to integer
            cout<<"eventNum is "<<eventNum<<endl; // use cout statement to check

            // description should be second followed by children
            getline(ss, description, delimiter);
            cout<<"description is "<<description<<endl;
            getline(ss, leftString, delimiter);
            leftNum = stoi(leftString);
            cout<<"leftNum is "<<leftNum<<endl;
            getline(ss, rightString, delimiter);
            rightNum = stoi(rightString);
            cout<<"rightNum is "<<rightNum<<endl;
        }
        MyFile.close();
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        cout << "playGame" << endl;
    }
};

#endif // GAMEDECISIONTREE_H