maze = [
    ['S', 0, 0, 1, 0],
    [1, 0, 1, 0, 0],
    [0, 0, 0, 0, 'G'],
    [1, 1, 0, 1, 1]
]

rows = len(maze)
cols = len(maze[0])

def get_start_goal(maze):
    start = goal = None
    for r in range(rows):
        for c in range(cols):
            if maze[r][c] == 'S':
                start = (r, c)
            elif maze[r][c] == 'G':
                goal = (r, c)
    return start, goal

def get_neighbors(pos):
    r, c = pos
    neighbors = []
    for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
        nr, nc = r+dr, c+dc
        if 0 <= nr < rows and 0 <= nc < cols and maze[nr][nc] != 1:
            neighbors.append((nr,nc))
    return neighbors

def dfs_limited(start, goal, limit):
    stack = [(start, [start], 0)]
    while stack:
        node, path, depth = stack.pop()
        if node == goal:
            return path
        if depth < limit:
            for neighbor in reversed(get_neighbors(node)):
                if neighbor not in path:
                    stack.append((neighbor, path + [neighbor], depth + 1))
    return None

def iterative_deepening(start, goal):
    depth = 0
    while True:
        result = dfs_limited(start, goal, depth)
        if result:
            return result
        depth += 1

start, goal = get_start_goal(maze)

print("DFS with dpth limit 10:", dfs_limited(start, goal, 10))
print("Iterativ Deepening Search:", iterative_deepening(start, goal))

# 3 : 
# Iterative Deepening Search is more suitable because DFS with a depth limit may miss the goal if the limit is too low, 
# and standard DFS can get stuck exploring deep but unpromising paths. Iterative Deepening gradually increases the depth, 
# ensuring completness while keeping memory usage low, combining DFS's space eficiency and BFS's completness.