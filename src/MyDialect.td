include "mlir/IR/OpBase.td"
include "mlir/IR/AttrTypeBase.td"

// ============================================================================
// DIALECT
// ============================================================================

def MyDialect_Dialect : Dialect {

  let name = "mydialect";

  let cppNamespace = "::mlir::mydialect";

  // Auto-generate:
  //   parseType()
  //   printType()
  let useDefaultTypePrinterParser = 1;
}

// ============================================================================
// CUSTOM TYPE
// Syntax:
//   !mydialect.tensor<2x3xf32>
// ============================================================================

def MyTensorType : TypeDef<MyDialect_Dialect, "Tensor"> {

  let mnemonic = "tensor";

  let parameters = (ins
    ArrayRefParameter<"int64_t">:$shape,
    "Type":$elementType
  );

  let assemblyFormat =
      "`<` `[` $shape `]` `,` $elementType `>`";
}

// ============================================================================
// OPERATIONS
// ============================================================================

// --------------------------------------------------------------------------
// mydialect.myop
// Adds two f32 values
// --------------------------------------------------------------------------

def MyOp : Op<MyDialect_Dialect, "myop"> {

  let arguments = (ins F32:$lhs, F32:$rhs);

  let results = (outs F32:$res);

  let assemblyFormat =
      "$lhs `,` $rhs attr-dict `:` type($res)";
}

// --------------------------------------------------------------------------
// mydialect.mysub
// Subtracts two f32 values
// --------------------------------------------------------------------------

def MySubOp : Op<MyDialect_Dialect, "mysub"> {

  let arguments = (ins F32:$lhs, F32:$rhs);

  let results = (outs F32:$res);

  let assemblyFormat =
      "$lhs `,` $rhs attr-dict `:` type($res)";
}