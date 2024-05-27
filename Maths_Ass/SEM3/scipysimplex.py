import numpy as np
from scipy.optimize import linprog

def get_linear_program():
    print("Linear Programming Solver using Simplex Method")
    obj_type = input("Enter the type of problem (maximize or minimize): ").strip()
    if obj_type not in ["maximize", "minimize"]:
        print("Invalid objective type. Please enter 'maximize' or 'minimize'.")
        return None
    
    num_variables = int(input("Enter the number of variables: "))
    num_constraints = int(input("Enter the number of constraints: "))
    
    print("Enter the coefficients of the objective function:")
    obj_coeff = list(map(float, input().split()))
    
    constraints = []
    for i in range(num_constraints):
        print(f"Enter coefficients of constraint {i + 1} (including the type, '>=', '<=', or '='):")
        constraint = input().split()
        constraints.append(constraint)
    
    return obj_type, num_variables, num_constraints, obj_coeff, constraints

def solve_linear_program(obj_type, num_variables, num_constraints, obj_coeff, constraints):
    A = np.zeros((num_constraints, num_variables))
    b = np.zeros(num_constraints)
    c = np.array(obj_coeff)
    bounds = [(0, None) for _ in range(num_variables)]
    
    for i in range(num_constraints):
        constraint = constraints[i]
        constraint_type = constraint[-2]
        constraint_rhs = float(constraint[-1])
        
        if constraint_type == '>=':
            A[i] = [-float(x) for x in constraint[:-2]]
            b[i] = -constraint_rhs
        elif constraint_type == '<=':
            A[i] = [float(x) for x in constraint[:-2]]
            b[i] = constraint_rhs
        elif constraint_type == '=':
            A[i] = [float(x) for x in constraint[:-2]]
            b[i] = constraint_rhs
    
    if obj_type == "maximize":
        c = -c  # Convert maximization to minimization
    
    result = linprog(c, A_ub=A, b_ub=b, bounds=bounds, method='highs')
    
    if result.success:
        print("\nOptimal Solution:")
        print("Objective Value:", result.fun)
        print("Optimal Variables:")
        for i in range(num_variables):
            print(f"x_{i+1} =", result.x[i])
    else:
        print("The problem is infeasible or unbounded.")

if __name__ == "__main__":
    lp_data = get_linear_program()
    if lp_data:
        obj_type, num_variables, num_constraints, obj_coeff, constraints = lp_data
        solve_linear_program(obj_type, num_variables, num_constraints, obj_coeff, constraints)
