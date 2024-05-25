# Stage 1: Build the Java application
FROM openjdk:latest AS builder

# Set the working directory
WORKDIR /usr/src/app

# Copy the source code
COPY MatrixMultiplication.java .

# Compile the Java application
RUN javac MatrixMultiplication.java

# Stage 2: Run the Java application
FROM openjdk:latest

# Set the working directory
WORKDIR /root/

# Copy the compiled class files from the builder stage
COPY --from=builder /usr/src/app/MatrixMultiplication.class /root/
COPY --from=builder /usr/src/app/MatrixMultiplication\$MatrixMultiplyTask.class /root/

# Set the entry point
ENTRYPOINT ["java", "MatrixMultiplication"]
