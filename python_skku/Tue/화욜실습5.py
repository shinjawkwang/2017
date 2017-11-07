hour=int(input("몇 시인가요?"))
min=int(input("몇 분인가요?"))

if 9<hour<=16:
    age=int(input("나이를 입력하세요:"))
    if age<=12 or age>=65:
        print("25,000원입니다.")
    else:
        print("34,000원입니다.")
else:
    print("10,000원입니다.")
