module {
    func.func @compare(%x: i32, %y: i32) -> i32 {
        %cond = arith.cmpi slt, %x, %y : i32 
        cf.cond_br %cond, ^bb_first, ^bb_second 
        ^bb_first:
            %res1 = arith.constant 1 : i32 
            cf.br ^bb_third(%res1 : i32)
        ^bb_second:
            %res2 = arith.constant 2 : i32 
            cf.br ^bb_third(%res2: i32)
        ^bb_third(%phi: i32):
            return %phi : i32 
    }

    func.func @sum(%n: index) -> i32 {
        %c0 = arith.constant 0 : index 
        %c1 = arith.constant 1 : index
        %c2 = arith.constant 0 : i32 
        %result  = scf.for %i = %c0 to %n step %c1 iter_args(%acc = %c2) -> i32 {
            %i_i32 = arith.index_cast %i : index to i32 
            %new = arith.addi %acc, %i_i32 : i32 
            scf.yield %new : i32
        } 
        return %result : i32
    }
}