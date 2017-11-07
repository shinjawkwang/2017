weight=float(input("몸무게를 입력하세요(kg):"))
height=float(input("키를 입력하세요(m):"))
BMI=weight/height**2

if BMI<18.5:
    print("저체중입니다.")
elif BMI<23:
    print("정상입니다.")
elif BMI<25:
    print("과체중입니다.")
elif BMI<30:
    print("경도비만입니다.")
elif BMI<35:
    print("중등도비만입니다.")
else:
    print("고도비만입니다!")
