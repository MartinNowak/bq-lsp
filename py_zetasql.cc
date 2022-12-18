// -*- compile-command: "bazel run --config=g++ :zetasql_test" -*-
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "zetasql/public/evaluator.h"
#include "zetasql/public/simple_catalog.h"

namespace py = pybind11;
using namespace zetasql;

int add(int i, int j) {
    return i + j;
}

// PYBIND11_MAKE_OPAQUE(Type);

PYBIND11_MODULE(zetasql, m) {
    m.doc() = "zetasql bindings";

    m.def("add", &add, "A function that adds two numbers");

    py::enum_<ProductMode>(m, "ProductMode")
        .value("PRODUCT_INTERNAL", ProductMode::PRODUCT_INTERNAL)
        .value("PRODUCT_EXTERNAL", ProductMode::PRODUCT_EXTERNAL)
        .export_values()
        ;

    py::class_<SimpleTable>(m, "SimpleTable")
        .def(py::init<absl::string_view, const std::vector<SimpleTable::NameAndType>&>())
        .def("GetTableTypeName", &SimpleTable::GetTableTypeName)
        ;

    py::class_<SimpleCatalog>(m, "SimpleCatalog")
        .def(py::init<const std::string&>())
        .def("AddTable", py::overload_cast<absl::string_view, const Table*>(&SimpleCatalog::AddTable))
        .def("AddTable", py::overload_cast<const Table*>(&SimpleCatalog::AddTable))
        ;

    py::class_<Type, std::unique_ptr<Type, py::nodelete>>(m, "Type")
        .def("ShortTypeName", &Type::ShortTypeName)
        .def("TypeName", &Type::TypeName)
        .def("DebugString", &Type::DebugString, py::arg("details")=false)
        ;

    py::class_<ContainerType, Type, std::unique_ptr<ContainerType, py::nodelete>>(m, "ContainerType")
        ;

    py::class_<ArrayType, ContainerType, std::unique_ptr<ArrayType, py::nodelete>>(m, "ArrayType")
        ;

    py::class_<StructType, ContainerType, std::unique_ptr<StructType, py::nodelete>>(m, "StructType")
        ;
    
    auto m_ty = m.def_submodule("types");
    m_ty.def("Int32Type", &types::Int32Type, py::return_value_policy::reference);
    m_ty.def("Int64Type", &types::Int64Type, py::return_value_policy::reference);
    m_ty.def("Uint32Type", &types::Uint32Type, py::return_value_policy::reference);
    m_ty.def("Uint64Type", &types::Uint64Type, py::return_value_policy::reference);
    m_ty.def("BoolType", &types::BoolType, py::return_value_policy::reference);
    m_ty.def("FloatType", &types::FloatType, py::return_value_policy::reference);
    m_ty.def("DoubleType", &types::DoubleType, py::return_value_policy::reference);
    m_ty.def("StringType", &types::StringType, py::return_value_policy::reference);
    m_ty.def("BytesType", &types::BytesType, py::return_value_policy::reference);
    m_ty.def("DateType", &types::DateType, py::return_value_policy::reference);
    m_ty.def("TimestampType", &types::TimestampType, py::return_value_policy::reference);
    m_ty.def("TimeType", &types::TimeType, py::return_value_policy::reference);
    m_ty.def("DatetimeType", &types::DatetimeType, py::return_value_policy::reference);
    m_ty.def("IntervalType", &types::IntervalType, py::return_value_policy::reference);
    m_ty.def("GeographyType", &types::GeographyType, py::return_value_policy::reference);
    m_ty.def("NumericType", &types::NumericType, py::return_value_policy::reference);
    m_ty.def("BigNumericType", &types::BigNumericType, py::return_value_policy::reference);
    m_ty.def("JsonType", &types::JsonType, py::return_value_policy::reference);
    m_ty.def("EmptyStructType", &types::EmptyStructType, py::return_value_policy::reference);

    m_ty.def("Int32ArrayType", &types::Int32ArrayType, py::return_value_policy::reference);
    m_ty.def("Int64ArrayType", &types::Int64ArrayType, py::return_value_policy::reference);
    m_ty.def("Uint32ArrayType", &types::Uint32ArrayType, py::return_value_policy::reference);
    m_ty.def("Uint64ArrayType", &types::Uint64ArrayType, py::return_value_policy::reference);
    m_ty.def("BoolArrayType", &types::BoolArrayType, py::return_value_policy::reference);
    m_ty.def("FloatArrayType", &types::FloatArrayType, py::return_value_policy::reference);
    m_ty.def("DoubleArrayType", &types::DoubleArrayType, py::return_value_policy::reference);
    m_ty.def("StringArrayType", &types::StringArrayType, py::return_value_policy::reference);
    m_ty.def("BytesArrayType", &types::BytesArrayType, py::return_value_policy::reference);
    m_ty.def("TimestampArrayType", &types::TimestampArrayType, py::return_value_policy::reference);
    m_ty.def("DateArrayType", &types::DateArrayType, py::return_value_policy::reference);
    m_ty.def("DatetimeArrayType", &types::DatetimeArrayType, py::return_value_policy::reference);
    m_ty.def("TimeArrayType", &types::TimeArrayType, py::return_value_policy::reference);
    m_ty.def("IntervalArrayType", &types::IntervalArrayType, py::return_value_policy::reference);
    m_ty.def("GeographyArrayType", &types::GeographyArrayType, py::return_value_policy::reference);
    m_ty.def("NumericArrayType", &types::NumericArrayType, py::return_value_policy::reference);
    m_ty.def("BigNumericArrayType", &types::BigNumericArrayType, py::return_value_policy::reference);
    m_ty.def("JsonArrayType", &types::JsonArrayType, py::return_value_policy::reference);
}
