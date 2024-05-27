import numpy as np
from scipy.optimize import linprog


#always giving 0 0

def main():
    # Type of the problem
    mode = input("Enter 'max' or 'min': ")

    # Objective function coefficients
    obj_coeffs = list(map(float, input("Enter the coefficients of the objective function (separated by spaces): ").split()))

    # Constraints matrix
    A = []
    for _ in range(int(input("Enter the number of constraints: "))):
        row = list(map(float, input("Enter the coefficients of the constraint (separated by spaces): ").split()))
        A.append(row)

    # Constraints type (<=, >=) and bounds
    b = np.array(list(map(float, input("Enter the right-hand side values of the constraints (separated by spaces): ").split())))
    constraint_type = list(map(str, input("Enter the type of each constraint (<= or >=, separated by spaces): ").split()))

    if constraint_type[0] == "<=":
        constraints = ({'type': 'ineq', 'fun': lambda x: A[i][j] * x[j] - b[i]} for i, j in enumerate(range(len(obj_coeffs))))
    elif constraint_type[0] == ">=":
        constraints = ({'type': 'ineq', 'fun': lambda x: b[i] - A[i][j] * x[j]} for i, j in enumerate(range(len(obj_coeffs))))

    # Bounds for the variables
    x_bounds = [(0, None)] * len(obj_coeffs)

    # Run the simplex method
    res = linprog(obj_coeffs, A_ub=A, b_ub=b, bounds=x_bounds, method='highs')

    if res.success:
        print(f"Optimal solution found: {res.x}")
        print(f"Optimal value: {res.fun}")
    elif res.status == 2:
        print("Unbounded solution.")
    elif res.status == 3:
        print("Infeasible solution.")
    else:
        print("Error:", res.message)

if __name__ == "__main__":
    main()