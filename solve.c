#include <stdlib.h>
#include "parse.h"

int solve(struct pointers ptrs){
    int temp;
    for(int i=0; i<49; i++){
        switch (ptrs.ops[i]) {
            case multiply:
                temp = ptrs.nums[i]*ptrs.nums[i+1];
                ptrs.ops[i]=null;
                for(int j=i;ptrs.ops[j]==null; j--){
                    ptrs.nums[j]=temp;
                }
                for(int j=i;ptrs.ops[j]==null; j++){
                    ptrs.nums[j+1]=temp;
                }
                break;
            case divide:
                temp = ptrs.nums[i]/ptrs.nums[i+1];
                ptrs.ops[i]=null;
                for(int j=i;ptrs.ops[j]==null; j--){
                    ptrs.nums[j]=temp;
                }
                for(int j=i;ptrs.ops[j]==null; j++){
                    ptrs.nums[j+1]=temp;
                }
                break;
            default:
                break;
        }
    }
    for(int i=0; i<49; i++){
        switch (ptrs.ops[i]) {
            case add:
                temp = ptrs.nums[i]+ptrs.nums[i+1];
                ptrs.ops[i]=null;
                for(int j=i;ptrs.ops[j]==null; j--){
                    ptrs.nums[j]=temp;
                }
                for(int j=i;ptrs.ops[j]==null; j++){
                    ptrs.nums[j+1]=temp;
                }
                break;
            case sub:
                temp = ptrs.nums[i]-ptrs.nums[i+1];
                ptrs.ops[i]=null;
                for(int j=i;ptrs.ops[j]==null; j--){
                    ptrs.nums[j]=temp;
                }
                for(int j=i;ptrs.ops[j]==null; j++){
                    ptrs.nums[j+1]=temp;
                }
                break;
            default:
                break;
        }
    }

    return ptrs.nums[1];
}
