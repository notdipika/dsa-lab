def create_node(data):
    return {'data': data, 'next': None}

first = None
last = None

def InsertAtBeg(element):

    global first, last
    new_node = create_node(element)

    if first is None:
        first = last = new_node

    else:
        new_node['next'] = first
        first = new_node

    print(f"{element} WAS INSERTED AT THE BEGINNING")

def InsertAtEnd(element):
    global first, last
    new_node = create_node(element)

    if first is None:
        first = last = new_node

    else:
        last['next'] = new_node
        last = new_node

    print(f"{element} WAS INSERTED AT THE END")

def InsertAtPosition(element, pos):
    global first

    if first is None or pos <= 0:
        print("INVALID INSERTION!")

    elif pos == 1:
        InsertAtBeg(element)

    else:
        new_node = create_node(element)
        temp = first
        i = 1

        while i < pos - 1 and temp is not None:
            temp = temp['next']
            i += 1

        if temp is None:
            InsertAtEnd(element)

        else:
            new_node['next'] = temp['next']
            temp['next'] = new_node
            print(f"{element} WAS INSERTED AT POSITION {pos}")

def DeleteFromBeg():
    global first, last

    if first is None:
        print("EMPTY LIST!")

    elif first['next'] is None:
        print(f"{first['data']} IS GOING TO BE DELETED")
        first = last = None

    else:
        print(f"{first['data']} IS GOING TO BE DELETED")
        first = first['next']

def DeleteFromEnd():
    global first, last
    if first is None:
        print("EMPTY LIST!")

    elif first['next'] is None:
        print(f"{first['data']} IS GOING TO BE DELETED")
        first = last = None

    else:
        temp = first
        while temp['next'] != last:
            temp = temp['next']

        print(f"{last['data']} IS GOING TO BE DELETED")
        last = temp
        last['next'] = None

def DeleteFromPosition(pos):
    global first, last
    if first is None or pos <= 0:
        print("INVALID DELETION!")

    elif first['next'] is None or pos == 1:
        DeleteFromBeg()

    else:
        temp = first

        for i in range(1, pos - 1):
            if temp is None or temp['next'] is None:
                print("INVALID POSITION!")
                return
            
            temp = temp['next']

        if temp['next'] == last:
            DeleteFromEnd()

        elif temp['next'] is not None:
            print(f"{temp['next']['data']} IS GOING TO BE DELETED")
            temp['next'] = temp['next']['next']

        else:
            print("INVALID POSITION!")

def display():
    global first

    if first is None:
        print("EMPTY LIST!")
        
    else:
        temp = first
        while temp is not None:
            print(f"{temp['data']} -> ", end="")
            temp = temp['next']
        print("NULL")

def search(key):
    global first

    if first is None:
        print("EMPTY LIST!")

    else:
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
                InsertAtBeg(element)

            elif subchoice == 2:
                InsertAtEnd(element)

            elif subchoice == 3:
                pos = int(input("Enter position: "))
                InsertAtPosition(element, pos)

            else:
                print("Invalid insert choice!")

        elif choice == 2:
            print("Delete:\n1. From Beginning\n2. From End\n3. From Specific Position")
            subchoice = int(input("Enter your choice: "))

            if subchoice == 1:
                DeleteFromBeg()

            elif subchoice == 2:
                DeleteFromEnd()

            elif subchoice == 3:
                pos = int(input("Enter position: "))
                DeleteFromPosition(pos)
                
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
