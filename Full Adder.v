

FullAdder( //a full adder module
    input a0,
    input b0,
    input cin,
    output c1,
    output s0
    );
    assign s0=(~a0 & ~b0 & cin) | (~a0 & b0 & ~cin) | (a0 & ~b0 & ~cin) | (a0 & b0 & cin);
    assign c1= (~a0 & b0 & cin) | (a0 & ~b0 & cin) | (a0 & b0 & ~cin) | (a0 & b0 & cin);
endmodule
