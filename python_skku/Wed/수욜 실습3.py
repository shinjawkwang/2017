n=int(input("숫자를 입력하세요:"))
sum=0
for i in range(1, n):
    if n%i==0:
        sum+=i
print(sum)
