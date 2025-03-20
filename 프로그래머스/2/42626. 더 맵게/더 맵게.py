import heapq

def solution(scoville, K):
    heapq.heapify(scoville)
    answer = 0
    while scoville:
        A = heapq.heappop(scoville)
        
        # 최솟값이 K보다 큰 경우 바로 return
        if A >= K:
            return answer
        
        # 최솟값이 K보다 작은데 섞을 음식이 더 없는 경우 바로 Fail
        elif A < K and not scoville:
            return - 1
            
        # 최솟값이 K보다 작아서 섞는 경우
        else:
            B = heapq.heappop(scoville)
            C = A + 2 * B
            heapq.heappush(scoville, C)
            answer += 1
        
    return -1