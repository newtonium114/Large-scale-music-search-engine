//
// Created by rache on 7/10/2026.
//

#pragma once

#include "Song.h"

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode*> children;

    bool isEndOfTitle = false;

    vector<Song> songs;
};

class Trie
{
private:
    TrieNode* root;

    void collectSongs(TrieNode* node, vector<Song>& results);

public:
    Trie();

    void insert(Song song);

    vector<Song> search(string title);

    vector<Song> startsWith(string prefix);
};