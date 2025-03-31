[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `[Jan Miko Bautista]`  
### **Student ID:** `[121756515]`  

---

## **1. Project Overview**
> This coding project assignment implements a text-based RPG using the data structure of a binary decision tree that can
have a special case where parent nodes that share a child node.
- Each game event is represented as a node and includes options (1) OR (2) followed by a decision to make, following two 
different paths; otherwise it is a leaf node with the final game statement preceding a cout-statement: "GAME OVER".
> The story line is loaded from 'story.text', an external text file which is parsed to construct the decision tree.
- The game ends when a leaf node with both '-1' as the left and right child is reached.
> To make a decision the user is to input either '1' or '2' in the terminal which corresponds to the marked option and
if another input is used otherwise, they would be given a message and be prompted to input the number 1 or number 2.
- Running the main cpp file with the story I had written in the story text file would allow the user to play a game with
a theme of luck and fortune.
> The user is the main character in this game who had just experienced losing money at a casino.
- Immediately following the misfortune, a mysterious stranger presents the user with choices that lead to a series of
unexpected events that can are beyond what one might consider normal.

---

## **2. Folder & File Structure**
- **`main.cpp`** → `[Describe its function]`: Assigns file name, delimiter and calls functions from GameDecisionTree.h
- **`GameDecisionTree.h`** → `[Explain what this file contains]`: Contains GameDecisionTree class with its respective 
methods
- **`Node.h`** → `[Explain what this file contains]` : Class Used to build binary tree
- **`Story.h`** → `[Explain what this file contains]` : Class Used to organize parsed lines
- **`story.txt`** → `[Explain how the game loads story events from this file]` : Each of the lines in this file
represents a node with one left child node and one right child node

---

## **3. Decision Tree Construction**
> How are `Story` objects created from the text file?
- Each line in the text file is considered to be an individual Story object. The loadStoryFromFile() method assumes
that the txt file is formatted properly in the order of event number, delimiter, description, left event number, right
event number. Based on this assumption a Story object gets constructed for each line. These story objects are 
temporarily stored in an unordered map before being put into the binary tree data structure.

> How are nodes linked based on left and right event numbers?
- For each story object the left and right event numbers are checked. If it is not '-1' the binary tree data structure
is searched to see if a node already exists for that given child. If a respective node for the child isn't found in the
tree then a new Story Node is made for it. The parent's left and right pointers get assigned appropriately thereafter.

> What happens if an event has `-1` as left or right children?
- If an event has a value of '-1' for either of its children then no nodes are created for them and the left and right
pointers are nullptrs by default.

---

## **4. Game Traversal**
> How does user input determine the path taken?
- The user is prompted to input either a 1 or 2. Based on this input '1' traverses to the left child if it exists while
'2' traverses to the right child if it exists. Any other input is considered invalid and the game will not continue
otherwise.

> What happens when the player reaches a leaf node?  
- When a leaf node is reached the game is over. The loop structure is exited and "GAME OVER" is outputted.

> Explain the special case where multiple events lead to the same outcome.  
- Multiple events can lead to the same outcome. That is to say, that certain nodes can point to the same node as one 
of their children. The game proceeds as normal from there.

---

## **5. File Parsing & Data Loading**
> How is the file read and parsed using a delimiter?
- As previously mentioned in number 3, individual lines in the text file are treated as individual Story objects. The 
lines are parsed using a string stream as a buffer. Once the given delimiter is reached, the program assigns the text
read so far to the appropriate variable. It is assumed that the first string read is the event number followed by the
event description and the left and right children. After all variables are properly assigned, a new Story object is
constructed and inserted temporarily into an unordered map before creating the binary tree data structure.

> How do you ensure nodes are properly linked?
- The assignChild helper method was created in order to properly link the parent nodes to their children. For each 
parent the left and right event numbers are checked. If the numbers are not '-1' then the binary tree is searched to see
if a node already exists for that child. If the node does exist then the pointers for the parent are properly updated.
If the node does not exist yet an new Story Node is created by accessing the Story object stored in the unordered map 
and making a new node for it before updating the left and right pointers of the parent.

>Any challenges faced while handling file input? 
- One challenge that I faced when handling file input was that I accidentally left blank new lines at the end of the 
text file.This messed up my program because it wanted to create Story objects out of them. In order to resolve this 
issue, I simply deleted the extra lines.

---

## **6. Debugging Process (Errors & Fixes)**
> I had run into multiple errors in where the case was because I had added an extra curly brace or forgot a curly brace.
- A similar issue came up where I spent a long time trying to see where my code went wrong but the fix was just adding 
a semi-colon ; at the end of a line 

---

## **7. Sample Output & Walkthrough**
>Here is an example of what outputs when running the game. In this example the user's choice inputs are : 1, 2, 1, 3, 1, 
and lastly 1.

C:\Users\bauti\CLionProjects\programming-assignment-2-jan-miko\cmake-build-debug\CS210PA2.exe
You're walking to your car after losing money at a casino. A stranger approaches you with an unexpected question. Would
you (1) play a game for a chest of good fortune OR (2) take a mystery gift box without stopping to play.
> Enter choice:1
- You choose to play the game and you're asked to choose between 2 chests: (1) one made of gold OR (2) one
made of jade.
> Enter choice:2
- You pick the jade chest. Inside is a deck of silver cards. The stranger says, "Draw a card, your fortune
depends on it." (1) Draw now OR (2) Ask if there's anything else you can do instead.
> Enter choice:1
- You're about to draw a card. (1) Pick from the left of the deck OR (2) Pick from the middle of the deck
> Enter choice:3
- Please enter either '1' or '2'
- You're about to draw a card. (1) Pick from the left of the deck OR (2) Pick from the middle of the deck
> Enter choice:1
- You pull a joker card. You wake up and it was all a dream but it's the morning of the day you planned to
go to a casino (1) Bring a close friend. (2) Go by yourself.
> Enter choice:1
- You and your friend each win a $500,000 jackpot!. Congrats!
> GAME OVER

Process finished with exit code 0

---

## **8. Big-O Analysis of Core Methods**

- **Loading the tree from the file** → `O(N^2)` - Loading the data from the file, parsing the file and making story
objects would be O(N) time complexity but in order to insert individual nodes into the binary tree, a search is
necessary to check if the node is already in the tree. Since we do this for each child node that we add, the method 
becomes O(N^2)
- **Searching for an event in the tree** → `O(N)` - The search method itself runs in O(N) time because the whole tree 
needs to be traversed to determine if a node exists.
- **Game traversal efficiency** → `O(1)`  - Going from one node to the next is constant time
- **Playing the entire game** → `O(logN)`  - Assuming the binary decision tree is balanced
- **Playing the entire game** → `O(N)`  - Assuming the binary tree is unbalanced like if you just have a long chain

---

## **9. Edge Cases & Testing**
>I tested a scenario in which invalid input was given. That is to say, the user did not put in the integer of either
'1' or '2' as their input. Originally the game would simply exit and the program would end. Now, there is functionality
to catch those invalid inputs and redirect the player to input either the number '1' or '2' as their response.


---

## **10. Justification of Additional Features (If Any)**
> I added a text file called 'teststory.txt' to move what was originally written in the story text into another file.
- This was so that I could add my own story with multiple levels and not have to change the name of the original file
 used in main.cpp
> I added a helper function within the GameDecisionTree.h in order to assign children properly without making duplicates
- I also added another helper function in GameDecisionTree.h to handle the exception for when nodes point to the same
child.
> I added a cout statement that reads "GAME OVER" because I wanted my game to say that to indicate that the story has 
ended plus it feels like one of those retro games reading those words in all capital letters.
- The user may then run the program again in order to play again.
> To give credit to where I had learned the input validation method I adapted for the story playGame function,
- I provided a comment that includes the url to cite the source as I did not just copy and paste the code.
> In my README.md file I used the ">" and "-" characters to separate lines by color in order for better readability

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
