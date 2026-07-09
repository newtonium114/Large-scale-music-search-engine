# Testing Plan

## COP3530 Project 2
### Large Scale Music Search Engine
### Team 6

---

# 1. Purpose

The purpose of this testing plan is to verify that every feature of the Large Scale Music Search Engine works correctly before submission.

The project compares two data structures:

- Trie
- Hash Table

The testing process ensures that both implementations return correct results, handle invalid input safely, and produce consistent outputs.

---

# 2. Testing Environment

Operating System:
- Windows 11

IDE:
- CLion 2026.1

Compiler:
- C++17

Build Tool:
- CMake

Dataset:
- Spotify Songs Dataset
- Approximately 170,000 songs

---

# 3. Functional Testing

## Test 1 – Main Menu

### Objective

Verify that the main menu is displayed correctly.

### Input

Program starts.

### Expected Result

The menu displays:

1. Search Song Title
2. Search Artist
3. Prefix Search
4. Compare Performance
5. Exit

### Status

Pending

---

## Test 2 – Search Song Title

### Objective

Verify exact title search.

### Input

Love Story

### Expected Result

Returns all matching songs, including artist names.

Example:

1. Love Story - Taylor Swift
2. Love Story (Taylor's Version)
3. Love Story (Acoustic)

### Status

Pending

---

## Test 3 – Search Artist

### Objective

Verify artist search.

### Input

Taylor Swift

### Expected Result

Returns all songs by Taylor Swift.

Example:

- Love Story
- Blank Space
- Anti-Hero
- Cruel Summer

### Status

Pending

---

## Test 4 – Prefix Search

### Objective

Verify autocomplete functionality.

### Input

lov

### Expected Result

Returns all titles beginning with "lov".

Example:

- Love Story
- Love Yourself
- Love Again
- Love Somebody

### Status

Pending

---

## Test 5 – Performance Comparison

### Objective

Verify that benchmark statistics are displayed.

### Expected Result

Displays:

Trie

- Build Time
- Search Time
- Memory Usage

Hash Table

- Build Time
- Search Time
- Memory Usage

Winner Summary

- Exact Search
- Prefix Search

### Status

Pending

---

## Test 6 – Invalid Menu Option

### Objective

Verify invalid menu handling.

### Input

9

### Expected Result

Display

Invalid choice.

Return to main menu.

### Status

Pending

---

## Test 7 – Empty Search

### Objective

Verify empty input handling.

### Input

(Press Enter)

### Expected Result

Display

No input detected.

Return to menu.

### Status

Pending

---

## Test 8 – Song Not Found

### Objective

Verify behavior when no matching title exists.

### Input

abcdefgxyz

### Expected Result

Display

No songs found.

### Status

Pending

---

## Test 9 – Artist Not Found

### Objective

Verify behavior when artist does not exist.

### Input

Unknown Artist

### Expected Result

Display

No artists found.

### Status

Pending

---

## Test 10 – Prefix Not Found

### Objective

Verify prefix search with no matches.

### Input

zzz

### Expected Result

Display

No matching songs.

### Status

Pending

---

# 4. Integration Testing

After integrating the Trie, Hash Table, Dataset Loader, and User Interface:

Verify that

- Menu correctly calls each function.
- Trie returns correct search results.
- Hash Table returns correct search results.
- Performance comparison displays benchmark results.
- Program exits correctly.

Status:

Pending

---

# 5. Performance Testing

Measure

- Build Time
- Exact Search Time
- Prefix Search Time
- Memory Usage

Compare

Trie

vs

Hash Table

Actual benchmark results will be inserted after implementation.

---

# 6. Test Summary

| Test Case | Status |
|-----------|--------|
| Main Menu | Pass |
| Search Song | Pass |
| Search Artist | Pass |
| Prefix Search | Pass |
| Performance | Partial Pass |
| Invalid Input | Pass |
| Empty Input | Pending Integration |
| Song Not Found | Pass |
| Artist Not Found | Pass |
| Prefix Not Found | Pending Integration |
---

# ## Current Testing Results

### Hash Table Test

The Hash Table branch compiled and ran successfully.

Dataset size tested: 100 songs  
Dataset load time: 0.000765 seconds  
Hash table build time: 0.000340 seconds  
Unique title keys: 98  
Unique artist keys: 79  
Total current collisions: 10

Exact title search was tested using "Love Story". The program returned two matching songs and completed the search in 7.7 microseconds.

Artist search was tested using "Taylor Swift". The program returned three matching songs and completed the search in 7.3 microseconds.

A not-found test was performed using "abcdefgxyz". The program correctly displayed "No results found."

### Trie Test

The Trie branch compiled and ran successfully.

Build time: 0.0000782 seconds

Exact search was tested using "Love Story". The program correctly returned "Love Story - Taylor Swift".

A not-found test was performed using "Love Song". The program correctly reported that the song was not found.

Prefix search was tested using "Lov". The program returned five matching songs.

Prefix search was also tested using "Blank". The program returned "Blank Space - Taylor Swift".

### Integration Status

Hash Table and Trie were tested separately and both passed their individual functional tests.

Full integration testing will be completed after the feature branches are merged into the final main branch.