import os

import sys

import typing

def main(args) -> None:
    filenames: str = args[1:]

    for filename in filenames:
        count: int = 0
        void_start: Union[int, None] = None
        void_end: Union[int, None] = None

        lines: typing.List[str] = []

        with open(filename, mode="r") as file:
            for line in file:
                count += 1
                if void_start is None:
                    if line.startswith("void hw"):
                        void_start = count
                elif void_end is None:
                    if line.startswith("}"):
                        void_end = count

                lines.append(line)

        lines[void_start - 1] = "int main() {"
        lines.insert(void_end - 1, "\n")
        lines.insert(void_end, "    return 0;\n")
        
        filename = filename.split("/")[-1]
        with open("submission/" + filename, mode="w", encoding="utf-8") as file:
            file.writelines(lines)


if __name__ == "__main__":
    main(sys.argv)
