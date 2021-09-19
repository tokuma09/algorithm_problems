# %%
import subprocess
import sys

from networkx.algorithms.bipartite.basic import color
reqs = subprocess.check_output([sys.executable, '-m', 'pip', 'freeze'])
installed_packages = [r.decode().split('==')[0] for r in reqs.split()]
if not 'matplotlib' in installed_packages:
    subprocess.run('pip install matplotlib', shell=True)
import networkx as nx
import matplotlib.pyplot as plt

# %%
with open('/workspaces/algorithm_problems/input.txt', 'r') as f:
    r, c = map(int, f.readline().split())
    G = []
    for _ in range(r):
        G.append(f.readline())

# %%
ff = nx.DiGraph()
s, t = r*c*3, r*c*3 + 1 
num_blank, num_adjacent = 0, 0
for i in range(r):
    for j in range(c):
        if G[i][j] == '#':
            num_blank += 1
            v = i*c + j
            # if adjacent in row, cannot both 0
            if i+1 < r and G[i+1][j] == '#':
                num_adjacent += 1
                newv = v + r*c
                ff.add_edge(newv, t, capacity=1)
                ff.add_edge(v, newv, capacity=float('inf'))
                ff.add_edge(v+c, newv, capacity=float('inf'))
                
            # if adjacent in col, cannot both 1
            if j+1 < c and G[i][j+1] == '#':
                num_adjacent += 1
                newv = v + r*c*2
                ff.add_edge(s, newv, capacity=1)
                ff.add_edge(newv, v, capacity=float('inf'))
                ff.add_edge(newv, v+1, capacity=float('inf'))
# %%
edges = ff.edges()
nodes = sorted(list(ff.nodes()))
pos = {s:[1, 1], t:[1, 0]}
counter = 0
for v in nodes[0:len(nodes)-2]:
    counter = v % (r*c)
    pos[v] = [0.33*(v//(r*c)), 1/(r*c)*counter]

colors = ['g' if ff[u][v]['capacity'] == 1 else 'r' for u,v in edges]

nx.draw_networkx(ff, pos)
capacity = nx.get_edge_attributes(ff,'capacity')
nx.draw(ff, pos, edges=edges, edge_color=colors)
print('red if capacity is inf, green if capacity is 1')
plt.show()
print(f'num_blank:{num_blank}, num_adjacent:{num_adjacent}')


# %%
