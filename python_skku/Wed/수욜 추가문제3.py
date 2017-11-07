n=int(input("마름모의 길이를 입력하시오:"))
for i in range(1, n+1):
    for j in range(n-i):
        print(end=" ")
    for k in range(i):
        print("*", end=" ")
    print("")
for l in range(1, n):
    for m in range(l):
        print(end=" ")
    for b in range(n-l):
        print("*", end=" ")
    print("")
