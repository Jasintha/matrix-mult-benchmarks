# Stage 1: Build the Go application
FROM golang:latest AS builder

# Set the working directory
WORKDIR /app

# Copy the Go module files and source code
COPY . .

# Initialize Go module
RUN go mod init matrix_multiplication

# Add Gonum dependency
RUN go get gonum.org/v1/gonum/mat

# Build the Go application
RUN go build -o matrix_multiplication .

# Stage 2: Create a minimal runtime environment
FROM alpine:latest

# Install libc6-compat for Go
RUN apk --no-cache add libc6-compat

# Set the working directory
WORKDIR /root/

# Copy the built binary from the builder stage
COPY --from=builder /app/matrix_multiplication .

# Set the entry point
ENTRYPOINT ["./matrix_multiplication"]
