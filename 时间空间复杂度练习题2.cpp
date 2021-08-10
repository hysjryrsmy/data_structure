
//260：只出现一次的数字 III

//给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。
//找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
//进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
//示例 1：
//输入：nums = [1, 2, 1, 3, 2, 5]
//输出：[3, 5]
//解释：[5, 3] 也是有效的答案。



class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int n : nums)
            ret ^= n;
        int div = 1;
        while ((div & ret) == 0)
            div <<= 1;
        int a = 0, b = 0;
        for (int n : nums)
            if (div & n)
                a ^= n;
            else
                b ^= n;
        return vector<int>{a, b};
    }
};


/*
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
//假设出现1次的两个数位x1和x2
int* singleNumber(int* nums, int numsSize, int* returnSize) {
	int ret = 0;
	for (int i = 0; i < numsSize; i++) {
		ret ^= nums[i];
		//数组中所有数异或，那么出线两次都异或没了 
        //ret最后的值 == x1 x2
	}

	//找出ret的第m位为1的位
	int m = 0;
	while (m < 32)
	{
		if (ret & (1 << m))
			break;
		else
			++m;
	}

	//分离
	int x1 = 0, x2 = 0;
	for (int i = 0; i < numsSize; ++i) {
		if (nums[i] & (1<<m)) {
			x1 ^= nums[i];
		}
		else {
			x2 ^= nums[i];
		}
	}

	int* retArr = (int*)malloc(sizeof(int) * 2);
	retArr[0] = x1;
	retArr[1] = x2;

	*returnSize = 2;

	return retArr;
}
*/

