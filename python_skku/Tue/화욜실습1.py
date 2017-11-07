a=int(input("삼각형의 한 변의 길이를 입력하세요:"))
b=int(input("삼각형의 한 변의 길이를 입력하세요:"))
c=int(input("삼각형의 한 변의 길이를 입력하세요:"))
if max(a, b, c)<a+b+c-max(a, b, c):
    print("Yes")
elif a<0 or b<0 or c<0:
    print("No")
else:
    print("No")
