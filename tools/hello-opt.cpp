#include "HelloPass.h"

#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/SCF/IR/SCF.h"

#include "mlir/IR/DialectRegistry.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"

int main(int argc, char **argv) {

  mlir::DialectRegistry registry;

  registry.insert<
      mlir::arith::ArithDialect,
      mlir::func::FuncDialect,
      mlir::scf::SCFDialect>();

  mlir::registerHelloPass();

  return mlir::asMainReturnCode(
      mlir::MlirOptMain(
          argc,
          argv,
          "Hello MLIR\n",
          registry));
}