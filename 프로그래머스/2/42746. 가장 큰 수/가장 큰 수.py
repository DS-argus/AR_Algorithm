def solution(numbers):
    # 모든 숫자를 문자열로 변환
    numbers = list(map(str, numbers))
    
    # 정렬 기준: 두 숫자를 이어붙였을 때 더 큰 순서대로 정렬
    numbers.sort(key=lambda x: x*3, reverse=True)  # x*3을 하면 '3', '30' 비교 가능
    
    # 결과 조합 후 반환
    return str(int("".join(numbers)))  # '0000' 같은 경우 '0'으로 처리