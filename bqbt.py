# distutils: language = c++

import cython
from cython.cimports.zetasql import SimpleCatalog, analyze
from cython.cimports.libcpp.string import string as std_string
from cython.cimports.libcpp.memory import unique_ptr as std_unique_ptr

def analyze_query(query: str) -> cython.bint:
    c: std_unique_ptr(SimpleCatalog) = new SimpleCatalog("bqbt")
    catalog: BQBTCatalog
    q: string = query.encode()
    return analyze(q, cython.operator.dereference(c))
