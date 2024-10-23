#define _CRT_SECURE_NO_WARNINGS 1
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    // 防止k超过数组长度
    k = k % numsSize;

    // 反转整个数组
    reverse(nums, 0, numsSize - 1);

    // 反转前k个元素
    reverse(nums, 0, k - 1);

    // 反转剩下的部分
    reverse(nums, k, numsSize - 1);
}
