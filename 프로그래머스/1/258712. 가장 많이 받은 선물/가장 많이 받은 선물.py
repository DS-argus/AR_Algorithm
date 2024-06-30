def create_index(friends, gifts):
    index_dict = dict()
    
    for i in range(len(friends)):
        index_dict[friends[i]] = [0] * len(friends)
        
    for gift in gifts:
        fr, to = gift.split()[0], gift.split()[1]
        index_dict[fr][friends.index(to)] += 1
        index_dict[to][friends.index(fr)] -= 1
    
    return index_dict

    
def solution(friends, gifts):
    idx = create_index(friends, gifts)
    predict = [0] * len(friends)
    
    for i in range(len(friends)):
        for j in range(i+1, len(friends)):
            
            if idx[friends[i]][j] != 0 and idx[friends[i]][j] != idx[friends[j]][i]:
                if idx[friends[i]][j] > idx[friends[j]][i]:
                    predict[i] += 1
                elif idx[friends[i]][j] < idx[friends[j]][i]:
                    predict[j] += 1
                    
            else:
                if sum(idx[friends[i]]) > sum(idx[friends[j]]):
                    predict[i] += 1
                elif sum(idx[friends[i]]) < sum(idx[friends[j]]):
                    predict[j] += 1
                    
    answer = max(predict) 
    return answer