#include <iostream>
#include <string>

int main() {
	int T; std::cin >> T;
	int num_activities, contest_rank, bonus, bug_severity, num_laddus = 0;
	std::string origin; // INDIAN or NON_INDIAN
	
	//activity: one of CONTEST_WON, TOP_CONTRIBUTOR, BUG_FOUND, CONTEST_HOSTED
	std::string activity;
	while(T--) {
		num_laddus = 0;
		std::cin >> num_activities;
		//std::cout << "Num activities = " << num_activities << "\n";
		std::cin >> origin;
		//std::cout << "Origin: " << origin << "\n";

		while(num_activities--) {
			std::cin >> activity;
			if (activity.compare("CONTEST_WON") == 0) {
				std::cin >> contest_rank;
				//std::cout << "Won contest with rank: " << contest_rank << "\n";
				bonus = (contest_rank > 20) ? 0 : 20-contest_rank;
				num_laddus += (300 + bonus); 
			} else if (activity.compare("TOP_CONTRIBUTOR") == 0) {
				//std::cout << "Top Contributor on discuss\n";
				num_laddus += 300;
			} else if (activity.compare("BUG_FOUND") == 0) {
				std::cin >> bug_severity;
				//std::cout << "Found bug with severity: " << bug_severity << "\n";	
				num_laddus += bug_severity;
			} else if (activity.compare("CONTEST_HOSTED") == 0) {
				//std::cout << "Hosted contest\n";
				num_laddus += 50;
			}
		}	
		
		if (origin.compare("INDIAN") == 0) std::cout << num_laddus / 200 << "\n";
		else if (origin.compare("NON_INDIAN") == 0) std::cout << num_laddus / 400 << "\n";
	}
	return 0;
}
