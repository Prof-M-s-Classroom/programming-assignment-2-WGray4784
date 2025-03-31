# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** William Gray 
### **Student ID:** 131835376  

---

## **1. Project Overview**
This program is an interactive text-based RPG. The story.txt text file stores the line by line data that is used to construct a binary decision tree that the player will traverse (root to leaf) throughout the game by selecting one of two paths. The tree contains nodes that hold the data for each story event (event number, story text, left event number, right event number). The game ends when the player reaches a leaf node that contains a "win" or "lose" message.

---

## **2. Folder & File Structure**
- **`main.cpp`** → `The main file is where the program is executed. It creates all the objects and calls all the methods required to construct the binary decision tree and play the game.`  
- **`GameDecisionTree.h`** → `The GameDecisionTree.h file contains a default constructor that sets the root of the tree to nullptr. It contains the method to construct the binary decision tree by extracting the lines from the text file. It contains the method that allows the player to play the game by traversing through the decision tree based on user input.`  
- **`Node.h`** → `The Node.h file contains the variables for the node's data, left node pointer, and right node pointer. It has a constructor that initializes the data to a given parameter and sets both pointers to nullptr.`  
- **`Story.h`** → `The Story.h file contains the variables for the story description, event number, left event number, and right event number. It contains a default constructor and a paramaterized constructor. The Story.cpp file is the one that initializes the variables, not the Story.h file.`  
- **`story.txt`** → `The story.txt file is where all the lines for the story nodes are stored. Each line contains the event number, story description, left event number, and right event number all separated by the delimiter "|". The file is opened using an ifstream. Each line is read using a stringstream to store the data into nodes. A vector is used to store these nodes because it has dynamic size unlike an array with fixed size. Then the tree is built, using the event numbers to get the left and right children in their proper places. Finally, the file is closed when each line is read and stored into the tree.`  

---

## **3. Decision Tree Construction**
- How are `Story` objects created from the text file?  
The loadStoryFromFile method is used to create the Story objects. The file is opened, with each line containing the data for each Story object. The getline method stores the text into a variable line up until the delimiter, and stores each part into specific variables pertaining to each part (separated by the delimiter) of the Story object's data. These variables (eventNum, text, leftEventNum, rightEventNum) are then used to create each Story object.
- How are nodes linked based on left and right event numbers?  
A vector holds all the data for each node in the tree. The method loops through the vector, assigning the left and right children based on the node's left and right event numbers. If the left or right event number is -1, that means the node is a leaf node at the end of the tree.
- What happens if an event has `-1` as left or right children?  
If the left or right event number is -1, that means the node is a leaf node. This is the end of the tree (the node has no children).

---

## **4. Game Traversal**

- How does user input determine the path taken?  
The user has the option of choosing option 1 or 2 (except for the case when there is only one option). The user can enter 1 or 2, which determines the choice they made. 1 means they chose the left child event, and 2 means they chose the right child event.
- What happens when the player reaches a leaf node?  
When the player reaches a leaf node, the game has ended. A "win" or "lose" message will be displayed.
- Explain the special case where multiple events lead to the same outcome.  
For the special case where multiple events lead to the same outcome, the tree connects two parent nodes to the same child node.

---

## **5. File Parsing & Data Loading**

- How is the file read and parsed using a delimiter?  
Each line in the story.txt file contains the event number, story description, left event number, and right event number all separated by the delimiter "|". A stringstream is used to extract each part of the line until the delimiter. Each part is stored in a variable for that specific part of the line.
- How do you ensure nodes are properly linked?  
I made sure the nodes were properly linked by storing the values for the left and right event numbers into variables that were then used to make the Story objects. I tested each outcome to make sure the story was correct.
- Any challenges faced while handling file input?  
One challenge I had was trying to store the nodes before constructing the tree. I found a data structure called a vector that works like a dynamic sized array that allowed me to easily store all the nodes in the correct order by line.

---

## **6. Debugging Process (Errors & Fixes)**
One error I faced during this project was when trying to construct the binary decision tree. I had forgotten to initialize the root, so my program had no output. I also had trouble when the user would enter an invalid input (value other than 1 or 2). I used a while loop that checks if the user entered an invalid input and prompts them to enter a valid one.

---

## **7. Sample Output & Walkthrough**
You are lost in a deserted area and trying to get back to civilization. There are two paths to take. 1. Go left toward the forest. 2. Go right toward an open grassland.  
Enter choice 1 or 2:1  
  
As you are walking through the forest, you hear a noise. 1. Investigate the noise. 2. Keep following the path.  
Enter choice 1 or 2:2  
  
You see a clearing in the trees but the path still goes through the forest. 1. Keep following the path. 2. Go through the clearing.  
Enter choice 1 or 2:1  
  
You have made it out of the forest and civilization is straight ahead. As you are about to go, you notice something on the ground. 1. Pick it up. 2. Ignore it and go toward civilization.  
Enter choice 1 or 2:2  
  
Congratulations! You made it back to civilization.  
End of game. Thanks for playing.

---

## **8. Big-O Analysis of Core Methods**
- **Loading the tree from the file** → `O(n)`  
- **Searching for an event in the tree** → `O(log n)`  
- **Game traversal efficiency** → `O(log n)`  

---

## **9. Edge Cases & Testing**
One edge case is when the player reaches the leaf node at the end of the game. When the node has a nullptr to both the left child and right child, this means that the node is a leaf node. When this is the case, I display the message "End of game. Thanks for playing." and the program ends.

---

## **10. Justification of Additional Features (If Any)**
I added a feature that deals with when the user enters invalid input. When prompted to choose between choice 1 and 2, the user must enter either 1 or 2. If the user enters anything other than 1 or 2, I added a feature that displays "Invalid input. Enter 1 or 2." until the user enters a valid input. The story proceeds as normal after this is resolved.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
