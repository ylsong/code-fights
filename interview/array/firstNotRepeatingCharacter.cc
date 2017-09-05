// AC solution: 
// Traverse only once through the whole array
// Can be improved to use 2 bit maps to save space, even through this is already
// const space. 
char firstNotRepeatingCharacter(std::string s) {
    int count[26];
    for (int i = 0; i < 26; i ++) {
        count[i] = -1;
    }
    int len = s.length();
    for (int i = 0; i < s.length(); i ++) {
        int idx = s[i] - 'a';
        if (count[idx] != -1) {
            count[idx] = 100000;
        } else {
            count[idx] = i;
        }
    }
    char ret = '_';
    int min_count = 100000;
    for (int i = 0; i < 26; i ++) {
        if (count[i] < min_count && count[i] != -1) {
            ret = 'a' + i;
            min_count = count[i];
        }
    }
    return ret;
}