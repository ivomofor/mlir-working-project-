module {

  func.func @tensor_test(
    %arg0 : !mydialect.tensor<[2,3],f32>
  ) -> f32 {

    %0 = arith.constant 1.0 : f32

    return %0 : f32
  }

}