# Member 2 - Hash Table Implementation and Dataset Processing

Gianluca's part of the Group 6 music search project.

## Files

- `Song.h` - stores one song
- `TextUtils.h` - cleans text for case-insensitive searching
- `DatasetProcessor.h/.cpp` - opens and processes the CSV dataset
- `HashTable.h/.cpp` - custom hash table made from scratch
- `main.cpp` - builds the title/artist tables and tests exact searches
- `sample_songs_100.csv` - 100-row test dataset
- `CMakeLists.txt` - CLion/CMake setup

## Important about the 100-song sample

The 100-song file is only for testing and demonstrating the code.

It does **not** satisfy the final project requirement by itself. The real group project still needs the approved dataset with at least 100,000 rows.

The sample file has exactly:

- 10 pagode songs
- 10 sertanejo songs
- 10 funk songs
- 70 songs from other genres

## Compile manually

```bash
g++ -std=c++17 main.cpp DatasetProcessor.cpp HashTable.cpp -o music_search
```

Run:

```bash
./music_search
```

Or pass another CSV:

```bash
./music_search path/to/real_dataset.csv
```

## What this part does

1. Loads the CSV.
2. Finds the song, artist, genre, and popularity columns.
3. Stores the rows in `vector<Song>`.
4. Builds a custom hash table for exact song-title searches.
5. Builds another custom hash table for exact artist searches.
6. Handles duplicate song titles and duplicate artists.
7. Reports loading time, build time, search time, load factor, and collisions.

Do not replace the custom hash table with `unordered_map`, because the project requires the data structure to be implemented by the group.
