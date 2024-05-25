import time
import numpy as np
import matrix

def create_matrix(size):
    return np.ones((size, size), dtype=int)

def main(size):
    a = create_matrix(size)
    b = create_matrix(size)

    start_time = time.time()
    result = matrix.multiply(a, b, size)
    end_time = time.time()

    elapsed_time = end_time - start_time
    print(f"Matrix multiplication took: {elapsed_time:.9f} seconds.")

if __name__ == "__main__":
    import sys
    if len(sys.argv) < 2:
        print("Please provide the matrix size as an argument.")
        sys.exit(1)

    try:
        size = int(sys.argv[1])
    except ValueError:
        print("Invalid matrix size. Please provide an integer value.")
        sys.exit(1)

    main(size)

