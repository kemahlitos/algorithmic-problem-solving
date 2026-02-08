# Selection Algorithms with QuickSelect

This directory contains an implementation and analysis of **selection-based algorithms**
focused on efficiently finding order statistics in an unsorted array.

The study explores partition-based techniques inspired by **QuickSort** and **QuickSelect**,
with emphasis on correctness, efficiency, and algorithmic trade-offs.

---

## Problem Overview

Given an unsorted array of elements, the goal is to efficiently determine specific
order statistics (e.g., the k-th smallest element) without fully sorting the array.

The problem highlights the difference between **selection** and **sorting** tasks
and demonstrates how partial ordering can significantly reduce computational cost.

---

## Approach

The solution is based on a **partitioning strategy** similar to QuickSort:

- Elements are partitioned around a chosen pivot
- Only the relevant subproblem is recursively explored
- Unnecessary recursive calls are avoided

This approach enables average-case linear-time selection while preserving correctness.

---

## Complexity Analysis

- **Average Time Complexity:** O(n)
- **Worst-Case Time Complexity:** O(n²)
- **Space Complexity:** O(1) (in-place partitioning)

---

## Notes

This study emphasizes algorithmic reasoning behind selection problems and illustrates
why selection algorithms can outperform full sorting when only partial order
information is required.
