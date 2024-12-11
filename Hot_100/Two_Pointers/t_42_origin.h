// can't pass,because at the right side,only pick the peek is not enough

int trap(int* height, int heightSize) {
    int index = 0;
    int area = 0;
    while (index < heightSize - 2) {
        int origin_height = height[index];
        if (origin_height == 0) {
            index++;
            continue;
        }
        int forward = index + 1;
        int tmp_area = 0;
        while (true) {
            if (height[forward] < origin_height) {
                if (forward == heightSize - 1) {
                    int re_forward = index + 1;
                    int re_max_height = 0;
                    while (true) {
                        if (re_forward == heightSize - 1) {
                            re_max_height = height[re_forward];
                            for (int i = index + 1; i < re_forward; i++) {
                                area += re_max_height - height[i];
                            }
                            index = re_forward;
                            break;
                        }
                        if (height[re_forward] < height[re_forward + 1]) {
                            re_forward++;
                            re_max_height = height[re_forward];
                        } else if (height[re_forward] >= height[re_forward + 1]) {
                            for (int i = index + 1; i < re_forward; i++) {
                                area += re_max_height - height[i];
                            }
                            index = re_forward;
                            break;
                        }
                    }
                    break;
                }
                tmp_area += origin_height - height[forward];
                forward++;
            } else {
                area += tmp_area;
                index = forward;
                break;
            }
        }
    }
    return area;
}
