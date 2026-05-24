/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* AttrDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_ATTRDEF_LIST
#undef GET_ATTRDEF_LIST

::mlir::mydialect::LayoutAttr

#endif // GET_ATTRDEF_LIST

#ifdef GET_ATTRDEF_CLASSES
#undef GET_ATTRDEF_CLASSES

static ::mlir::OptionalParseResult generatedAttributeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type type, ::mlir::Attribute &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mlir::mydialect::LayoutAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::mydialect::LayoutAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedAttributePrinter(::mlir::Attribute def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Attribute, ::llvm::LogicalResult>(def)    .Case<::mlir::mydialect::LayoutAttr>([&](auto t) {
      printer << ::mlir::mydialect::LayoutAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir::mydialect {

namespace detail {

struct LayoutAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<std::string>;
  LayoutAttrStorage(std::string layout) : layout(std::move(layout)) {}

  KeyTy getAsKey() const {
    return KeyTy(layout);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (layout == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static LayoutAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto layout = std::move(std::get<0>(tblgenKey));
    return new (allocator.allocate<LayoutAttrStorage>()) LayoutAttrStorage(std::move(layout));
  }

  std::string layout;
};

} // namespace detail
LayoutAttr LayoutAttr::get(::mlir::MLIRContext *context, std::string layout) {
  return Base::get(context, std::move(layout));
}

::mlir::Attribute LayoutAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<std::string> _result_layout;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};

  // Parse variable 'layout'
  _result_layout = ::mlir::FieldParser<std::string>::parse(odsParser);
  if (::mlir::failed(_result_layout)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse MyLayoutAttr parameter 'layout' which is to be a `std::string`");
    return {};
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_layout));
  return LayoutAttr::get(odsParser.getContext(),
      std::string((*_result_layout)));
}

void LayoutAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter.printStrippedAttrOrType(getLayout());
  odsPrinter << ">";
}

std::string LayoutAttr::getLayout() const {
  return getImpl()->layout;
}


} // namespace mlir::mydialect
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mydialect::LayoutAttr)
namespace mlir::mydialect {


/// Parse an attribute registered to this dialect.
::mlir::Attribute MyDialectDialect::parseAttribute(::mlir::DialectAsmParser &parser,
                                      ::mlir::Type type) const {
  ::llvm::SMLoc typeLoc = parser.getCurrentLocation();
  ::llvm::StringRef attrTag;
  {
    ::mlir::Attribute attr;
    auto parseResult = generatedAttributeParser(parser, &attrTag, type, attr);
    if (parseResult.has_value())
      return attr;
  }
  
  parser.emitError(typeLoc) << "unknown attribute `"
      << attrTag << "` in dialect `" << getNamespace() << "`";
  return {};
}
/// Print an attribute registered to this dialect.
void MyDialectDialect::printAttribute(::mlir::Attribute attr,
                         ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedAttributePrinter(attr, printer)))
    return;
  
}

} // namespace mlir::mydialect

#endif // GET_ATTRDEF_CLASSES

