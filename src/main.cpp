#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h" 
#include "mlir/Parser/Parser.h"
#include "mlir/Support/FileUtilities.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_ostream.h"
#include <iostream>
#include <string>

int main() {
    // 1. Core compiler setup
    mlir::MLIRContext context;
    
    // Load the Dialects required to parse our test.mlir (func and arith)
    context.loadDialect<mlir::func::FuncDialect>();
    context.loadDialect<mlir::arith::ArithDialect>();

    // 2. Set up the LLVM Source Manager to handle file loading
    llvm::SourceMgr sourceMgr;
    std::string errorMessage;
    
    // Path relative to where you execute the binary (or use an absolute path)
    std::string filename = "../src/test.mlir";
    
    auto file = mlir::openInputFile(filename, &errorMessage);
    if (!file) {
        llvm::errs() << "Error: Could not open source file: " << errorMessage << "\n";
        return 1;
    }
    
    // Hand the file buffer over to the source manager
    sourceMgr.AddNewSourceBuffer(std::move(file), llvm::SMLoc());
    
    // 3. Parse the MLIR file into an in-memory ModuleOperation
    mlir::OwningOpRef<mlir::ModuleOp> module = mlir::parseSourceFile<mlir::ModuleOp>(sourceMgr, &context);
    
    if (!module) {
        llvm::errs() << "Error: Failed to parse MLIR syntax inside " << filename << "\n";
        return 1;
    }
    
    // 4. Verify the structural integrity of the module
    if (mlir::failed(module->verify())) {
        llvm::errs() << "Error: MLIR verification failed!\n";
        return 1;
    }
    
    std::cout << "Success: File parsed and verified! Printing module content:\n\n";
    
    // 5. Print the verified MLIR representation back out to the console
    module->print(llvm::outs());
    
    return 0;
}

