/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int isAnagram(char *s, char *t) {
    int s_len = strlen(s);
    int t_len = strlen(t);
    if (s_len != t_len) {
        return 0;
    }
    int s_count[26] = {0};
    int t_count[26] = {0};
    for (int i = 0; i < s_len; i++) {
        s_count[s[i] - 'a']++;
        t_count[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (s_count[i] != t_count[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to clone a string
char *cloneString(const char *str) {
    char *clone = (char *)malloc(strlen(str) + 1);
    strcpy(clone, str);
    return clone;
}


// Function to append a string to an array of strings
void appendStringToArray(char ***array, int *size, const char *str) {
    (*size)++;
    *array = (char **)realloc(*array, (*size) * sizeof(char *));
    (*array)[(*size) - 1] = cloneString(str);
}


char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    char ***result = (char ***)malloc(sizeof(char **)*strsSize); // Allocate memory for the maximum possible number of groups
    int *resultSizes = (int *)malloc(sizeof(int)*strsSize); // Allocate memory for the sizes of each group
    int resultCount = 0;

    for (int i = 0; i < strsSize; i++) {
        int found = 0;
        for (int j = 0; j < resultCount; j++) {
            if (isAnagram(strs[i], result[j][0])) {
                appendStringToArray(&result[j], &resultSizes[j], strs[i]);
                found = 1;
                break;
            }
        }
        if (!found) {
            // Allocate memory for a new group
            result[resultCount] = NULL; // Initialize the new group
            resultSizes[resultCount] = 0; // Initialize the size of the new group
            appendStringToArray(&result[resultCount], &resultSizes[resultCount], strs[i]);
            resultCount++;
        }
    }

    *returnSize = resultCount;
    *returnColumnSizes = resultSizes;
    return result;
}
