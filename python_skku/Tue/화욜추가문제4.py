first=input("첫 번째 사람은 무엇을 내었습니까?")
second=input("두 번째 사람은 무엇을 내었습니까?")
if (first=='가위' and second=='가위') or (first=='바위' and second=='바위') or (first=='보' and second=='보'):
    print("비겼습니다.")
elif (first=='가위' and second=='보') or (first=='바위' and second=='가위') or (first=='보' and second=='바위'):
    print("첫 번째 사람이 이겼습니다.")
elif (first=='가위' and second=='바위') or (first=='바위' and second=='보') or (first=='보' and second=='가위'):
    print("두 번째 사람이 이겼습니다.")
else:
    print("잘못 입력했습니다.")
