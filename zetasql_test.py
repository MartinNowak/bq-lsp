from zetasql.zetasql import types, SimpleCatalog, ProductMode, SimpleTable
from google.cloud import bigquery as bq

bqc = bq.Client()
t = bqc.get_table('data.product_attributes')

type_map = {
    ty().TypeName(ProductMode.PRODUCT_EXTERNAL): ty()
    for name, ty in types.__dict__.items()
    if name.endswith('Type')
}
# map BQ client field types (https://cloud.google.com/bigquery/docs/reference/rest/v2/tables#TableFieldSchema.FIELDS.type)
type_map['INTEGER'] = types.Int64Type()
type_map['BOOLEAN'] = types.BoolType()

print(SimpleTable(t.table_id, [(col.name, type_map[col.field_type]) for col in t.schema]).GetTableTypeName(ProductMode.PRODUCT_EXTERNAL))
