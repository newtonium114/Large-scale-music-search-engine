# Spotify Music Search Engine

**COP3530 – Group Project 2**  
University of Florida

---

# Project Overview

This project implements a Spotify Music Search Engine using two custom data structures:

- **Hash Table**
  - Exact song title search
  - Exact artist search

- **Trie**
  - Prefix (autocomplete) song title search

The program also compares the performance of both data structures using a real Spotify dataset containing over **113,999 songs**.

---

# Features

- Exact Song Title Search
- Exact Artist Search
- Prefix Search (Trie)
- Performance Comparison
- Case-insensitive searching
- Dataset loading and preprocessing

---

# Project Structure


```text
Large-scale-music-search-engine
│
├── docs/
│   ├── presentation/
│   │   └── PresentationNotes.md
│   │
│   ├── report/
│   │   └── ReportDraft.md
│   │
│   └── testing/
│       └── TestingPlan.md
│
├── resources/
│   ├── images/
│   └── MARKDOWN.md
│
├── src/
│   ├── main.cpp
│   ├── DatasetProcessor.cpp
│   ├── DatasetProcessor.h
│   ├── HashTable.cpp
│   ├── HashTable.h
│   ├── Trie.cpp
│   ├── Trie.h
│   ├── UserInterface.cpp
│   ├── UserInterface.h
│   ├── Song.h
│   └── TextUtils.h
│
├── dataset.csv
├── CMakeLists.txt
└── README.md
```

---

# Requirements

- C++17
- CMake 3.16 or newer
- CLion (recommended)

The project was developed and tested using **CLion**.

---

# Dataset

This project uses a Spotify dataset containing approximately **113,999 songs**.

Place the dataset file in the project root directory:

```text
dataset.csv
```

---

# Build Instructions

Open the project in **CLion**.

CLion will automatically load the CMake project.

Build the project by selecting:

```text
Build → Build Project
```

or click the **Build** (hammer) icon.

---

# Run Instructions

Run:

```text
src/main.cpp
```

After launching, the following menu will appear:

```text
1. Search Song Title
2. Search Artist
3. Prefix Search
4. Performance Comparison
5. Exit
```

---

# Data Structures

## Hash Table

Used for:

- Exact song title search
- Exact artist search

## Trie

Used for:

- Prefix song title search (autocomplete)

---

# Performance Comparison

The program reports:

- Dataset loading time
- Hash Table build time
- Trie build time

Performance results can be viewed from the **Performance Comparison** menu.

---

# Notes

- Hash Table is optimized for exact searches.
- Trie is optimized for prefix searches.
- Searches are case-insensitive through text normalization.
- The project uses custom implementations of both the Hash Table and Trie.

---

# Team Members

- Renyu Piao
- Gianluca Perrella
- Abhay Narayan

