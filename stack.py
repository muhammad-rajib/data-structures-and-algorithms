# Data Structure: Stack Implementation

def create_stack():
    stack = []
    return stack

def is_stack_empty(stack):
    if len(stack) == 0:
        return True
    return False

def insert(stack, insert_value):
    stack.append(insert_value)

def delete(stack):
    if is_stack_empty(stack):
        return 'stack is empty'

    return stack.pop()


stack = create_stack()
insert(stack, 1)
insert(stack, 2)
insert(stack, 3)
insert(stack, 4)
print('After Insert: ', stack)
delete(stack)
print('After delete: ', stack)