#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map> // Used as a dictionary to organize story objects
#include <fstream> // Used to read lines from input file
#include <sstream> // Used to parse lines
#include <iostream> // Used to take user input and output game
#include "Node.h" // Used to build binary tree
#include "Story.h" // Used to organize parsed lines
#include <limits>

// Generic datatype
template <typename T>

// Underlying game data structure
class GameDecisionTree {

// Start of the binary tree
private:
    Node<T>* root;

    // Helper function to assign children properly
    void assignChild(Node<T>* rootPtr, Node<T>* current, unordered_map<int, T> uo_map) {
        T tempStory = uo_map[current->data.eventNumber];
       // cout << "Assigning for " << current->data.eventNumber << endl;

        // Assigns left child
        if (tempStory.leftEventNumber != -1) {
            bool leftMatchFound = true; // Assume true before running search
            Node<T>* tempNode = searchTree(rootPtr, tempStory.leftEventNumber);

            if (tempNode == nullptr) {
                leftMatchFound = false;// Set to false since not found
                T leftStory = uo_map[tempStory.leftEventNumber];
                Node<T>* leftNode = new Node<T>(leftStory);
                tempNode = leftNode;
            }
            current->left = tempNode;

            if (current->left != nullptr && !leftMatchFound) { // Only assign children if necessary
                assignChild(rootPtr, current->left, uo_map);
            }
        }
        // Assigns right child
        if (tempStory.rightEventNumber != -1) {
            bool rightMatchFound = true; // Assume true before running search
            Node<T>* tempNode = searchTree(rootPtr, tempStory.rightEventNumber);

            if (tempNode == nullptr) {
                rightMatchFound = false;// Set to false since not found
                T rightStory = uo_map[tempStory.rightEventNumber];
                Node<T>* rightNode = new Node<T>(rightStory);
                tempNode = rightNode;
            }
            current->right = tempNode;

            if (current->right != nullptr && !rightMatchFound) { // Only assign children if necessary
                assignChild(rootPtr, current->right, uo_map);
            }
        }
    }

        // Helper function to handle exception when nodes point to the same child
        Node<T>* searchTree(Node<T>* tempNodePtr, int searchNum) {
            Node<T>* searchNode = nullptr;

            if (tempNodePtr != nullptr) {
                if (tempNodePtr->data.eventNumber == searchNum) {
                    searchNode = tempNodePtr;
                }
                else {
                    searchNode = searchTree(tempNodePtr->right, searchNum);
                }
            }
        return searchNode;
        }

public:
    // Constructor: root always starts empty
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) { // O(N^2)

        // Opens filename as an input file stream
        ifstream MyFile(filename);

        // Check if is able to open
        if (!MyFile.is_open()) {
            cout << "Error: Unable to open file " << filename << endl;
            return;
        }

        // Declare variables to be used within while loop
        unordered_map<int, T> uo_map;
        string line, description, eventString, leftString, rightString;
        int eventNum, leftNum, rightNum;
        int firstEvent =-1; // Keeps track of first line in story text

        // Reads lines from file
        while (getline(MyFile, line)) {
            stringstream ss(line); // Use a stringstream as a buffer

            // Assume file is formatted correctly, get each chunk
            getline(ss, eventString, delimiter); // Read until delimiter
            eventNum = stoi(eventString); // Turn string to integer
           // cout<<"eventNum is "<<eventNum<<endl; // used cout statements to check
            if (firstEvent == -1) {
                firstEvent = eventNum;
            }
            // Description should be second followed by children
            getline(ss, description, delimiter); //cout<<"description is "<<description<<endl;
            getline(ss, leftString, delimiter);
            leftNum = stoi(leftString); //cout<<"leftNum is "<<leftNum<<endl;
            getline(ss, rightString, delimiter);
            rightNum = stoi(rightString); //cout<<"rightNum is "<<rightNum<<endl;

            // Insert story into dictionary data structure O(1) access
            uo_map[eventNum] = T(description, eventNum, leftNum, rightNum);
        }

        // Closes filename file
        MyFile.close();

        // Build binary tree
        T tempStory = uo_map[firstEvent];
        Node<T>* tempNode = new Node<T>(tempStory);
        root = tempNode;
        assignChild(root, root, uo_map);

    }


    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<T>* currNode = root;

        while (currNode && (currNode->left || currNode->right)) {
            cout << currNode->data.description << endl;
          /*  if (currNode->left)
               // cout << "1. " << currNode->left->data.description << "(go left)" << endl;
            if (currNode->right)
              //  cout << "2. " << currNode->right->data.description << "(go right)" << endl; */
            int choice;

            // Following input validation adapted from https://www.geeksforgeeks.org/how-to-use-cin-fail-method-in-cpp/
            while (true) {
                cout << "Enter choice: ";

                //Read input from user
                cin >> choice;

                // Check if the input operation failed
                if (cin.fail()) {

                    // Clear the error flags on the input stream
                    cin.clear();;

                    // Leave the rest of the line
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    // Ask the user to enter a valid int number only
                    cout << "Wrong input, please enter an integer: '1' or '2' \n";
                }
                else {
                    break;

                }
            }
            if (choice == 1) {
                currNode = currNode->left;
            }
            else if (choice == 2) {
                currNode = currNode->right;
            }
            else {
                cout << "Please enter either '1' or '2'" << endl;
            }
        }
        if (currNode)
            cout << currNode->data.description << endl;
        cout << "GAME OVER" << endl;
    }
};

#endif // GAMEDECISIONTREE_H
