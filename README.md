[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `[Jan Miko Bautista]`  
### **Student ID:** `[121756515]`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)
> This coding project assignment implements a text-based RPG using the data structure of binary decision tree.
> Each game event is represented as a node and includes options (1) OR (2) followed by a choice to make, following two 
> different paths; otherwise it would be a leaf node with the final game statement preceding the cout "GAME OVER".
> The story line is loaded from 'story.text', an external text file which is parsed to construct the decision tree.
> The game ends when a leaf node with both '-1' as the left and right child is reached.
> To make a decision the user is to input either '1' or '2' in the terminal which corresponds to the marked option and
> if another input is used otherwise, they would be given a message and be prompted to input the number 1 or number 2.
> Running the main cpp file with the story I had written in the story text file would allow the user to play a game with
> a theme of luck and fortune.
> The user is the main character in this game who had just experienced losing money at a casino.
> Immediately following the misfortune, a mysterious stranger presents the user with choices that lead to a series of
> unexpected events that can are beyond what one might consider normal.

---

## **2. Folder & File Structure**
- **`main.cpp`** → `[Describe its function]`  
- **`GameDecisionTree.h`** → `[Explain what this file contains]`  
- **`Node.h`** → `[Explain what this file contains]`  Used to build binary tree
- **`Story.h`** → `[Explain what this file contains]`  Used to organize parsed lines
- **`story.txt`** → `[Explain how the game loads story events from this file]`  
- 

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?  
- How are nodes linked based on left and right event numbers?  
- What happens if an event has `-1` as left or right children?  

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
- What happens when the player reaches a leaf node?  
- Explain the special case where multiple events lead to the same outcome.  

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
- How do you ensure nodes are properly linked?  
- Any challenges faced while handling file input?  

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

Example:
> Initially, my program was crashing when trying to access an uninitialized node. 
> I realized it was because I was not properly checking for `nullptr` before accessing child nodes, 
> so I added a check to prevent accessing uninitialized memory.

---

## **7. Sample Output & Walkthrough**
>Here is an example of what outputs when running the game. In this example the user's choice inputs are : 1, 2, 1, 3, 1, 
> and lastly 1.

C:\Users\bauti\CLionProjects\programming-assignment-2-jan-miko\cmake-build-debug\CS210PA2.exe
You're walking to your car after losing money at a casino. A stranger approaches you with an unexpected question. Would
you (1) play a game for a chest of good fortune OR (2) take a mystery gift box without stopping to play.
Enter choice:1
You choose to play the game and you're asked to choose between 2 chests: (1) one made of gold OR (2) one
made of jade.
Enter choice:2
You pick the jade chest. Inside is a deck of silver cards. The stranger says, "Draw a card, your fortune
depends on it." (1) Draw now OR (2) Ask if there's anything else you can do instead.
Enter choice:1
You're about to draw a card. (1) Pick from the left of the deck OR (2) Pick from the middle of the deck
Enter choice:3
Please enter either '1' or '2'
You're about to draw a card. (1) Pick from the left of the deck OR (2) Pick from the middle of the deck
Enter choice:1
You pull a joker card. You wake up and it was all a dream but it's the morning of the day you planned to
go to a casino (1) Bring a close friend. (2) Go by yourself.
Enter choice:1
You and your friend each win a $500,000 jackpot!. Congrats!
GAME OVER

Process finished with exit code 0

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(?)`  
- **Searching for an event in the tree** → `O(?)`  
- **Game traversal efficiency** → `O(?)`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
> I added a text file called 'teststory.txt' to move what was originally written in the story text into another file.
> This was so that I could add my own story with multiple levels and not have to change the name of the original file
> used in main.cpp
> I added a helper function within the GameDecisionTree.h in order to assign children properly without making duplicates.
> I also added another helper function in GameDecisionTree.h to handle the exception for when nodes point to the same child.
> I added a cout statement that reads "GAME OVER" because I wanted my game to say that to indicate that the story is ended.
> The user may then run the program again in order to play again.
> To give credit to where I had learned the input validation method I adapted for the story playGame function,
> I provided a comment that includes the url to cite the source as I did not just copy and paste the code.
---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
