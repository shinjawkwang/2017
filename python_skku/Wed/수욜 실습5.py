width=int(input("가로 길이를 입력하세요:"))
height=int(input("세로 길이를 입력하세요:"))
for i in range(height):
    for j in range(width):
        print ("*", end="")
    print("")
