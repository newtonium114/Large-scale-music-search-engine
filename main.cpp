#include "Song.h"
#include "TextUtils.h"
#include "DatasetProcessor.h"
#include "HashTable.h"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <limits>

using namespace std;


//Prints the songs found by either hash table
void printResults(vector<int> indexes, vector<Song>& songs) {
    if (indexes.empty()) {
        cout << "No results found." << endl;
        return;
    }


    int limit = (int)indexes.size();

    //Nao vou printar 500 musicas de uma vez se o artista tiver um monte
    if (limit > 20)
        limit = 20;


    for (int i = 0; i < limit; i++) {
        Song song = songs[indexes[i]];

        cout << i + 1 << ". " << song.name;
        cout << " | " << song.artist;

        if (!song.genre.empty())
            cout << " | " << song.genre;

        cout << " | popularity: " << song.popularity << endl;
    }


    if ((int)indexes.size() > limit) {
        cout << "Showing first " << limit << " of "
             << indexes.size() << " results." << endl;
    }
}


//Builds one table for exact titles and another one for exact artists
void buildHashTables(vector<Song>& songs, HashTable& titleTable, HashTable& artistTable) {
    for (int i = 0; i < (int)songs.size(); i++) {
        string titleKey = normalizeText(songs[i].name);
        string artistKey = normalizeText(songs[i].artist);

        titleTable.insert(titleKey, i);
        artistTable.insert(artistKey, i);
    }
}


int main(int argc, char* argv[]) {

    string datasetFile = "sample_songs_100.csv";

    //Can still pass the real dataset path from the command line later
    if (argc >= 2)
        datasetFile = argv[1];


    try {

        auto loadStart = chrono::high_resolution_clock::now();
        vector<Song> songs = DatasetProcessor::loadSongs(datasetFile);
        auto loadEnd = chrono::high_resolution_clock::now();


        HashTable titleTable(1009);
        HashTable artistTable(1009);

        auto buildStart = chrono::high_resolution_clock::now();
        buildHashTables(songs, titleTable, artistTable);
        auto buildEnd = chrono::high_resolution_clock::now();


        double loadTime = chrono::duration<double>(loadEnd - loadStart).count();
        double buildTime = chrono::duration<double>(buildEnd - buildStart).count();


        cout << fixed << setprecision(6);
        cout << "Loaded songs: " << songs.size() << endl;
        cout << "Dataset load time: " << loadTime << " seconds" << endl;
        cout << "Hash table build time: " << buildTime << " seconds" << endl;
        cout << "Unique title keys: " << titleTable.size() << endl;
        cout << "Unique artist keys: " << artistTable.size() << endl;
        cout << "Total current collisions: "
             << titleTable.collisionCount() + artistTable.collisionCount() << endl;


        int choice = 0;

        while (choice != 4) {

            cout << "\nMUSIC HASH TABLE MENU" << endl;
            cout << "1. Search exact song title" << endl;
            cout << "2. Search exact artist" << endl;
            cout << "3. Show hash table statistics" << endl;
            cout << "4. Exit" << endl;
            cout << "Choice: ";


            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input." << endl;
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');


            if (choice == 1 || choice == 2) {

                string query;
                cout << "Search: ";
                getline(cin, query);


                auto searchStart = chrono::high_resolution_clock::now();

                vector<int> results;

                if (choice == 1)
                    results = titleTable.search(normalizeText(query));
                else
                    results = artistTable.search(normalizeText(query));

                auto searchEnd = chrono::high_resolution_clock::now();


                double searchTime =
                    chrono::duration<double, micro>(searchEnd - searchStart).count();


                printResults(results, songs);
                cout << "Search time: " << searchTime << " microseconds" << endl;


            } else if (choice == 3) {

                cout << "\nTITLE HASH TABLE" << endl;
                cout << "Keys: " << titleTable.size() << endl;
                cout << "Buckets: " << titleTable.bucketCount() << endl;
                cout << "Load factor: " << titleTable.loadFactor() << endl;
                cout << "Collisions: " << titleTable.collisionCount() << endl;

                cout << "\nARTIST HASH TABLE" << endl;
                cout << "Keys: " << artistTable.size() << endl;
                cout << "Buckets: " << artistTable.bucketCount() << endl;
                cout << "Load factor: " << artistTable.loadFactor() << endl;
                cout << "Collisions: " << artistTable.collisionCount() << endl;


            } else if (choice != 4) {
                cout << "Choose 1, 2, 3, or 4." << endl;
            }
        }


    } catch (const exception& error) {
        cout << "Error: " << error.what() << endl;
        return 1;
    }


    return 0;
}
