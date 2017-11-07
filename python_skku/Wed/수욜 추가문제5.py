a=int(input("첫 번째 숫자를 입력하시오:"))
b=int(input("두 번째 숫자를 입력하시오:"))
count=0
for i in range(a, b+1):
    if i==2:
        count+=1
    for j in range(2, i):
        if i%j==0:
            break
        if j==i-1:
            count+=1
            
print("{0}부터 {1}까지의 소수의 개수는 {2}입니다.".format(a, b, count))
