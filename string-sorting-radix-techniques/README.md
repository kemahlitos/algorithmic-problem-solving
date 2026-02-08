# String Sorting with Radix-Based Techniques

This directory contains an implementation and analysis of **non-comparison-based
string sorting algorithms**, focusing on **Radix Sort** and its underlying components.

The study demonstrates how multi-character strings can be sorted efficiently by
processing characters digit by digit, rather than relying on pairwise comparisons.

---

## Problem Overview

Given a collection of strings with fixed maximum length, the goal is to sort them
efficiently while minimizing unnecessary comparisons.

Traditional comparison-based sorting algorithms incur an O(n log n) lower bound.
This problem illustrates how **Radix Sort**, combined with stable counting-based
subroutines, can achieve linear-time complexity under suitable constraints.

---

## Approach

The solution applies a **Radix Sort strategy**:

- Strings are processed from least significant character to most significant
- A stable counting-based sorting method is used at each digit
- Group size and character range are carefully managed to control memory usage

This approach ensures correctness while achieving improved asymptotic performance.

---

## Complexity Analysis

- **Time Complexity:** O(n · k)  
  where n is the number of strings and k is the maximum string length
- **Space Complexity:** O(n + σ)  
  where σ is the size of the character alphabet

---

## Notes

This study highlights the trade-offs between comparison-based and non-comparison-based
sorting algorithms and demonstrates how problem constraints can be exploited to
achieve more efficient solutions.
