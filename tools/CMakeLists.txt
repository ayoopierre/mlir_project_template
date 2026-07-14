add_llvm_executable(hello-opt

    hello-opt.cpp
)

llvm_update_compile_flags(hello-opt)

target_link_libraries(hello-opt PRIVATE

    HelloPass

    MLIROptLib

    MLIRFuncDialect
    MLIRSCFDialect
    MLIRArithDialect
)