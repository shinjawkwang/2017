import random
options=[1, 2, 3] #1=left 2=center 3=right
com=random.choice(options)

choice=input("어디로 차실건가요?:")
if choice==com:
    print("goal!!")
else:
    print("fail")
