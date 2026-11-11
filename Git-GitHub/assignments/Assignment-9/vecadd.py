"""
Vector Dot Product with Parallel Computation and Input Validation
Created for Assignment 9 – Git Branching (Resolved Merge State)
"""

from multiprocessing import Pool

def multiply_pair(pair):
    """Computes element-wise product for a pair (x, y)."""
    return pair[0] * pair[1]

def main():
    try:
        n = int(input("Enter vector size: "))
        if n <= 0:
            print("Error: Vector size must be a positive integer.")
            return
    except ValueError:
        print("Error: Invalid vector size. Please enter an integer.")
        return

    print("Enter elements of first vector:")
    a = list(map(float, input().split()))
    print("Enter elements of second vector:")
    b = list(map(float, input().split()))

    if len(a) != n or len(b) != n:
        print(f"Error: Both vectors must have {n} elements.")
        return

    pairs = list(zip(a, b))
    with Pool() as pool:
        products = pool.map(multiply_pair, pairs)

    dot_product = sum(products)
    print("Dot product (parallel):", dot_product)

if __name__ == "__main__":
    main()

