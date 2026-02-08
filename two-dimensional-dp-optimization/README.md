# Two-Dimensional Dynamic Programming Optimization

This directory contains a **two-dimensional dynamic programming study**
focused on solving an optimization problem over a rectangular domain.

The problem highlights how careful state formulation and transition design
can make otherwise exponential search spaces tractable.

---

## Problem Overview

Given a two-dimensional structure, the objective is to partition it into
valid sub-structures while **minimizing the remaining unused area**.

Each partition must satisfy specific feasibility constraints, and only
horizontal or vertical cuts are allowed at each step.

The challenge arises from the large state space and the need to efficiently
evaluate all valid subproblems.

---

## Approach

The solution uses a **2D dynamic programming formulation**:

- Each DP state represents the optimal result for a sub-rectangle
- Transitions consider all possible horizontal and vertical cuts
- Previously computed subproblems are reused to avoid redundant computation

This approach exploits **optimal substructure** and **overlapping subproblems**
to achieve an efficient solution.

---

## Complexity Analysis

- **Time Complexity:** O(W · H · (W + H))
- **Space Complexity:** O(W · H)

where W and H represent the dimensions of the original structure.

---

## Notes

This study demonstrates advanced dynamic programming techniques for
multi-dimensional optimization problems and emphasizes the importance of
state-space reduction and careful transition design.
