
//
// Created by rache on 7/9/2026.
//

#include "UserInterface.h"
#include <iostream>
#include <limits>
using namespace std;

void UserInterface::displayMainMenu()
{
    int choice = 0;

    while (true)
    {
        cout << endl;
        cout << "==============================================" << endl;
        cout << "      Spotify Music Search Engine" << endl;
        cout << " Trie vs Hash Table Performance Comparison" << endl;
        cout << "==============================================" << endl;
        cout << endl;

        cout << "MAIN MENU" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1. Search Song Title" << endl;
        cout << "2. Search Artist" << endl;
        cout << "3. Prefix Search" << endl;
        cout << "4. Compare Performance" << endl;
        cout << "5. Exit" << endl;
        cout << endl;

        cout << "Please enter your choice: ";
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');

            cout << "Invalid input. Please enter a number (1-5): ";
        }

        switch (choice)
        {
            case 1:
                searchSongUI();
                break;

            case 2:
                searchArtistUI();
                break;

            case 3:
                prefixSearchUI();
                break;

            case 4:
                performanceComparisonUI();
                break;

            case 5:
                cout << endl;
                cout << "Thank you for using Spotify Music Search Engine!" << endl;
                return;

            default:
                cout << endl;
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void UserInterface::searchSongUI()
{
    cout << endl;
    cout << "==============================================" << endl;
    cout << "              Search Song Title" << endl;
    cout << "==============================================" << endl;

    string songName;

    cout << "Enter Song Name: ";
    cout << "> ";
    cin.ignore();
    getline(cin, songName);

    // TODO:
    // Replace this mock data with Hash Table search results
    vector<string> results =
    {
        "Love Story - Taylor Swift",
        "Love Story (Taylor's Version)",
        "Love Story (Acoustic)"
    };

    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Results Found:" << endl;
    cout << "----------------------------------------------" << endl;

    if (results.empty())
    {
        cout << "No songs found." << endl;
    }
    else
    {
        for (int i = 0; i < results.size(); i++)
        {
            cout << i + 1 << ". " << results[i] << endl;
        }
    }

    cout << endl;
    waitForEnter();
}

void UserInterface::searchArtistUI()
{
    cout << endl;
    cout << "==============================================" << endl;
    cout << "               Search Artist" << endl;
    cout << "==============================================" << endl;

    string artistName;

    cout << "Enter Artist Name: ";
    cin.ignore();
    getline(cin, artistName);

    // TODO:
    // Replace this mock data with Hash Table search results
    vector<string> results =
    {
        "Love Story",
        "Blank Space",
        "Cruel Summer",
        "Shake It Off",
        "Anti-Hero"
    };

    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Results Found" << endl;
    cout << "----------------------------------------------" << endl;

    if (results.empty())
    {
        cout << "No songs found." << endl;
    }
    else
    {
        for (int i = 0; i < results.size(); i++)
        {
            cout << i + 1 << ". " << results[i] << endl;
        }
    }

    cout << endl;
    waitForEnter();
}

void UserInterface::prefixSearchUI()
{
    cout << endl;
    cout << "==============================================" << endl;
    cout << "               Prefix Search" << endl;
    cout << "==============================================" << endl;

    string prefix;

    cout << "Enter Prefix: ";
    cin.ignore();
    getline(cin, prefix);

    // TODO:
    // Replace this mock data with Trie prefix search
    vector<string> suggestions =
    {
        "Love Story",
        "Love Yourself",
        "Love Me Like You Do",
        "Love Again",
        "Love Somebody"
    };

    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Suggestions" << endl;
    cout << "----------------------------------------------" << endl;

    if (suggestions.empty())
    {
        cout << "No matching songs found." << endl;
    }
    else
    {
        for (int i = 0; i < suggestions.size(); i++)
        {
            cout << i + 1 << ". " << suggestions[i] << endl;
        }
    }

    cout << endl;
    waitForEnter();
}


void UserInterface::performanceComparisonUI()
{
    cout << endl;
    cout << "==============================================" << endl;
    cout << "         Performance Comparison" << endl;
    cout << "==============================================" << endl;

    cout << endl;
    cout << "Dataset Size: 170,000+ Spotify Songs" << endl;

    cout << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Data Structure        Build Time      Search Time" << endl;
    cout << "------------------------------------------------------------" << endl;

    // TODO:
    // Replace these placeholder values with actual benchmark results
    cout << "Trie                  N/A             N/A" << endl;
    cout << "Hash Table            N/A             N/A" << endl;

    cout << "------------------------------------------------------------" << endl;

    cout << endl;
    cout << "Notes:" << endl;
    cout << "- Trie is optimized for prefix searches." << endl;
    cout << "- Hash Table is optimized for exact searches." << endl;

    cout << endl;

    waitForEnter();
}

void UserInterface::waitForEnter()
{
    cout << endl;
    cout << "Press Enter to return to the Main Menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

