# Graph Metrics and Shortest Path Analysis

This directory contains a **graph analysis study** focused on computing
custom relationship metrics using **shortest path algorithms** on directed,
weighted graphs.

The problem emphasizes how classical graph algorithms can be extended
to derive higher-level metrics beyond simple distance computation.

---

## Problem Overview

Given a directed weighted graph, the goal is to compute a pairwise metric
between nodes based on the structure and shortest path distances of the graph.

The metric combines:
- The shortest path between two nodes
- The relative closeness of each node to the rest of the graph

Special cases such as unreachable nodes and asymmetric reachability
must be handled carefully to ensure correctness.

---

## Approach

The solution follows a structured graph-based strategy:

- Shortest path distances are computed from each node to all others
- These distances are used to derive node-level and pairwise metrics
- Edge directionality is respected throughout the computation
- Special conditions (e.g., unreachable paths) are explicitly handled

The approach leverages classical shortest path algorithms while extending
their results into a meaningful graph-level metric.

---

## Complexity Analysis

- **Time Complexity:** O(V · (V + E))
- **Space Complexity:** O(V²)

where V is the number of nodes and E is the number of edges in the graph.

---

## Notes

This study demonstrates how shortest path algorithms can be used as
building blocks for more complex graph metrics, a technique commonly
used in network analysis, ranking systems, and social graph modeling.
