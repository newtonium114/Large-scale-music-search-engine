#include "DatasetProcessor.h"
#include "TextUtils.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;


//Reads the CSV and turns every valid line into one Song
vector<Song> DatasetProcessor::loadSongs(string fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        throw runtime_error("Could not open dataset file: " + fileName);
    }

    string line;

    //First line should have the column names
    if (!getline(file, line)) {
        throw runtime_error("The dataset is empty.");
    }

    vector<string> headers = parseCSVLine(line);

    for (int i = 0; i < (int)headers.size(); i++) {
        headers[i] = normalizeText(headers[i]);
    }


    //Some Spotify CSVs use different names for basically the same thing
    int nameColumn = findColumn(headers, {
        "song_name", "song name", "track_name", "track name", "title", "name"
    });

    int artistColumn = findColumn(headers, {
        "artist", "artists", "artist_name", "artist name", "track_artist"
    });

    int genreColumn = findColumn(headers, {
        "genre", "playlist_genre", "track_genre", "music_genre"
    });

    int popularityColumn = findColumn(headers, {
        "popularity", "track_popularity", "song_popularity"
    });


    if (nameColumn == -1 || artistColumn == -1) {
        throw runtime_error("Could not find the song name or artist column.");
    }


    vector<Song> songs;
    songs.reserve(200000);   //The real dataset is supposed to be 100k+ anyway

    int skippedRows = 0;

    while (getline(file, line)) {
        if (line.empty())
            continue;

        vector<string> fields = parseCSVLine(line);

        int biggestNeeded = max(nameColumn, artistColumn);

        if ((int)fields.size() <= biggestNeeded) {
            skippedRows++;
            continue;
        }


        Song song;
        song.name = fields[nameColumn];
        song.artist = fields[artistColumn];

        if (genreColumn != -1 && genreColumn < (int)fields.size())
            song.genre = fields[genreColumn];

        if (popularityColumn != -1 && popularityColumn < (int)fields.size())
            song.popularity = safeToInt(fields[popularityColumn]);


        //No point storing a song if these two are blank
        if (normalizeText(song.name).empty() || normalizeText(song.artist).empty()) {
            skippedRows++;
            continue;
        }

        songs.push_back(song);
    }


    if (skippedRows > 0)
        cout << "Skipped " << skippedRows << " invalid/incomplete rows." << endl;

    return songs;
}


//CSV looked easy until I remembered song names can have commas inside quotes
vector<string> DatasetProcessor::parseCSVLine(string line) {
    vector<string> fields;
    string current = "";
    bool insideQuotes = false;

    for (int i = 0; i < (int)line.size(); i++) {
        char ch = line[i];

        if (ch == '"') {
            //Two quotes together inside a field means one actual quote
            if (insideQuotes && i + 1 < (int)line.size() && line[i + 1] == '"') {
                current += '"';
                i++;
            } else {
                insideQuotes = !insideQuotes;
            }

        } else if (ch == ',' && !insideQuotes) {
            fields.push_back(current);
            current = "";

        } else {
            current += ch;
        }
    }

    fields.push_back(current);
    return fields;
}


//Finds the first matching header
int DatasetProcessor::findColumn(vector<string> headers, vector<string> possibleNames) {
    for (int i = 0; i < (int)headers.size(); i++) {
        for (int j = 0; j < (int)possibleNames.size(); j++) {
            if (headers[i] == normalizeText(possibleNames[j]))
                return i;
        }
    }

    return -1;
}


//Popularity is nice to show but it should not crash the whole thing if one row is weird
int DatasetProcessor::safeToInt(string value) {
    try {
        return stoi(value);
    } catch (...) {
        return 0;
    }
}
