from collections import defaultdict
def solution(tickets):
    numTickets = len(tickets)
    
    EDGES = defaultdict(list)
    for a, b in tickets:
        EDGES[a].append(b)

    ans = []
    
    def travel(airport, itinerary):
        if not tickets:
            ans.append(itinerary)
            return
        
        for nextAirport in EDGES[airport]:
            if [airport, nextAirport] in tickets:
                tickets.remove([airport, nextAirport])
                travel(nextAirport, itinerary + [nextAirport])
                tickets.append([airport, nextAirport])
    
    travel("ICN", ["ICN"])

    return min(ans)