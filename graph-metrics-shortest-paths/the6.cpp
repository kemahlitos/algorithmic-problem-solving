#include "the6.h"
#include <climits>

std::vector<int> shortest_row_element(const std::vector<std::vector<int> > & APSP_matrix) {
    int size = (int)APSP_matrix.size();
    std::vector<int> SP1(size, INT_MAX);

    for (int i = 0; i < size; i++) {
        int min_elem = INT_MAX;
        for (int j = 0; j < size; j++) {
            if (APSP_matrix[i][j] < min_elem) {
                min_elem = APSP_matrix[i][j];
            }
        }
        SP1[i] = (min_elem == INT_MAX) ? (-1) : (min_elem);
    }

    return SP1;
}

std::vector< std::vector<float> > get_friendship_scores(const std::vector< std::vector< std::pair<int, int> > >& network) {
    int INF = INT_MAX;
    int size = (int)network.size();

    if (size == 0) {
        return std::vector<std::vector<float>>();
    }

    // Initialize APSP matrix
    std::vector<std::vector<int> > APSP_matrix(size, std::vector<int>(size, INF));
    for (int i = 0; i < size; i++) {
        APSP_matrix[i][i] = INF; // INFINITY FOR DIAGONALS DUE TO PDF
        int list_size = (int)network[i].size();
        for (int j = 0; j < list_size; j++) {
            int dest_vertex = network[i][j].first;
            int weight = network[i][j].second;
            if (weight < APSP_matrix[i][dest_vertex]) {
                APSP_matrix[i][dest_vertex] = weight;
            }
        }
    }

    // Floyd-Warshall
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            if (APSP_matrix[i][k] == INF) continue;
            for (int j = 0; j < size; j++) {
                if (APSP_matrix[k][j] == INF) continue;
                int nd = APSP_matrix[i][k] + APSP_matrix[k][j];
                if (nd < APSP_matrix[i][j]) {
                    APSP_matrix[i][j] = nd;
                }
            }
        }
    }




    // Compute SP1 
    std::vector<int> SP1 = shortest_row_element(APSP_matrix);

    std::vector<std::vector<float>> FS(size, std::vector<float>(size, 0.0f));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // FS(i,j) for i != j
            bool forward_inf = (APSP_matrix[i][j] == INT_MAX);
            bool backward_inf = (APSP_matrix[j][i] == INT_MAX);

            if (forward_inf && backward_inf) {
            // No communication
                FS[i][j] = -1.0f;
            } else if (forward_inf != backward_inf) {
                // One-way communication
                FS[i][j] = 0.0f;
            } else {
                // Both ways finite
                int sp_i = SP1[i];
                int sp_j = SP1[j];
                float numerator = (float)sp_i * (float)sp_j;
                float denominator = (float)APSP_matrix[i][j] * (float)APSP_matrix[j][i];
                FS[i][j] = numerator / denominator;
                }
            }
        }
    

    return FS;
}
