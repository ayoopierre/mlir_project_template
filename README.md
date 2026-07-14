# 
This is very minimal template project for MLIR development

# Building
```sh
cmake -G Ninja -DMLIR_DIR=<path-to-llvm-project>/build/lib/cmake/mlir -DLLVM_DIR=<path-to-llvm-project>/build/lib/cmake/llvm ..
```

After that run ninja