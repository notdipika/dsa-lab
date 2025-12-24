import math
from queue import PriorityQueue

graph = {
    'a': {'b': 2,'c': 6},
    'b': {'a': 3,'d': 2, 'f': 1},
    'c': {'b': 2,'d': 4,},
    'd': {'c': 5,'e': 3,'f': 1},
    'e': {'a': 2,'b': 3,'f': 4},
    'f': {'d': 1,'e': 4}
}

def init_graph(graph, start):
    key = dict()
    parent = dict()

    for vertex in graph.keys():
        key[vertex] = math.inf
        parent[vertex] = None
    
    key[start] = 0

    return key, parent

def prim(graph, start):
    key, parent = init_graph(graph, start)

    q = PriorityQueue()
    queue_items = []

    for vertex in graph.keys():
        q.put((key[vertex], vertex))
        queue_items.append(vertex)
    

    while not q.empty():
        _, temp = q.get()
        for neighbor in graph[temp].keys():
            weight = graph[temp][neighbor]
            if (neighbor in queue_items) and (weight < key[neighbor]):
                parent[neighbor] = temp
                key[neighbor] = weight
            
    return key, parent

s = 'a'
key, parent = prim(graph, s)

print(key)
print(parent)