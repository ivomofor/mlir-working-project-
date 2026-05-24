include "mlir/IR/OpBase.td"

def MyDialect_Dialect : Dialect {
  let name = "mydialect";
  let cppNamespace = "::mlir::mydialect";
}

// ============================================================================
// myop
// ============================================================================

def MyOp : Op<MyDialect_Dialect, "myop"> {

  let summary = "integer addition";

  let arguments = (ins
    I32:$lhs,
    I32:$rhs
  );

  let results = (outs
    I32:$res
  );

  let assemblyFormat =
    "$lhs `,` $rhs attr-dict `:` type($res)";
}

// ============================================================================
// mysub
// ============================================================================

def MySubOp : Op<MyDialect_Dialect, "mysub"> {

  let summary = "integer subtraction";

  let arguments = (ins
    I32:$lhs,
    I32:$rhs
  );

  let results = (outs
    I32:$res
  );

  let assemblyFormat =
    "$lhs `,` $rhs attr-dict `:` type($res)";
}