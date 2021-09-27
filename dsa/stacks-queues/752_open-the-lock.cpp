class Solution {
public:
    /*
    // check if generated string is a deadend.
    // O(n) time.
    // Instead of this, we can mark the deadends as visited in the map to achieve the same effect
    bool isDeadend(const vector<string>& deadends, const string str) {
        for (auto &s : deadends) {
            if (str.compare(s) == 0) return true;
        }
        return false;
    }
    */
    
    // check if str hasn't been generated. If not, then push it to the queue and mark it generated
    void checkAndInsert(queue<string> &q, unordered_map<string, int> &generated, string &curr, string &str) {
        if (generated.find(str) == generated.end()) {
            //std::cout << "Pushed " << str << std::endl;
            q.push(str);
            generated[str] = generated[curr] + 1;
        }        
    }
    
    int openLock(const vector<string>& deadends, const string target) {
        string initial = "0000";
        if (initial.compare(target) == 0) return 0;
        
        unordered_map<string, int> generated;
        
        // hack: set all deadends as visited instead of using isDeadend
        for (auto &s : deadends) {
            generated.insert({s, -1});
        }
        if (generated.find(initial) != generated.end()) {
            // initial config is a deadend
            return -1;
        }
        
        queue<string> q;
        q.push(initial);
        
        // mark initial as visited, and, we can reach the initial state in zero moves
        generated[initial] = 0;
        
        while (!q.empty()) {
            string curr = q.front(); q.pop();
            for (int i=0; i<4; i++) {
                string prev = curr, next = curr;
                
                // move the ith wheel once in reverse order
                prev[i] = ((prev[i] - '0' - 1) + 10) % 10 + '0';
                if (prev == target) {
                    //std::cout << "reached " << prev << std::endl;
                    // the target was reached from curr using 1 additional move
                    return generated[curr]+1;
                }
                checkAndInsert(q, generated, curr, prev);
                
                // move the ith wheel once
                next[i] = (next[i] - '0' + 1) % 10 + '0';
                if (next == target) {
                    //std::cout << "reached " << next << std::endl; 
                    // the target was reached from curr using 1 additional move
                    return generated[curr]+1;
                }
                checkAndInsert(q, generated, curr, next); 
                
            }
        }
        
        return -1;
        
    }
};
