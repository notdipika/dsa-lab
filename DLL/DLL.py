def create_node(data):
    return {'data': data, 'next': None, 'prev': None}

first = None
last = None

def insertAtBeg(element):
    global first, last
    new_node = create_node(element)

    if first is None:
        first = last = new_node

    else:
        new_node['next'] = first
        first['prev'] = new_node
        first = new_node

    print(f"{element} WAS INSERTED AT THE BEGINNING")

def insertAtEnd(element):
    global first, last
    new_node = create_node(element)

    if first is None:
        first = last = new_node

    else:
        last['next'] = new_node
        new_node['prev'] = last
        last = new_node

    print(f"{element} WAS INSERTED AT THE END")

def insertAtPosition(element, pos):
    global first, last

    if first is None or pos <= 0:
        print("INVALID INSERTION!")
        return
    
    if pos == 1:
        insertAtBeg(element)
        return

    new_node = create_node(element)
    temp = first
    i = 1

    while i < pos - 1 and temp is not None:
        temp = temp['next']
        i += 1

    if temp is None or temp == last:
        insertAtEnd(element)
        
    else:
        new_node['next'] = temp['next']
        new_node['prev'] = temp

        if temp['next'] is not None:
            temp['next']['prev'] = new_node

        temp['next'] = new_node
        print(f"{element} WAS INSERTED AT POSITION {pos}")

def deletionFromBeg():
    global first, last

    if first is None:
        print("EMPTY LIST!")

    elif first['next'] is None:
        print(f"{first['data']} IS GOING TO BE DELETED")
        first = last = None

    else:
        print(f"{first['data']} IS GOING TO BE DELETED")
        first = first['next']
        first['prev'] = None

def deletionFromEnd():
    global first, last

    if first is None:
        print("EMPTY LIST!")

    elif first['next'] is None:
        print(f"{first['data']} IS GOING TO BE DELETED")
        first = last = None

    else:
        print(f"{last['data']} IS GOING TO BE DELETED")
        last = last['prev']
        last['next'] = None

def deletionFromPosition(pos):

    global first, last

    if first is None or pos <= 0:
        print("INVALID DELETION!")
        return
    
    if pos == 1:
        deletionFromBeg()
        return
    
    temp = first
    i = 1
    
    while i < pos and temp is not None:
        temp = temp['next']
        i += 1

    if temp is None:
        print("INVALID POSITION!")
        return
    
    if temp == last:
        deletionFromEnd()

    else:
        print(f"{temp['data']} IS GOING TO BE DELETED")

        if temp['prev'] is not None:
            temp['prev']['next'] = temp['next']

        if temp['next'] is not None:
            temp['next']['prev'] = temp['prev']

def display():
    global first

    if first is None:
        print("EMPTY LIST!")
        return
    
    temp = first

    while temp is not None:
        print(f"{temp['data']} <-> ", end="")
        temp = temp['next']

    print("NULL")

def search(key):
    global first

    if first is None:
        print("EMPTY LIST!")
        return
    
    temp = first
    found = False

    while temp is not None:
        if temp['data'] == key:
            found = True
            break

        temp = temp['next']

    print("Element Found!" if found else "SEARCH UNSUCCESSFUL!")


def main():
    while True:
        print("\n--- MENU ---")
        print("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            print("Insert:\n1. At Beginning\n2. At End\n3. At Specific Position")
            subchoice = int(input("Enter your choice: "))
            element = int(input("Enter element to insert: "))

            if subchoice == 1:
                insertAtBeg(element)

            elif subchoice == 2:
                insertAtEnd(element)

            elif subchoice == 3:
                pos = int(input("Enter position: "))
                insertAtPosition(element, pos)

            else:
                print("Invalid insert choice!")

        elif choice == 2:
            print("Delete:\n1. From Beginning\n2. From End\n3. From Specific Position")
            subchoice = int(input("Enter your choice: "))

            if subchoice == 1:
                deletionFromBeg()

            elif subchoice == 2:
                deletionFromEnd()
                
            elif subchoice == 3:
                pos = int(input("Enter position: "))
                deletionFromPosition(pos)

            else:
                print("Invalid delete choice!")

        elif choice == 3:
            key = int(input("Enter element to search: "))
            search(key)

        elif choice == 4:
            display()

        elif choice == 5:
            print("Exiting program.")
            break

        else:
            print("Invalid choice. Try again.")


if __name__ == "__main__":
    main()
