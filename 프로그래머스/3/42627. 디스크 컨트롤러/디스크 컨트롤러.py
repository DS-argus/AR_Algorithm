from collections import defaultdict
import heapq
def solution(jobs):
    requestTimes = defaultdict(list)    
    for idx, (requestTime, requiredTime) in enumerate(jobs):
        requestTimes[requestTime].append((requiredTime, idx))

    working = 0
    elapsedTimes = []
    queue = []
    
    t = 0
    while t < 1000000:
        # 이번에 요청 들어온 작업있으면 (소요시간, 요청 시각, 작업 번호) 형태로 queue에 추가
        if t in requestTimes:
            for requiredTime, idx in requestTimes[t]:
                heapq.heappush(queue, (requiredTime, t, idx))
            
        # 작업이 가능한 시간이고 queue가 있으면
        if t >= working and queue:
            requiredTime, requestTime, _ = heapq.heappop(queue)
            working = t + requiredTime          
            elapsedTimes.append(working - requestTime)
            
            # 모든 job의 소요시간 구했으면 종료
            if len(elapsedTimes) == len(jobs):
                return int(sum(elapsedTimes)/len(elapsedTimes))
        
        t += 1
                
        
        
        