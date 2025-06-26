moves = 0

def TOH(n, src, dest, temp):
    global moves
    if n == 1:
        print(f"Move disk 1 from rod {src} to rod {dest}")
        moves += 1
    else:
        TOH(n - 1, src, temp, dest)
        print(f"Move disk {n} from rod {src} to rod {dest}")
        moves += 1
        TOH(n - 1, temp, dest, src)

n = int(input("Enter the number of disks: "))
print("The sequence of moves are:")
TOH(n, 1, 3, 2)
print(f"Total moves: {moves}")
