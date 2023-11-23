#include <stdio.h>

// 交换两个数的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 递归函数，对数组中的元素进行全排列
void permute(int* nums, int start, int end) {
    if (start == end) { // 当只剩下一个元素时，输出排列结果
        for (int i = 0; i <= end; i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            // 将第i个元素与第start个元素交换位置
            swap(&nums[start], &nums[i]);

            // 对剩下的元素进行全排列
            permute(nums, start + 1, end);

            // 还原数组，以便进行下一次排列
            swap(&nums[start], &nums[i]);
        }
    }
}

int main() {
    int n;
    printf("请输入数字的个数：");
    scanf("%d", &n);

    int nums[n];
    printf("请输入%d个数字：", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("全排列结果为：\n");
    permute(nums, 0, n - 1);

    return 0;
}
