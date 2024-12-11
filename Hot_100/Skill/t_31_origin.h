void swap(int* nums,int i,int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
void all_down(int* nums,int begin,int end){
    for(int i=begin;i<(begin+end+1)/2;i++){
        swap(nums,i,begin+end-i);
    }
}
void nextPermutation(int* nums, int numsSize) {
    int turning_point_index = -1;
    for(int j=numsSize-1;j>=1;j--){
        if(nums[j] > nums[j-1]){
            turning_point_index = j-1;
            break;
        }
    }
    if(turning_point_index < 0){
        all_down(nums,0,numsSize-1);
    }
    else{
        int turning_number = nums[turning_point_index];
        int to_change_index = turning_point_index + 1;
        for(int j=numsSize-1;j>to_change_index;j--){
            if(nums[j] > turning_number){
                to_change_index = j;
                break;
            }
        }
        swap(nums,turning_point_index,to_change_index);
        all_down(nums,turning_point_index+1,numsSize-1);
    }
}