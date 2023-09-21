names = ['S', 'N', 'U']
choice = ""
maxRatio = 0

for name in names:
    snack = list(map(int, input().split())) 
    ratio = (snack[1] / snack[0]) if 10*snack[0] < 5000 else ((10*snack[1]) / (10*snack[0]-500))
    if ratio > maxRatio:
        choice = name
        maxRatio = ratio

print(choice)
