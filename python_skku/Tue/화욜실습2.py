price_onepiece=50000
price_sweat=30000
num_onepiece=int(input("원피스를 몇 벌 구매하셨나요?"))
num_sweat=int(input("스웨터를 몇 벌 구매하셨나요?"))
buy_onepiece=price_onepiece*num_onepiece
buy_sweat=price_sweat*num_sweat
sum=buy_onepiece+buy_sweat

if sum<100000:
    print("구매 가격은 {0}원 입니다.".format(sum*0.95))
elif sum<200000:
    print("구매 가격은 {0}원 입니다.".format(sum*0.9))
else:
    print("구매 가격은 {0}원 입니다.".format(sum*0.8))
