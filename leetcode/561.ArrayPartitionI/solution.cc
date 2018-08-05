class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        quickSort(nums, 0, nums.size()-1);
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
    
    void quickSort(vector<int> &nums, int low, int high) {
		if (low < high){
			int mid = nums[low];
			int high_inst = high;
			int low_inst = low;

			while (low_inst < high_inst) {
				while (low_inst < high_inst && nums[high_inst] >= mid) {
					high_inst --;
				}
				nums[low_inst] = nums[high_inst];
				while (low_inst < high_inst && nums[low_inst] < mid) {
					low_inst ++;
				}
				nums[high_inst] = nums[low_inst];
			}
			nums[low_inst] = mid;
			quickSort(nums, low, low_inst - 1);
			quickSort(nums, low_inst + 1, high);
		}
	}
};
