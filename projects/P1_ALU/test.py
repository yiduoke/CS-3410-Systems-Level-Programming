import random

biggest_32_bit = 4294967295   # for B
biggest_5_bit = 31    # for Sa

def left_shift(B, Sa, Cin):
    binary_B = format(B,'032b') #pads the binary form of B with leading 0 so that it's 32 bits
    return binary_B[Sa:] + Sa * str(Cin)

def right_shift(B, Sa, Op):
    binary_B = format(B,'032b') #pads the binary form of B with leading 0 so that it's 32 bits
    Cin = '0'
    if (Op == 1):
        Cin = binary_B[0]
    return Sa * str(Cin) + binary_B[: 32-Sa]

def left_shift_test():
    f = open("left_shift_test.txt", "w")
    print("B[32]                            Sa[5] Cin C[32]")
    f.write("B[32]                            Sa[5] Cin C[32]\n")
    for i in range(50000):
        B = random.randint(0, biggest_32_bit)
        Sa = random.randint(0, biggest_5_bit)
        Cin = random.randint(0,1)
        C = left_shift(B, Sa, Cin)
        print(format(B,"032b") + " " + format(Sa,"05b") + " " + str(Cin) + "   " + C)
        f.write(format(B,"032b") + " " + format(Sa,"05b") + " " + str(Cin) + "   " + C + "\n")
    f.close()

def right_shift_test():
    f = open("right_shift_test.txt", "w")
    print("B[32]                            Sa[5] Op C[32]\n")
    f.write("B[32]                            Sa[5] Op C[32]\n")
    for i in range(50000):
        B = random.randint(0, biggest_32_bit)
        Sa = random.randint(0, biggest_5_bit)
        Op = random.randint(0,1)
        C = right_shift(B, Sa, Op)
        print(format(B,"032b") + " " + format(Sa,"05b") + " " + str(Op) + "   " + C)
        f.write(format(B,"032b") + " " + format(Sa,"05b") + " " + str(Op) + "  " + C + "\n")
    f.close()

left_shift_test()
right_shift_test()


