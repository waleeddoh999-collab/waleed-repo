from pyamaze import maze, agent
import numpy as np
import random


class MazeSolver:
    def __init__(self, lr, gamma, start, end, M, epochs):

        self.lr = lr
        self.gamma = gamma
        self.epochs = epochs

        self.maze = M
        self.start = start
        self.end = end

        self.actions = ['E', 'W', 'N', 'S']
        self.states = list(self.maze.maze_map.keys())

        # Q-table: dict of dict (VERY STABLE)
        self.q_table = {
            state: {a: 0 for a in self.actions}
            for state in self.states
        }

    # ---------------- ACTION CHECK ----------------
    def valid_actions(self, state):
        return [a for a, v in self.maze.maze_map[state].items() if v == 1]

    # ---------------- NEXT STATE ----------------
    def move(self, state, action):
        r, c = state

        if action == 'E':
            return (r, c + 1)
        if action == 'W':
            return (r, c - 1)
        if action == 'N':
            return (r - 1, c)
        if action == 'S':
            return (r + 1, c)

    # ---------------- TRAIN ----------------
    def train(self):

        for ep in range(self.epochs):

            state = self.start
            steps = 0

            while state != self.end:

                steps += 1

                actions = self.valid_actions(state)
                action = random.choice(actions)

                next_state = self.move(state, action)

                reward = 1 if next_state == self.end else 0

                old_q = self.q_table[state][action]
                max_next = max(self.q_table[next_state].values())

                # Q-learning update
                self.q_table[state][action] = old_q + self.lr * (
                    reward + self.gamma * max_next - old_q
                )

                state = next_state

            print(f"Epoch {ep+1}: {steps} steps")

    # ---------------- BEST PATH ----------------
    def path_finder(self):

        state = self.start
        path = [state]

        visited = set()

        while state != self.end:

            visited.add(state)

            action = max(self.q_table[state], key=self.q_table[state].get)
            next_state = self.move(state, action)

            if next_state in visited:
                break

            path.append(next_state)
            state = next_state

        return path


# ---------------- MAIN ----------------
if __name__ == "__main__":

    lr = 0.6
    gamma = 0.7
    epochs = 15

    start = (1, 1)
    end = (5, 5)

    m = maze(5, 5)
    m.CreateMaze(x=end[0], y=end[1], loopPercent=100)

    solver = MazeSolver(lr, gamma, start, end, m, epochs)

    solver.train()

    path = solver.path_finder()
    print("PATH:", path)

    a = agent(m, x=start[0], y=start[1], footprints=True)
    m.tracePath({a: path})
    m.run()