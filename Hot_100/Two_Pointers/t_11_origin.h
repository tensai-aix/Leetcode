// 双指针

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int area=0;
    while(right>left){
        int tmp_area;
        if(height[right]>height[left]){
            tmp_area = height[left] * (right-left);
            left++;
        }
        else if(height[right]<height[left]){
            tmp_area = height[right] * (right-left);
            right--;
        }
        else{
            tmp_area = height[left] * (right-left);
            left++;
        }
        if(tmp_area > area) area = tmp_area;
    }
    return area;
}
