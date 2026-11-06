# SLAM (Search Like A Matrix / Combinatorial Reference Engine)

An open-source, high-performance reference architecture that models text retrieval, pattern alignment, and document cross-comparison as a deterministic constraint-satisfaction problem. 

Licensed under the permissive MIT License.

## Core Algorithmic Architecture

Traditional search engines rely on probabilistic vector approximations or inverted keyword indices that lose contextual sequence and topological fidelity. SLAM processes data by converting contiguous text segments into structured multi-variable intersection fields.

### 1. The Fixed-Window Polynomial Input
To maintain a strict execution boundary and completely eliminate memory fragmentation on bare-metal systems, user queries or target string segments are constrained to an explicit 0 to 255 character limit. 

For a document vector of size n and a fixed window constraint size w:
Total Window Segments = n - w + 1

As n scales toward infinity, the boundary constraints render a purely linear O(n) footprint per document, transforming text streams into lean, indexable byte sequences.

### 2. The Bipartite Constraint Grid (Km,n)
When comparing two distinct documents (Document A with m windows and Document B with n windows), SLAM maps intersections into a bipartite adjacency matrix. Every window slice from the left column evaluates its identity state against the right column:

  [Document A Windows (m)]               [Document B Windows (n)]
       Window A1 ----------------------->  Window B1 (Intersection True/False)
       Window A2 ----------------------->  Window B2
       Window Am ----------------------->  Window Bn

This mapping strategy generates a clean m x n coordinate matrix where valid sequence continuities or overlapping constraints can be evaluated bitwise across individual compute cores.

## Repository Layout

* include/window_parser.hpp: Bounded linear string tokenizer.
* include/bipartite_matrix.hpp: Matrix array allocation and intersection logic.
* include/sat_encoder.hpp: Clause configuration and boolean state generation.
* test/src/validation_tests.cpp: System verification and edge-case assertion harness.

## Compiling and Running Tests

The project can be built cleanly using the provided raw optimization Makefile script:

make clean
make
./validation_tests


<img width="2477" height="4472" alt="mermaid-diagram-2026-11-06T13-41-22" src="https://github.com/user-attachments/assets/59d45b6c-273b-4941-af60-7fe4413c0f84" />

<img width="2389" height="5048" alt="mermaid-diagram-2026-11-06T13-41-36" src="https://github.com/user-attachments/assets/06250e43-50ad-4e9d-9071-d0f3b56728c6" />
