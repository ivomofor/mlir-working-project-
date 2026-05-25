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
// Attribute Definitions
// -----------------------------------------------------------------------------

#define GET_ATTRDEF_CLASSES
#include "MyAttrs.cpp.inc"

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

  // Register types
  addTypes<
#define GET_TYPEDEF_LIST
#include "MyTypes.cpp.inc"
      >();

  // Register attributes
  addAttributes<
#define GET_ATTRDEF_LIST
#include "MyAttrs.cpp.inc"
      >();

  // Register operations
  addOperations<
#define GET_OP_LIST
#include "MyOps.cpp.inc"
      >();
}

} // namespace mlir::mydialect

// -----------------------------------------------------------------------------
// MyOp Verifier
// -----------------------------------------------------------------------------

mlir::LogicalResult mlir::mydialect::MyOp::verify() {

  Type lhsType = getLhs().getType();
  Type rhsType = getRhs().getType();

  if (lhsType != rhsType) {
    return emitOpError(
        "lhs and rhs must have same type");
  }

  return mlir::success();
}