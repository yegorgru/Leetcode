#include <vector>
#include <algorithm>
#include <utility>

class Solution {
public:
    int trap(std::vector<int>& height) {
        std::vector<std::pair<int, int>> leftRightHeights(height.size(), {0,0});
        int maxLeft = height.at(0);
        int maxRight = height.back();
        for(size_t i = 0; i < height.size(); ++i)  {
            if(maxLeft < height.at(i)) {
                maxLeft = height.at(i);
            }
            leftRightHeights.at(i).first = maxLeft;
            
            if(maxRight < height.at(height.size() - 1 - i)) {
                maxRight = height.at(height.size() - 1 - i);
            }
            leftRightHeights.at(height.size() - 1 - i).second = maxRight;
        }
        int volume = 0;
        for(size_t i = 0; i < height.size(); ++i) {
            volume += std::min(leftRightHeights.at(i).first,
                               leftRightHeights.at(i).second) 
                      - height.at(i);
        }
        return volume;
    }
};
