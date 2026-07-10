# Presentation Notes

## COP3530 Project 2

### Large Scale Music Search Engine

---

# Introduction

Our project is a Spotify Music Search Engine that compares two different data structures:

- Trie
- Hash Table

The goal is to evaluate their performance for searching a large music dataset.

---

# Dataset

Spotify Songs Dataset

Approximately 170,000 songs

Each song contains

- Song Title
- Artist

---

# Features

The application supports:

1. Search Song Title

2. Search Artist

3. Prefix Search (Autocomplete)

4. Performance Comparison

---

# Data Structures

## Trie

Advantages

- Excellent for prefix search
- Fast autocomplete
- Organized character-by-character

Disadvantages

- Uses more memory
- Slower to build

---

## Hash Table

Advantages

- Very fast exact search
- Lower memory usage
- Simple implementation

Disadvantages

- Does not support prefix search efficiently

---

# Performance Comparison

The program measures

- Build Time
- Search Time
- Memory Usage

and compares both data structures.

---

# User Interface

The application provides a simple console interface with:

- Main Menu
- Song Search
- Artist Search
- Prefix Search
- Performance Report

---

# Challenges

Main challenges include

- Loading a large dataset
- Building efficient data structures
- Keeping the user interface responsive
- Comparing runtime fairly

---

# Conclusion

Trie performs better for prefix searching.

Hash Table performs better for exact searching.

Each data structure has advantages depending on the application.
