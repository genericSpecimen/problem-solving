#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    
    // Declare second integer, double, and String variables.
    int sum_i;
    double sum_d;
    string concat_s;
    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    cin >> sum_i >> sum_d;
    cin.ignore(256, '\n'); 
    getline(cin,concat_s);
    
    // Print the sum of both integer variables on a new line.
    cout << i+sum_i << endl;
    cout << showpoint << d+sum_d << endl;
    s += concat_s;
    cout << s << endl;
    // Print the sum of the double variables on a new line.
    
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.

    return 0;
}