
#always giving 0 0

def initialize_tableau(tableau, m, n, problem_type):

    # Objective function coefficients
    print("Enter the coefficients of the objective function:")
    for j in range(n):
        coefficient = float(input(f"Coefficient for x{j + 1}: "))
        tableau[0][j] = -coefficient if problem_type == 2 else coefficient

    # Constraints (Ax <= b)
    print("Enter the constraints (Ax <= b):")
    for i in range(1, m + 1):
        print(f"Enter coefficients for constraint {i}:")
        for j in range(n):
            coefficient = float(input(f"Coefficient for x{j + 1}: "))
            tableau[i][j] = coefficient
        right_hand_side = float(input(f"Enter the right-hand side value (b) for constraint {i}: "))
        tableau[i][n] = right_hand_side

    # Slack variables
    for i in range(1, m + 1):
        tableau[i][n + i] = 1.0

def find_entering_variable(tableau, n):
    # Find the entering variable (most negative coefficient in the objective function row)
    entering_var = 0
    min_coeff = 0.0

    for j in range(n + 1):
        if tableau[0][j] < min_coeff:
            min_coeff = tableau[0][j]
            entering_var = j

    return entering_var

def find_leaving_variable(tableau, m, entering_var):
    # Find the leaving variable (minimum ratio test)
    leaving_var = -1
    min_ratio = -1.0

    for i in range(1, m + 1):
        if tableau[i][entering_var] > 0.0:
            ratio = tableau[i][-1] / tableau[i][entering_var]
            if leaving_var == -1 or ratio < min_ratio:
                leaving_var = i
                min_ratio = ratio

    return leaving_var

def pivot(tableau, m, n, entering_var, leaving_var):
    # Perform a pivot operation to update the tableau
    pivot_element = tableau[leaving_var][entering_var]

    # Divide the pivot row by the pivot element
    for j in range(n + 1):
        tableau[leaving_var][j] /= pivot_element

    # Update other rows
    for i in range(m + 1):
        if i != leaving_var:
            factor = tableau[i][entering_var]
            for j in range(n + 1):
                tableau[i][j] -= factor * tableau[leaving_var][j]

def is_optimal(tableau, n):
    # Check if the current solution is optimal (all coefficients in the objective function row are non-positive)
    return all(coefficient >= 0 for coefficient in tableau[0][:n + 1])

def is_unbounded(tableau, m, entering_var):
    # Check for unboundedness (no positive coefficients in the column of the entering variable)
    return all(tableau[i][entering_var] <= 0.0 for i in range(1, m + 1))

def print_tableau(tableau, m, n):
    # Print the current tableau
    print("Current Tableau:")
    for i in range(m + 1):
        for j in range(n + 1):
            print(f"{tableau[i][j]:8.2f}", end=" ")
        print()

def main():
    m = int(input("Enter the number of constraints: "))
    n = int(input("Enter the number of variables: "))

    problem_type = int(input("Select the problem type:\n1. Maximize\n2. Minimize\n"))

    tableau = [[0.0] * (n + m + 1) for _ in range(m + 1)]

    initialize_tableau(tableau, m, n, problem_type)
    print_tableau(tableau, m, n)

    while not is_optimal(tableau, n):
        entering_var = find_entering_variable(tableau, n)
        if entering_var == 0:
            print("The problem is unbounded.")
            return

        leaving_var = find_leaving_variable(tableau, m, entering_var)
        if leaving_var == -1:
            print("The problem is infeasible.")
            return

        print(f"Entering variable: x{entering_var}, Leaving variable: x{leaving_var}")
        pivot(tableau, m, n, entering_var, leaving_var)
        print_tableau(tableau, m, n)

    if problem_type == 2:
        print("Optimal solution found!")
        print(f"Objective value: {tableau[0][-1]:.2f}")
    else:
        print("Optimal solution found!")
        print(f"Objective value: {tableau[0][-1]:.2f}")

if __name__ == "__main__":
    main()
