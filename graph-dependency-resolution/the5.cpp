#include "the5.h"

void topologicalSort(const std::vector<std::vector<int>>& graph, std::vector<int>& in_degree, std::vector<int>& topo_order, const std::vector<int>& find_scc_min) {
    std::vector<int> pq;
    int n = in_degree.size();
    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) {
            pq.push_back(i);
        }
    }
    for (int i = 0; i < pq.size(); ++i) {
        for (int j = i + 1; j < pq.size(); ++j) {
            if (find_scc_min[pq[i]] > find_scc_min[pq[j]]) {
                int temp = pq[i];
                pq[i] = pq[j];
                pq[j] = temp;
            }
        }
    }

    while (!pq.empty()) {
        int node = pq.front();
        pq.erase(pq.begin()); 
        topo_order.push_back(node);

        for (int neighbor : graph[node]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                pq.push_back(neighbor);
                for (int i = 0; i < pq.size(); ++i) {
                    for (int j = i + 1; j < pq.size(); ++j) {
                        if (find_scc_min[pq[i]] > find_scc_min[pq[j]]) {
                            int temp = pq[i];
                            pq[i] = pq[j];
                            pq[j] = temp;
                        }
                    }
                }
            }
        }
    }
}

void SSC(int node, int& index, std::vector<int>& ids, std::vector<int>& low,
            std::vector<int>& stack, std::vector<bool>& on_stack,
            const std::vector<std::vector<bool>>& dependencies,
            std::vector<std::vector<int>>& sccs) {
    ids[node] = low[node] = index++;
    stack.push_back(node);
    on_stack[node] = true;

    for (int neighbor = 0; neighbor < dependencies.size(); ++neighbor) {
        if (dependencies[node][neighbor]) {
            if (ids[neighbor] == -1) {
                SSC(neighbor, index, ids, low, stack, on_stack, dependencies, sccs);
                low[node] = (low[node] < low[neighbor]) ? low[node] : low[neighbor];
            } else if (on_stack[neighbor]) {
                low[node] = (low[node] < ids[neighbor]) ? low[node] : ids[neighbor];
            }
        }
    }

    if (ids[node] == low[node]) {
        std::vector<int> scc;
        while (!stack.empty()) {
            int top = stack.back();
            stack.pop_back();
            on_stack[top] = false;
            scc.push_back(top);
            if (top == node) break;
        }
        int n = scc.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (scc[j] > scc[j + 1]) {
                    int temp = scc[j];
                    scc[j] = scc[j + 1];
                    scc[j + 1] = temp;
                }
            }
        }
        sccs.push_back(scc);
    }
}



std::vector<std::vector<int>> find_work_order(const std::vector<std::vector<bool>>& dependencies) {
    int n = dependencies.size();
    std::vector<int> ids(n, -1);       // To track discovery times
    std::vector<int> low(n, 0);       // To track the smallest reachable node
    std::vector<int> stack;           // Stack for SSC's algorithm
    std::vector<bool> on_stack(n, false); // To check if a node is in the stack
    std::vector<std::vector<int>> sccs;   // To store all SCCs

    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (ids[i] == -1) {
            SSC(i, index, ids, low, stack, on_stack, dependencies, sccs);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (ids[i] == -1) {
            sccs.push_back({i});
        }
    }

    std::vector<int> scc_map(n, -1);
    for (int i = 0; i < sccs.size(); ++i) {
        for (int node : sccs[i]) {
            scc_map[node] = i;
        }
    }

    std::vector<std::vector<int>> condensed_graph(sccs.size());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dependencies[i][j] && scc_map[i] != scc_map[j]) {
                bool duplicate = false;
                for (int neighbor : condensed_graph[scc_map[i]]) {
                    if (neighbor == scc_map[j]) {
                        duplicate = true;
                        break;
                    }
                }
                if (!duplicate) {
                    condensed_graph[scc_map[i]].push_back(scc_map[j]);
                }
            }
        }
    }
    std::vector<int> in_degree(sccs.size(), 0);
    for (const auto& neighbors : condensed_graph) {
        for (int neighbor : neighbors) {
            ++in_degree[neighbor];
        }
    }
    std::vector<int> find_scc_min(sccs.size());
    for (int i = 0; i < sccs.size(); ++i) {
        find_scc_min[i] = sccs[i][0];
    }

    std::vector<int> topo_order;
    topologicalSort(condensed_graph, in_degree, topo_order, find_scc_min);

    std::vector<std::vector<int>> work_order;
    for (int scc_id : topo_order) {
        work_order.push_back(sccs[scc_id]);
    }

    return work_order;
}
