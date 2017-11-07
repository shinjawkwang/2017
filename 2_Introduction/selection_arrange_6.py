n = int(input("enter the size of array : "))
array = []
for i in range(n):
    array.append(int(input("enter number : ")))
def selectionSort(array):
    for i in range(n):
        min = array[i]
        for j in range(i, n):
            if min>=array[j]:
                min = array[j]
                min_place = j
        temp = array[i]
        array[i] = min
        array[min_place] = temp
selectionSort(array)
print(array)
