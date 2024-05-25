# Stage 1: Build the C++ application
FROM gcc:latest AS builder

# Set the working directory
WORKDIR /usr/src/app

# Copy the source code
COPY matrix_multiplication.cpp .

# Compile the application with optimization flags
RUN g++ -O3 -o matrix_multiplication matrix_multiplication.cpp

# Stage 2: Use the same base image for runtime
FROM gcc:latest

# Set the working directory
WORKDIR /root/

# Copy the built binary from the builder stage
COPY --from=builder /usr/src/app/matrix_multiplication .

# Set the entry point
ENTRYPOINT ["./matrix_multiplication"]
