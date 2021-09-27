#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>


template <class T>
std::ostream& operator<< (std::ostream& os, const std::vector<T> v) {
    os << "[";
    for (auto elem : v) {
        os << elem << ",";
    }
    os << "]";
    return os;
}

// O(n^3) TLE
int maxSubarraySumBF(const std::vector<int> &nums) {
    if (nums.size() == 1) {
        return nums.front();
    }
    
    int max_subarray_sum = std::numeric_limits<int>::min();
    
    for (int sub_size=1; sub_size<=nums.size(); sub_size++) {
        //std::cout << "Subarrays of size: " << sub_size << std::endl;
        int max_sub_size_sum = std::numeric_limits<int>::min();
        for (int i=0; i<(nums.size()-sub_size+1); i++) {
            int curr_sub_sum = 0;
            for (int j=i; j<i+sub_size; j++) {
                //std::cout << nums[j] << ", ";
                curr_sub_sum += nums[j];
            }
            //std::cout << std::endl;
            max_sub_size_sum = std::max(max_sub_size_sum, curr_sub_sum);
        }
        max_subarray_sum = std::max(max_subarray_sum, max_sub_size_sum);
    }
    return max_subarray_sum;
}

// O(n^2) avoid repeated sum calculations, AC but very high runtime
int maxSubarraySumBetterBF(const std::vector<int> &nums) {
    if (nums.size() == 1) {
        return nums.front();
    }
    
    std::pair<int, int> max_subarray_indices;
    int max_subarray_sum = std::numeric_limits<int>::min();
    for (int low=0; low<nums.size(); low++) {
        int curr_sum = 0;
        for (int high=low; high<nums.size(); high++) {
            curr_sum += nums[high];
            if (curr_sum > max_subarray_sum) {
                max_subarray_sum = curr_sum;
                max_subarray_indices = {low, high};
            }
        }
    }
    //std::cout << "Max Subarray indices: [" << max_subarray_indices.first << ", " << max_subarray_indices.second << "]" << std::endl;
    
    return max_subarray_sum;
}

// ______________________________________________________

/*
 * Find a maximum sum subarray which passes through mid
 * i.e. is of the form nums[low..mid], nums[mid+1..high].
 * This is a constrained version of the original problem,
 * where the subarray must pass through mid.
 * 
 * Find the left maximum subarray nums[i..mid], which maximizes max_left_sum.
 * Find the right maximum subarray nums[mid+1..j] which maximizes max_right_sum.
 * Then, the maximum subarray passing through mid is nums[i..j] with
 * sum = max_left_sum + max_right_sum.
 * 
 * Running time = num_iterations * O(1) per iteration
 * num_iterations = (mid-low+1) + (high-mid) = high-low+1 = n,
 * where n = number of elements in subarray nums[low..high]
 * 
 */
/*
int maxCrossingSubarray(const std::vector<int> &nums, int low, int mid, int high) {    
    int max_left_sum = std::numeric_limits<int>::min();
    // indices
    std::pair<int, int> max_crossing_subarray;
    
    int max_right_sum = std::numeric_limits<int>::min();
    
    // find max_left_sum in nums[low..mid]
    int sum = 0;
    for (int i=mid; i>=low; i--) {
        sum += nums[i];
        if (sum > max_left_sum) {
            max_left_sum = sum;
            // record left index
            max_crossing_subarray.first = i;
        }
    }
    
    // find max_right_sum in A[mid+1..high]
    sum = 0;
    for (int j=mid+1; j<=high; j++) {
        sum += nums[j];
        if (sum > max_right_sum) {
            max_right_sum = sum;
            // record right index
            max_crossing_subarray.second = j;
        }
    }
    return max_left_sum+max_right_sum;
    
}

//Divide and Conquer - O(n log n)
//T(n) = 2T(n/2) + O(n)
int maxSubarraySumDnC(const std::vector<int> &nums, int low, int high) {
    if (low == high) {
        // single element
        return nums[low];
    }
    
    int mid = low + (high-low)/2;
    
    int max_left_subarray_sum = maxSubarraySumDnC(nums, low, mid);
    int max_right_subarray_sum = maxSubarraySumDnC(nums, mid+1, high);
    int max_crossing_subarray_sum = maxCrossingSubarray(nums, low, mid, high);
    
    return std::max({
        max_left_subarray_sum,
        max_right_subarray_sum,
        max_crossing_subarray_sum
    });
    
}

int maxSubArray(const std::vector<int> &nums) {
    return maxSubarraySumDnC(nums, 0, nums.size()-1);
}
*/


// indices of the subarray and its sum
typedef std::pair<std::pair<int,int>, int> MaxSubArray;

MaxSubArray maxCrossingSubarray(const std::vector<int> &nums, int low, int mid, int high) {    
    int max_left_sum = std::numeric_limits<int>::min();
    
    MaxSubArray max_crossing_subarray;
    
    int max_right_sum = std::numeric_limits<int>::min();
    
    // find max_left_sum in nums[low..mid]
    int sum = 0;
    for (int i=mid; i>=low; i--) {
        sum += nums[i];
        if (sum > max_left_sum) {
            max_left_sum = sum;
            // record left index
            max_crossing_subarray.first.first = i;
        }
    }
    
    // find max_right_sum in A[mid+1..high]
    sum = 0;
    for (int j=mid+1; j<=high; j++) {
        sum += nums[j];
        if (sum > max_right_sum) {
            max_right_sum = sum;
            // record right index
            max_crossing_subarray.first.second = j;
        }
    }
    
    max_crossing_subarray.second = max_left_sum+max_right_sum;
    return max_crossing_subarray;
    
}

MaxSubArray maxSubarraySumDnC(const std::vector<int> &nums, int low, int high) {
    if (low == high) {
        // single element
        return {{low, high}, nums[low]};
    }
    
    int mid = low + (high-low)/2;
    
    MaxSubArray max_left_subarray = maxSubarraySumDnC(nums, low, mid);
    MaxSubArray max_right_subarray = maxSubarraySumDnC(nums, mid+1, high);
    MaxSubArray max_crossing_subarray = maxCrossingSubarray(nums, low, mid, high);
    
    if (max_left_subarray.second >= max_right_subarray.second &&
        max_left_subarray.second >= max_crossing_subarray.second
    ) {
        return max_left_subarray;
    }
    
    else if (max_right_subarray.second >= max_left_subarray.second &&
            max_right_subarray.second >= max_crossing_subarray.second
    ) {
        return max_right_subarray;
    }
    
    return max_crossing_subarray;
}

MaxSubArray maxSubArray(const std::vector<int> &nums) {
    return maxSubarraySumDnC(nums, 0, nums.size()-1);
}



MaxSubArray maxSubArrayKadane(const std::vector<int> &nums) {
    int max_subarray_sum = std::numeric_limits<int>::min();
    int max_subarray_start = 0, max_subarray_end = 0;
    
    int curr_subarray_sum = 0;
    int curr_subarray_start = 0, curr_subarray_end = 0;
    
    for (int curr_subarray_end=0; curr_subarray_end<nums.size(); curr_subarray_end++) {
        // max subarray ending at j
        if (curr_subarray_sum <= 0) {
            // start a new interval at curr_subarray_end
            curr_subarray_start = curr_subarray_end;
            curr_subarray_sum = nums[curr_subarray_end];
        } else {
            // extend the existing interval with the current element
            curr_subarray_sum += nums[curr_subarray_end];
        }
        
        if (curr_subarray_sum > max_subarray_sum) {
            max_subarray_sum = curr_subarray_sum;
            max_subarray_start = curr_subarray_start;
            max_subarray_end = curr_subarray_end;
        }
    }
    
    return {{max_subarray_start, max_subarray_end}, max_subarray_sum};
}

std::pair<std::pair<int,int>, int> longestSameElementsSubArray(const std::vector<int> &nums) {
    if (nums.empty()) {
        return {{-1, -1}, 0};
    } else if (nums.size() == 1) {
        return {{0, 0}, 1};
    }
    
    int max_length = std::numeric_limits<int>::min();
    int max_subarray_start = 0, max_subarray_end = 0;
    
    int curr_length = 0;
    int curr_subarray_start = 0;
    for (int curr_subarray_end = 0; curr_subarray_end<nums.size(); curr_subarray_end++) {
        if (nums[curr_subarray_end] == nums[curr_subarray_start]) {
            curr_length++;
        } else {
            curr_length = 1;
            curr_subarray_start = curr_subarray_end;
        }
        
        if (curr_length > max_length) {
            max_length = curr_length;
            max_subarray_start = curr_subarray_start;
            max_subarray_end = curr_subarray_end;
        }
    }
    
    return {{max_subarray_start, max_subarray_end}, max_length};
    
}

int main() {
    std::vector<std::vector<int>> test_cases = {
        {310,315,275,295,260,270,290,230,255,250},
        {1,4,2,3},
        {2,1,4},
        {0, 5, -40, 20, -35, 10, 20, -60, 25, -5},
        {-2,1,-3,4,-1,2,1,-5,4},
        {1},
        {5,4,-1,7,8},
        {5,4,-1,7,8,-2},
        {-2, -1},
        {0,-6,4,-2,3,-2},
        {1, 2, 2, 2, 3, 3, 4, 5, 4, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 6}
        
    };
    
    for (auto &vec : test_cases) {
        //std::cout << maxSubarraySumBF(vec) << std::endl;
        //std::cout << maxSubarraySumBetterBF(vec) << std::endl;
        MaxSubArray msa = maxSubArray(vec);
        std::cout << "Indices: [" << msa.first.first << "," << msa.first.second << "]"
                  << ", Sum: " << msa.second << std::endl;
        
        MaxSubArray msa1 = maxSubArrayKadane(vec);
        std::cout << "Indices: [" << msa1.first.first << "," << msa1.first.second << "]"
                  << ", Sum: " << msa1.second << std::endl << std::endl;
    }
    
    /*
    for (auto &vec : test_cases) {
        MaxSubArray lsesa = longestSameElementsSubArray(vec);
        std::cout << "Indices: [" << lsesa.first.first << "," << lsesa.first.second << "]"
                  << ", length: " << lsesa.second << std::endl << std::endl;
    }
    */
    return 0;
}
