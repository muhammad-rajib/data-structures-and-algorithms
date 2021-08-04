# Quick Sort Implementation using Python

def partition(L, low, high):
    sub_list = L[low:high+1]
    pivot = L[high]
    i = low - 1
    for j in range(low, high):
        if L[j] <= pivot:
            i += 1
            L[i], L[j] = L[j], L[i]
    
    L[i+1], L[high] = L[high], L[i+1]
    return i+1

def quick_sort(L, low, high):
    if low >= high:
        return
    pivot_index = partition(L, low, high)
    quick_sort(L, low, pivot_index-1)  # left sub-list
    quick_sort(L, pivot_index+1, high)  # right sub-list


if __name__ == '__main__':
    number_list = [1, 5, 6, 3, 8, 4, 7, 2]
    print('Unsorted List:', number_list)
    quick_sort(number_list, 0, len(number_list)-1)
    print('Sorted List:', number_list)