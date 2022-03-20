import os

RUNS = 10;

os.system("rm result.txt")
os.system("make clean")
os.system("make")
#file = open("result.txt")
median = [0.0, 0.0,0.0]
quickselect = [0.0, 0.0,0.0]
selectheap = [0.0, 0.0,0.0]
selectquick = [0.0, 0.0,0.0]
split_string = ["", "", ""]
for i in range(RUNS):
    os.system("make run")
    file = open("result.txt")
    string = file.readline()
    split_string = string.split(" ", -1)
    #print(split_string)
    median[0] = median[0] + float(split_string[0])
    median[1] = median[1] + float(split_string[1])
    median[2] = median[2] + float(split_string[2])

    quickselect[0] = quickselect[0] + float(split_string[3])
    quickselect[1] = quickselect[1] + float(split_string[4])
    quickselect[2] = quickselect[2] + float(split_string[5])

    selectheap[0] = selectheap[0] + float(split_string[8])
    selectheap[1] = selectheap[1] + float(split_string[7])
    selectheap[2] = selectheap[2] + float(split_string[8])

    selectquick[0] = selectquick[0] + float(split_string[9])
    selectquick[1] = selectquick[1] + float(split_string[10])
    selectquick[2] = selectquick[2] + float(split_string[11])

    file.close()

median[0] = median[0] / RUNS
median[1] = median[1] / RUNS
median[2] = median[2] / RUNS

quickselect[0] = quickselect[0] / RUNS
quickselect[1] = quickselect[1] / RUNS
quickselect[2] = quickselect[2] / RUNS

selectheap[0] = selectheap[0] / RUNS
selectheap[1] = selectheap[1] / RUNS
selectheap[2] = selectheap[2] / RUNS

selectquick[0] = selectquick[0] / RUNS
selectquick[1] = selectquick[1] / RUNS
selectquick[2] = selectquick[2] / RUNS

print("Medians of medians :" + median)
print("Quickselect :" + quickselect)
print("Select by heapsort :" + selectheap)
print("Select by quicksort :" + selectquick)
