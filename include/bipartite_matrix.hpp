#ifndef BIPARTITE_MATRIX_HPP
#define BIPARTITE_MATRIX_HPP

#include <vector>
#include <string>

struct IntersectionState {
    size_t index_a;
    size_t index_b;
    bool is_match;
};

class BipartiteMatrix {
private:
    size_t m_rows;
    size_t n_cols;
    std::vector<std::vector<IntersectionState>> grid;

public:
    BipartiteMatrix(size_t m, size_t n) : m_rows(m), n_cols(n) {
        grid.resize(m, std::vector<IntersectionState>(n));
    }

    // Evaluates intersections across the m x n grid array
    void ComputeIntersections(const std::vector<std::string>& doc_a_windows, 
                              const std::vector<std::string>& doc_b_windows) {
        for (size_t i = 0; i < m_rows; ++i) {
            for (size_t j = 0; j < n_cols; ++j) {
                grid[i][j].index_a = i;
                grid[i][j].index_b = j;
                grid[i][j].is_match = (doc_a_windows[i] == doc_b_windows[j]);
            }
        }
    }
};

#endif // BIPARTITE_MATRIX_HPP
