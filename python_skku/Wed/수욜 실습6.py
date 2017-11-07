count=0
height=float(input("높이를 입력하세요(m):"))
while True:
    count+=1
    height=height/2
    if height<0.00001:
        break
print("공이 튀긴 횟수는 {0}입니다.".format(count))
