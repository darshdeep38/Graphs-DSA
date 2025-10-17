#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = watchedVideos.size();
        unordered_set<int> visited;
        queue<int> q;
        visited.insert(id);
        q.push(id);
        int currLevel = 0;

        // Step 1: BFS to reach the exact 'level' friends
        while (!q.empty() && currLevel < level) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int person = q.front();
                q.pop();
                for (int f : friends[person]) {
                    if (visited.find(f) == visited.end()) {
                        visited.insert(f);
                        q.push(f);
                    }
                }
            }
            currLevel++;
        }

        // Step 2: Count videos watched by people at the exact level
        unordered_map<string, int> videoCount;
        while (!q.empty()) {
            int person = q.front();
            q.pop();
            for (const string& video : watchedVideos[person]) {
                videoCount[video]++;
            }
        }

        // Step 3: Sort by frequency, then lexicographically
        vector<pair<string, int>> videoList(videoCount.begin(), videoCount.end());
        sort(videoList.begin(), videoList.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
        });

        // Step 4: Prepare result
        vector<string> result;
        for (const auto& p : videoList)
            result.push_back(p.first);

        return result;
    }
};
