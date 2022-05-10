class Solution {
public:
    int totalNQueens(int n) {
        return solveNQueens(n).size();
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> collection;
        vector<string> conf(n, string(n, '.'));
        solveRow(conf, 0, collection);
        for(auto& conf : collection) {
            for(auto& row : conf) {
                std::replace(row.begin(), row.end(), '*', '.');
            }
        }
        return collection;
    }
    
    void solveRow(vector<string> conf, size_t idx, vector<vector<string>>& collection) {
        if(idx == conf.size()) {
            collection.push_back(conf);
            return;
        }
        for(size_t i = 0; i < conf.size(); ++i) {
            if(conf[idx][i] != '*') {
                vector<string> newConf = conf;
                newConf[idx][i] = 'Q';
                for(size_t r = i + 1, d = idx + 1; r < conf.size() && d < conf.size(); ++r, ++d) {
                    newConf[d][r] = '*';
                }
                if(i != 0) {
                    for(size_t l = i - 1, d = idx + 1; d < conf.size(); --l, ++d) {
                        newConf[d][l] = '*';
                        if(l == 0) {
                            break;
                        }
                    }   
                }
                for(size_t d = idx + 1; d < conf.size(); ++d) {
                    newConf[d][i] = '*';
                }
                solveRow(newConf, idx+1, collection);
            }   
        }
    }
};
