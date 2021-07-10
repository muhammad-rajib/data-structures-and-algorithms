# Bubble Sort Implementation
# n = 5
# for i in range(0, n):
#     print('Loop 1: i-%d\n-----------' % i)
#     for j in range(0, n-i-1):
#         print('j-', j)


def bubble_sort(data_list):
    n = len(data_list)
    for i in range(0, n): # n=5 (0, 5) --> 0, 1, 2, 3, 4
        for j in range(0, n-i-1):
            if data_list[j] > data_list[j+1]:
                # Swap
                temp = data_list[j]
                data_list[j] = data_list[j+1]
                data_list[j+1] = temp


if __name__ == '__main__':
    data_list = [8, 15, 3, 5, 2, 20, 10, 1]
    bubble_sort(data_list)
    print('Bubble Sorted List:', data_list)