// AC Solution:
bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
    // check length
    int l1 = crypt[0].length();
    int l2 = crypt[1].length();
    int l3 = crypt[2].length();
    if (l3 < l2 || l3 < l1) {
        return false;
    }
    int l_max = l1 > l2 ? l1 : l2;
    if (l3 > l_max + 1) {
        return false;
    }
    // Convert to map for const lookup
    std::unordered_map<char, int> check;
    for (std::vector<char> v : solution) {
        check[v[0]] = v[1] - '0';
    }
    // Check leading zeros
    for (std::string s : crypt) {
        if (check[s[0]] == 0 && s.length() != 1) {
            return false;
        }
    }
    // check algorithm
    int carry = 0;
    int l = l1 > l2 ? l2 : l1;
    for (int i = 0; i < l; i ++) {
        int x = check[crypt[0][l1-1-i]];
        int y = check[crypt[1][l2-1-i]];
        int sum = x + y + carry;
        carry = sum / 10;
        int digit = sum % 10;
        if (check[crypt[2][l3-1-i]] != digit) {
            return false;
        }
    }
    if (l1 > l) {
        for (int i = l; i < l1; i ++) {
            int x = check[crypt[0][l1-1-i]];
            int sum = x + carry;
            carry = sum / 10;
            int digit = sum % 10;
            if (check[crypt[2][l3-1-i]] != digit) {
                return false;
            }
        }
        if (carry == 1) {
            if (l3 == l1) {
                return false;
            }
            if (check[crypt[2][0]] != 1) {
                return false;
            }
        }
    } else if (l2 > l) {
        for (int i = l; i < l2; i ++) {
            int y = check[crypt[1][l2-1-i]];
            int sum = y + carry;
            carry = sum / 10;
            int digit = sum % 10;
            if (check[crypt[2][l3-1-i]] != digit) {
                return false;
            }
        }
        if (carry == 1) {
            if (l3 == l2) {
                return false;
            }
            if (check[crypt[2][0]] != 1) {
                return false;
            }
        }
    } else {
        if (carry == 1) {
            if (l3 == l2) {
                return false;
            }
            if (check[crypt[2][0]] != 1) {
                return false;
            }
        }
    }
    return true;
}
