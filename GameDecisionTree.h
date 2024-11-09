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
        ifstream myStory("story.txt"); 

        // Check if file opened successfully 
        if (myStory.is_open()) {

            // Extract line by line 
            while (getline(myStory, line)) {
                cout << line << '\n'; 
            }

            myStory.close(); 

        } else {

            cout << "Unable to open file!"; 
            
        }
    }

    // Function to start the game and traverse the tree based on user input
    void playGame() {

    }
};

#endif // GAMEDECISIONTREE_H
