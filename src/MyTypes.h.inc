/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES


namespace mlir {
class AsmParser;
class AsmPrinter;
} // namespace mlir
namespace mlir::mydialect {

class TensorType;
namespace detail {

struct TensorTypeStorage;

} // namespace detail
class TensorType : public ::mlir::Type::TypeBase<TensorType, ::mlir::Type, detail::TensorTypeStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "mydialect.tensor";
  static constexpr ::llvm::StringLiteral dialectName = "mydialect";
  static TensorType get(::mlir::MLIRContext *context, ::llvm::ArrayRef<int64_t> shape, Type elementType);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"tensor"};
  }

  static ::mlir::Type parse(::mlir::AsmParser &odsParser);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<int64_t> getShape() const;
  Type getElementType() const;
};

} // namespace mlir::mydialect
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::mydialect::TensorType)

#endif // GET_TYPEDEF_CLASSES

