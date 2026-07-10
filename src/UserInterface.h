//
// Created by rache on 7/9/2026.
//

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "HashTable.h"
#include "Trie.h"
#include "Song.h"

#include <string>
#include <vector>

// Trie is currently defined separately.
// A forward declaration is enough for storing a reference here.
class Trie;

class UserInterface {

private:
    std::vector<Song>& songs;
    HashTable& titleTable;
    HashTable& artistTable;
    Trie& songTrie;

    double hashBuildTime;
    double trieBuildTime;

public:

    // Receives the data structures already created in main.cpp.
    UserInterface(
        std::vector<Song>& songs,
        HashTable& titleTable,
        HashTable& artistTable,
        Trie& songTrie,
        double hashBuildTime,
        double trieBuildTime
    );

    // Main menu
    void displayMainMenu();

    // Search interfaces
    void searchSongUI();
    void searchArtistUI();
    void prefixSearchUI();

    // Performance comparison
    void performanceComparisonUI();

    // Helper function
    void waitForEnter();
};

#endif