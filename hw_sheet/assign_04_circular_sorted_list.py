"""
Note: return -1 means not found.
"""
import random
from typing import List, Sequence, Tuple

# ##########################################################################
# ############################# Solution Part ##############################
# ##########################################################################


def find_max_index(arr: Sequence[float], n: int, left: int, right: int) -> int:
    """
    According to the code,
    T_1(n) = T_1(n / 2) + O(1)

    Using Master's Theorem: T(n) = O(log n)  #
    """
    if n == 0:  # O(1)--base case (t_a)
        return -1

    if arr[right] >= arr[left]:  # O(1)--base case (t_a)
        return right
    # O(1) + O(1) = O(1)--base case (t_a)

    mid: int = (left + right) // 2  # O(1)--non-recursive (t_c)
    if arr[left] < arr[mid]:  # T_1(n / 2)--recursive call (t_b)
        return find_max_index(arr, n, mid, right)
    else:
        return find_max_index(arr, n, left, mid)


def find_in_circular(
    arr: Sequence[float],
    n: int,
    left: int,
    right: int,
    key: float,
    max_index: int,
) -> int:
    """
    According to the code,
    T_2(n) = T_2(n / 2) + O(1)

    Using Master's Theorem: T_2(n) = O(log n)  #
    """
    # O(1)--base case (t_a) + non-recursive (t_c)
    nleft: int = (left - max_index - 1) % n
    # O(1)--base case (t_a) + non-recursive (t_c)
    nright: int = (right - max_index - 1) % n
    # O(1)--base case (t_a) + non-recursive (t_c)
    mid: int = (max_index + (nleft + nright) // 2 + 1) % n

    if arr[mid] == key:  # O(1)--base case (t_a)
        return mid
    elif left == right:
        return -1

    if key < arr[mid]:  # T_2(n / 2)--recursive call (t_b)
        return find_in_circular(arr, n, left, mid, key, max_index)
    else:
        return find_in_circular(arr, n, (mid + 1) % n, right, key, max_index)


def circular_binary_search(
    arr: Sequence[float], n: int, key: float
) -> Tuple[int, int]:
    """
    According to the code,
    T(n) = T_1(n) + T_2(n)
         = O(log n) + O(log n)
         = O(log n)  #
    """
    max_index: int = find_max_index(arr, n, 0, n - 1)  # T_1(n) = O(log n)
    # T_2(n) = O(log n)
    key_index: int = find_in_circular(
        arr, n, (max_index + 1) % n, max_index, key, max_index
    )

    return max_index, key_index


# ######################################################################
# ############################# Testcases ##############################
# ######################################################################


def gen_testcase(n: int = 10) -> List[float]:
    ret: List[float] = sorted(random.sample(range(1, 100), n))
    max_index: int = random.sample(range(n), 1)[0]

    ret[:-max_index], ret[-max_index:] = ret[-max_index:], ret[:-max_index]
    return ret


def run_testcase(arr: Sequence[float], n: int) -> None:
    print("#" * 50)

    print("Target list: ", arr, ", n = ", n, sep="")

    key: float = random.sample(arr, 1)[0]
    print("Want to find the element with value ", key)

    max_index, key_index = circular_binary_search(arr, n, key)
    print("Found the maximum at index", max_index)
    print("Found key = ", key, " at index ", key_index, sep="")

    print()


def main() -> None:
    n: int = 10
    for _ in range(10):
        testcase: List[float] = gen_testcase(n)
        run_testcase(testcase, n)


if __name__ == "__main__":
    main()
