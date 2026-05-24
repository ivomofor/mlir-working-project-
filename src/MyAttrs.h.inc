/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* AttrDef Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_ATTRDEF_CLASSES
#undef GET_ATTRDEF_CLASSES


namespace mlir {
class AsmParser;
class AsmPrinter;
} // namespace mlir
namespace mlir::mydialect {

class LayoutAttr;
namespace detail {

struct LayoutAttrStorage;

} // namespace detail
class LayoutAttr : public ::mlir::Attribute::AttrBase<LayoutAttr, ::mlir::Attribute, detail::LayoutAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "mydialect.layout";
  static constexpr ::llvm::StringLiteral dialectName = "mydialect";
  static LayoutAttr get(::mlir::MLIRContext *context, std::string layout);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"layout"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  std::string getLayout() const;
};

} // namespace mlir::mydialect
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::mydialect::LayoutAttr)

#endif // GET_ATTRDEF_CLASSES

