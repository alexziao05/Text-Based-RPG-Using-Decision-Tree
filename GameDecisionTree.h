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
    GameDecisionTree() : root(nullptr) {}

    // Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const string& filename, char delimiter) {
        
        string line; 
        ifstream myStory(filename); 

        // Check if file opened successfully 
        if (myStory.is_open()) {

            // Extract line by line 
            while (getline(myStory, line)) {

                vector<string> elements; 
                stringstream sentence(line); 
                string item; 
                while (getline(sentence, item, delimiter)) {
                    elements.push_back(item); 
                } 

                // cout << elements[0] << endl; 
                // cout << elements[1] << endl; 
                // cout << elements[2] << endl; 
                // cout << elements[3] << endl; 

                int num = stoi(elements[0]); 
                string desc = elements[1]; 
                int leftNum = stoi(elements[2]);
                int rightNum = stoi(elements[3]);

                Story storyElement(desc, num, leftNum, rightNum); 
                insert(root, storyElement); 
            }

            myStory.close(); 

        } else {
            cout << "Unable to open file!"; 
        }
    }

    Node<T>* insert(Node<T>* root, Story storyElement) {
        if (root  == nullptr) {
            return new Node<T>(storyElement); 
        }

        if (storyElement.eventNumber < root->data.eventNumber) {
            root->left = insert(root->left, storyElement); 
        } else {
            root->right = insert(root->right,storyElement); 
        }

        return root; 
    }

    // Function to start the game and traverse the tree based on user input
    void playGame() {
        
    }
};

#endif // GAMEDECISIONTREE_H
