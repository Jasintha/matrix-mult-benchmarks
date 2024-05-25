FROM python:latest

# Set the working directory
WORKDIR /usr/src/app

# Copy the source code
COPY matrix_multiplication.py .

# Install numpy
RUN pip install numpy

# Set the entry point
ENTRYPOINT ["python", "matrix_multiplication.py"]

