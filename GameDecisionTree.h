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

    // helper function to assign children properly, still creates duplicate nodes though
    void assignChild(Node<T>* current, unordered_map<int, T> uo_map) {
        T tempStory = uo_map[current->data.eventNumber];

        // assigns left child
        if (tempStory.leftEventNumber != -1) {
            T leftStory = uo_map[tempStory.leftEventNumber];
            Node<T>* tempNode = new Node<T>(leftStory);
            current->left = tempNode;
            assignChild(current->left, uo_map);
        }
        // assigns right child
        if (tempStory.rightEventNumber != -1) {
            T rightStory = uo_map[tempStory.rightEventNumber];
            Node<T>* tempNode = new Node<T>(rightStory);
            current->right = tempNode;
            assignChild(current->right, uo_map);
        }

    }

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        //opens filename as an input file stream
        ifstream MyFile(filename);
        // check if is able to open
        if (!MyFile.is_open()) {
            cout << "Error: Unable to open file " << filename << endl;
            return;
        }
        //declare variables to be used within while loop
        unordered_map<int, T> uo_map;

        string line, description, eventString, leftString, rightString;
        int eventNum, leftNum, rightNum;
        int firstEvent =-1; // keeps track of first line in story text

        //reads lines from file
        while (getline(MyFile, line)) {
            stringstream ss(line); // use a stringstream as a buffer

            // assume file is formatted correctly, get each chunk
            getline(ss, eventString, delimiter); // read until delimiter
            eventNum = stoi(eventString); // turn string to integer
            //cout<<"eventNum is "<<eventNum<<endl; // used cout statements to check

            // description should be second followed by children
            getline(ss, description, delimiter); //cout<<"description is "<<description<<endl;
            getline(ss, leftString, delimiter);
            leftNum = stoi(leftString); //cout<<"leftNum is "<<leftNum<<endl;
            getline(ss, rightString, delimiter);
            rightNum = stoi(rightString); //cout<<"rightNum is "<<rightNum<<endl;

            //insert story into dictionary data structure O(1) access
            uo_map[eventNum] = T(description, eventNum, leftNum, rightNum);

        }
        MyFile.close();
        // build binary tree
        T tempStory = uo_map[firstEvent];
        Node<T>* tempNode = new Node<T>(tempStory);
        root = tempNode;
        assignChild(root, uo_map);

    }


    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        cout << "playGame" << endl;
    }
};

#endif // GAMEDECISIONTREE_H