money=int(input("소득액을 입력하세요:"))
if money>12000000:
    tax1=12000000*0.06
    if money>46000000:
        tax2=34000000*0.15
        if money>88000000:
            tax3=42000000*0.24
            if money>150000000:
                tax4=62000000*0.35
                tax5=(money-150000000)*0.38
                sum=tax1+tax2+tax3+tax4+tax5
            else:
                tax4=(money-88000000)*0.35
                sum=tax1+tax2+tax3+tax4
        else:
            tax3=(money-46000000)*0.24
            wum=tax+tax2+tax3
    else:
        tax2=(money-12000000)*0.15
        sum=tax1+tax2
else:
    tax1=money*0.06
    sum=tax1
print(int(sum))
