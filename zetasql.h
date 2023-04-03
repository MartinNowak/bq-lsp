#ifndef ZETASQL_H
#define ZETASQL_H

#include "zetasql/public/simple_catalog.h"

bool analyze(const std::string& query, zetasql::SimpleCatalog& catalog);

#endif
