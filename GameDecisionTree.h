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
        // check if is able to opem
        /*if (!MyFile.is_open()) {
            cout << "Error: Unable to open file " << filename << endl;
            return;
        } */
        cout << "before loop" << endl;
        string line;
        while (getline(MyFile, line)) {
            cout << line << endl;
            cout << "looping" << endl;
        }
        cout << "after loop" << endl;
        MyFile.close();
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        cout << "playGame" << endl;
    }
};

#endif // GAMEDECISIONTREE_H