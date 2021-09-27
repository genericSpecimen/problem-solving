class Solution {
public:
    pair<int, long long int> findKthElement(vector<int>& count, int k, int start=0, long long int curr_count=0) {
        // 1-based
        for (int i=start; i<count.size(); i++) {
            curr_count += count[i];
            
            if (curr_count >= k) {
                return {i, curr_count};
            }
        }
        assert(false);
        return {-1, -1};
    }
    
    double findMedian(vector<int>& count, int sample_size) {
        double median;
        
        int pos = sample_size / 2;
        if (sample_size % 2 != 0) pos++; // ceiling
        
        long long int curr_count = 0;
        int i = 0;
        
        // find pos-th element
        auto pos_info = findKthElement(count, pos);
        median = pos_info.first;
        
        if (sample_size % 2 == 0 && pos_info.second < pos + 1) {
            // find pos + 1 th element and recalculate median
            median = (median + findKthElement(count, pos+1, pos_info.first+1, pos_info.second).first) / 2.0;
        }
        
        return median;
    }
    
    vector<double> sampleStats(vector<int>& count) {
        double min = -1, max, mean, median, mode;
        int sample_size = 0, max_count = -1;
        long long int sum = 0;
        
        for (int i=0; i<count.size(); i++) {
            //for (int c=0; c<count[i]; c++) cout << i << ", ";
            
            // skip non-existent numbers
            if (count[i] == 0) continue;
            
            // set min only once
            if (min == -1) min = i;
            
            // keep setting max until you can
            max = i;
            
            // for mean
            sample_size += count[i];
            sum += (long)count[i] * i;
            
            // for mode
            if (count[i] > max_count) {
                max_count = count[i];
                mode = i;
            }
        }

        mean = sum / (double)sample_size;
        
        //cout << "sample size: " << sample_size << endl;

        return {min, max, mean, findMedian(count, sample_size), mode};
    }
};
