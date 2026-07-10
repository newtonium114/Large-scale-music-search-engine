
//
// Created by rache on 7/9/2026.
//

#include "UserInterface.h"

#include "TextUtils.h"
#include "Song.h"
#include "HashTable.h"
#include "Trie.h"

#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

UserInterface::UserInterface(
    vector<Song>& songs,
    HashTable& titleTable,
    HashTable& artistTable,
    Trie& songTrie,
    double hashBuildTime,
    double trieBuildTime
)
    : songs(songs),
      titleTable(titleTable),
      artistTable(artistTable),
      songTrie(songTrie),
      hashBuildTime(hashBuildTime),
      trieBuildTime(trieBuildTime)
{
}

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

    vector<int> indexes =
    titleTable.search(normalizeText(songName));

    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Results Found:" << endl;
    cout << "----------------------------------------------" << endl;

    if (indexes.empty())
    {
        cout << "No songs found." << endl;
    }
    else
    {
        int limit = indexes.size();

        if (limit > 20)
            limit = 20;

        for (int i = 0; i < limit; i++)
        {
            Song song = songs[indexes[i]];

            cout << i + 1 << ". "
                 << song.name
                 << " | "
                 << song.artist
                 << " | "
                 << song.genre
                 << " | popularity: "
                 << song.popularity
                 << endl;
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


    vector<int> indexes =
    artistTable.search(normalizeText(artistName));

    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Results Found" << endl;
    cout << "----------------------------------------------" << endl;

    if (indexes.empty())
    {
        cout << "No songs found." << endl;
    }
    else
    {
        int limit = indexes.size();

        if (limit > 20)
            limit = 20;

        for (int i = 0; i < limit; i++)
        {
            Song song = songs[indexes[i]];

            cout << i + 1 << ". "
                 << song.name
                 << " | "
                 << song.artist;

            if (!song.genre.empty())
                cout << " | " << song.genre;

            cout << " | popularity: "
                 << song.popularity
                 << endl;
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


    vector<Song> results =
        songTrie.startsWith(normalizeText(prefix));

    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Suggestions" << endl;
    cout << "----------------------------------------------" << endl;

    if (results.empty())
    {
        cout << "No matching songs found." << endl;
    }
    else
    {
        int limit = results.size();

        if (limit > 20)
            limit = 20;

        for (int i = 0; i < limit; i++)
        {
            cout << i + 1 << ". "
                 << results[i].name
                 << " | "
                 << results[i].artist;

            if (!results[i].genre.empty())
                cout << " | " << results[i].genre;

            cout << " | popularity: "
                 << results[i].popularity
                 << endl;
        }

        if (results.size() > limit)
        {
            cout << endl;
            cout << "Showing first "
                 << limit
                 << " of "
                 << results.size()
                 << " results."
                 << endl;
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
    cout << "Dataset Size: " << songs.size() << " Songs" << endl;

    cout << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Data Structure        Build Time      Search Type" << endl;
    cout << "------------------------------------------------------------" << endl;


    cout << fixed << setprecision(2);

    cout << left
         << setw(20) << "Trie"
         << setw(18) << trieBuildTime
         << "Prefix Search"
         << endl;

    cout << left
         << setw(20) << "Hash Table"
         << setw(18) << hashBuildTime
         << "Exact Search"
         << endl;

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

