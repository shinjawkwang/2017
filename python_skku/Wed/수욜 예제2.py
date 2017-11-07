n=int(input("숫자를 입력하세요:"))
sum=0
while n>0:
    digit=n%10
    n=n//10
    sum+=digit

print(sum)
