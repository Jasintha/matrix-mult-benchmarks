
# Matrix Multiplication Benchmarks
   
This repository contains a fun benchmark comparison of matrix multiplication implementations across multiple programming languages.

## Disclaimer
This project is intended for fun and educational purposes only. The results should not be taken as definitive performance metrics for any of the included languages. Performance can vary based on numerous factors including compiler optimizations, hardware, and specific use cases.


## Languages Included
   - C
   - C++
   - Go
   - Java
   - Python
   - Rust
   - Python with C extension

## Structure
   Each language's implementation is contained in its own directory with the necessary source code and Dockerfile to build and run the program.
   
   ```
     .
     ├── matrix-c-plus
     │   ├── Dockerfile
     │   └── matrix_multiplication.cpp
     ├── matrix-go
     │   ├── Dockerfile
     │   ├── go.mod
     │   └── matrix_multiplication.go
     ├── matrix-java
     │   ├── Dockerfile
     │   └── MatrixMultiplication.java
     ├── matrix-python
     │   ├── Dockerfile
     │   └── matrix_multiplication.py
     ├── matrix-rust
     │   ├── Dockerfile
     │   └── matrix_multiplication.rs
     ├── matrix-python-c
     │   ├── Dockerfile.python-c
     │   ├── matrix_multiplication.c
     │   ├── setup.py
     │   └── matrix_multiplication.py
     ├── matrix-c
     │   ├── Dockerfile
     │   └── matrix_multiplication.c
     ├── Makefile
     └── README.md
   ```


## How to Build and Run

   1. **Clone the repository:**
      ```sh
      git clone https://github.com/Jasintha/matrix-mult-benchmarks.git
      cd matrix-mult-benchmarks
      ```

   2. **Build all Docker images:**
      ```sh
      make build
      ```

   3. **Run the benchmarks for all languages:**
      ```sh
      make run-all MATRIX_SIZE=1000
      ```

   ## Results

   Here are the benchmark results for matrix size 1000:

   | Language | Time (seconds) |
   |----------|----------------|
   | Go       |    0.109532197 |
   | C++      |    0.563254000 |
   | Rust     |    0.802906297 |
   | C        |    1.459348000 |
   | Python-C |    1.574121475 |
   | Java     |    1.760523987 |
   | Python   |    2.505929470 |

   ## License
   This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
   ```
