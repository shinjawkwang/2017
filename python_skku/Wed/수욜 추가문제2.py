n=int(input("밑변의 길이를 입력하시오:"))
for i in range(1, n+1):
    for j in range(n-i):
        print(end=" ")
    for k in range(i):
        print("*", end=" ")
    print("")
