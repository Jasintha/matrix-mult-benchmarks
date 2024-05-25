# Stage 1: Build the C program using the gcc image
FROM gcc:latest AS builder

# Set the working directory
WORKDIR /usr/src/app

# Copy the source code into the container
COPY matrix_multiplication.c .

# Compile the C program with optimization flags and OpenMP support
RUN gcc -O3 -fopenmp -o matrix_multiplication matrix_multiplication.c

# Stage 2: Use the same base image to run the compiled binary
FROM gcc:latest

# Set the working directory
WORKDIR /root/

# Copy the compiled binary from the builder stage
COPY --from=builder /usr/src/app/matrix_multiplication .

# Set the entry point to the compiled binary
ENTRYPOINT ["./matrix_multiplication"]
