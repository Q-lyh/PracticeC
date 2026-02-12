#include <stdio.h>
#include <stdlib.h>

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;

    int* arr = NULL;
    int len = 0;
    int cap = 0;

    while (q--) {
        int op;
        if (scanf("%d", &op) != 1) break;

        if (op == 1) {
            // 1 x：在末尾添加整数x
            long long x;
            if (scanf("%lld", &x) != 1) break;
            if (len >= cap) {
                cap = (cap == 0) ? 4 : cap * 2;
                arr = realloc(arr, cap * sizeof(int));
                if (!arr) exit(1);
            }
            arr[len++] = (int)x;
        }
        else if (op == 2) {
            // 2：删除末尾元素
            if (len > 0) len--;
        }
        else if (op == 3) {
            // 3 i：输出下标i的元素
            int i;
            if (scanf("%d", &i) != 1) break;
            if (i >= 0 && i < len) {
                printf("%d\n", arr[i]);
            }
        }
        else if (op == 4) {
            // 4 i x：在下标i和i+1之间插入x
            int i;
            long long x;
            if (scanf("%d %lld", &i, &x) != 2) break;
            if (i < 0 || i > len) continue; // 非法位置
            if (len >= cap) {
                cap = (cap == 0) ? 4 : cap * 2;
                arr = realloc(arr, cap * sizeof(int));
                if (!arr) exit(1);
            }
            for (int j = len; j > i + 1; j--) {
                arr[j] = arr[j - 1];
            }
            arr[i + 1] = (int)x;
            len++;
        }
        else if (op == 5) {
            // 5：升序排序
            for (int i = 0; i < len - 1; i++) {
                for (int j = 0; j < len - 1 - i; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int t = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = t;
                    }
                }
            }
        }
        else if (op == 6) {
            // 6：降序排序
            for (int i = 0; i < len - 1; i++) {
                for (int j = 0; j < len - 1 - i; j++) {
                    if (arr[j] < arr[j + 1]) {
                        int t = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = t;
                    }
                }
            }
        }
        else if (op == 7) {
            // 7：输出当前长度
            printf("%d\n", len);
        }
        else if (op == 8) {
            // 8：输出整个序列
            for (int i = 0; i < len; i++) {
                if (i > 0) printf(" ");
                printf("%d", arr[i]);
            }
            printf("\n");
        }
    }

    free(arr);
    return 0;
}