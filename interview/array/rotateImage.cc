// AC Solution:
std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
    int n = a.size();
    int round = n/2;
    for (int i = 0; i < round; i ++) {
        for (int j = i; j < n-1-i; j++) {
            int tmp = a[j][n-1-i];
            a[j][n-1-i] = a[i][j];
            int tmp2 = a[n-1-i][n-1-j];
            a[n-1-i][n-1-j] = tmp;
            tmp = a[n-1-j][i];
            a[n-1-j][i] = tmp2;
            a[i][j] = tmp;
        }
    }
    return a;
}
