
//面试题 17.04. 消失的数字
 //数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
//示例 1：
//输入：[3, 0, 1]
//输出：2


int missingNumber(int* nums, int numsSize) {
        int x = 0;
        for (size_t i = 0; i < numsSize; ++i) {
            x ^= nums[i];
        }
        for (size_t i = 0; i <= numsSize; ++i) {
            x ^= i;
        }
    return x;
}
