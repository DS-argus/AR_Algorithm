from collections import defaultdict
import heapq

def solution(genres, plays):
    songByGenre = defaultdict(list)
    playTimesByGenre = defaultdict(int)
    
    for idx, (genre, play) in enumerate(zip(genres, plays)):
        songByGenre[genre].append((-play, idx))
        playTimesByGenre[genre] += play
        
    playTimesByGenre = sorted([(-totalPlayTimes, genre) for genre, totalPlayTimes in playTimesByGenre.items()])

    ans = []
    while playTimesByGenre:
        playTimes, genre = heapq.heappop(playTimesByGenre)
        songs = sorted(songByGenre[genre])
        count = 0
        while count < 2 and songs:
            _, idx = heapq.heappop(songs)
            ans.append(idx)
            count += 1
    
    return ans