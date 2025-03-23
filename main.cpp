#include <iostream>
#include <string>
#include "GameDecisionTree.h"
using namespace std;
int main() {
    GameDecisionTree<Story> myGame;

    string filename = "C:\\Users\\bauti\\CLionProjects\\programming-assignment-2-jan-miko\\story.txt"; //Specify file
    char delimiter = '|';                // '|' is the delimiter, change if needed

    // Load the story data from the file
    myGame.loadStoryFromFile(filename, delimiter);

    // Start the game
    myGame.playGame();

    return 0;
}