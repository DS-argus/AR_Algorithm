bool isPalindrome(int x) {
    if (x<0) return false;

    int arr[100];
    int i = 0;
    while (x>=1){
        arr[i] = x%10;
        i++;
        x = x/10;
    }

    for (int k = 0; k < i; k++){
        if (arr[k] != arr[i-1-k]) return false;
    }
    return true;

    // if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    // int rev = 0;
    // while (rev < x) {
    //     rev = rev * 10 + x % 10;
    //     printf("%d\n", rev);
    //     x /= 10;
    // }

    // printf("%d\n", rev);    
    // return x == rev || x == rev / 10;
}