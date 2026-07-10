#ifndef SONG_H
#define SONG_H
#include <string>

using namespace std;


//Stores one song from the dataset
//Keeping this simple because both the Hash Table and Trie can use the same struct later
struct Song {
    string name;
    string artist;
    string genre;
    int popularity;

    Song() {
        popularity = 0;
    }
};

#endif
