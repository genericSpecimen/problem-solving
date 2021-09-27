
std::unordered_map<char, int> roman = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

bool isException(int prev_value, int value) {
    return (
        (prev_value == roman['I'] && (value == roman['V'] || value == roman['X'])) ||
        (prev_value == roman['X'] && (value == roman['L'] || value == roman['C'])) ||
        (prev_value == roman['C'] && (value == roman['D'] || value == roman['M']))
        );
}

int romanToInt(string s) {
    int prev_value = std::numeric_limits<int>::max();
    int num = 0;
    for (char ch : s) {
        int value = roman[ch];
        if (value > prev_value) {
            // check for exceptions
            if (isException(prev_value, value)) {
                // valid exception
                //std::cout << "Found valid exception." << std::endl;
                num = (num - prev_value) + (value - prev_value);
            } else {
                //std::cout << "Invalid Roman number." << std::endl;
                return -1;
            }
        } else {
            num += value;
            prev_value = value;
        }
    }
    
    return num;
}

std::map<int, std::string> roman = {
    {1,   "I" },
    {4,   "IV"},
    {5,   "V" },
    {9,   "IX"},
    {10,  "X" },
    {40,  "XL"},
    {50,  "L" },
    {90,  "XC"},
    {100, "C" },
    {400, "CD"},
    {500, "D" },
    {900, "CM"},
    {1000, "M"}
};
string intToRoman(int num) {
    std::string roman_str = "";
    for (auto it = roman.crbegin(); it != roman.crend(); it++) {
        //std::cout << it->first << ":" << it->second << '\n';
        int q = num / it->first;
        
        if (q > 0) {   
            for (int i=0; i<q; i++) {
                roman_str += it->second;
            }
            num = num % it->first;
        }
        
    }
    return roman_str;
}
