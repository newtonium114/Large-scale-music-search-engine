#include "Song.h"
#include "TextUtils.h"
#include "DatasetProcessor.h"
#include "HashTable.h"
#include "UserInterface.h"
#include "Trie.h"

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <filesystem>
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


    string datasetFile;

    if (filesystem::exists("dataset.csv"))
        datasetFile = "dataset.csv";
    else if (filesystem::exists("../dataset.csv"))
        datasetFile = "../dataset.csv";
    else if (filesystem::exists("../../dataset.csv"))
        datasetFile = "../../dataset.csv";
    else {
        cerr << "Cannot find dataset.csv" << endl;
        return 1;
    }


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


        //  Trie Integration test added by Renyu Piao //
        Trie songTrie;

        auto trieBuildStart = chrono::high_resolution_clock::now();

        for (int i = 0; i < (int)songs.size(); i++) {
            songTrie.insert(songs[i]);
        }

        auto trieBuildEnd = chrono::high_resolution_clock::now();

        vector<Song> trieResults = songTrie.startsWith("Love");



        double loadTime = chrono::duration<double>(loadEnd - loadStart).count();
        double buildTime = chrono::duration<double>(buildEnd - buildStart).count();

        double trieBuildTime = chrono::duration<double>(trieBuildEnd - trieBuildStart).count();


        cout << fixed << setprecision(6);
        cout << "Loaded songs: " << songs.size() << endl;
        cout << "Dataset load time: " << loadTime << " seconds" << endl;
        cout << "Hash table build time: " << buildTime << " seconds" << endl;
        cout << "Trie build time: " << trieBuildTime << " seconds" << endl;

        cout << "Unique title keys: " << titleTable.size() << endl;
        cout << "Unique artist keys: " << artistTable.size() << endl;
        cout << "Total current collisions: "
             << titleTable.collisionCount() + artistTable.collisionCount() << endl;


        UserInterface ui(
            songs,
            titleTable,
            artistTable,
            songTrie,
            buildTime,
            trieBuildTime
        );

        ui.displayMainMenu();
    } catch (const exception& error) {
        cout << "Error: " << error.what() << endl;
        return 1;
    }


    return 0;
}
