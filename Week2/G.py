n = int(input())
L = [0] * 150
L[0] = 2
L[1] = 1
for i in range(2, 150):
    L[i] = L[i - 1] + L[i - 2]
print(L[n])