// Trie.cpp
// Trie data structure for the Large Scale Music Search Engine project
// Role: Trie Implementation + Performance Analysis (Abhay)
// The Trie stores song titles character by character. Each node that completes a full song title also stores the full Song info (title, artist, genre, popularity) so we can look up more than just the name

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <chrono> 
using namespace std;
#include "../Song.h"
#include "../TextUtils.h"

// Represents one song from the dataset
// struct Song {
//     string title;
//     string artist;
//     string genre;
//     int popularity;
// };


// One node in the Trie. Each node represents one character

struct TrieNode {

    unordered_map<char, TrieNode*> children; 
    bool isEndOfTitle;                       
    vector<Song> songs;                       


    TrieNode() {
        isEndOfTitle = false;
    }
};



class Trie {
    
private:
    TrieNode* root;


    
public:

    Trie() {

        root = new TrieNode();
    }


    void insert(Song song) {


        TrieNode* current = root;

        string key = normalizeText(song.name);

        for (int i = 0; i < key.length(); i++) {
            char c = key[i];


            if (current->children.find(c) == current->children.end()) {

                current->children[c] = new TrieNode();
            }


            current = current->children[c];
        }



        current->isEndOfTitle = true;
        current->songs.push_back(song);
    }

    // Exact search. Returns every song stored under this exact title



    vector<Song> search(string title) {
        TrieNode* current = root;

        title = normalizeText(title);
        for (int i = 0; i < title.length(); i++) {

            char c = title[i];


            if (current->children.find(c) == current->children.end()) {
                return vector<Song>(); // path doesn't exist, title not found
            }


            current = current->children[c];
        }


        if (current->isEndOfTitle) {

            return current->songs;
        }


        return vector<Song>();
    }




    // Prefix search (autocomplete). Returns every song whose title starts with the given prefix.
    vector<Song> startsWith(string prefix) {

        vector<Song> results;
        TrieNode* current = root;

        prefix = normalizeText(prefix);
        for (int i = 0; i < prefix.length(); i++) {

            char c = prefix[i];


            if (current->children.find(c) == current->children.end()) {
                return results; 
            }

            current = current->children[c];
        }


        collectSongs(current, results);

        return results;
    }




    private:
    // Helper function that walks every branch below "node" and collects every song it finds, using recursion (DFS)

    void collectSongs(TrieNode* node, vector<Song> &results) {

        if (node->isEndOfTitle) {

            for (int i = 0; i < node->songs.size(); i++) {


                results.push_back(node->songs[i]);

            }
        }


        for (auto const &pair : node->children) {

            TrieNode* nextNode = pair.second;

            collectSongs(nextNode, results);
        }
    }
};



// int main() {
//     Trie songTrie;
//
//     // Simple test data (mirrors the wireframe examples from the proposal), once the CSV loader is ready, this will instead loop through every  row of the dataset and call insert() for each one.
//
//     vector<Song> testSongs = {
//         {"Love Story", "Taylor Swift", "Country", 88},
//         {"Love Yourself", "Justin Bieber", "Pop", 91},
//         {"Love Me Like You Do", "Ellie Goulding", "Pop", 85},
//         {"Love Again", "The Kid LAROI", "Pop", 80},
//         {"Love Somebody", "Morgan Wallen", "Country", 89},
//         {"Blank Space", "Taylor Swift", "Pop", 90}
//     };
//
//
//     auto buildStart = chrono::high_resolution_clock::now();
//
//
//
//     for (int i = 0; i < testSongs.size(); i++) {
//
//         songTrie.insert(testSongs[i]);
//     }
//
//     auto buildEnd = chrono::high_resolution_clock::now();
//     chrono::duration<double> buildTime = buildEnd - buildStart;
//     cout << "Build time: " << buildTime.count() << " seconds" << endl << endl;
//     cout << "=== Exact Search Test ===" << endl;
//     auto searchStart = chrono::high_resolution_clock::now();
//     vector<Song> exactMatches = songTrie.search("Love Story");
//     auto searchEnd = chrono::high_resolution_clock::now();
//     chrono::duration<double> searchTime = searchEnd - searchStart;
//
//
//     if (exactMatches.empty()) {
//
//         cout << "Love Story not found." << endl;
//     }
//
//
//     else {
//
//         for (int i = 0; i < exactMatches.size(); i++) {
//
//             cout << "Found! " << exactMatches[i].title << " - " << exactMatches[i].artist
//                  << " (" << exactMatches[i].genre << ", popularity " << exactMatches[i].popularity << ")" << endl;
//         }
//     }
//
//     cout << "Search time: " << searchTime.count() << " seconds" << endl;
//
//     vector<Song> notFound = songTrie.search("Love Song");
//
//
//     if (notFound.empty()) {
//
//         cout << "Love Song not found (this is expected, it's not in the trie)." << endl;
//     }
//
//     cout << endl << "=== Prefix Search Test (\"Lov\") ===" << endl;
//     vector<Song> matches = songTrie.startsWith("Lov");
//
//     for (int i = 0; i < matches.size(); i++) {
//
//         cout << matches[i].title << " - " << matches[i].artist << endl;
//     }
//
//     cout << endl << "=== Prefix Search Test (\"Blank\") ===" << endl;
//     vector<Song> matches2 = songTrie.startsWith("Blank");
//
//     for (int i = 0; i < matches2.size(); i++) {
//
//         cout << matches2[i].title << " - " << matches2[i].artist << endl;
//     }
//
//     return 0;
// }
