/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MyDialect.td                                                         *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mydialect::MyDialectDialect)
namespace mlir::mydialect {


MyDialectDialect::MyDialectDialect(::mlir::MLIRContext *context)
    : ::mlir::Dialect(getDialectNamespace(), context, ::mlir::TypeID::get<MyDialectDialect>())
    
     {
  
  initialize();
}

MyDialectDialect::~MyDialectDialect() = default;


} // namespace mlir::mydialect
