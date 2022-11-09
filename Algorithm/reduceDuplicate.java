public class reduceDuplicate {
        public int removeDuplicates(int[] nums) {
            int n = nums.length;
            if(n==0){
                return 0;
            }
            int fast = 1;
            int slow = 1;
            while(fast<n){
                //利用快慢双指针 扫描和覆盖位置
                if(nums[fast]!=nums[fast-1]){
                    nums[slow] = nums[fast];
                    ++slow;
                }
                ++fast;
            }
            return slow;
        }
}
