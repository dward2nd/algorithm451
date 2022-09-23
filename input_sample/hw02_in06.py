import random


with open("./hw02_in06.txt", mode="w", encoding="utf-8") as f:
    sample_line = []
    lines = []
    
    count = 0
    multiplier = 1
    while multiplier <= 2048:
        for i in range(0, 2048, multiplier):
            sample_line.append("%04d %04d" % (i, i + multiplier))

        count += 2048 // multiplier
        multiplier <<= 1

    random.shuffle(sample_line)
    lines.append("100")

    for i in range(100):
        lines.append(str(count))
        random.shuffle(sample_line)
        lines.extend(sample_line)

    f.write("\n".join(lines))
