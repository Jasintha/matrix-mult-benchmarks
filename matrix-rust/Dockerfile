# Stage 1: Build the Rust application
FROM rust:latest AS builder

# Set the working directory
WORKDIR /usr/src/app

# Create a new binary Rust project
RUN USER=root cargo new --bin matrix_multiplication
WORKDIR /usr/src/app/matrix_multiplication

# Copy the source code
COPY matrix_multiplication.rs ./src/main.rs

# Add Rayon dependency
RUN echo 'rayon = "1.5"' >> Cargo.toml

# Build the Rust application in release mode
RUN cargo build --release

# Stage 2: Use the same base image for runtime
FROM rust:latest

# Set the working directory
WORKDIR /root/

# Copy the built binary from the builder stage
COPY --from=builder /usr/src/app/matrix_multiplication/target/release/matrix_multiplication .

# Set the entry point
ENTRYPOINT ["./matrix_multiplication"]
