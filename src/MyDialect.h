#ifndef MY_DIALECT_H
#define MY_DIALECT_H

#include "mlir/IR/Dialect.h"
#include "mlir/IR/OpImplementation.h"
#include "mlir/IR/BuiltinTypes.h"

#include "MyDialect.h.inc"

#define GET_OP_CLASSES
#include "MyOps.h.inc"

#endif