/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **result = (int **)malloc(sizeof(int *)*factorial(numsSize));
    int *resultSizes = (int *)malloc(sizeof(int)*factorial(numsSize));
    int resultCount = 0;
    int *path = (int *)malloc(sizeof(int)*numsSize);
    int *visited = (int *)malloc(sizeof(int)*numsSize);
    for (int i = 0; i < numsSize; i++) {
        visited[i] = 0;
    }
    permuteHelper(nums, numsSize, 0, path, visited, result, &resultCount, resultSizes);
    *returnSize = resultCount;
    *returnColumnSizes = resultSizes;
    free(visited);
    free(path);
    return result;
}

void permuteHelper(int *nums, int numsSize, int pathSize, int *path, int *visited, int **result, int *resultCount, int *resultSizes) {
    if (pathSize == numsSize) {
        result[*resultCount] = (int *)malloc(sizeof(int)*numsSize);
        resultSizes[*resultCount] = numsSize;
        for (int i = 0; i < numsSize; i++) {
            result[*resultCount][i] = path[i];
        }
        (*resultCount)++;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            path[pathSize] = nums[i];
            permuteHelper(nums, numsSize, pathSize + 1, path, visited, result, resultCount, resultSizes);
            visited[i] = 0;
        }
    }
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}