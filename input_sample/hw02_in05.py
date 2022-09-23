with open("./hw02_in05.txt", mode="w", encoding="utf-8") as f:
    f.write("1\n")
    f.write("4095\n")

    count = 0
    multiplier = 1
    while multiplier <= 2048:
        for i in range(0, 2048, multiplier):
            f.write("%04d %04d\n" % (i, i + multiplier))

        count += 2048 // multiplier
        multiplier <<= 1

