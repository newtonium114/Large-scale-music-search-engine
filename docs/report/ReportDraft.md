# Large Scale Music Search Engine Using Trie and Hash Table

# Administrative

**Team Name:** Group 6

**Team Members**
- Abhay Narayan 
- Gianluca Perrella
- Renyu Piao

**GitHub Repository:**
https://github.com/newtonium114/Large-scale-music-search-engine

**Video Demonstration:** (To be added)

---

# Extended and Refined Proposal

## Problem
Modern music streaming platforms contain hundreds of thousands of songs. Users expect search results to be returned almost instantly regardless of dataset size. This project investigates efficient search techniques by comparing a Hash Table and a Trie using the same Spotify dataset.

## Motivation
Different search tasks require different data structures. Hash Tables provide extremely fast exact lookups, while Tries efficiently support prefix searching and autocomplete. Comparing both structures demonstrates their strengths and trade-offs in a realistic application.

## Features Implemented
- Exact song title search
- Artist search
- Prefix (autocomplete) search
- Performance comparison
- Runtime statistics

## Dataset
The project uses a public Spotify Songs dataset (~170,000 songs). Only the song title and artist fields are indexed. The dataset is loaded once during initialization and inserted into both data structures to ensure fair performance comparisons.

## Tools / Languages / Libraries

| Category | Technology |
|-----------|------------|
| Language | C++17 |
| IDE | CLion |
| Version Control | Git & GitHub |
| Libraries | string, vector, unordered_map, chrono |
| Dataset | Spotify Songs Dataset (Kaggle) |

## Algorithms Implemented

### Trie
- Stores titles character-by-character.
- Supports exact and prefix searches.
- Insert: **O(L)**
- Exact Search: **O(L)**
- Prefix Search: **O(L)**

### Hash Table
- Stores song titles using hashing.
- Optimized for exact lookup.
- Insert/Search Average: **O(1)**
- Worst Case: **O(n)**

## Additional Data Structures
Standard C++ containers including `vector`, `string`, and `unordered_map` are used for data storage and communication between modules.

## Distribution of Responsibilities

| Member | Responsibilities |
|---------|------------------|
| Abhay Narayan | Trie implementation, performance analysis |
| Gianluca Perrella | Hash table implementation, dataset processing |
| Renyu Piao | User interface, testing, report, presentation |

---

# Analysis

## Changes Since Proposal
Several improvements were made after the initial proposal:
- Adopted a modular architecture separating the UI from the data structures.
- Added a performance comparison feature to measure runtime.
- Used GitHub branches for independent development and easier integration.
- Expanded documentation and testing for better maintainability.

## Big-O Complexity

| Function | Data Structure | Worst-Case Complexity |
|----------|----------------|----------------------|
| Insert | Trie | O(L) |
| Exact Search | Trie | O(L) |
| Prefix Search | Trie | O(L) |
| Insert | Hash Table | O(n) (Average O(1)) |
| Exact Search | Hash Table | O(n) (Average O(1)) |

The Trie complexity depends on the query length rather than the dataset size, making it suitable for autocomplete. The Hash Table provides constant average lookup time but may degrade under heavy collisions.

---

# Reflection

## Overall Experience
This project strengthened our understanding of how different data structures solve different search problems. Integrating them into one application provided practical software engineering experience beyond classroom examples.

## Challenges
The largest challenge was integrating independently developed components while maintaining compatibility. GitHub branches, frequent communication, and interface standardization helped reduce merge conflicts.

## Future Improvements
If starting again, we would integrate components earlier, schedule more frequent testing, and define interfaces before implementation. Future versions could support fuzzy search, additional metadata, and playlist management.

## What Each Member Learned
- **Abhay Narayan:** Trie implementation and performance evaluation.
- **Gianluca Perrella:** Hash table design and large dataset processing.
- **Renyu Piao:** UI integration, testing, documentation, and collaborative software development.

---

# References

1. Spotify Songs Dataset, Kaggle.
2. OpenDSA Data Structures.
3. GeeksforGeeks. Trie Data Structure.
4. GeeksforGeeks. Hashing Data Structure.