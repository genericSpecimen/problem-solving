#include <iostream>
#include <climits>

int main() {
    int n;
    std::cin >> n;
    int score, min_score, max_score;
    std::cin >> score;
    min_score = max_score = score;
    
    int num_max_score_record_break = 0;
    int num_min_score_record_break = 0;
    for(int i=0;i<n-1;i++) {
        std::cin >> score;
        if(score < min_score) {
            min_score = score;
            num_min_score_record_break++;
        }
        else if(score > max_score) {
            max_score = score;
            num_max_score_record_break++;
        }
    }
    std::cout << num_max_score_record_break << " " << num_min_score_record_break << std::endl;
}