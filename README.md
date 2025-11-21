# Binary Search For CP

This repository contains C++ solutions for various Codeforces problems, focusing on binary search algorithms and related techniques.

## Repository Structure

```
Complete-Binary-Search-for-CP/
├── Floor-Ceil in Sorted Array/
│   ├── B_Closest_to_the_Left.cpp
│   └── Thinking_steps.md
├── Search Index/
│   └── Thinking_step.md
└── README.md
```

## Files and Folders Description


### Floor-Ceil in Sorted Array/
This folder contains problems related to finding floor and ceil values in sorted arrays using binary search.

- **B_Closest_to_the_Left.cpp**: Implements binary search to find the closest element to the left (rightmost element ≤ query value).
  - Input: First line contains n (array size) and k (number of queries). Second line has n integers (sorted array). Next k lines have query values.
  - Output: For each query, prints the 1-based index of the rightmost element ≤ query, or 0 if none exists.
  - Logic: Uses binary search to find the upper bound, then adjusts for 1-based indexing.

- **Thinking_steps.md**: Contains step-by-step reasoning and approach for solving the closest to the left problem, including floor/ceil concepts and binary search algorithms.

### Search Index/
- **Thinking_step.md**: General notes and indexing for search-related problems in the repository, including lower bound implementations.

## How to Compile and Run

To compile any C++ file, use g++ with C++17 standard:

**Windows (PowerShell):**
```powershell
g++ -std=c++17 "Floor-Ceil in Sorted Array\B_Closest_to_the_Left.cpp" -o closest.exe
./closest.exe
```

**Linux/macOS:**
```bash
g++ -std=c++17 "Floor-Ceil in Sorted Array/B_Closest_to_the_Left.cpp" -o closest
./closest
```

Provide input through stdin or redirect from a file.

## Notes
- All arrays are assumed to be sorted in ascending order.
- Solutions use standard C++ libraries via `<bits/stdc++.h>`.
- For competitive programming, ensure fast I/O if needed (add `ios::sync_with_stdio(false); cin.tie(nullptr);`).

---
*Generated based on folder structure analysis.*
