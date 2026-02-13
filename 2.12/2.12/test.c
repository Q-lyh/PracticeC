#include <stdio.h>
#include <stdlib.h>


#define max_size 100005
int stack[max_size];
int top = -1;// 栈顶指针：核心状态变量，用于标记栈顶的位置
// 关键说明：
// 1. top = -1 表示「空栈」（没有任何元素）；
// 2. top = 0 表示栈中有1个元素（存在stack[0]）；
// 3. top = k 表示栈中有k+1个元素，栈顶元素是stack[k]；
// 4. 栈的元素个数 = top + 1（后续size操作会用到这个公式）

int main()
{
    int n;
    scanf_s("%d", &n);
    while (n--)
    {
        char op[10];
        scanf("%s", op);
        if (op[0] == 'p' && op[1] == 'u')
        {
            int x;
            scanf_s("%d", &x);
            top++;
            stack[top] = x;

        }
        else if (op[0] == 'p' && op[1] == 'o')
        {
            if (top == -1)
            {
                printf("Empty\n");
            }
            else {
                top--;
            }
        }
        else if (op[0] == 'q')
        {
            if (top == -1)
            {
                printf("Empty\n");
            }
            else {
                printf("%d\n", stack[top]);
            }
        }
        else if (op[0] == 's') {
            printf("%d\n", top + 1);
        }
    }
    return 0;
}