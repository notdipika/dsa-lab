MAX = 100

class Stack:
    def __init__(self):
        self.data = []
    
    def is_empty(self):
        return len(self.data) == 0

    def is_full(self):
        return len(self.data) == MAX

    def push(self, value):
        if self.is_full():
            print("Stack Overflow! Cannot push", value)
        else:
            self.data.append(value)
            print(f"{value} pushed to stack.")

    def pop(self):
        if self.is_empty():
            print("Stack Underflow! Cannot pop.")
        else:
            value = self.data.pop()
            print(f"Popped element: {value}")

    def display(self):
        if self.is_empty():
            print("Stack is empty.")
        else:
            print("Stack elements (top to bottom):", end=" ")
            for item in reversed(self.data):
                print(item, end=" ")
            print()


def main():
    stack = Stack()

    while True:
        print("1. Push (Insert element)")
        print("2. Pop (Remove top element)")
        print("3. Display (Show all elements)")
        print("4. Check if stack is empty")
        print("5. Check if stack is full")
        print("6. Exit")
        choice = input("Enter your choice (1–6): ")

        if choice == '1':
            value = int(input("Enter value to push: "))
            stack.push(value)
        elif choice == '2':
            stack.pop()
        elif choice == '3':
            stack.display()
        elif choice == '4':
            if stack.is_empty():
                print("Stack is EMPTY.")
            else:
                print("Stack is NOT empty.")
        elif choice == '5':
            if stack.is_full():
                print("Stack is FULL.")
            else:
                print("Stack is NOT full.")
        elif choice == '6':
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Try again.")

if __name__ == "__main__":
    main()
