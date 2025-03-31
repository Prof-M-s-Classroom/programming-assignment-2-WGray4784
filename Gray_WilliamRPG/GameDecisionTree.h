#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"
#include <vector>

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        ifstream file;
        string line;
        string text;
        int eventNum;
        int leftEventNum;
        int rightEventNum;
        vector<Node<Story>*> tree;

        file.open(filename);
        if (!file.is_open()) {
            cout << "File not found." << endl;
            return;
        }

        while (getline(file, line)) {
            stringstream ss(line);

            getline(ss, line, delimiter);
            eventNum = stoi(line);
            getline(ss, line, delimiter);
            text = line;
            getline(ss, line, delimiter);
            leftEventNum = stoi(line);
            getline(ss, line);
            rightEventNum = stoi(line);

            Story story(text, eventNum, leftEventNum, rightEventNum);
            Node<Story>* storyNode = new Node<Story>(story);
            tree.push_back(storyNode);
        }

        for (int i = 0; i < tree.size(); i++) {
            Node<Story>* temp = tree[i];
            if (i == 0) {
                root = temp;
            }
            if (temp != nullptr) {
                if (temp->data.leftEventNumber != -1) {
                    leftEventNum = temp->data.leftEventNumber;
                    temp->left = tree[leftEventNum-1];
                }
                if (temp->data.rightEventNumber != -1) {
                    rightEventNum = temp->data.rightEventNumber;
                    temp->right = tree[rightEventNum-1];
                }
            }
        }
        file.close();
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<T>* temp = root;
        int input;

        while (temp != nullptr) {
            cout << temp->data.description << endl;;
            if (temp->left == nullptr && temp->right == nullptr) {
                cout << "End of game. Thanks for playing." << endl;
                break;
            } else if (temp->left != nullptr && temp->right == nullptr) {
                input = 1;
            } else if (temp->left == nullptr && temp->right != nullptr) {
                input = 2;
            } else {
                cout << "Enter choice 1 or 2: ";
                cin >> input;

                while (input != 1 && input != 2) {
                    cout << "Invalid input. Enter 1 or 2: ";
                    cin >> input;
                }
            }

            if (input == 1) {
                temp = temp->left;
            } else if (input == 2) {
                temp = temp->right;
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H