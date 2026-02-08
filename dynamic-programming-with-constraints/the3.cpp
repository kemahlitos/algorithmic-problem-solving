#include "the3.h"

// DO NOT CHANGE ABOVE THIS LINE!
// you may implement helper functions below

int find_min_cost(const std::vector<std::vector<int>>& costs, int N) {
    int i, j;
    int min_cost = 0;
    
    // Assuming 6 is the number of columns, as in the problem
    int no_cost = 6;
    
    // Create a 2D vector of size N x 6, initialized to 0
    std::vector<std::vector<int>> arr(N-1, std::vector<int>(6, 0));
    
    // Initialize the first row of arr with the first row of costs
    for (i = 0; i < 6; i++) {
        arr[0][i] = costs[0][i];
    }

    // Fill in the rest of arr with minimum cost values
    int min_value;
    for (i = 1; i < N-1; i++) {
        for (j = 0; j < 6; j++) {
            switch (j) {
                case 0:
                    min_value = std::fmin(arr[i - 1][0], std::fmin(arr[i - 1][2], std::fmin(arr[i - 1][3], std::fmin(arr[i - 1][4], arr[i - 1][5]))));
                    arr[i][j] = min_value + costs[i][j];
                    break;

                case 1:
                    min_value = std::fmin(arr[i - 1][1], std::fmin(arr[i - 1][2], std::fmin(arr[i - 1][3], std::fmin(arr[i - 1][4], arr[i - 1][5]))));
                    arr[i][j] = min_value + costs[i][j];
                    break;

                case 2:
                    min_value = std::fmin(arr[i - 1][0], std::fmin(arr[i - 1][1], std::fmin(arr[i - 1][4], arr[i - 1][5])));
                    arr[i][j] = min_value + costs[i][j];
                    break;

                case 3:
                    min_value = std::fmin(arr[i - 1][0], std::fmin(arr[i - 1][1], std::fmin(arr[i - 1][4], arr[i - 1][5])));
                    arr[i][j] = min_value + costs[i][j];
                    break;

                case 4:
                    min_value = std::fmin(arr[i - 1][0], std::fmin(arr[i - 1][1], std::fmin(arr[i - 1][2], arr[i - 1][3])));
                    arr[i][j] = min_value + costs[i][j];
                    break;

                case 5:
                    min_value = std::fmin(arr[i - 1][0], std::fmin(arr[i - 1][1], std::fmin(arr[i - 1][2], arr[i - 1][3])));
                    arr[i][j] = min_value + costs[i][j];
                    break;
            }
        }
    }

    // After filling arr, find the minimum cost in the last row
    min_cost = std::fmin(arr[N - 2][0], std::fmin(arr[N - 2][1], std::fmin(arr[N - 2][2], std::fmin(arr[N - 2][3], std::fmin(arr[N - 2][4], arr[N - 2][5])))));

    return min_cost;
}
