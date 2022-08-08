# 204451: Algorithm Analysis

This mini-project uses **Cmake** to compile the source code. In case you haven't 
installed Cmake, I recommend that you search for the instruction to install it 
on Google.

## To run

*I assume you are using a Unix-compliance OS, like Linux or macOS. If not, for 
example, you are running on Windows instead, then I don't know.*

Execute

```bash
make all
```

then you will see a new file `algorithm451.out`, an executable file.

Next, run 

```bash
./algorithm451.out
```

You will see a prompt that asks you to input a specific choice (in other words, 
a character) to choose what to run.

```
==========
[1] HW01 - Card
[2] HW02 - Station
[3] HW03 - Polynomial
[4] HW04 - Stack
[5] HW05 - Parentheses
[6] HW06 - Ranking
[7] HW07 - Bandwidth Management
[8] HW08 - BST
[a] test1 - 2d-pointer-based array
[b] test2 - Infix to Postfix
==========
Homework number: █
```

*Note: this is not the real output. I copied from the old project that has a 
similar prompt like this one.*

For example, if you want to run HW01, then input `1` (it is between `[` and
`]`) and enter. It will then bring you to **HW01**.

## To run with input sample text file

```bash
echo "hw_no "$(cat input_sample/filename.txt) | ./algorithm451.out
```

For example,

```bash
echo "2 "$(cat input_sample/hw02_in02.txt) | ./algorithm451.out
```

In this case, `hw_no` is 2

The output 

## To submit to the grader

If you take a look carefully in the homework files, you will notice that 
there are no main funcions (those declared using `int main()`). This 
is because of the compilation convenience. However, I already made a solution 
for such a problem.

Go to the root directory of this project, and run 

```bash
python make_submission_file.py src/*.cpp
```


