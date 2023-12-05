class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        merged_array = sorted(nums1 + nums2)
        if(len(merged_array)%2 == 0):
            return (merged_array[len(merged_array)//2] + merged_array[len(merged_array)//2-1]) / 2.0
        else:
            return merged_array[len(merged_array)//2]
        