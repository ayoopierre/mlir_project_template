add_mlir_library(HelloPass

    HelloPass.cpp

    LINK_LIBS PUBLIC
        MLIRIR
        MLIRPass
        MLIRFuncDialect
)