#include <iostream>
#include <vector>

template <class T>
std::ostream& operator<< (std::ostream& os, const std::vector<T> v) {
    os << "[";
    for (auto elem : v) {
        os << elem << "\n";
    }
    os << "]";
    return os;
}

class GenericObject {
public:
    int key;
    int obj_id;
    static int id;
    
    GenericObject() {}
    GenericObject(int _key) : key(_key), obj_id(id++) {}
    
    friend std::ostream& operator<< (std::ostream &os, const GenericObject &obj) {
        os << "Object ID: " << obj.obj_id << ", key: " << obj.key;
        return os;
    }
};

int GenericObject::id = 0;

// not a stable sort
void threeKeysSort(std::vector<GenericObject> &A) {     
    int red_end = 0, white = 0, blue_start = A.size();
    
    while (white < blue_start) {
        if (A[white].key == 0) {
            // swap with first WHITE
            std::swap(A[red_end++], A[white++]);
        } else if (A[white].key == 1) {
            // do nothing
            white++;
        } else {
            // swap with the last unclassified element (just before blue_start)
            std::swap(A[--blue_start], A[white]);
        }
    }
    
}

std::vector<GenericObject> countingSort(std::vector<GenericObject> &A, int num_keys) {
    std::vector<int> count(num_keys, 0);
    std::vector<GenericObject> sorted_output(A.size());
    
    for (auto &obj : A) {
        count[obj.key]++;
    }
    
    //std::cout << count << std::endl;
    
    for (int i=1; i<num_keys;i++) {
        count[i] += count[i-1];
    }
    
    // start iterating from the end to preserve order
    for (auto it=A.rbegin() ; it!=A.rend(); it++) {
        sorted_output[count[it->key]-1] = *it;
        count[it->key]--;
    }
    
    return sorted_output;
}

int main() {
    std::vector<GenericObject> obj_vec(10);
    int num_keys = 2;
    
    for (int i=0; i<10; i++) {
        obj_vec[i] = GenericObject(i%num_keys);
    }
    
    std::cout << obj_vec << "\n\n";
    
    //threeKeysSort(obj_vec);
    
    std::vector<GenericObject> sorted_output = countingSort(obj_vec, num_keys);
    
    std::cout << sorted_output << "\n\n";
}
