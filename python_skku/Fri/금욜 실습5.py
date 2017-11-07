import random
options=[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
answer=['a', 'b', 'c']
for i in range(3):
    answer[i]=random.choice(options)
print(answer)
#컴퓨터 답 생성

def check():
    for i in range(3):
        STRIKE=0
        BALL=0
        OUT=0
        if answer[i]==user_choice[i]:
            STRIKE+=1
        for j in range(2, -1, -1):
            if answer[i]==user_choice[j] and i!=j:
                BALL+=1
            elif answer[i]!=user_choice[j]:
                OUT=1
    if OUT==0:
        print("{0}스트라이크, {0}볼 입니다.".format(STRIKE, BALL))
    else:
        print("OUT!")
    if answer==user_choice:
        return 1
#카운트를 체크하는 함수
while check()!=1:
    user_choice=['A', 'B', 'C']
    for i in range(num):
        user_choice[i]=int(input("숫자를 입력하세요:"))
    #사용자 답안 입력(9회 해야하는 거 지정 안함)
    check()    



baseball_game(9)
if baseball_game(9)==0:
    print("You lose")



                
            
