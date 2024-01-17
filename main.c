#include <Python.h>

PyObject obj;
PyObject *pobj = NULL;

int main(int argc, char *argv[])
{
    if (argc)
    {
        pobj = &obj; // To prevent compiler optimization over obj fields.
    }

    for (int i = 0; i < 1000 * 1000 * 1000; i++)
    {
        Py_INCREF(pobj);
    }
    printf("ob_refcnt=%lu\n", pobj->ob_refcnt);
    return 0;
}
