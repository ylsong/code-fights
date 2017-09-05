// First attempt:
// This is a O(n) time and O(1) space solution. The problem is it cannot
// reserve ordering while swapping, so we cannot find the duplicate with
// smallest index.

int firstDuplicate(std::vector<int> a) {
    for (int i = 0; i < a.size(); i ++) {
        if (a[i] == i + 1) {
            continue;
        }
        int dest = a[i] - 1;
        int tmp = a[dest];
        if (tmp == a[i]) {
            return tmp;
        }
        a[dest] = a[i];
        a[i] = tmp;
        i --;
    }
    return -1;
}

// AC solution:
int firstDuplicate(std::vector<int> a) {
    for (int i = 0; i < a.size(); i ++) {
        int dest = a[i] > 0 ? a[i] - 1 : -a[i] - 1;
        if (a[dest] < 0) {
            return a[i] > 0 ? a[i] : -a[i];
        }
        a[dest] = - a[dest];
    }
    return -1;
}