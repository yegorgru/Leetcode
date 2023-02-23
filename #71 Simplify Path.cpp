class Solution {
public:
    string simplifyPath(string path) {
        vector<string> pathParts;
        size_t currPos = 1;
        while(currPos < path.size()) {
            auto slashPos = path.find('/', currPos);
            if(slashPos == currPos) {
                ++currPos;
                continue;
            }
            if(slashPos == string::npos) {
                slashPos = path.size();
            }
            string pathPart(path.begin() + currPos, path.begin() + slashPos);
            if(pathPart == "..") {
                if (pathParts.size() > 0) {
                    pathParts.pop_back();
                }
            }
            else if(pathPart != ".") {
                pathParts.push_back(pathPart);
            }
            currPos = slashPos + 1;
        }
        string answer("/");
        for (const auto& part : pathParts) {
            answer += part + "/";
        }
        if(answer != "/") {
            answer.pop_back();
        }
        return answer;
    }
};
