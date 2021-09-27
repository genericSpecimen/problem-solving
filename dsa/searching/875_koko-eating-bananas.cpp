class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *std::max_element(piles.begin(), piles.end());
        
        int min_speed = r;
        
        while (l <= r) {
            int mid = l + (r-l) / 2;
            
            int num_hours = 0;
            for (int p : piles) num_hours += ceil(p / (double)mid);
            //cout << "mid: " <<  mid << ", num_hours: " << num_hours << endl;
            
            if (num_hours <= h) {
                // see if even less eating speed is possible
                //cout << mid << "is possible" << endl;
                r = mid - 1;
                min_speed = std::min(min_speed, mid);
            } else {
                //cout << mid << "is not possible" << endl;
                // need to increase eating speed since time limit was exceeded
                l = mid + 1;
            }
        }
        
        return min_speed;
    }
};
