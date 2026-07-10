//
// Created by rache on 7/9/2026.
//

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
#include <vector>

class UserInterface {
public:
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