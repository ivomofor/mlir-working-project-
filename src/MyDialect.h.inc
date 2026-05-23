/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MyDialect.td                                                         *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir::mydialect {


class MyDialectDialect : public ::mlir::Dialect {
  explicit MyDialectDialect(::mlir::MLIRContext *context);

  void initialize();
  friend class ::mlir::MLIRContext;
public:
  ~MyDialectDialect() override;
  static constexpr ::llvm::StringLiteral getDialectNamespace() {
    return ::llvm::StringLiteral("mydialect");
  }
};

} // namespace mlir::mydialect
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::mydialect::MyDialectDialect)
