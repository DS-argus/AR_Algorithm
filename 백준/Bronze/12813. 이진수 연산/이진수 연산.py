import sys

input = sys.stdin.readline

A = input().strip()
B = input().strip()

bit_len = max(len(A), len(B))  # 기준 비트 수 (예: 10)
intA = int(A, 2)
intB = int(B, 2)

# & | ^ 연산
and_result = intA & intB
or_result  = intA | intB
xor_result = intA ^ intB

# ~ 연산 (2의 보수 형태로 보기 위해 마스크 씌움)
notA = ~intA & ((1 << bit_len) - 1)
notB = ~intB & ((1 << bit_len) - 1)

# 이진수 출력 (자릿수 고정)
print(f'{and_result:0{bit_len}b}')
print(f'{or_result:0{bit_len}b}')
print(f'{xor_result:0{bit_len}b}')
print(f'{notA:0{bit_len}b}')
print(f'{notB:0{bit_len}b}')