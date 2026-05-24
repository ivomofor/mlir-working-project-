#ifndef MY_DIALECT_H
#define MY_DIALECT_H

#include "mlir/IR/Dialect.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/OpImplementation.h"
#include "mlir/IR/Types.h"

// -----------------------------------------------------------------------------
// Generated Dialect Declarations
// -----------------------------------------------------------------------------

#include "MyDialect.h.inc"

// -----------------------------------------------------------------------------
// Generated Type Declarations
// -----------------------------------------------------------------------------

#define GET_TYPEDEF_CLASSES
#include "MyTypes.h.inc"

// -----------------------------------------------------------------------------
// Generated Operation Declarations
// -----------------------------------------------------------------------------

#define GET_OP_CLASSES
#include "MyOps.h.inc"

#endif