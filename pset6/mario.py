n=input("\nEnter an integer: ")
n= int(n)
print(f"Height: {n}")
for i in range(0,n):
    for j in range(0,n-i-1):
        print(' ', end='')
    for k in range(0,i+1):
        print('#',end='')
    print(' ',end='')
    for l in range(0,i+1):
        print('#',end='')
    for m in range(0,n-i-1):
        print(' ',end='')
    print('')
