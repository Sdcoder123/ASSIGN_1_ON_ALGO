import numpy as np  # for arrays
import csv  # for reading .csv files
import matplotlib.pyplot as plt  # for plotting

no_elements = int(10e6)
max_value = int(100)

# .csv has 10e6 values, so defining 10e6 value array
random_numbers = np.zeros(no_elements)

with open('normal_distribution.csv') as csv_file:  # while .csv file is open
    csv_reader = csv.reader(csv_file, delimiter=',')  # define .csv file reader
    line_count = 0  # linecount made as index of array
    for row in csv_reader:  # parse through every lines
        # first value of every line is the random number
        random_numbers[line_count] = row[0]
        line_count = line_count + 1
    print(f"Processed {line_count} lines.")

plt.figure("Histogram of Normal Distribution Dataset")
plt.title("Histogram of Normal Distribution Dataset")
plt.xlabel("Number")
plt.ylabel("No. of Occurrence")
plt.hist(random_numbers, bins=range(max_value + 1)) # 101 as between 0-100, there are 101 ranges
plt.show()