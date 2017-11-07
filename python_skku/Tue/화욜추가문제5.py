cnt=0
sum=0
sum2=0
while sum2<18:
    grade=input("성적을 입력하세요:")
    if grade=='A':
        g=4
    elif grade=='B':
        g=3
    elif grade=='C':
        g=2
    elif grade=='D':
        g=1
    else:
        print("성적이 잘못 입력되었습니다.")
        break
    hak=int(input("해당 과목의 학점을 입력하세요."))
    sum+=g*hak
    sum2+=hak
    cnt+=1
GPA=sum/18
result=round(GPA, 2)
print("학생의 GPA는 {0}입니다.".format(result))
        
