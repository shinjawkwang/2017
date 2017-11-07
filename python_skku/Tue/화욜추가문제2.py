a=float(input("사각형 1번의 왼쪽 아래 x좌표를 입력하세요:"))
b=float(input("사각형 1번의 왼쪽 아래 y좌표를 입력하세요:"))
c=float(input("사각형 1번의 오른쪽 위 x좌표를 입력하세요:"))
d=float(input("사각형 1번의 오른쪽 위 y좌표를 입력하세요:"))

A=float(input("사각형 2번의 왼쪽 아래 x좌표를 입력하세요:"))
B=float(input("사각형 2번의 왼쪽 아래 y좌표를 입력하세요:"))
C=float(input("사각형 2번의 오른쪽 위 x좌표를 입력하세요:"))
D=float(input("사각형 2번의 오른쪽 위 y좌표를 입력하세요:"))

if (c<A and d<B) or (C<a and D<b):
    area=0
    print(area)
else:
    area=(min(c, C)-max(a, A))*(min(d, D)-max(b, B))
    print(area)
