# Binary search algorithm implementation
#   0   1   2   3   4   5   6   7
# [10, 20, 30, 40, 50, 60, 70, 80]

def binary_search(number_list, search_value):

    low = 0
    high = len(number_list)-1

    while low <= high:

        mid = (low + high) // 2

        if number_list[mid] == search_value:
            print('Great!!...Value found at index ', mid)
            return
        if number_list[mid] < search_value: # Search in right side
            low = mid+1
        if number_list[mid] > search_value: # Search in left side
            high = mid-1

    print('OOPS!!..Value not found in number list')

number_list = [10, 20, 30, 40, 50, 60, 70, 80]
binary_search(number_list, search_value=80)