n=int(input("정수입력:"))
count=0
for i in range(1, n+1):
    while i>0:
        if i%10==1:
            count+=1
        i=i//10
print(count)
