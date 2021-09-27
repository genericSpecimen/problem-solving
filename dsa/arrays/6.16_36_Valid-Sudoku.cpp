// https://leetcode.com/problems/valid-sudoku/


/*
 * Time complexity: O(n^2), where n = order of n*n matrix
 * hasValidRows: O(n) rows, O(n) time to check each row, total = O(n^2)
 * hasValidCols: O(n) cols, O(n) time to check each col, total = O(n^2)
 * hasValidSubGrids: O(n) subgrids.
 *      Each subgrid: O(√n) rows, O(√n) cols. Time to validate one subgrid = O(n)
 *      Time to validate O(n) subgrids = O(n^2)
 */
class Solution {
public:
    bool isValidPart(std::vector<std::vector<char>> &board,
                    std::pair<int,int> start, std::pair<int,int> end) {
        /*
         * check whether the part of the board
         * from start to end (inclusive) is valid,
         * i.e. contains no duplicates.
         */
        std::deque<bool> seen(board.size()+1, false);
        
        for (int row=start.first; row<=end.first; row++) {
            for (int col=start.second; col<=end.second; col++) {
                if (board[row][col] != '.') {
                    if (seen[board[row][col]-'0']) {
                        return false;
                    }
                    seen[board[row][col]-'0'] = true;
                }
            }
        }
        
        return true;
    }
    
    bool hasValidRows(std::vector<std::vector<char>> &board) {
        // check all rows
        for (int row=0; row<board.size(); row++) {
            if (!isValidPart(board, {row, 0}, {row, board.size()-1})) {
                std::cout << "Invalid row: " << row << std::endl;
                return false;
            }
        }

        return true;
    }
    
    bool hasValidCols(std::vector<std::vector<char>> &board) {
        // check all cols
        for (int col=0; col<board.size(); col++) {
            if (!isValidPart(board, {0, col}, {board.size()-1, col})) {
                std::cout << "Invalid col: " << col << std::endl;
                return false;
            }
        }
        
        return true;
    }
    
    bool hasValidSubGrids(std::vector<std::vector<char>> &board) {
        // check all subgrids
        for (int row=0; row<board.size(); row+=3) {
            for (int col=0; col<board.size(); col+=3) {
                if (!isValidPart(board, {row, col}, {row+3-1, col+3-1})) {
                    std::cout << "Invalid subgrid: {"
                              << row << "," << col << "}, {"
                              << row+3-1 << "," << col+3-1 << "}"
                              << std::endl;
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        return (
            hasValidRows(board) &&
            hasValidCols(board) &&
            hasValidSubGrids(board)
            );
    }
};
