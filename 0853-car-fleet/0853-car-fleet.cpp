class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // initialize a stack to store fleets results
        stack<float> fleets;
        // initialize a vector to store the position and time
        vector<pair<int, float>> pos_time;

        for(int i = 0; i < position.size(); i++){
            pos_time.push_back({position[i], float(target - position[i]) / speed[i]});
        }

        // sort the vector
        sort(pos_time.begin(), pos_time.end());

        for(int i = 0; i < position.size(); i++){
            float fleet_i = pos_time[i].second;

            while(fleets.size() && (fleet_i >= fleets.top())){
                fleets.pop();
            }
            fleets.push(fleet_i);
        }
        return fleets.size();
    }
};