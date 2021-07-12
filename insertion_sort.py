# Insertion Sort Implementation
#       index = [ 0  1  2  3   4]
# number_list = [5, 2, 3, 4, 1]

def insertion_sort(number_list):
    n = len(number_list)

    for i in range(1, n):
        item = number_list[i]
        j = i - 1 
        while j>=0 and number_list[j] > item:
            number_list[j+1] = number_list[j]
            j = j - 1

        number_list[j+1] = item

number_list = [10, 3, 7, 5, 12]
insertion_sort(number_list)
print('After Insertion Sort:', number_list)