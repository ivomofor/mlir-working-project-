module {

  func.func @test() -> f32 {

    %0 = arith.constant 10.0 : f32
    %1 = arith.constant 5.0 : f32

    %2 = mydialect.myop %0, %1
      {layout = #mydialect.layout<"NHWC">}
      : f32

    return %2 : f32
  }

}