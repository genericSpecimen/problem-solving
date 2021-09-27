#include <iostream>
#include <vector>

template <class T>
std::ostream& operator<< (std::ostream& os, const std::vector<T> v) {
    os << "[";
    for (auto elem : v) {
        os << elem << ",";
    }
    os << "]";
    return os;
}


// brute force with O(n) additional space
std::vector<int> applyPermutationBF(std::vector<int> &A, std::vector<int> &P) {
    std::vector<int> result(A.size());
    for (int i=0; i<A.size(); i++) {
        result[P[i]] = A[i];
    }
    return result;
}

std::vector<int> applyPermutation(std::vector<int> &A, std::vector<int> &P) {
    for (int i=0; i<A.size(); i++) {
        if (P[i] < 0) {
            // element has already been processed
            continue;
        } else {
            int next = i;
            int temp = P[next];
            int displaced = A[temp];
            A[temp] = A[next];
            next = temp;
            while (P[next] >= 0) {
                temp = P[next];
                int old_displaced = displaced;
                displaced = A[temp];
                A[temp] = old_displaced;
                P[next] -= P.size();
                next = temp;
            }
        }
    }
    
    // restore P
    for (auto &p : P) p += A.size();
    
    return A;
}

// if modifying P is ok
std::vector<int> applyPermutation1(std::vector<int> &A, std::vector<int> &perm) {
  for (int i = 0; i < A.size(); ++i) {
    while (perm[i] != i) {
      std::swap(A[i], A[perm[i]]);
      std::swap(perm[i], perm[perm[i]]);
    }
  }
  return A;
}

std::vector<int> inversePermutation(std::vector<int> &P) {
    std::vector<int> result(P.size());
    
    for (int i=0; i<P.size(); i++) {
        result[P[i]] = i;
    }
    
    return result;
}

std::vector<int> inversePermutation1(std::vector<int> &P) {
    for (int i=0; i<P.size(); i++) {
        if (P[i] < 0) {
            // already processed
            continue;
        } else {
            int next = i;
            int temp = P[next];
            while (P[temp] >= 0) {
                int displaced = P[temp];
                //std::cout << "displacing: " << displaced << std::endl;
                P[temp] = next - P.size();
                
                next = temp;
                temp = displaced;
            }
        }
        std::cout << P << std::endl;
    }
    
    for(auto &p : P) p += P.size();
    
    return P;
}

int main() {
    std::vector<int> A = {10, 20, 30, 40};
    std::vector<int> P = {2, 0, 1, 3};
    //std::vector<int> P = {3, 1, 0, 2};
    
    //std::cout << applyPermutationBF(A, P) << std::endl;
    //std::cout << P << std::endl;
    //std::cout << applyPermutation(A, P) << std::endl;
    //std::cout << applyPermutation1(A, P) << std::endl;
    std::cout << P << std::endl;
    std::cout << inversePermutation(P) << std::endl;
    std::cout << inversePermutation1(P) << std::endl;
    //std::vector<int> inv_P = inversePermutation(P);
    //std::cout << applyPermutation(A, inv_P) << std::endl;
    return 0;
}
