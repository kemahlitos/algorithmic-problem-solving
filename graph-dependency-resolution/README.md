# Graph Dependency Resolution

This directory contains a **graph-based dependency analysis study**
focused on resolving ordering constraints in systems with direct and indirect dependencies.

The problem demonstrates how complex dependency structures can be simplified
by identifying tightly coupled components and reasoning over a reduced graph.

---

## Problem Overview

Given a set of entities with dependency relationships, the goal is to determine
a valid execution order while respecting all direct and indirect dependencies.

Some entities may form **cyclic dependencies**, making it impossible to order
them individually. These entities must be grouped and treated as a single unit
to enable a valid global ordering.

---

## Approach

The solution is based on fundamental **graph algorithms**:

- Strongly Connected Components (SCC) are identified to group mutually dependent entities
- Each component is condensed into a single node, forming a Directed Acyclic Graph (DAG)
- A topological ordering is computed over the condensed graph
- Priority rules are applied to ensure deterministic and consistent ordering

This approach transforms a complex dependency graph into a manageable structure
while preserving correctness.

---

## Complexity Analysis

- **Time Complexity:** O(V + E)
- **Space Complexity:** O(V + E)

where V is the number of nodes and E is the number of edges in the dependency graph.

---

## Notes

This study highlights how graph abstraction techniques such as SCC condensation
enable reasoning about systems with cyclic dependencies and are widely applicable
in scheduling, build systems, and project planning.
