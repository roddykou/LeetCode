vector<double> calcEquation(vector<pair<string, string>> equations,
                            vector<double>& values,
                            vector<pair<string, string>> queries) {
    // 22:05
    unordered_map<string, int> str2idx;
    int idx = 0;
    for (auto p : equations) {
        if (str2idx.find(p.first) == str2idx.end())
            str2idx[p.first] = idx++;
        if (str2idx.find(p.second) == str2idx.end())
            str2idx[p.second] = idx++;
    }
    
    int n = str2idx.size();
    vector<vector<double>> matrix (n, vector<double> (n, NAN));
    for (int i = 0; i < equations.size(); i++) {
        int idx1 = str2idx[equations[i].first];
        int idx2 = str2idx[equations[i].second];
        matrix[idx1][idx2] = values[i];
        matrix[idx2][idx1] = 1.0 / values[i];
        matrix[idx1][idx1] = 1.0;
        matrix[idx2][idx2] = 1.0;
    }
    
    vector<double> ret;
    for (auto q : queries) {
        if (str2idx.find(q.first) == str2idx.end() ||
            str2idx.find(q.second) == str2idx.end())
            ret.push_back(-1.0);
        else
            ret.push_back(bfs(matrix, str2idx[q.first], str2idx[q.second]));
    }
    return ret;
}

double bfs(vector<vector<double>>& matrix, int start, int end) {
    if (!isnan(matrix[start][end]))
        return matrix[start][end];
    
    queue<int> q;
    for (int i = 0; i < matrix.size(); i++)
        if (!isnan(matrix[start][i]))
            q.push(i);
    
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < matrix.size(); i++) {
            if (isnan(matrix[start][i]) && !isnan(matrix[current][i])) {
                matrix[start][i] = matrix[start][current] * matrix[current][i];
                matrix[i][start] = 1.0 / matrix[start][i];
                if (i == end)
                    return matrix[start][end];
                q.push(i);
            }
        }
    }
    return -1.0;
}