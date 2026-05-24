#include "MyDialect.h"

#include "mlir/IR/DialectImplementation.h"
#include "llvm/ADT/TypeSwitch.h"

// -----------------------------------------------------------------------------
// Dialect Definitions
// -----------------------------------------------------------------------------

#include "MyDialect.cpp.inc"

// -----------------------------------------------------------------------------
// Type Definitions
// -----------------------------------------------------------------------------

#define GET_TYPEDEF_CLASSES
#include "MyTypes.cpp.inc"

// -----------------------------------------------------------------------------
// Operation Definitions
// -----------------------------------------------------------------------------

#define GET_OP_CLASSES
#include "MyOps.cpp.inc"

// -----------------------------------------------------------------------------
// Dialect Initialization
// -----------------------------------------------------------------------------

namespace mlir::mydialect {

void MyDialectDialect::initialize() {

  addTypes<
#define GET_TYPEDEF_LIST
#include "MyTypes.cpp.inc"
      >();

  addOperations<
#define GET_OP_LIST
#include "MyOps.cpp.inc"
      >();
}

} // namespace mlir::mydialect