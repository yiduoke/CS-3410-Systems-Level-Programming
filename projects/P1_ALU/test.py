import random

biggest_32_bit = 4294967295   # for B
biggest_5_bit = 31    # for Sa

biggest_32_signed = 2147483647
smallest_32_signed = -2147483648

def left_shift(B, Sa, Cin):
    binary_B = format(B,'032b') #pads the binary form of B with leading 0 so that it's 32 bits
    return binary_B[Sa:] + Sa * str(Cin)

def right_shift(B, Sa, Op):
    binary_B = format(B,'032b') #pads the binary form of B with leading 0 so that it's 32 bits
    Cin = '0'
    if (Op == 1):
        Cin = binary_B[0]
    return Sa * str(Cin) + binary_B[: 32-Sa]

def formatted(x):
    return format(x if x >= 0 else (1 << 32) + x, "032b")

def ne(A, B):
    if (A != B):
        return "00000000000000000000000000000001"
    return "00000000000000000000000000000000"

def eq(A, B):
    if (A == B):
        return "00000000000000000000000000000001"
    return "00000000000000000000000000000000"

def le(A, B):
    if (A <= B):
        return "00000000000000000000000000000001"
    return "00000000000000000000000000000000"

def gt(A, B):
    if (A > B):
        return "00000000000000000000000000000001"
    return "00000000000000000000000000000000"


def left_shift_test():
    f = open("left_shift_test.txt", "w")
    f.write("B[32]                            Sa[5] Cin C[32]\n")
    for i in range(500):
        B = random.randint(0, biggest_32_bit)
        Sa = random.randint(0, biggest_5_bit)
        Cin = random.randint(0,1)
        C = left_shift(B, Sa, Cin)
        f.write(format(B,"032b") + " " + format(Sa,"05b") + " " + str(Cin) + "   " + C + "\n")
    f.close()

def right_shift_test():
    f = open("right_shift_test.txt", "w")
    f.write("B[32]                            Sa[5] Op C[32]\n")
    for i in range(500):
        B = random.randint(0, biggest_32_bit)
        Sa = random.randint(0, biggest_5_bit)
        Op = random.randint(0,1)
        C = right_shift(B, Sa, Op)
        f.write(format(B,"032b") + " " + format(Sa,"05b") + " " + str(Op) + "  " + C + "\n")
    f.close()

def adder_test():
    f = open("adder.txt", "w")
    f.write("A[32]                            B[32]                            Cin C[32]                            V\n")
    for i in range(500):
        A = random.randint(smallest_32_signed, biggest_32_signed)
        B = random.randint(smallest_32_signed, biggest_32_signed)
        Cin = random.randint(0,1)
        result = A+B+Cin
        C = format(result if result >= 0 else (1 << 32) + result, "032b")
        V = 0
        
        formatted_A = format(A if A >= 0 else (1 << 32) + A, "032b")
        formatted_B = format(B if B >= 0 else (1 << 32) + B, "032b")
        
        if ((formatted_A[0] == formatted_B[0]) and (C[0] != formatted_B[0])):
            V = 1
        f.write(formatted_A + " " + formatted_B + " " + str(Cin) + "   " + C + " " + str(V) + "\n")
    f.close()

def subtracter_test():
    f = open("subtracter.txt", "w")
    f.write("A[32]                            B[32]                            C[32]                            V\n")
    for i in range(500):
        A = random.randint(smallest_32_signed, biggest_32_signed)
        B = random.randint(smallest_32_signed, biggest_32_signed)
        result = A - B
        C = format(result if result >= 0 else (1 << 32) + result, "032b")
        V = 0
        
        # overflow during addition only happens when both numbers are of the same sign,
        # which means different signs during subtraction because subtraction is just addition
        # with the second number negated
        formatted_A = format(A if A >= 0 else (1 << 32) + A, "032b")
        formatted_B = format(B if B >= 0 else (1 << 32) + B, "032b")
        
        if ((formatted_A[0] != formatted_B[0]) and (C[0] == formatted_B[0])):
            V = 1
        f.write(formatted_A + " " + formatted_B + " " + C + " " + str(V) + "\n")
    f.close()

def less_test():
    f = open("less.txt", "w")
    f.write("A[32]          B[32]         C\n")
    
    for i in range(500):
        A = random.randint(smallest_32_signed, biggest_32_signed)
        B = random.randint(smallest_32_signed, biggest_32_signed)
        C = 0
        if (A < B):
            C = 1
        f.write(str(A) + "    " + str(B) + "    " + str(C) + "\n")
        f.write(str(A) + "    " + str(A) + "    " + str(0) + "\n")
    f.close()

def greater_test():
    f = open("greater.txt", "w")
    f.write("A[32]          B[32]         C\n")
    
    for i in range(500):
        A = random.randint(smallest_32_signed, biggest_32_signed)
        B = random.randint(smallest_32_signed, biggest_32_signed)
        C = 0
        if (A > B):
            C = 1
        f.write(str(A) + "    " + str(B) + "    " + str(C) + "\n")
        f.write(str(A) + "    " + str(A) + "    " + str(0) + "\n")
    f.close()

def equal_test():
    f = open("equal.txt", "w")
    f.write("A[32]          B[32]         C\n")
    
    for i in range(500):
        A = random.randint(smallest_32_signed, biggest_32_signed)
        B = random.randint(smallest_32_signed, biggest_32_signed)
        C = 0
        if (A == B):
            C = 1
        
        f.write(str(A) + "    " + str(B) + "    " + str(C) + "\n")
    
        f.write(str(A) + "    " + str(A) + "    " + str(1) + "\n")
    f.close()

def ALU_test():
    f = open("ALU.txt", "w")
    f.write("A[32]                            B[32]                            Sa[5] Op[4] C[32]                            V\n")
    
    # and
    Op = "0000"
    for i in range(500):
        A = random.randint(0, biggest_32_bit)
        B = random.randint(0, biggest_32_bit)
        C = A&B
        Sa = random.randint(0, biggest_5_bit)
        print(str(A) + "    " + str(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x")
        f.write(str(A) + "    " + str(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x" + "\n")

    #or
    Op = "0001"
    for i in range(500):
        A = random.randint(0, biggest_32_bit)
        B = random.randint(0, biggest_32_bit)
        C = A|B
        Sa = random.randint(0, biggest_5_bit)
        print(str(A) + "    " + str(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x")
        f.write(str(A) + "    " + str(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x" + "\n")

    #shift left logical
    Op = "001x"
    for i in range(500):
        B = random.randint(0, biggest_32_bit)
        Sa = random.randint(0, biggest_5_bit)
        Cin = 0
        C = left_shift(B, Sa, Cin)
        print(str(A) + "    " + str(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x")
        f.write(str(A) + "    " + str(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x" + "\n")

    #XOR
    Op = "0100"
    for i in range(500):
        A = random.randint(0, biggest_32_bit)
        B = random.randint(0, biggest_32_bit)
        C = A^B
        print(str(A) + "    " + str(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x")
        f.write(str(A) + "    " + str(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x" + "\n")
    #NOR
    Op = "0101"
    for i in range(500):
        A = random.randint(0, biggest_32_bit)
        B = random.randint(0, biggest_32_bit)
        C = ~(A|B)
        print(str(A) + "    " + str(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x")
        f.write(str(A) + "    " + str(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x" + "\n")

    #shift left logical
    Op = "0110"
    for i in range(500):
        B = random.randint(0, biggest_32_bit)
        Sa = random.randint(0, biggest_5_bit)
        Cin = 0
        C = right_shift(B, Sa, Cin)
        print(str(A) + "    " + str(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x")
        f.write(str(A) + "    " + str(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x" + "\n")

    #shift left arithmetic
    Op = "0111"
    for i in range(500):
        B = random.randint(0, biggest_32_bit)
        Sa = random.randint(0, biggest_5_bit)
        Cin = 1
        C = right_shift(B, Sa, Cin)
        print(str(A) + "    " + str(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x")
        f.write(str(A) + "    " + str(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x" + "\n")

    # ne
    Op = "1000"
    for i in range(500):
        A = random.randint(0, biggest_32_bit)
        B = random.randint(0, biggest_32_bit)
        C = ne(A,B)
        Sa = random.randint(0, biggest_5_bit)
        print(formatted(A) + "    " + formatted(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x")
        f.write(formatted(A) + "    " + formatted(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x" + "\n")
        
        B = A
        C = ne(A,B)
        f.write(formatted(A) + "    " + formatted(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x" + "\n")

    # eq
    Op = "1001"
    for i in range(500):
        A = random.randint(0, biggest_32_bit)
        B = random.randint(0, biggest_32_bit)
        C = eq(A,B)
        Sa = random.randint(0, biggest_5_bit)
        print(formatted(A) + "    " + formatted(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x")
        
        B = A
        C = eq(A,B)
        f.write(formatted(A) + "    " + formatted(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x" + "\n")

    # le
    Op = "1010"
    for i in range(500):
        A = random.randint(0, biggest_32_bit)
        B = random.randint(0, biggest_32_bit)
        C = le(A,B)
        Sa = random.randint(0, biggest_5_bit)
        print(formatted(A) + "    " + formatted(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x")
        
        B = A
        C = le(A,B)
        f.write(formatted(A) + "    " + formatted(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x" + "\n")

    # gt
    Op = "1011"
    for i in range(500):
        A = random.randint(0, biggest_32_bit)
        B = random.randint(0, biggest_32_bit)
        C = gt(A,B)
        Sa = random.randint(0, biggest_5_bit)
        print(formatted(A) + "    " + formatted(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x")
        
        B = A
        C = gt(A,B)
        f.write(formatted(A) + "    " + formatted(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " x" + "\n")

    # subtract
    Op = "110x"
    for i in range(500):
        A = random.randint(smallest_32_signed, biggest_32_signed)
        B = random.randint(smallest_32_signed, biggest_32_signed)
        result = A - B
        C = format(result if result >= 0 else (1 << 32) + result, "032b")
        Sa = random.randint(0, biggest_5_bit)
        V = 0
        
        # overflow during addition only happens when both numbers are of the same sign,
        # which means different signs during subtraction because subtraction is just addition
        # with the second number negated
        formatted_A = format(A if A >= 0 else (1 << 32) + A, "032b")
        formatted_B = format(B if B >= 0 else (1 << 32) + B, "032b")
        
        if ((formatted_A[0] != formatted_B[0]) and (C[0] == formatted_B[0])):
            V = 1
        f.write(formatted(A) + "    " + formatted(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " " + str(V) + "\n")

    # add
    Op = "111x"
    for i in range(500):
        A = random.randint(smallest_32_signed, biggest_32_signed)
        B = random.randint(smallest_32_signed, biggest_32_signed)
        result = A+B
        C = format(result if result >= 0 else (1 << 32) + result, "032b")
        V = 0
        
        formatted_A = format(A if A >= 0 else (1 << 32) + A, "032b")
        formatted_B = format(B if B >= 0 else (1 << 32) + B, "032b")
        
        if ((formatted_A[0] == formatted_B[0]) and (C[0] != formatted_B[0])):
            V = 1
        f.write(formatted(A) + "    " + formatted(B) + "    " + str(Sa) + " " + str(Op) + " " + str(C) + " " + str(V) + "\n")
    f.close()

left_shift_test()
right_shift_test()
adder_test()
subtracter_test()
less_test()
greater_test()
equal_test()
ALU_test()
