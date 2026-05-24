module {

  func.func @math(%a : i32, %b : i32) -> i32 {

    %0 = mydialect.myop %a, %b : i32

    %1 = mydialect.mysub %0, %a : i32

    return %1 : i32
  }

}