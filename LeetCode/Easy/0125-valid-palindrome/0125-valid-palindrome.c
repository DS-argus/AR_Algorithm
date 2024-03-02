void removeNonAlphanumeric(char *str) {
    int length = strlen(str); // 원본 문자열의 길이 계산
    int index = 0; // 새 문자열에 사용할 인덱스 초기화

    for (int i = 0; i < length; i++) {
        // 현재 문자가 알파벳이거나 숫자인지 검사
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= '0' && str[i] <= '9')) {
            str[index++] = str[i]; // 조건을 만족하는 경우 새 위치에 문자 복사
        }
    }

    str[index] = '\0'; // 새 문자열의 끝에 NULL 문자 추가
}

int isPalindrome_str(char *str, int start, int end) {
    while (start < end) {
        char startChar = str[start];
        char endChar = str[end];

        // 대문자를 소문자로 변환
        if (startChar >= 'A' && startChar <= 'Z') {
            startChar += 32;
        }
        if (endChar >= 'A' && endChar <= 'Z') {
            endChar += 32;
        }

        // 변환된 문자 비교
        if (startChar != endChar) {
            return 0; // 문자가 다르면 0 반환
        }

        start++; // 다음 문자로 이동
        end--;   // 이전 문자로 이동
    }
    return 1; // 모든 검사를 통과하면 1 반환
}


bool isPalindrome(char* s) {
    //cleasing
    removeNonAlphanumeric(s);
    
    return isPalindrome_str(s, 0, strlen(s)-1);
    
}