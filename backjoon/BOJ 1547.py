M = int(input())
a = 1
for i in range(M):
    X,Y = map(int,input().split())
    if X==Y:
        continue
    elif X==a:
        a=Y
    elif Y==a:
        a=X
print(a)
