class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> sizeToPeople;
        vector<vector<int>> result;

        // Step 1: Group people by their required group size
        for (int i = 0; i < groupSizes.size(); ++i) {
            int size = groupSizes[i];
            sizeToPeople[size].push_back(i);

            // Step 2: When we collect enough people for a group, move it to result
            if (sizeToPeople[size].size() == size) {
                result.push_back(sizeToPeople[size]);
                sizeToPeople[size].clear(); // Reset for next group
            }
        }

        return result;
    }
};
