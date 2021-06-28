# linear search algorithm implementation

# def linear_search(array=[10, 50, 20, 30, 40, 100], search_item=40)
def linear_search(array, search_item):
    #         [ 0   1   2   3   4    5]
    # array = [10, 50, 20, 30, 40, 100]
    found = False
    for index in range(len(array)):
        # index = 4
        # array_item = array[4]
        # 40 --> array[4] 
        array_item = array[index]
        # 40 = array[4]
        if array_item == search_item:
            # 40 == 40 
            found = True
            break

    if found == True:
        print('Search item found at index', index)
    else:
        print('Search item not found!')
        

linear_search(array=[10, 50, 20, 30, 40, 100], search_item=40)
