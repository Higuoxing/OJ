graph = {
    "V1": [ "V2", "V3" ],
    "V2": [ "V1", "V4", "V5" ],
    "V3": [ "V1", "V6", "V7" ],
    "V4": [ "V2", "V8" ],
    "V5": [ "V2", "V8" ],
    "V6": [ "V3", "V7" ],
    "V7": [ "V3", "V6" ],
    "V8": [ "V4", "V5" ]
    }

def dfs(graph, s):
    visited = []
    stack = [s]
    while (stack != []):
        p = stack.pop(0)
        flag = 0
        for i in visited:
            if i == p:
                flag = 1
        if flag == 1:
            # has been visited
            pass
        else:
            # has not been visited
            print(p)
            visited.append(p)
            for i in graph[p]:
                stack.append(i)

dfs(graph, "V1")
