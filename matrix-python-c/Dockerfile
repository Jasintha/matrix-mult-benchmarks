FROM python:latest

# Install necessary build tools and NumPy
RUN apt-get update && apt-get install -y build-essential
RUN pip install numpy

# Set the working directory
WORKDIR /usr/src/app

# Copy the source code
COPY matrix_multiplication.c .
COPY setup.py .
COPY matrix_multiplication.py .

# Build and install the C extension
RUN python setup.py build_ext --inplace

# Ensure the module is in the PYTHONPATH
ENV PYTHONPATH=/usr/src/app

# Set the entry point
ENTRYPOINT ["python", "matrix_multiplication.py"]
