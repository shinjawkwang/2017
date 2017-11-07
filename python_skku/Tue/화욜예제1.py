year=int(input("연도를 입력하세요"))
if year%4==0 and year%100!=0 or year%400==0:
    print("{0}년은 윤년입니다.".format(year))
else:
    print("{0}년은 윤년이 아닙니다.".format(year))
