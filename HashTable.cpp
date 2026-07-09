#include "HashTable.h"
#include <iostream>

using namespace std;


//Starts the table with a prime-ish number of buckets
HashTable::HashTable(int initialSize) {
    if (initialSize < 1)
        initialSize = 1009;

    buckets.resize(initialSize);
    totalKeys = 0;
    totalCollisions = 0;
    maxLoadFactor = 0.75;
}


//Simple string hash function
//TODO: testar outra formula depois e ver se muda muito as collisions
int HashTable::hashFunction(string key) {
    unsigned long long hash = 0;

    for (int i = 0; i < (int)key.size(); i++) {
        hash = hash * 31 + (unsigned char)key[i];
    }

    return (int)(hash % buckets.size());
}


//Adds a key and stores the dataset position of that song
void HashTable::insert(string key, int songIndex) {
    if (key.empty())
        return;

    int bucketIndex = hashFunction(key);


    //Checks if this key already exists first
    for (int i = 0; i < (int)buckets[bucketIndex].size(); i++) {
        if (buckets[bucketIndex][i].key == key) {
            buckets[bucketIndex][i].songIndexes.push_back(songIndex);
            return;
        }
    }


    //If the bucket already had something, then this new key collided with it
    if (!buckets[bucketIndex].empty())
        totalCollisions++;


    Entry newEntry;
    newEntry.key = key;
    newEntry.songIndexes.push_back(songIndex);

    buckets[bucketIndex].push_back(newEntry);
    totalKeys++;


    //Nao quero deixar a tabela lotada demais senao a busca fica ruim
    if (loadFactor() > maxLoadFactor)
        rehash((int)buckets.size() * 2 + 1);
}


//Exact key search
vector<int> HashTable::search(string key) {
    vector<int> result;

    if (key.empty())
        return result;

    int bucketIndex = hashFunction(key);

    for (int i = 0; i < (int)buckets[bucketIndex].size(); i++) {
        if (buckets[bucketIndex][i].key == key)
            return buckets[bucketIndex][i].songIndexes;
    }

    return result;
}


//Makes a bigger table and puts every old key back into a new bucket
void HashTable::rehash(int newSize) {
    vector<vector<Entry>> oldBuckets = buckets;

    buckets.clear();
    buckets.resize(newSize);

    totalCollisions = 0;


    for (int i = 0; i < (int)oldBuckets.size(); i++) {
        for (int j = 0; j < (int)oldBuckets[i].size(); j++) {

            Entry oldEntry = oldBuckets[i][j];
            int newIndex = hashFunction(oldEntry.key);

            if (!buckets[newIndex].empty())
                totalCollisions++;

            buckets[newIndex].push_back(oldEntry);
        }
    }
}


int HashTable::size() {
    return totalKeys;
}

int HashTable::bucketCount() {
    return (int)buckets.size();
}

int HashTable::collisionCount() {
    return totalCollisions;
}

double HashTable::loadFactor() {
    return (double)totalKeys / (double)buckets.size();
}
