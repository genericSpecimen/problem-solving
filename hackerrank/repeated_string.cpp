#include <iostream>

int main() {
    std::string s;
    unsigned long int n;
    std::cin >> s >> n;
    unsigned int size = s.size();

    unsigned long int num_a_in_input = 0;
    for(unsigned int i=0;i<s.size();i++) if(s[i] == 'a') num_a_in_input++;

    unsigned long int num_a = 0;
    num_a += num_a_in_input * (n/size);
    for(unsigned long int i=0;i<(n%size);i++) if(s[i] == 'a') num_a++;
    std::cout << num_a << std::endl;
}