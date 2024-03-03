// Function to find the longest palindrome length
int longestPalindrome(char** words, int wordsSize) {

    int counter[26][26] = {0};
    int ans = 0;

    for (int i = 0; i < wordsSize; i++){
        int a = words[i][0] - 'a';
        int b = words[i][1] - 'a';

        if (counter[b][a]){
            ans += 4;
            counter[b][a]--;
        }else{
            counter[a][b]++;
        }
    }

    for (int i = 0; i < 26; i++){
        if (counter[i][i]){
            ans += 2;
            break;
        }
    }

    return ans;
}
