import heapq
def solution(operations):
    minheap, maxheap = [], []
    
    for operation in operations:
        if operation[0] == "I":
            target = int(operation.split()[1])
            heapq.heappush(minheap, target)
            heapq.heappush(maxheap, -target)
        elif operation == "D 1":
            if maxheap:
                minheap.remove(-heapq.heappop(maxheap))
        else:
            if minheap:
                maxheap.remove(-heapq.heappop(minheap))
    
    
    if minheap:
        return [-heapq.heappop(maxheap), heapq.heappop(minheap), ]
        pass
    else:
        return [0, 0]
    