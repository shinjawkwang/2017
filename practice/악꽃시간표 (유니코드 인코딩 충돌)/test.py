import datetime, time

d = datetime.date.today()
print(d.month)
if(d.month % 2 == 1):
    print("홀수달입니다.\n")
else:
    print("짝수달입니다.\n")
