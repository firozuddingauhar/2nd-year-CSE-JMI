
# array = []

# print("Enter elements of the initial array (type 'done' when finished):")
# while True:
#     input_str = input()
#     if input_str == 'done':
#         break
#     array.append(int(input_str))

# while True:
#     print("\nEnter choice:")
#     print("1) Insert element at beginning")
#     print("2) Insert element at end")
#     print("3) Insert element at given position")
#     print("4) Delete element at beginning")
#     print("5) Delete element at end")
#     print("6) Delete element at given position")
#     print("7) Exit")

#     choice = int(input())

#     if choice == 1:
#         element = int(input("Enter element you want to insert: "))
#         array.insert(0, element)
#         print(array)
#     elif choice == 2:
#         element = int(input("Enter element you want to insert: "))
#         array.append(element)
#         print(array)
#     elif choice == 3:
#         element = int(input("Enter element you want to insert: "))
#         position = int(input("Enter position where you want to insert the element: "))
#         array.insert(position, element)
#         print(array)
#     elif choice == 4:
#         print("Deleting element at beginning")
#         array.pop(0)
#         print(array)
#     elif choice == 5:
#         print("Deleting element at end")
#         array.pop()
#         print(array)
#     elif choice == 6:
#         position = int(input("Enter position you want to delete: "))
#         print("Deleting element at position")
#         array.pop(position)
#         print(array)
#     elif choice == 7:
#         break



# # def insert(array, size, element, position):
# #     for i in range(size, position, -1):
# #         array[i] = array[i - 1]
# #     array[position] = element

# # def delete_(array, size, position):
# #     for i in range(position, size - 1):
# #         array[i] = array[i + 1]

# # size = int(input("Enter size of array: "))
# # array = []

# # print("Enter elements of array:")
# # for i in range(size):
# #     array[i] = int(input())

# # while True:
# #     print("\nEnter choice:")
# #     print("1) Insert element at beginning")
# #     print("2) Insert element at end")
# #     print("3) Insert element at given position")
# #     print("4) Delete element at beginning")
# #     print("5) Delete element at end")
# #     print("6) Delete element at given position")
# #     print("7) Exit")
    
# #     choice = int(input())
    
# #     if choice == 1:
# #         element = int(input("Enter element you want to insert: "))
# #         insert(array, size, element, 0)
# #         size += 1
# #         print(array)
# #     elif choice == 2:
# #         element = int(input("Enter element you want to insert: "))
# #         insert(array, size, element, size)
# #         size += 1
# #         print(array)
# #     elif choice == 3:
# #         element = int(input("Enter element you want to insert: "))
# #         position = int(input("Enter position where you want to insert the element: "))
# #         insert(array, size, element, position)
# #         size += 1
# #         print(array)
# #     elif choice == 4:
# #         print("Deleting element at beginning")
# #         delete_(array, size, 0)
# #         size -= 1
# #         print(array)
# #     elif choice == 5:
# #         print("Deleting element at end")
# #         delete_(array, size, size - 1)
# #         size -= 1
# #         print(array)
# #     elif choice == 6:
# #         position = int(input("Enter position you want to delete: "))
# #         print("Deleting element at position")
# #         delete_(array, size, position)
# #         size -= 1
# #         print(array)
# #     elif choice == 7:
# #         break


# #budhil aage betha h usko leke nahi gaye humne bola nahi jaa rahe taki usse na lejana pade
# #nahi hue select


def parse_complex_number(complex_str):
    real, imaginary = complex_str.split('+')
    real = float(real.strip())
    imaginary = float(imaginary.replace('i', '').strip())
    return complex(real, imaginary)

def perform_operations(complex_str):
    complex_numbers = complex_str.split(',')
    
    # Parsing complex numbers from input string
    num1 = parse_complex_number(complex_numbers[0])
    num2 = parse_complex_number(complex_numbers[1])
    
    # Perform operations
    addition = num1 + num2
    subtraction = num1 - num2
    multiplication = num1 * num2
    division = num1 / num2 if num2 != 0 else "Division by zero is not allowed"
    
    # Displaying results
    print(f"Addition: {addition:.3f}")
    print(f"Subtraction: {subtraction:.3f}")
    print(f"Multiplication: {multiplication:.3f}")
    print(f"Division: {division:.3f}")

# Taking input from the user
complex_input = input("Enter two complex numbers (e.g., '1.5 + 2.3i, 1.55 + 2.0i'): ")
perform_operations(complex_input)
