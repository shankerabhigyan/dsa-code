arr = [12, 9, 3, 4, 5, 6, 7, 8, 2, 10, 11, 1]

for i in range(8):
    for j in range(i + 1, 9):
        if arr[j] % arr[i] == 0 and arr[j + 1] % arr[i + 1] == 0:
            print(f"i = {i}, j = {j}")
            break
    else:
        continue
    break
else:
    print("Such an i, j pair does not exist.")
