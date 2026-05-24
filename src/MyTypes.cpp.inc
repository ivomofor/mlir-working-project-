/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_LIST
#undef GET_TYPEDEF_LIST

::mlir::mydialect::TensorType

#endif // GET_TYPEDEF_LIST

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES

static ::mlir::OptionalParseResult generatedTypeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mlir::mydialect::TensorType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::mydialect::TensorType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedTypePrinter(::mlir::Type def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Type, ::llvm::LogicalResult>(def)    .Case<::mlir::mydialect::TensorType>([&](auto t) {
      printer << ::mlir::mydialect::TensorType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir::mydialect {

namespace detail {

struct TensorTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<::llvm::ArrayRef<int64_t>, Type>;
  TensorTypeStorage(::llvm::ArrayRef<int64_t> shape, Type elementType) : shape(std::move(shape)), elementType(std::move(elementType)) {}

  KeyTy getAsKey() const {
    return KeyTy(shape, elementType);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (shape == std::get<0>(tblgenKey)) && (elementType == std::get<1>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey));
  }

  static TensorTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto shape = std::move(std::get<0>(tblgenKey));
    auto elementType = std::move(std::get<1>(tblgenKey));
    shape = allocator.copyInto(shape);
    return new (allocator.allocate<TensorTypeStorage>()) TensorTypeStorage(std::move(shape), std::move(elementType));
  }

  ::llvm::ArrayRef<int64_t> shape;
  Type elementType;
};

} // namespace detail
TensorType TensorType::get(::mlir::MLIRContext *context, ::llvm::ArrayRef<int64_t> shape, Type elementType) {
  return Base::get(context, std::move(shape), std::move(elementType));
}

::mlir::Type TensorType::parse(::mlir::AsmParser &odsParser) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  ::mlir::FailureOr<::llvm::SmallVector<int64_t>> _result_shape;
  ::mlir::FailureOr<Type> _result_elementType;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};
  // Parse literal '['
  if (odsParser.parseLSquare()) return {};

  // Parse variable 'shape'
  _result_shape = ::mlir::FieldParser<::llvm::SmallVector<int64_t>>::parse(odsParser);
  if (::mlir::failed(_result_shape)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse MyTensorType parameter 'shape' which is to be a `::llvm::ArrayRef<int64_t>`");
    return {};
  }
  // Parse literal ']'
  if (odsParser.parseRSquare()) return {};
  // Parse literal ','
  if (odsParser.parseComma()) return {};

  // Parse variable 'elementType'
  _result_elementType = ::mlir::FieldParser<Type>::parse(odsParser);
  if (::mlir::failed(_result_elementType)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse MyTensorType parameter 'elementType' which is to be a `Type`");
    return {};
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_shape));
  assert(::mlir::succeeded(_result_elementType));
  return TensorType::get(odsParser.getContext(),
      ::llvm::ArrayRef<int64_t>((*_result_shape)),
      Type((*_result_elementType)));
}

void TensorType::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  odsPrinter << "[";
  odsPrinter.printStrippedAttrOrType(getShape());
  odsPrinter << "]";
  odsPrinter << ",";
  odsPrinter << ' ';
  odsPrinter.printStrippedAttrOrType(getElementType());
  odsPrinter << ">";
}

::llvm::ArrayRef<int64_t> TensorType::getShape() const {
  return getImpl()->shape;
}

Type TensorType::getElementType() const {
  return getImpl()->elementType;
}


} // namespace mlir::mydialect
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::mydialect::TensorType)
namespace mlir::mydialect {


/// Parse a type registered to this dialect.
::mlir::Type MyDialectDialect::parseType(::mlir::DialectAsmParser &parser) const {
  ::llvm::SMLoc typeLoc = parser.getCurrentLocation();
  ::llvm::StringRef mnemonic;
  ::mlir::Type genType;
  auto parseResult = generatedTypeParser(parser, &mnemonic, genType);
  if (parseResult.has_value())
    return genType;
  
  parser.emitError(typeLoc) << "unknown  type `"
      << mnemonic << "` in dialect `" << getNamespace() << "`";
  return {};
}
/// Print a type registered to this dialect.
void MyDialectDialect::printType(::mlir::Type type,
                    ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedTypePrinter(type, printer)))
    return;
  
}

} // namespace mlir::mydialect

#endif // GET_TYPEDEF_CLASSES

