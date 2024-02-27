#include <stdio.h>
#include<stdlib.h>

int smallest_pos_int(int arr[], int size){

    int pos_size = 0;
    for(int i=0; i<size; i++){
        if(arr[i] > 0){
            pos_size++;
        }
    }

    // printf("%d", pos_size);

    int* pos = (int *)malloc(pos_size*sizeof(int));
    int j=0;
    for(int i=0; i<size; i++){
        if(arr[i] > 0){
            pos[j] = arr[i];
            j++;
        }
    }

    int ans = pos_size+1;
    // printf("%d", ans);
    for(int i = 1; i <= pos_size; i++){
        int flag = 0;
        for (int j = 0; j < pos_size; j++){
            if(pos[j] == i){
                flag = 1;
            }
        }

        if (flag == 0){
            ans = i;
            break;
        }
    }
    free(pos);
    return ans;
}

int main(void){

    int arr1[] = {4, 7, -1, 1, 2};
    int arr2[] = {100, 101, 102};
    int arr3[] = {3, 2, 1, 0, -1};
    int arr4[] = {5, -1, 2, 4, 1, 3};

    printf("%d\n", smallest_pos_int(arr1, 5));
    printf("%d\n", smallest_pos_int(arr2, 3));
    printf("%d\n", smallest_pos_int(arr3, 5));
    printf("%d\n", smallest_pos_int(arr4, 6));

}