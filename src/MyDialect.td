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

  // Auto-generate:
  //   parseAttribute()
  //   printAttribute()
  let useDefaultAttributePrinterParser = 1;
}

// ============================================================================
// CUSTOM ATTRIBUTE
// Example:
//   #mydialect.layout<"NHWC">
// ============================================================================

def MyLayoutAttr : AttrDef<MyDialect_Dialect, "Layout"> {

  let mnemonic = "layout";

  let parameters = (ins
    "std::string":$layout
  );

  let assemblyFormat =
      "`<` $layout `>`";
}

// ============================================================================
// CUSTOM TYPE
// Example:
//   !mydialect.tensor<[2,3],f32>
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

def MyOp : Op<MyDialect_Dialect, "myop"> {

  let arguments = (ins AnyType:$lhs, AnyType:$rhs);

  let results = (outs AnyType:$res);

let assemblyFormat =
    "$lhs `,` $rhs attr-dict `:` type($lhs) `,` type($rhs) `->` type($res)";

  let hasVerifier = 1;
}

def MySubOp : Op<MyDialect_Dialect, "mysub"> {

  let arguments = (ins F32:$lhs, F32:$rhs);

  let results = (outs F32:$res);

  let assemblyFormat =
      "$lhs `,` $rhs attr-dict `:` type($res)";
}

