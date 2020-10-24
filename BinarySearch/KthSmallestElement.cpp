class Solution {
public:
    int partition(vector<int>& nums, int st, int end) {
        int pivot = nums[end];

        int i = st - 1, j = st;
        while (j < end) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
            j++;
        }
        i++;
        swap(nums[end], nums[i]);
        return i;
    }

    int quickSort(vector<int>& nums, int st, int end, int k) {
        if (st >= end) {
            return nums[k];
        }
        int pivotIdx = partition(nums, st, end);
        if (pivotIdx == k) {
            return nums[pivotIdx];
        }
        if (pivotIdx > k) {
            return quickSort(nums, st, pivotIdx - 1, k); //left
        }
        else {
            return quickSort(nums, pivotIdx + 1, end, k); //right
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }
        return quickSort(nums, 0, nums.size() - 1, k - 1);
    }
};







