import os

import sys

import typing

def format(filepath):
    # format file using clang-format
    if os.system("which clang-format > /dev/null") == 0:
        fps = lambda el, n: [el] * n
        os.system(
            (
                "clang-format "
                "{} "
                "-style=\"{{BasedOnStyle: llvm, IndentWidth: 4}}\" "
                "| tee {}.tmp > /dev/null"
            ).format(*fps(filepath, 2))
        )
        os.system(
            (
                "cat {}.tmp | tee {} > /dev/null"
            ).format(*fps(filepath, 2))
        )
        os.system(
            (
                "rm {}.tmp"
            ).format(filepath)
        )
    else:
        print("Note: clang-format isn't installed.")

def main(args) -> None:
    filenames: str = args[1:]

    for filename in filenames:
        count: int = 0
        void_start: Union[int, None] = None
        void_end: Union[int, None] = None

        lines: typing.List[str] = []

        format(filename)
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

        lines[void_start - 1] = "int main() {\n"
        lines.insert(void_end - 1, "\n")
        lines.insert(void_end, "    return 0;\n")
        
        filename = filename.split("/")[-1]
        filepath = "submission/" + filename
        with open(filepath, mode="w", encoding="utf-8") as file:
            file.writelines(lines)

        # format file using clang-format
        format(filepath)


if __name__ == "__main__":
    main(sys.argv)
