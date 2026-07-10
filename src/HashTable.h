#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <string>
#include <vector>

using namespace std;


class HashTable {
private:

    //One key can point to multiple songs because duplicate titles/artists exist
    struct Entry {
        string key;
        vector<int> songIndexes;
    };


    vector<vector<Entry>> buckets;
    int totalKeys;
    int totalCollisions;
    double maxLoadFactor;


    int hashFunction(string key);
    void rehash(int newSize);

public:
    HashTable(int initialSize = 1009);

    void insert(string key, int songIndex);
    vector<int> search(string key);

    int size();
    int bucketCount();
    int collisionCount();
    double loadFactor();
};

#endif
