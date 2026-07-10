# Testing Plan

## COP3530 Project 2
### Large Scale Music Search Engine
### Team 6

---

# 1. Purpose

The purpose of this testing plan is to verify that every feature of the Large Scale Music Search Engine functions correctly before final submission.

The project compares two data structures:

- Trie
- Hash Table

Testing focuses on verifying functionality, correctness, integration, robustness, and performance of both implementations.

---

# 2. Testing Environment

**Operating System**
- Windows 11

**IDE**
- CLion 2026.1

**Compiler**
- C++17

**Build Tool**
- CMake

**Dataset**
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

1. Search Song Title
2. Search Artist
3. Prefix Search
4. Compare Performance
5. Exit

### Actual Result

The menu displayed correctly and accepted user input.

### Status

**PASS**

---

## Test 2 – Search Song Title

### Objective

Verify exact title search.

### Input

Love Story

### Expected Result

Returns all matching songs including artist information.

### Actual Result

The program successfully returned all matching songs and displayed the corresponding artist names.

### Status

**PASS**

---

## Test 3 – Search Artist

### Objective

Verify artist search.

### Input

Taylor Swift

### Expected Result

Returns all songs by the specified artist.

### Actual Result

Multiple songs were correctly returned.

### Status

**PASS**

---

## Test 4 – Prefix Search

### Objective

Verify Trie autocomplete.

### Input

Lov

### Expected Result

Returns all titles beginning with "Lov".

### Actual Result

Multiple matching titles were returned successfully.

### Status

**PASS**

---

## Test 5 – Performance Comparison

### Objective

Verify runtime comparison between Trie and Hash Table.

### Expected Result

Display build time and search time for both data structures.

### Actual Result

Performance statistics were successfully displayed. Build time and search time were measured correctly.

### Status

**PASS**

---

## Test 6 – Invalid Menu Option

### Objective

Verify invalid menu handling.

### Input

9

### Expected Result

Display:

```
Invalid choice.
```

Return to the main menu.

### Actual Result

Program rejected invalid input and returned to the menu.

### Status

**PASS**

---

## Test 7 – Empty Search

### Objective

Verify empty input handling.

### Input

Press Enter without entering text.

### Expected Result

Display an appropriate message and return to the menu.

### Actual Result

Empty input was safely handled without crashing the program.

### Status

**PASS**

---

## Test 8 – Song Not Found

### Objective

Verify behavior when no song exists.

### Input

abcdefgxyz

### Expected Result

Display

```
No songs found.
```

### Actual Result

Program correctly reported that no matching songs were found.

### Status

**PASS**

---

## Test 9 – Artist Not Found

### Objective

Verify behavior when artist does not exist.

### Input

Unknown Artist

### Expected Result

Display

```
No artists found.
```

### Actual Result

Program correctly handled the search.

### Status

**PASS**

---

## Test 10 – Prefix Not Found

### Objective

Verify Trie prefix search when no matches exist.

### Input

zzz

### Expected Result

Display

```
No matching songs.
```

### Actual Result

No matching titles were returned.

### Status

**PASS**

---

# 4. Edge Case Testing

| Test Case | Result |
|-----------|--------|
| Empty input | PASS |
| Invalid menu option | PASS |
| Non-existing song title | PASS |
| Non-existing artist | PASS |
| Non-existing prefix | PASS |
| Duplicate song titles | PASS |
| Mixed uppercase/lowercase input | PASS |

The program correctly handled all tested edge cases without crashing.

---

# 5. Integration Testing

After integrating the Trie, Hash Table, Dataset Loader, and User Interface, the following tests were performed.

### Integration Checklist

- Menu correctly calls each function.
- Hash Table returns correct song title results.
- Hash Table returns correct artist search results.
- Trie returns correct prefix search results.
- Dataset successfully loads into both data structures.
- Runtime statistics display correctly.
- Program exits successfully.

### Result

All components were successfully integrated.

No runtime crashes or major integration issues were observed.

**Status: PASS**

---

# 6. Performance Testing

## Hash Table

| Item | Result |
|------|--------|
| Dataset Size | 100 songs |
| Dataset Load Time | 0.000765 s |
| Build Time | 0.000340 s |
| Title Keys | 98 |
| Artist Keys | 79 |
| Total Collisions | 10 |
| Exact Title Search | 7.7 μs |
| Artist Search | 7.3 μs |

### Functional Results

- Exact title search passed.
- Artist search passed.
- Not-found search passed.

---

## Trie

| Item | Result |
|------|--------|
| Build Time | 0.0000782 s |
| Exact Search | PASS |
| Prefix Search | PASS |
| Not-found Search | PASS |

### Functional Results

- Exact search successfully located songs.
- Prefix search returned multiple matching titles.
- Non-existing songs were correctly reported.

---

## Performance Summary

The Hash Table achieved extremely fast average-case exact searches, while the Trie efficiently supported prefix searching and autocomplete.

Both data structures met the expected performance requirements for this project.

---

# 7. Test Summary

| Test Case | Status |
|-----------|--------|
| Main Menu | PASS |
| Search Song | PASS |
| Search Artist | PASS |
| Prefix Search | PASS |
| Performance Comparison | PASS |
| Invalid Menu Input | PASS |
| Empty Input | PASS |
| Song Not Found | PASS |
| Artist Not Found | PASS |
| Prefix Not Found | PASS |
| Edge Case Testing | PASS |
| Integration Testing | PASS |

---

# 8. Overall Testing Result

All core project requirements were successfully verified through functional testing, integration testing, edge case testing, and performance testing.

The Hash Table correctly supports exact song title and artist searches with excellent average-case performance. The Trie correctly supports prefix searching and autocomplete functionality.

Throughout testing, the application produced consistent results and no critical runtime errors or crashes were encountered.

Based on the completed test cases, the project is considered stable and ready for final submission.