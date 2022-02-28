import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import matplotlib
from pandas.core.indexing import is_label_like

uniform_df = pd.read_csv('uniform_comparisons.txt')
normal_df = pd.read_csv('normal_comparisons.txt')
random_uniform_df = pd.read_csv('C:/Users/HP/Downloads/ALGO Assignment 1/Question 4/RQS uniform datasets_obs.txt')
random_normal_df = pd.read_csv('C:/Users/HP/Downloads/ALGO Assignment 1/Question 4/RQS normal datasets_obs.txt')

n_uniform = uniform_df['num'].to_numpy()
comp_uniform = uniform_df['avg_comp'].to_numpy()
time_uniform = uniform_df['avg_time'].to_numpy()
comp_ratio_uniform = comp_uniform/(n_uniform*np.log2(n_uniform))
time_ratio_uniform = time_uniform/(n_uniform*np.log2(n_uniform))

n_normal = normal_df['num'].to_numpy()
comp_normal = normal_df['avg_comp'].to_numpy()
time_normal = normal_df['avg_time'].to_numpy()
comp_ratio_normal = comp_normal/(n_normal*np.log2(n_normal))
time_ratio_normal = time_normal/(n_normal*np.log2(n_normal))

n_random_uniform = uniform_df['num'].to_numpy()
comp_random_uniform = uniform_df['avg_comp'].to_numpy()
time_random_uniform = uniform_df['avg_time'].to_numpy()
comp_ratio_random_uniform = comp_random_uniform/(n_random_uniform*np.log2(n_random_uniform))
time_ratio_random_uniform = time_random_uniform/(n_random_uniform*np.log2(n_random_uniform))

n_random_normal = normal_df['num'].to_numpy()
comp_random_normal = normal_df['avg_comp'].to_numpy()
time_random_normal = normal_df['avg_time'].to_numpy()
comp_ratio_random_normal = comp_random_normal/(n_random_normal*np.log2(n_random_normal))
time_ratio_random_normal = time_random_normal/(n_random_normal*np.log2(n_random_normal))

fig, axis = plt.subplots(2, 1, figsize=(10, 7))

fig.suptitle('Comparision and Time Ratio')

axis[0].plot(comp_ratio_uniform, 'o-', label='Uniform')
axis[0].plot(comp_ratio_random_uniform, 'o--', label='Random Uniform')
axis[0].plot(comp_ratio_normal, 'o-', label='Normal')
axis[0].plot(comp_ratio_random_normal, 'o--', label='Random Normal')
axis[0].legend()
axis[0].set_ylabel(r'$\frac{comp}{n*lgn}$', rotation=0, labelpad=13)

axis[1].plot(time_ratio_uniform, 'o-', label='Uniform')
axis[1].plot(time_ratio_random_uniform, 'o--', label='Random Uniform')
axis[1].plot(time_ratio_normal, 'o-', label = 'Normal')
axis[1].plot(time_ratio_random_normal, 'o--', label='Random Uniform')
axis[1].legend()
axis[1].set_ylabel(r'$\frac{time}{n*lgn}$', rotation=0, labelpad=13)

plt.xlabel(r'n [array size = $2^n$]')
plt.show()