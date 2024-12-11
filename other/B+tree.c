#include "B+tree.h"

int nums[100] = {5,8,10,15,16,17,18,19,20,21,22,6,9,7,22,23,24};

int main(){
    /** 
    init(2,1);
    for(int i = 1;i <= 8;i++){
        add(i);
    }
    show();
    add(0);
    show();
    del(3);
    del(6);
    del(8);
    show();*/
    /**
    init(4,2);
    for(int i = 0;i < 14;i++){
        add(nums[i]);
    }
    show();
    del(22);
    del(15);
    del(7);
    show();
    find(17,true);
    find(8,true);
    find(7,true);*/
    init(4,2);
    for(int i=0;i<100;i++){
        add(i);
    }
    show();
    for(int i=0;i<80;i++){
        del(i);
    }
    show();
}