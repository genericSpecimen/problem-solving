/*
 * Get nth (0-indexed) row using O(n) additional space.
 * O(k^2) time complexity.
 */
vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex+1, 1);
    for (int i=0; i<rowIndex-1; i++) {
        //std::cout << "i: " << i << std::endl;
        for (int j=i+1; j>=1; j--) {
            //std::cout << "Add " << row[j] << "+" << row[j-1] << std::endl;
            row[j] = row[j] + row[j-1];
        }
    }
    return row;
}
