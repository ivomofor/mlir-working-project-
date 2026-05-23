module {
    func.func @add(%a: i32, %b: i32 ) -> i32 {
        %sum = arith.addi %a, %b : i32 
        return %sum : i32 
    }


    func.func @double_add(%a: i32, %b: i32 ) -> i32 {
        %sum = arith.addi %a,%b : i32 
        %c2 = arith.constant 2 : i32 
        %result = arith.muli %sum, %c2 : i32 
        return %result : i32 
    }
}