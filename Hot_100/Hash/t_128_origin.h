// fault:exceed time

typedef struct S_Array{
    int begin;
    int end;
}s_Array;
typedef struct STATUS{
    int sta;
    int index;
}Status;
Status check(int num,s_Array* s_array,int s_array_length){
    Status status;
    status.sta = -1;
    for(int i=0;i<s_array_length;i++){
        if(num >= s_array[i].begin && num <= s_array[i].end){
            status.sta = 0;
            return status;
        }
    }
    for(int i=0;i<s_array_length;i++){
        if(num == s_array[i].begin - 1){
            status.sta = 1;
            status.index = i;
            break;
        }
        else if(num == s_array[i].end + 1) {
            status.sta = 2;
            status.index = i;
            break;
        }
    }
    return status;
}
void init_s_array(s_Array* s_array,int index,int value){
    s_array[index].begin = value;
    s_array[index].end = value;
}
int longestConsecutive(int* nums, int numsSize) {
    if(!numsSize) return 0;
    s_Array s_array[numsSize];
    int s_array_length = 0;
    for(int i=0;i<numsSize;i++){
        int to_deal_number = nums[i];
        if(!s_array_length){
            s_array_length++;
            init_s_array(s_array,s_array_length-1,to_deal_number);
        }
        else{
            Status status = check(to_deal_number,s_array,s_array_length);
            switch(status.sta){
                case -1 :   // -1表示不存在于可能序列中
                    s_array_length++;
                    init_s_array(s_array,s_array_length-1,to_deal_number);
                    break;
                case 1 :s_array[status.index].begin--;   // 其它表示不在已有序列中但在可能序列中,头插
                    break;
                case 2 :s_array[status.index].end++;  // 尾插
                    break;
            }
        }
    }
    for(int i=0;i<s_array_length;i++){
        for(int j=i+1;j<s_array_length;j++){
            if(s_array[i].begin == s_array[j].end + 1){
                s_array[j].end = s_array[i].end;
                break;
            }
            if(s_array[i].end == s_array[j].begin - 1){
                s_array[j].begin = s_array[i].begin;
                break;
            }
        }
    }
    int return_value = 0;
    for(int i=0;i<s_array_length;i++){
        int tmp_length = s_array[i].end - s_array[i].begin + 1;
        if(tmp_length > return_value) return_value = tmp_length;
    }
    return return_value;
}
 