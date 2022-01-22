import pandas as pd
import numpy as np
import math
import matplotlib.pyplot as plt

df = pd.read_csv('plot_data.csv')
sorted_df = df.sort_values(by=['arr_size'], ascending=True)

x = np.linspace(30, 1000, 100)
y = [i*math.log(i, 2) for i in x]

fig, axs = plt.subplots(figsize=(10, 8))
axs.plot(sorted_df.arr_size, sorted_df.n_comps, linewidth=3)
# axs.plot(x, y, linewidth=3)
axs.set_yticks([0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000])
axs.set_xticks([30, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000])
axs.set_yticklabels(['0', '1000', '2000', '3000', '4000', '5000', '6000', '7000', '8000', '9000', '10000'])
axs.set_xticklabels(['30', '100', '200', '300', '400', '500', '600', '700', '800', '900', '1000'])
axs.grid()
# plt.legend(['No. of comparisons in Heap Sort', 'nlogn(base=2)'], loc='lower right')
plt.xlabel('Size of array(n)', labelpad=10)
plt.ylabel('No. of comparisons', labelpad=10)
# plt.title('Heap Sort Graph compared with Graph of nlogn')
plt.title('Heap Sort Graph')

# plt.savefig('plot_compare_nlogn.png', dpi=275, bbox_inches='tight') # To save the plot
plt.savefig('plot.png', dpi=275, bbox_inches='tight') # To save the plot
plt.show()