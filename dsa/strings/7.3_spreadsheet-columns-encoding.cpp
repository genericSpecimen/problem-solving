/*
#define MAXWEIGHT std::numeric_limits<int>::max() / 26
int titleToNumber(string columnTitle) {
    int columnNum = 0;
    int weight = 1;
    for (int i=columnTitle.size()-1; i>=0; i--) {
        columnNum += ((columnTitle[i]-'A'+1) * weight);
        if (weight <=  MAXWEIGHT) {
            weight *= 26;
        }
    }
    
    return columnNum;
}
*/

// O(n) time, O(1) space
int titleToNumber(string columnTitle) {
    int columnNum = 0, base = 26;
    for (int i=0; i<columnTitle.size(); i++) {
        columnNum = (columnNum * 26) + (columnTitle[i]-'A'+1);
    }
    
    return columnNum;
}

// if A : 0, .., Z : 25
int titleToNumberStartsFromZero(string columnTitle) {
    int columnNum = 0, base = 26;
    for (int i=0; i<columnTitle.size()-1; i++) {
        columnNum = (columnNum * 26) + (columnTitle[i]-'A'+1);
    }
    
    columnNum = (columnNum * 26) + (columnTitle[columnTitle.size()-1]-'A');
    return columnNum;
}


// O(log_26 n) = O(log n) time
std::string convertToTitle(int columnNumber) {
    int n = columnNumber;
    std::string columnTitle = "";
    while (n > 0) {
        int rem = n % 26;
        n /= 26;
        if (rem == 0) {
            columnTitle += 'Z';
            n--;
        } else {
            columnTitle += 'A' + rem - 1;
        }
    }
    
    std::reverse(columnTitle.begin(), columnTitle.end());
    return columnTitle;
}
