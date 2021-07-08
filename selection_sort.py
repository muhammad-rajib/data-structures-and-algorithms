# Selection Sort Algorithm Implementation

def selection_sort(data_list):
    length = len(data_list)

    for i in range(length - 1):
        min_index = i
        for j in range(i+1, length):
            if data_list[j] < data_list[min_index]:
                min_index = j

        if min_index != i:
            temp = data_list[i]
            data_list[i] = data_list[min_index]
            data_list[min_index] = temp
        

if __name__ == '__main__':
    # data_list = 0   1   2  3   4   5
    data_list = [80, 50, 40, 5, 10, 15]
    selection_sort(data_list)
    print('Sorted List: ', data_list)