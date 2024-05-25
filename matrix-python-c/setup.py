from setuptools import setup, Extension
import numpy

module = Extension('matrix', sources=['matrix_multiplication.c'], include_dirs=[numpy.get_include()])

setup(
    name='MatrixMultiplication',
    version='1.0',
    description='Matrix multiplication using C',
    ext_modules=[module]
)
