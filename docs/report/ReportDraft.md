# Large Scale Music Search Engine Using Trie and Hash Table

## Team Information

**Team Name**

Group 6

**Team Members**

- Abhay Narayan
- Gianluca Perrella
- Renyu Piao

**GitHub Repository**

https://github.com/newtonium114/Large-scale-music-search-engine

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

# 4. Dataset Description

The project uses a public Spotify Songs dataset containing approximately 170,000 songs.

Each record includes multiple attributes. For this project, the following fields are used:

- Song Title
- Artist Name

The dataset is loaded once during program initialization and inserted into both the Trie and Hash Table.

Using the same dataset for both data structures ensures a fair comparison of build time, search speed, and memory usage.

---

# 5. Tools, Languages, and Libraries

Programming Language

- C++17

Development Environment

- CLion

Version Control

- Git
- GitHub

Libraries

- iostream
- string
- vector
- unordered_map
- chrono

Dataset Source

- Spotify Songs Dataset (Kaggle)
---

# 6. Algorithms

## Trie

The Trie stores song titles character by character in a tree structure.

Each node represents a single character, allowing songs with common prefixes to share nodes.

This structure enables efficient prefix searching and autocomplete functionality.

---

## Hash Table

The Hash Table stores song titles using a hash function.

Each song title is mapped to a bucket, allowing efficient exact lookups.

Hash Tables are well suited for exact search operations because they provide fast average lookup performance.

---

## Additional Data Structures

The project also uses several standard C++ data structures, including:

- vector
- string
- unordered_map

These structures simplify data storage and communication between different modules.

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

Functional tests verify that each menu option displays the correct interface and expected results.

Invalid input tests ensure the program handles unexpected user input gracefully without crashing.

Performance tests compare the execution time of the Trie and Hash Table implementations.

Detailed test cases are documented in TestingPlan.md.

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

# 10. Analysis

## 10.1 Changes Since Proposal

Compared with the original proposal, several improvements were made during development.

First, the project adopted a modular software architecture by separating the user interface from the underlying data structures. This allows the interface to remain independent of the Trie and Hash Table implementations, making future maintenance and extension easier.

Second, a dedicated performance comparison interface was added. Instead of only implementing the two data structures, the application will also compare their build time, search time, and memory usage, allowing users to better understand the strengths of each approach.

Third, the team organized development using GitHub branches. Each member worked independently on assigned components before integrating them into the main branch, reducing merge conflicts and improving collaboration.

Finally, project documentation was expanded throughout development, including testing plans, presentation notes, and report drafts to improve project organization and maintain consistency across the team.

---

## 10.2 Big-O Analysis

The project compares two different data structures for song searching: a Trie and a Hash Table.

### Trie

| Operation | Time Complexity |
|-----------|-----------------|
| Insert | O(L) |
| Exact Search | O(L) |
| Prefix Search | O(L) |

where **L** is the length of the search string.

The Trie processes one character at a time, so its running time depends on the length of the input rather than the size of the dataset. This makes it highly efficient for autocomplete and prefix searching.

### Hash Table

| Operation | Average Case | Worst Case |
|-----------|--------------|------------|
| Insert | O(1) | O(n) |
| Search | O(1) | O(n) |

The Hash Table provides very fast average-case lookup performance by mapping song titles directly to buckets using a hash function. In the unlikely event of many collisions, lookup time may degrade to O(n).

---

## 10.3 Design Discussion

The two data structures were selected because they demonstrate different design philosophies and strengths.

The Trie is specifically designed for prefix searching. By storing shared prefixes only once, it efficiently supports autocomplete without scanning every song title. Although it generally requires more memory, it provides predictable search performance that depends only on the query length.

The Hash Table is optimized for exact lookups. It offers excellent average-case performance and typically uses less memory than a Trie. However, it cannot efficiently perform prefix searches because each lookup requires a complete key.

By implementing both data structures within the same application, users can directly compare their performance and better understand the trade-offs between memory usage, lookup speed, and supported functionality. This comparison demonstrates why different data structures are appropriate for different search problems.


# 11. Reflection

This project provided valuable experience in implementing fundamental data structures within a realistic application. Rather than studying algorithms independently, the team integrated them into a complete music search engine and observed how different data structures affect application performance.

The project also strengthened our experience with GitHub collaboration. Using feature branches allowed each team member to work independently while reducing merge conflicts during development. In addition, preparing documentation, testing plans, and presentation materials emphasized the importance of software engineering practices beyond coding.

One challenge was coordinating work across multiple team members while ensuring that all components remained compatible. Regular communication and clearly defined responsibilities helped the team make steady progress throughout development.

Although the current implementation satisfies the project requirements, several future improvements are possible. The application could support fuzzy searching, playlist management, genre filtering, and additional song metadata such as albums or release years. Performance could also be further optimized when working with even larger datasets.

# References

1. Spotify Songs Dataset

https://www.kaggle.com/

2. OpenDSA

https://opendsa-server.cs.vt.edu/

3. GeeksforGeeks Trie

https://www.geeksforgeeks.org/trie-insert-and-search/

4. GeeksforGeeks Hash Table

https://www.geeksforgeeks.org/hashing-data-structure/