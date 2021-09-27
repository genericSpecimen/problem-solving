class MedianFinder {
public:
    priority_queue <int,
                    vector<int>,
                    std::less<int>> left; // maxheap
    priority_queue <int,
                    vector<int>,
                    std::greater<int>> right; // min heap
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);
        
        if (!left.empty() && !right.empty() && left.top() > right.top()) {
            int left_max = left.top(); left.pop();
            right.push(left_max);
            //cout << "1. popped from L and pushed to R: " << left_max << endl;
        }
        
        if (left.size() > right.size() + 1) {
            int left_max = left.top(); left.pop();
            right.push(left_max);
            //cout << "2. popped from L and pushed to R: " << left_max << endl;
        }
        
        if (right.size() > left.size() + 1) {
            int right_min = right.top(); right.pop();
            left.push(right_min);
            //cout << "popped from R and pushed to L: " << right_min << endl;
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) return left.top();
        if (right.size() > left.size()) return right.top();
        
        return (left.top() + right.top()) / 2.0; // imp: 2.0 to cast to double
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
