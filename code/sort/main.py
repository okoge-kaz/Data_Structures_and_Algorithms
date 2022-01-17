import time
import random


def selectionSort(Array: list[int]):
    '''selection sort'''
    arraySIZE: int = len(Array)

    for index in range(arraySIZE):
        min_idx: int = index
        for j in range(index + 1, arraySIZE):
            if Array[min_idx] > Array[j]:
                min_idx = j
        Array[index], Array[min_idx] = Array[min_idx], Array[index]


def insertionSort(Array: list[int]):
    '''insertion sort'''
    arraySIZE: int = len(Array)

    for index in range(1, arraySIZE):
        key: int = Array[index]
        j: int = index - 1
        while j >= 0 and key < Array[j]:
            Array[j + 1] = Array[j]
            j -= 1
        Array[j + 1] = key


def bubbleSort(Array: list[int]):
    '''bubble sort'''
    arraySIZE: int = len(Array)

    for index in range(arraySIZE):
        for j in range(arraySIZE - index - 1):
            if Array[j] > Array[j + 1]:
                Array[j], Array[j + 1] = Array[j + 1], Array[j]


def shellSort(Array: list[int]):
    '''shell sort'''
    arraySIZE: int = len(Array)

    h: int = arraySIZE // 2
    while h > 0:
        for index in range(h, arraySIZE):
            target: int = Array[index]
            j: int = index
            while j >= h and Array[j - h] > target:
                Array[j] = Array[j - h]
                j -= h
            Array[j] = target
        h = h // 2


def mergeSort(Array: list[int]):
    '''merge sort'''
    arraySIZE: int = len(Array)
    if arraySIZE > 1:
        mid: int = arraySIZE // 2
        L: list[int] = Array[:mid]
        R: list[int] = Array[mid:]
        mergeSort(L)
        mergeSort(R)
        i: int = 0
        j: int = 0
        k: int = 0

        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                Array[k] = L[i]
                i += 1
            else:
                Array[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            Array[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            Array[k] = R[j]
            j += 1
            k += 1


def quickSort(Array: list[int]):
    '''quick sort'''
    arraySIZE: int = len(Array)
    QuickSort(Array, 0, arraySIZE - 1)


def partition(arr, low, high):
    i = (low - 1)         # index of smaller element
    pivot = arr[high]     # pivot

    for j in range(low, high):

        # If current element is smaller than or
        # equal to pivot
        if arr[j] <= pivot:

            # increment index of smaller element
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return (i + 1)


def QuickSort(arr, low, high):
    if len(arr) == 1:
        return arr
    if low < high:

        # pi is partitioning index, arr[p] is now
        # at right place
        pi = partition(arr, low, high)

        # Separately sort elements before
        # partition and after partition
        QuickSort(arr, low, pi - 1)
        QuickSort(arr, pi + 1, high)


def timeMeasurer(sortName: str):
    N_SIZEs: list[int] = [10, 100, 1000, 10000, 100000]
    for N_SIZE in N_SIZEs:
        START = time.time()
        selfDefinedSort(sortName, N_SIZE)
        print(sortName + ": size = " + str(N_SIZE) + ", " + str((time.time() - START) / 10))


def selfDefinedSort(sortName: str, N_SIZE: int):
    # 10回繰り返す
    for cnt in range(10):
        targetArray: list[int] = [random.randint(0, 10000) for index in range(N_SIZE)]
        if sortName == "selection":
            selectionSort(targetArray)
        elif sortName == "insertion":
            insertionSort(targetArray)
        elif sortName == "bubble":
            bubbleSort(targetArray)
        elif sortName == "shell":
            shellSort(targetArray)
        elif sortName == "merge":
            mergeSort(targetArray)
        elif sortName == "quick":
            quickSort(targetArray)


def main():
    sortNames: list[str] = ["selection", "insertion", "bubble", "shell", "merge", "quick"]
    for sortName in sortNames:
        timeMeasurer(sortName)


if __name__ == '__main__':
    main()
