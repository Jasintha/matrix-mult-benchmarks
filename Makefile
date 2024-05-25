# Define directories for each language
DIRS := matrix-c-plus matrix-go matrix-java matrix-python matrix-rust matrix-python-c matrix-c

# Default matrix size
MATRIX_SIZE ?= 500

# Build goal for each language
build: build-cpp build-go build-java build-python build-rust build-python-c build-c

build-cpp:
	@echo "Building C++ matrix multiplication..."
	@docker build -f matrix-c-plus/Dockerfile -t matrix_multiplication_cpp matrix-c-plus

build-go:
	@echo "Building Go matrix multiplication..."
	@docker build -f matrix-go/Dockerfile -t matrix_multiplication_go matrix-go

build-java:
	@echo "Building Java matrix multiplication..."
	@docker build -f matrix-java/Dockerfile -t matrix_multiplication_java matrix-java

build-python:
	@echo "Building Python matrix multiplication..."
	@docker build -f matrix-python/Dockerfile -t matrix_multiplication_python matrix-python

build-rust:
	@echo "Building Rust matrix multiplication..."
	@docker build -f matrix-rust/Dockerfile -t matrix_multiplication_rust matrix-rust

build-python-c:
	@echo "Building Python-C matrix multiplication..."
	@docker build -f matrix-python-c/Dockerfile.python-c -t matrix_multiplication_python_c matrix-python-c

build-c:
	@echo "Building C matrix multiplication..."
	@docker build -f matrix-c/Dockerfile -t matrix_multiplication_c matrix-c

# Run goal for each language
run: run-cpp run-go run-java run-python run-rust run-python-c run-c

run-cpp:
	@echo "Running C++ matrix multiplication with size $(MATRIX_SIZE)..."
	@docker run --rm matrix_multiplication_cpp $(MATRIX_SIZE)

run-go:
	@echo "Running Go matrix multiplication with size $(MATRIX_SIZE)..."
	@docker run --rm matrix_multiplication_go $(MATRIX_SIZE)

run-java:
	@echo "Running Java matrix multiplication with size $(MATRIX_SIZE)..."
	@docker run --rm matrix_multiplication_java $(MATRIX_SIZE)

run-python:
	@echo "Running Python matrix multiplication with size $(MATRIX_SIZE)..."
	@docker run --rm matrix_multiplication_python $(MATRIX_SIZE)

run-rust:
	@echo "Running Rust matrix multiplication with size $(MATRIX_SIZE)..."
	@docker run --rm matrix_multiplication_rust $(MATRIX_SIZE)

run-python-c:
	@echo "Running Python-C matrix multiplication with size $(MATRIX_SIZE)..."
	@docker run --rm matrix_multiplication_python_c $(MATRIX_SIZE)

run-c:
	@echo "Running C matrix multiplication with size $(MATRIX_SIZE)..."
	@docker run --rm matrix_multiplication_c $(MATRIX_SIZE)

# Run all and display results in table format
run-all:
	@echo "Running matrix multiplication for all languages with size $(MATRIX_SIZE)..."
	@{ \
	  echo "Language,Time"; \
	  echo -n "C++,"; docker run --rm matrix_multiplication_cpp $(MATRIX_SIZE) 2>&1 | grep "Matrix multiplication took" | awk '{print $$4 " seconds"}'; \
	  echo -n "Go,"; docker run --rm matrix_multiplication_go $(MATRIX_SIZE) 2>&1 | grep "Matrix multiplication took" | awk '{print $$4}'; \
	  echo -n "Java,"; docker run --rm matrix_multiplication_java $(MATRIX_SIZE) 2>&1 | grep "Matrix multiplication took" | awk '{print $$4}'; \
	  echo -n "Python,"; docker run --rm matrix_multiplication_python $(MATRIX_SIZE) 2>&1 | grep "Matrix multiplication took" | awk '{print $$4}'; \
	  echo -n "Rust,"; docker run --rm matrix_multiplication_rust $(MATRIX_SIZE) 2>&1 | grep "Matrix multiplication took" | awk '{print $$4}'; \
	  echo -n "Python-C,"; docker run --rm matrix_multiplication_python_c $(MATRIX_SIZE) 2>&1 | grep "Matrix multiplication took" | awk '{print $$4}'; \
	  echo -n "C,"; docker run --rm matrix_multiplication_c $(MATRIX_SIZE) 2>&1 | grep "Matrix multiplication took" | awk '{print $$4}'; \
	} | tail -n +2 | awk -F, 'BEGIN { print "| Language | Time (seconds) |"; print "|----------|----------------|"; } \
	  { \
	    if ($$2 ~ /ms$$/) { \
	      sub(/ms/, "", $$2); \
	      $$2 = $$2 / 1000; \
	    } else { \
	      sub(/ seconds/, "", $$2); \
	    } \
	    printf "| %-8s | %14.9f |\n", $$1, $$2; \
	  }' | sort -t'|' -k3,3n

