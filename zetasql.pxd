from libcpp.string cimport string as std_string

cdef extern from "zetasql/public/evaluator.h" namespace "zetasql":
    cdef cppclass SimpleCatalog:
        SimpleCatalog(const std_string& name)

cdef extern from "zetasql.h":
    cdef bint analyze(const std_string& q, SimpleCatalog& catalog)
