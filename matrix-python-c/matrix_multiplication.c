#include <Python.h>
#include <numpy/arrayobject.h>

static PyObject* matrix_multiply(PyObject* self, PyObject* args) {
    PyArrayObject *a_array, *b_array;
    int size;

    if (!PyArg_ParseTuple(args, "O!O!i", &PyArray_Type, &a_array, &PyArray_Type, &b_array, &size)) {
        return NULL;
    }

    npy_intp dims[2] = {size, size};
    PyArrayObject *result = (PyArrayObject *) PyArray_ZEROS(2, dims, NPY_INT, 0);

    int *a = (int *)PyArray_DATA(a_array);
    int *b = (int *)PyArray_DATA(b_array);
    int *res = (int *)PyArray_DATA(result);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int sum = 0;
            for (int k = 0; k < size; k++) {
                sum += a[i * size + k] * b[k * size + j];
            }
            res[i * size + j] = sum;
        }
    }

    return PyArray_Return(result);
}

static PyMethodDef MatrixMethods[] = {
    {"multiply", matrix_multiply, METH_VARARGS, "Multiply two matrices"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef matrixmodule = {
    PyModuleDef_HEAD_INIT,
    "matrix",
    NULL,
    -1,
    MatrixMethods
};

PyMODINIT_FUNC PyInit_matrix(void) {
    import_array();
    return PyModule_Create(&matrixmodule);
}
