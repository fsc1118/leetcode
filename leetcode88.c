#include<stdlib.h>
#include<string.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int* result = malloc(sizeof(int) * (nums1Size + nums2Size));
    int pointer1 = 0;
    int pointer2 = 0;
    int index = 0;
    while (1){
        if (pointer1 == nums1Size && pointer2 == nums2Size)
            break;
        else if (pointer1 == nums1Size){
            result[index++] = nums2[pointer2++];
        } else if (pointer2 == nums2Size){
            result[index++] = nums1[pointer1++];
        } else{
            result[index++] = (nums1[pointer1] < nums2[pointer2]) ? nums1[pointer1++] : nums2[pointer2++];
        }    
    }
    memcpy(nums1, result, (m + n) * sizeof(int));
}