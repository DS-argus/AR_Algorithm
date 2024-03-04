/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
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
        int flagg = 0; // Assume path is not found initially
        for (int i = 0; i < *resultCount; i++) { // Use *resultCount to get the current size of result
            int isSamePath = 1; // Assume current path matches the path being checked
            if (resultSizes[i] == pathSize) { // Check only if sizes are equal
                for (int j = 0; j < resultSizes[i]; j++) {
                    if (result[i][j] != path[j]) {
                        isSamePath = 0; // Paths differ
                        break;
                    }
                }
            } else {
                isSamePath = 0; // Different sizes, paths cannot be the same
            }
            if (isSamePath) {
                flagg = 1; // Found a matching path
                break;
            }
        }

        if (!flagg) { // If path was not found, add it
            result[*resultCount] = (int *)malloc(sizeof(int) * numsSize);
            resultSizes[*resultCount] = numsSize;
            for (int i = 0; i < numsSize; i++) {
                result[*resultCount][i] = path[i];
            }
            (*resultCount)++;
        }
        // No need for return here unless you are explicitly controlling flow to exit the function
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
