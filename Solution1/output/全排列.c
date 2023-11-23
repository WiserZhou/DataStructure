#include <stdio.h>

// ������������ֵ
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// �ݹ麯�����������е�Ԫ�ؽ���ȫ����
void permute(int* nums, int start, int end) {
    if (start == end) { // ��ֻʣ��һ��Ԫ��ʱ��������н��
        for (int i = 0; i <= end; i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            // ����i��Ԫ�����start��Ԫ�ؽ���λ��
            swap(&nums[start], &nums[i]);

            // ��ʣ�µ�Ԫ�ؽ���ȫ����
            permute(nums, start + 1, end);

            // ��ԭ���飬�Ա������һ������
            swap(&nums[start], &nums[i]);
        }
    }
}

int main() {
    int n;
    printf("���������ֵĸ�����");
    scanf("%d", &n);

    int nums[n];
    printf("������%d�����֣�", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("ȫ���н��Ϊ��\n");
    permute(nums, 0, n - 1);

    return 0;
}
