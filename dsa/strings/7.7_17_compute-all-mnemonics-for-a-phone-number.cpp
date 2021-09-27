std::array<std::string, 10> mappings = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

/*
 // recursive solution
void generateCombinations(std::string digits,
                        int idx, std::string curr,
                        std::vector<std::string> &combinations) {
    if (idx == digits.size()-1) {
        // append the last possible digits
        for (char ch : mappings[digits[idx]-'0']) {
            combinations.push_back(curr + ch);
        }
    } else {
        // choose each possible character at this point, 
        // and recursively generate combinations of remaining digits
        for (char ch : mappings[digits[idx]-'0']) {
            generateCombinations(digits, idx+1, curr+ch, combinations);
        }
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) {
        return {};
    }
    
    std::vector<std::string> combinations;
    int idx = 0;
    std::string curr = "";
    generateCombinations(digits, idx, curr, combinations);
    
    return combinations;
}
*/

// iterative solution
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    
    std::vector<std::string> combinations = {""};
    for (char digit : digits) {
        std::vector<std::string> temp;
        for (std::string s : combinations) {
            for (char ch : mappings[digit-'0']) {
                temp.push_back(s + ch);
            }
        }
        combinations = temp;
    }
    
    return combinations;
}
