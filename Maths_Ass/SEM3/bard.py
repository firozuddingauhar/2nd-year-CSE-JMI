import numpy as np

def simplex(objective_coefficients, constraint_coefficients, constraint_types, problem_type):
    # Convert constraint types to standard form
    for i in range(len(constraint_types)):
        if constraint_types[i] == ">=":
            constraint_coefficients[i] *= -1
            constraint_types[i] = "<="

    # Add slack variables to the constraint matrix and objective function
    slack_variables = [0 for _ in range(len(constraint_coefficients))]
    constraint_matrix = np.concatenate((constraint_coefficients, np.identity(len(constraint_coefficients))), axis=1)
    objective_function = np.append(objective_coefficients, slack_variables)

    # Initialize the tableau
    tableau = np.vstack((objective_function, constraint_matrix))

    # Check for unboundedness
    while True:
        entering_variable_index = None
        for i in range(len(tableau[0]) - 1):
            if tableau[0, i] < 0:
                entering_variable_index = i
                break

        if entering_variable_index is None:
            if problem_type == "maximize":
                print("The problem is unbounded.")
            else:
                print("The problem has a minimum solution.")
            return

        # Check for infeasibility
        ratios = tableau[1:, -1] / tableau[1:, entering_variable_index]
        for i in range(len(ratios)):
            if ratios[i] < 0:
                print("The problem is infeasible.")
                return

        pivot_row_index = np.argmin(ratios)

        # Perform pivoting
        pivot_element = tableau[pivot_row_index, entering_variable_index]
        tableau[pivot_row_index] /= pivot_element
        for i in range(len(tableau)):
            if i != pivot_row_index:
                ratio = tableau[i, entering_variable_index] / tableau[pivot_row_index, entering_variable_index]
                tableau[i] -= ratio * tableau[pivot_row_index]

    # Check for optimal solution
    if problem_type == "maximize":
        if tableau[0, -1] < 0:
            print("No optimal solution exists.")
            return
    else:
        if tableau[0, -1] > 0:
            print("No optimal solution exists.")
            return

    # Extract optimal solution
    optimal_solution = [0 for _ in range(len(objective_coefficients))]
    for i in range(len(constraint_coefficients)):
        for j in range(len(constraint_coefficients)):
            if constraint_matrix[i, j] == 1:
                optimal_solution[i] = tableau[1, j]
    for i in range(len(slack_variables)):
        for j in range(len(constraint_coefficients) + len(slack_variables)):
            if constraint_matrix[i, j] == 1:
                optimal_solution[i + len(constraint_coefficients)] = tableau[1, j]

    # Print optimal solution
    print("Optimal solution:")
    for i in range(len(optimal_solution)):
        print(f"x{i + 1}: {optimal_solution[i]}")

    print("Optimal value:")
    print(tableau[0, -1])


if __name__ == "__main__":
    problem_type = input("Enter the type of problem (maximize/minimize): ")
    objective_coefficients = list(map(float, input("Enter objective function coefficients: ").split()))
    num_constraints = int(input("Enter the number of constraints: "))
    constraint_coefficients = []
    constraint_types = []
    for _ in range(num_constraints):
        constraint_coefficients.append(list(map(float, input("Enter constraint coefficients: ").split())))
        constraint_types.append(input("Enter constraint type (<=/>=): "))

    simplex(objective_coefficients, constraint_coefficients, constraint_types, problem_type)
