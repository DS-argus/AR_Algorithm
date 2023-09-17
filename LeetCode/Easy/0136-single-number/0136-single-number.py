class Solution:
    def singleNumber(self, nums: List[int]) -> int:

      # nums의 최솟값 저장
      minVal, bits = min(nums), 0

      # num에서 nums의 최솟값을 빼줘서 (음수가 있는 경우 처리하기 위함)
      # 2**(해당값)과 bits의 XOR 연산을 통해 몇번 나왔는지 체크
      ## ex) nums = [3, 3, 2, -5, -5]
      ## bin(bits) = 0b100000000 XOR 0b100000000 XOR 0b10000000 XOR 0b1 XOR 0b1 = 0b10000000
      ## bits = 2**7  
      for num in nums:
          bits ^= (1<<(num-minVal))

      
      # bits = 2**7, bin(bits)= 0b10000000 일 때 2가 나와야 하니
      # len(bin(bits)) - 3 -5 =  10 - 3 - 5 = 2
      return len(bin(bits))-3+minVal
