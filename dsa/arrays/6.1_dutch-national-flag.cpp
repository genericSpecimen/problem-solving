#include <iostream>
#include <vector>

template <class T>
std::ostream& operator<< (std::ostream& os, const std::vector<T> v) {
    os << "[";
    for (auto elem : v) {
        os << elem << ", ";
    }
    os << "]";
    return os;
}

/*
void partition(std::vector<int> &A, int pivot_idx) {
    int pivot = A[pivot_idx];
    
    int i = -1;
    for (int j=0; j<A.size(); j++) {
        if (A[j] < pivot) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i+1], A[pivot_idx]);
}
*/
/*
// O(n^2) worst case time complexity
void partition(std::vector<int> &A, int pivot_idx) {
    int pivot = A[pivot_idx];
    // group elems < pivot
    for (int i=0; i<A.size(); i++) {
        for (int j=i+1; j<A.size(); j++) {
            if (A[j] < pivot) {
                std::swap(A[i], A[j]);
                break;
            }
        }
    }
    
    // group elems > pivot
    for (int i=A.size()-1; i>=0 && A[i]>=pivot; i--) {
        for (int j=i-1; j>=0 && A[j]>=pivot; j--) {
            if (A[j] > pivot) {
                std::swap(A[i], A[j]);
                break;
            }
        }
    }
}
*/

/*
 // O(n) time complexity: two passes
void partition(std::vector<int> &A, int pivot_idx) {
    int pivot = A[pivot_idx];
    
    // move A[i] < pivot to the left
    int L = 0;
    for(int i=0; i<A.size(); i++) {
        if (A[i] < pivot) {
            std::swap(A[i], A[L]);
            L++;
        }
    }
    
    // move A[i] > pivot to the right
    int G = A.size()-1;
    for (int i=A.size()-1; i>=0 && A[i]>=pivot; i--) {
        if (A[i] > pivot) {
            std::swap(A[i], A[G]);
            G--;
        }
    }
}
*/
/*
 * A[0:lesser-1] < pivot
 * A[lesser:equal-1] == pivot
 * A[equal:greater-1] : unclassified
 * A[greater:A.size()-1] : > pivot
 * 
 * Each iteration reduces the number of unclassified elements
 * by one, and the time spent within each iteration is O(1).
 * 
 * O(n) time complexity, single pass
 */

void partition(std::vector<int> &A, int pivot_idx) {
    int pivot = A[pivot_idx];
    
    int lesser = 0, equal = 0, greater = A.size();
    
    while (equal < greater) {
        if (A[equal] < pivot) {
            std::swap(A[lesser++], A[equal++]);
        } else if(A[equal] == pivot) {
            equal++;
        } else {
            std::swap(A[--greater], A[equal]);
        }
    }
}

/*
typedef enum {RED, WHITE, BLUE} DutchColor;
void dutchNationalFlag(std::vector<DutchColor> &A, int pivot_idx) {
    DutchColor pivot = A[pivot_idx];
    std::cout << pivot << std::endl;
    
//      0:red_end-1 RED
//      red_end:white-1 WHITE
//      white:blue_start-1 unclassified
//      blue_start:A.size()-1 BLUE
     
    int red_end = 0, white = 0, blue_start = A.size();
    
    while (white < blue_start) {
        if (A[white] == RED) {
            // swap with first WHITE
            std::swap(A[red_end++], A[white++]);
        } else if (A[white] == WHITE) {
            // do nothing
            white++;
        } else {
            // swap with the last unclassified element (just before blue_start)
            std::swap(A[--blue_start], A[white]);
        }
    }
    
}
*/

typedef enum {RED, BLUE, YELLOW, GREEN} MauritiusColor;
void mauritiusNationalFlag(std::vector<MauritiusColor> &A, int pivot_idx) {
    MauritiusColor pivot = A[pivot_idx];
    
    /*
     * A[0:red_end-1] : RED
     * A[red_end:blue-1]: BLUE
     * A[blue:yellow_start-1]: unclassified
     * A[yellow_start:green_start-1]: YELLOW
     * A[green_start:A.size()-1]: GREEN
     */
    
    int red_end = 0, blue = 0, yellow_start = A.size(), green_start = A.size();
    
    while (blue < yellow_start) {
        //std::cout << "red_end: " <<  red_end << ", blue: " << blue 
        //<< ", yellow_start: " << yellow_start << ", green_start: " << green_start << std::endl;
        if (A[blue] == RED) {
            // swap with first BLUE (= red_end)
            std::swap(A[red_end++], A[blue++]);
        } else if (A[blue] == BLUE) {
            // do nothing
            blue++;
        } else if (A[blue] == YELLOW) {
            //std::cout << "Swapping yellow with index " << yellow_start -1 << std::endl;
            // swap with last unclassified element (just before yellow_start)
            std::swap(A[--yellow_start], A[blue]);
        } else {
            if (yellow_start == blue + 1) {
                // no more unclassified elements left (except the current being processed)
                std::swap(A[--green_start], A[blue++]);
            } else {
                // swap last yellow with last unclassified element "?"
                std::swap(A[--green_start], A[--yellow_start]);
                // then swap current green with swapped "?"
                std::swap(A[green_start], A[blue]);
            }
        }
        //std::cout << A << std::endl << std::endl;
    }
}

/*
void booleanFlag(std::vector<bool> &A, bool pivot=false) {
    int false_end = 0, true_start = A.size();
    while (false_end < true_start) {
        if (A[false_end] == false) {
            false_end++;
        } else {
            std::swap(A[--true_start], A[false_end]);
        }
    }
}
*/

// preserve relative ordering among the true values
void booleanFlag(std::vector<bool> &A) {
    int last_false = A.size();
    for (int i=A.size()-1; i>=0; i--) {
        if (A[i] == true) {
            // swap with --last_false
            std::swap(A[i], A[--last_false]);
        }
    }
}

int main() {
    std::vector<int> A = {0, 1, 2, 3, 4, 1, 6, 7, 0, 2, 1, 1};
    std::cout << A << std::endl;
    int pivot_idx = 6;
    partition(A, pivot_idx);
    std::cout << A << std::endl;
    
    /*
    std::vector<DutchColor> A = {RED, WHITE, BLUE, RED, BLUE, WHITE, WHITE};
    dutchNationalFlag(A, 1);
    std::cout << A << std::endl;
    */
    
    std::vector<MauritiusColor> B = {RED, BLUE, RED, RED, BLUE, YELLOW, GREEN, BLUE, GREEN, YELLOW, RED, GREEN, BLUE, RED, BLUE, YELLOW, BLUE, BLUE, YELLOW, RED, YELLOW, BLUE};
    mauritiusNationalFlag(B, 1);
    std::cout << B << std::endl;
    
    std::vector<bool> C = {false, true, false, false, true, true};
    booleanFlag(C);
    std::cout << C << std::endl;
}
