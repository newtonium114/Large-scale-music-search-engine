# Large Scale Music Search Engine Using Trie and Hash Table

## Team Information

**Team Name**

Group 6

**Team Members**

- Abhay Narayan
- Gianluca Perrella
- Renyu Piao

**GitHub Repository**

(To be added)

**Video Demonstration**

(To be added)

---

# 1. Problem

Music streaming platforms contain hundreds of thousands of songs. Users expect search results to appear instantly, even when searching through very large music databases.

This project investigates which data structure provides better performance for large-scale music searching.

---

# 2. Motivation

Efficient searching is one of the most important functions of modern music streaming services.

Different search operations require different data structures.

Exact searches and prefix searches have different performance characteristics, making Trie and Hash Table ideal candidates for comparison.

---

# 3. Features Implemented

The application supports the following features:

- Exact Song Title Search
- Artist Search
- Prefix Search
- Performance Comparison
- Runtime Statistics

---

# 4. Dataset

Dataset:

Spotify Songs Dataset

Approximately 170,000 songs

Fields used:

- Song Title
- Artist

---

# 5. Programming Environment

Language

- C++17

Development Environment

- CLion

Libraries

- Standard C++ Library

Version Control

- GitHub

---

# 6. Algorithms

## Trie

The Trie stores song titles character by character.

It supports fast prefix searching and autocomplete functionality.

Expected Complexity

- Insert: O(L)
- Search: O(L)
- Prefix Search: O(L)

where L is the length of the search string.

---

## Hash Table

The Hash Table stores song titles using hashing.

It supports efficient exact search.

Expected Complexity

- Insert: O(1) Average
- Exact Search: O(1) Average

---

# 7. User Interface

The application provides a console-based user interface.

The main menu allows users to:

- Search Song Title
- Search Artist
- Prefix Search
- Compare Performance
- Exit Program

The interface was designed to remain independent from the underlying data structures, allowing the Trie and Hash Table implementations to be integrated without modifying the user interface.

---

# 8. Testing

Testing focuses on:

- Functional Testing
- Invalid Input Testing
- Edge Case Testing
- Performance Testing

Detailed testing procedures are described in TestingPlan.md.

---

# 9. Distribution of Responsibilities

Abhay Narayan

- Trie Implementation
- Performance Analysis

Gianluca Perrella

- Hash Table
- Dataset Processing

Renyu Piao

- User Interface
- Testing
- Report
- Presentation

---

# 10. Future Work

The project can be improved by:

- Supporting fuzzy search
- Supporting playlists
- Supporting genre filtering
- Improving memory efficiency

---

# References

1. Spotify Songs Dataset

https://www.kaggle.com/

2. OpenDSA

https://opendsa-server.cs.vt.edu/

3. GeeksforGeeks Trie

https://www.geeksforgeeks.org/trie-insert-and-search/

4. GeeksforGeeks Hash Table

https://www.geeksforgeeks.org/hashing-data-structure/