with open("./hw02_in04.txt", mode="w", encoding="utf-8") as f:
    lines = ["1", "2400"]
    for i in range(2400):
        lines.append("%04d %04d" % (i, i + 1))

    f.write("\n".join(lines))
