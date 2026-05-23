module {
    func.func @compute(%a: i32, %b: i32) -> i32 {
        %cond = arith.cmpi slt, %a, %b : i32 
        cf.cond_br %cond, ^bb1, ^bb2
        ^bb1: 
        %sum = arith.addi %a,%b : i32 
        cf.br ^bb3(%sum: i32)
        ^bb2:
        %diff = arith.subi %a, %b : i32 
        cf.br ^bb3(%diff: i32)
        ^bb3(%res: i32):
        return %res : i32 
    }
    func.func @accumulate(%n: index) -> i32 {
        %c0 = arith.constant 0 : index
        %c1 = arith.constant 1 : index
        %c0_i32 = arith.constant 0 : i32 
        %result = scf.for %i = %c0 to %n step %c1 iter_args(%acc = %c0_i32) -> i32 {
            %i_i32 = arith.index_cast %i : index to i32 
            %new = arith.addi %acc, %i_i32 : i32 
            scf.yield %new : i32 
        }
        return %result : i32 
    }
}