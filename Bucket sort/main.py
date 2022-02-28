import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import matplotlib
from pandas.core.indexing import is_label_like

uniform_df = pd.read_csv('C:/Users/HP/Downloads/ALGO Assignment 1/Question 5&6/Bucket sort/bucket_uniform_obs.csv')
normal_df = pd.read_csv('C:/Users/HP/Downloads/ALGO Assignment 1/Question 5&6/Bucket sort/bucket_normal_obs.csv')

n_uniform = uniform_df['num'].to_numpy()
comp_uniform = uniform_df['avg_comp'].to_numpy()
time_uniform = uniform_df['avg_time'].to_numpy()
comp_ratio_uniform = comp_uniform/(n_uniform)
time_ratio_uniform = time_uniform/(n_uniform)

n_normal = normal_df['num'].to_numpy()
comp_normal = normal_df['avg_comp'].to_numpy()
time_normal = normal_df['avg_time'].to_numpy()
comp_ratio_normal = comp_normal/(n_normal)
time_ratio_normal = time_normal/(n_normal)

x_axis = range(1,18)

plt.figure(figsize = (9,8))
plt.title('Comparision and Time Ratio')

plt.plot(x_axis,time_ratio_uniform, 'o-', label='Uniform')
plt.plot(x_axis,time_ratio_normal, 'o-', label = 'Normal')
plt.legend()
plt.ylabel(r'$\frac{time}{arr size}$', rotation=0, labelpad=13)

plt.xlabel(r'n [array size = $2^n$]')
plt.show()