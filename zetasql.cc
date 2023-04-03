#include "zetasql/public/evaluator.h"

#include "zetasql.h"

bool analyze(const std::string& query, zetasql::SimpleCatalog& catalog) {
    using namespace zetasql;

    // TODO: configure outside
    catalog.AddZetaSQLFunctions();

    PreparedQuery pq(query, EvaluatorOptions());
    // TODO: configure ahead of time
    AnalyzerOptions analyzer_options;
    LanguageOptions* language_options = analyzer_options.mutable_language();
    language_options->EnableMaximumLanguageFeatures();
    auto status = pq.Prepare(analyzer_options, &catalog);
    if (!status.ok()) {
        std::cerr << status << std::endl;
        return true;
    }
    for (const auto& col : pq.GetColumns()) {
        std::cout << col.first << ' ' << col.second->DebugString() << std::endl;
    }
    return false;
}
