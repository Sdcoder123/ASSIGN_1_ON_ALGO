import pandas as pd
import matplotlib.pyplot as plt

uniform_df = pd.read_csv('C:/Users/HP/Downloads/ALGO Assignment 1/Question 9/mom uniform obs.csv')
normal_df = pd.read_csv('C:/Users/HP/Downloads/ALGO Assignment 1/Question 9/mom normal obs.csv')

n_uniform = uniform_df['arr_size'].to_numpy()
part_uniform = uniform_df['avg_partition_size'].to_numpy()

n_normal = normal_df['arr_size'].to_numpy()
part_normal = normal_df['avg_partition_size'].to_numpy()

plt.figure(figsize=(10,8))
plt.plot(n_uniform, part_uniform/n_uniform, '.', label='Uniform')
plt.plot(n_normal, part_normal/n_normal, '.', label='Normal')
plt.legend()
plt.xlabel('arr_size (n)')
plt.ylabel(r'$\frac{partitions}{n}$')
plt.title('Time vs Array Size in MoM with divide size 5')
plt.show()
#plt.savefig('observation3.png')