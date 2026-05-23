#include "MyDialect.h"

#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/DialectRegistry.h"
#include "mlir/IR/MLIRContext.h"

#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"

#include "mlir/Parser/Parser.h"
#include "mlir/Support/FileUtilities.h"

#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_ostream.h"

#include <iostream>
#include <string>

int main() {

    // -------------------------------------------------------------------------
    // Register dialects
    // -------------------------------------------------------------------------

    mlir::DialectRegistry registry;

    registry.insert<
        mlir::func::FuncDialect,
        mlir::arith::ArithDialect,
        mlir::mydialect::MyDialectDialect
    >();

    // -------------------------------------------------------------------------
    // Create MLIR context
    // -------------------------------------------------------------------------

    mlir::MLIRContext context(registry);

    // -------------------------------------------------------------------------
    // Explicitly load dialects
    // -------------------------------------------------------------------------

    context.loadDialect<
        mlir::func::FuncDialect,
        mlir::arith::ArithDialect,
        mlir::mydialect::MyDialectDialect
    >();

    // -------------------------------------------------------------------------
    // Source manager
    // -------------------------------------------------------------------------

    llvm::SourceMgr sourceMgr;

    std::string errorMessage;

    std::string filename = "../src/test.mlir";

    auto file = mlir::openInputFile(filename, &errorMessage);

    if (!file) {
        llvm::errs()
            << "Could not open file: "
            << errorMessage
            << "\n";

        return 1;
    }

    sourceMgr.AddNewSourceBuffer(
        std::move(file),
        llvm::SMLoc()
    );

    // -------------------------------------------------------------------------
    // Parse MLIR
    // -------------------------------------------------------------------------

    auto module =
        mlir::parseSourceFile<mlir::ModuleOp>(
            sourceMgr,
            &context
        );

    if (!module) {
        llvm::errs()
            << "Failed to parse MLIR file\n";

        return 1;
    }

    // -------------------------------------------------------------------------
    // Verify module
    // -------------------------------------------------------------------------

    if (mlir::failed(module->verify())) {

        llvm::errs()
            << "Module verification failed\n";

        return 1;
    }

    // -------------------------------------------------------------------------
    // Print module
    // -------------------------------------------------------------------------

    llvm::outs()
        << "\n=== Parsed MLIR Module ===\n\n";

    module->print(llvm::outs());

    llvm::outs() << "\n";

    return 0;
}