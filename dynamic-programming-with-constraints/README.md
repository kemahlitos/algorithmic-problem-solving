# Dynamic Programming with Constraints

This directory contains a **dynamic programming (DP) study** focused on solving
optimization problems under **adjacency and feasibility constraints**.

The problem emphasizes careful **state design** and efficient transitions to
satisfy constraints while minimizing computational complexity.

---

## Problem Overview

Given a sequence of elements with specific compatibility constraints between
adjacent positions, the goal is to compute an optimal solution that satisfies
all constraints.

The challenge lies in balancing correctness with efficiency, as naive
recursive solutions quickly become infeasible for large inputs.

---

## Approach

The solution is based on a **bottom-up dynamic programming strategy**:

- DP states are designed to capture the minimum information required to enforce constraints
- Transitions consider only valid neighboring configurations
- Memory usage is optimized by reusing previous states where possible

This structured approach ensures correctness while maintaining linear or near-linear runtime.

---

## Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

---

## Notes

This study demonstrates how dynamic programming can be applied effectively
to constraint-heavy problems by carefully defining states and transitions,
avoiding unnecessary recomputation.
