#include "/root/leetcode/tool/helper.cpp"
using namespace std;

/*
给你一个 n 个点组成的无向图边集 edgeList ，其中 edgeList[i] = [ui, vi, disi] 表示点 ui
和点 vi 之间有一条长度为 disi 的边。请注意，两个点之间可能有 超过一条边 。 给你一个查询数组queries ，其中 queries[j] =
[pj, qj, limitj] ，你的任务是对于每个查询 queries[j] ，判断是否存在从 pj 到 qj 的路径，且这条路径上的每一条边都
严格小于 limitj 。 请你返回一个 布尔数组 answer ，其中 answer.length ==
queries.length ，当 queries[j] 的查询结果为 true 时， answer 第 j 个值为 true ，否则为 false 。

description:
2 <= n <= 10^5
1 <= edgeList.length, queries.length <= 10^5
edgeList[i].length == 3
queries[j].length == 3
0 <= ui, vi, pj, qj <= n - 1
ui != vi
pj != qj
1 <= disi, limitj <= 10^9
*/

// Class Solution

class Solution {
  public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<int> queriesrank(queries.size());
        iota(queriesrank.begin(), queriesrank.end(), 0);
        sort(queriesrank.begin(), queriesrank.end(), [&](int i, int j) { return queries[i][2] < queries[j][2]; });
        sort(edgeList.begin(), edgeList.end(), [](vector<int> e1, vector<int> e2) { return e1[2] < e2[2]; });
        vector<int> father(n);
        iota(father.begin(), father.end(), 0);
        vector<int> rank(n, 1);
        int edge_id = 0;
        vector<bool> ans(queries.size());
        for (int query_id : queriesrank) {
            int& nowweight = queries[query_id][2];
            while (edge_id < edgeList.size() && nowweight > edgeList[edge_id][2]) {
                merge(father, rank, edgeList[edge_id][0], edgeList[edge_id][1]);
                ++edge_id;
            }
            // check connected
            ans[query_id] = find(father, queries[query_id][0]) == find(father, queries[query_id][1]);
        }
        // show(father);
        // show(rank);
        return ans;
    }
    void merge(vector<int>& father, vector<int>& rank, int i, int j) {
        i = find(father, i);
        j = find(father, j);
        if (i == j) {
            return;
        }
        // cout << "i:" << i << " j:" << j << " rank[i]" << rank[i] << " rank[j]" << rank[j] << endl;
        if (rank[i] < rank[j]) {
            swap(i, j);
        }

        father[j] = i;
        rank[i] += rank[j];
    }
    int find(vector<int>& father, int i) {
        return i == father[i] ? i : father[i] = find(father, father[i]);
    }
};

int main() {
    Solution A;
    // vector<vector<int>> edgeList{{0, 1, 2}, {1, 2, 6}, {2, 0, 8}, {1, 0, 16}};
    // vector<vector<int>> queries{{0, 1, 2}, {0, 2, 5}}; // 1 0
    vector<vector<int>> edgeList{{0, 1, 10}, {1, 2, 5}, {2, 3, 9}, {3, 4, 13}};
    vector<vector<int>> queries{{0, 4, 14}, {1, 4, 13}};
    show(A.distanceLimitedPathsExist(5, edgeList, queries));
    return 0;
}
