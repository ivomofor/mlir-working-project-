module {
  func.func @test(%a : f32, %b : i32) -> f32 {

    %0 = mydialect.myop %a, %b : f32, i32 -> f32

    return %0 : f32
  }
}