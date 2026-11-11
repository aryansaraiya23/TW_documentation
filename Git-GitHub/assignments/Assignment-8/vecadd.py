"""
Vector Dot Product Calculation
Created for Assignment 8 – Git Basics
"""

def main():
    try:
        n = int(input("Enter vector size: "))
    except ValueError:
        print("Error: Vector size must be an integer.")
        return

    print("Enter elements of first vector:")
    a = list(map(float, input().split()))
    print("Enter elements of second vector:")
    b = list(map(float, input().split()))

    if len(a) != n or len(b) != n:
        print(f"Error: Both vectors must have {n} elements.")
    else:
        dot_product = sum(x * y for x, y in zip(a, b))
        print("Dot product:", dot_product)

if __name__ == "__main__":
    main()

