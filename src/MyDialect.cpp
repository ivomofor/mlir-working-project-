#include "MyDialect.h"

#include "mlir/IR/Builders.h"
#include "mlir/IR/DialectImplementation.h"

using namespace mlir;
using namespace mlir::mydialect;

// -----------------------------------------------------------------------------
// Dialect Definitions
// -----------------------------------------------------------------------------

#include "MyDialect.cpp.inc"

// -----------------------------------------------------------------------------
// Operation Definitions
// -----------------------------------------------------------------------------

#define GET_OP_CLASSES
#include "MyOps.cpp.inc"

// -----------------------------------------------------------------------------
// Dialect Initialization
// -----------------------------------------------------------------------------

void MyDialectDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "MyOps.cpp.inc"
      >();
}