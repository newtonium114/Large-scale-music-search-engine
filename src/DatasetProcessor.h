#ifndef DATASET_PROCESSOR_H
#define DATASET_PROCESSOR_H
#include "Song.h"
#include <string>
#include <vector>

using namespace std;


class DatasetProcessor {
private:
    //Breaks one CSV line into its fields. Had to account for commas inside quotes
    static vector<string> parseCSVLine(string line);

    //Looks for a column using a few possible names because Spotify datasets differ
    static int findColumn(vector<string> headers, vector<string> possibleNames);

    static int safeToInt(string value);

public:
    static vector<Song> loadSongs(string fileName);
};

#endif
