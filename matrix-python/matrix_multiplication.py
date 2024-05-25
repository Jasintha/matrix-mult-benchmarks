import numpy as np
import sys
import time

def main():
    if len(sys.argv) < 2:
        print("Please provide the matrix size as an argument.")
        return

    try:
        size = int(sys.argv[1])
    except ValueError:
        print("Invalid matrix size. Please provide an integer value.")
        return

    a = np.ones((size, size), dtype=int)
    b = np.ones((size, size), dtype=int)

    start_time = time.time()
    result = np.dot(a, b)
    end_time = time.time()

    elapsed_time = end_time - start_time
    print(f"Matrix multiplication took: {elapsed_time:.9f} seconds.")

if __name__ == "__main__":
    main()
