// AC Solution:
bool sudoku2(std::vector<std::vector<char>> grid) {
    // Check row
    for (int i = 0; i < 9; i ++) {
        std::vector<bool> seen(9, false);
        for (int j = 0; j < 9; j ++) {
            char c = grid[i][j];
            if (c == '.') {
                continue;
            }
            if (seen[c-'1']) {
                return false;
            }
            seen[c-'1'] = true;
        }
    }
    // Check column
    for (int i = 0; i < 9; i ++) {
        std::vector<bool> seen(9, false);
        for (int j = 0; j < 9; j ++) {
            char c = grid[j][i];
            if (c == '.') {
                continue;
            }
            if (seen[c-'1']) {
                return false;
            }
            seen[c-'1'] = true;
        }
    }
    // Check 3 * 3
    for (int i = 0; i < 9; i ++) {
        std::vector<bool> seen(9, false);
        for (int j = 0; j < 3; j ++) {
            for (int k = 0; k < 3; k ++) {
                char c = grid[j + i / 3 * 3][k + i % 3 * 3];
                if (c == '.') {
                    continue;
                }
                if (seen[c-'1']) {
                    return false;
                }
                seen[c-'1'] = true;
            }
        }
    }
    return true;
}
