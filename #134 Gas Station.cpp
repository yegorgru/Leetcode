class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        mEndPoints.resize(gas.size());
        for(size_t i = 0; i < gas.size(); ++i) {
            if(gas[i] == cost[i] && gas.size() > 1) {
                continue;
            }
            int currGas = 0;
            int count = canCompleteCircuit(gas, cost, i, currGas, 0);
            if(count == gas.size()) {
                return i;
            }
            else {
                mEndPoints[i] = {count, currGas};
                i = (i + count) % gas.size();
            }
        }
        return -1;
    }

private:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost, size_t currIdx, int& currGas, int count) {
        if(count == gas.size()) {
            return count;
        }
        int endCount = mEndPoints[currIdx].mCount;
        if(endCount > 0) {
            currGas += mEndPoints[currIdx].mGas;
            return endCount + count >= gas.size() ? gas.size() : canCompleteCircuit(gas, cost, (currIdx + endCount) % gas.size(), currGas, count + endCount);
        }
        int newGas = currGas + gas[currIdx] - cost[currIdx];
        if(newGas >= 0) {
            currGas = newGas;
            return canCompleteCircuit(gas, cost, (currIdx + 1) % gas.size(), currGas, count + 1);
        }
        else {
            return count;
        }
    }

private:
    struct EndPoint {
        int mCount = -1;
        int mGas = -1;
    };
private:
    vector<EndPoint> mEndPoints;
};
