import numpy as np


print("\n**** Simplex Algorithm ****\n")

# Get the number of constraints and decision variables from the user
num_constraints = int(input("Enter the number of constraints: "))
num_variables = int(input("Enter the number of decision variables: "))

# Initialize arrays to store the input data
A = np.zeros((num_constraints, num_variables))
b = np.zeros(num_constraints)
c = np.zeros(num_variables)

# Input the coefficients of the constraints
print("Enter the coefficients of the constraints (one row at a time):")
for i in range(num_constraints):
    constraint_coefficients = list(map(float, input().split()))
    A[i, :] = constraint_coefficients

# Input the amount of resources
print("Enter the what constraint equates to: ")
b = list(map(float, input().split()))

# Input the coefficients of the objective function
print("Enter the coefficients of the objective function:")
c = list(map(float, input().split()))
print(A,b,c)
# Initialize other variables
cb = np.array([c[-1]])
B = np.array([[0], [0]])
cb = np.vstack((cb, c[-2]))
xb = np.transpose([b])
table = np.hstack((B, cb))
table = np.hstack((table, xb))
table = np.hstack((table, A))
table = np.array(table, dtype='float')

MIN = 0

print("\nTable at itr = 0")
print("B \tCB \tXB \t", end='')
for i in range(num_variables):
    print(f"x{i + 1}\t", end='')
print()
for row in table:
    for el in row:
        print(el, end='\t')
    print()

print("\nSimplex Working....")

reached = 0
itr = 1
unbounded = 0
alternate = 0

while reached == 0:

    print("Iteration: ", itr)
    print("B \tCB \tXB \t", end='')
    for i in range(num_variables):
        print(f"x{i + 1}\t", end='')
    print()
    for row in table:
        for el in row:
            print(el, end='\t')
        print()

    rel_prof = [c[i] - np.sum(table[:, 1] * table[:, 3 + i]) for i in range(num_variables)]

    print("rel profit: ", end=" ")
    for profit in rel_prof:
        print(profit, end=", ")
    print()

    i = 0
    b_var = table[:, 0]
    while i < num_variables:
        j = 0
        present = 0
        while j < len(b_var):
            if int(b_var[j]) == i:
                present = 1
                break
            j += 1
        if present == 0:
            if rel_prof[i] == 0:
                alternate = 1
                print("Case of Alternate found")
        i += 1

    flag = 0
    for profit in rel_prof:
        if profit > 0:
            flag = 1
            break
    if flag == 0:
        print("All profits are <= 0, optimality reached")
        reached = 1
        break

    k = rel_prof.index(max(rel_prof))
    min = 99999
    i = 0
    r = -1

    while i < len(table):
        if (table[:, 2][i] > 0 and table[:, 3 + k][i] > 0):
            val = table[:, 2][i] / table[:, 3 + k][i]
            if val < min:
                min = val
                r = i
        i += 1

    if r == -1:
        unbounded = 1
        print("Case of Unbounded")
        break

    print("pivot element index:", np.array([r, 3 + k]))
    pivot = table[r][3 + k]
    print("pivot element: ", pivot)

    table[r, 2:len(table[0])] = table[r, 2:len(table[0])] / pivot
    i = 0
    while i < len(table):
        if i != r:
            table[i, 2:len(table[0])] = table[i, 2:len(table[0])] - table[i][3 + k] * table[r, 2:len(table[0])]
        i += 1

    table[r][0] = k
    table[r][1] = c[k]

    itr += 1

print("\n***************************************************************")
if unbounded == 1:
    print("UNBOUNDED LPP")
    exit()
if alternate == 1:
    print("ALTERNATE Solution")

print("optimal table:")
print("B \tCB \tXB \t", end='')
for i in range(num_variables):
    print(f"x{i + 1}\t", end='')
print()
for row in table:
    for el in row:
        print(el, end='\t')
    print()

print("value of Z at optimality: ", end=" ")
basis = []
i = 0
sum = 0
while i < len(table):
    sum += c[int(table[i][0])]*table[i][2]
    temp = "x" + str(int(table[i][0]) + 1)
    basis.append(temp)
    i += 1

if MIN == 1:
    print(-sum)
else:
    print(sum)
print("Final Basis: ", end=" ")
print(basis)

print("Simplex Finished...")
