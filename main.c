#include <Python.h>

PyObject obj1;
PyObject obj2;

Py_NO_INLINE static void
work(PyObject *pobj)
{
    Py_INCREF(pobj);
}

int main(int argc, char *argv[])
{
    PyObject* objects[2];
    objects[0] = &obj1;
    objects[1] = &obj2;

    int n = 1000 * 1000 * 1000;
    while (n--)
    {
        work(objects[n%2]);
    }

    printf("obj1.ob_refcnt=%lu\n", obj1.ob_refcnt);
    printf("obj2.ob_refcnt=%lu\n", obj2.ob_refcnt);
    return 0;
}
