from zetasql import add, SimpleTable, types, ProductMode, Type
from google.cloud import bigquery as bq

print(add(1, 2))

type_map = {
    ty().TypeName(ProductMode.PRODUCT_EXTERNAL): ty()
    for name, ty in types.__dict__.items()
    if name.endswith('Type')
}
# map BQ client field types (https://cloud.google.com/bigquery/docs/reference/rest/v2/tables#TableFieldSchema.FIELDS.type)
type_map['INTEGER'] = types.Int64Type()
type_map['BOOLEAN'] = types.BoolType()

bqc = bq.Client()
t = bqc.get_table('data.product_attributes')

print(SimpleTable('product_attributes', [(col.name, type_map[col.field_type]) for col in t.schema]).GetTableTypeName(ProductMode.PRODUCT_EXTERNAL))
