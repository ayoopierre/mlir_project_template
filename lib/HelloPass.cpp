#include "HelloPass.h"

#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/Pass/Pass.h"

using namespace mlir;

namespace {

struct HelloPass
    : public mlir::PassWrapper<HelloPass,
                               mlir::OperationPass<mlir::ModuleOp>> {

  MLIR_DEFINE_EXPLICIT_INTERNAL_INLINE_TYPE_ID(HelloPass)

  llvm::StringRef getArgument() const final {
    return "hello-pass";
  }

  llvm::StringRef getDescription() const final {
    return "Print all functions";
  }

  llvm::StringRef getName() const override {
    return "HelloPass";
  }

  void runOnOperation() override {
    auto module = getOperation();

    module.walk([](mlir::func::FuncOp func) {
      llvm::outs() << func.getName() << "\n";
    });
  }
};

} // namespace

void mlir::registerHelloPass() {
  PassRegistration<HelloPass>();
}