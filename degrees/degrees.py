import csv
import sys
from util import Node, StackFrontier, QueueFrontier
names = {} 
people = {} 
movies = {}
def load_data(directory):
    with open(f"{directory}/people.csv", encoding="utf-8") as f:
        reader = csv.DictReader(f)
        for row in reader:
            people[row["id"]] = {
                "name": row["name"],
                "birth": row["birth"],
                "movies": set() }
            names.setdefault(row["name"].lower(), set()).add(row["id"])
    with open(f"{directory}/movies.csv", encoding="utf-8") as f:
        reader = csv.DictReader(f)
        for row in reader:
            movies[row["id"]] = {
                "title": row["title"],
                "year": row["year"],
                "stars": set() }
    with open(f"{directory}/stars.csv", encoding="utf-8") as f:
        reader = csv.DictReader(f)
        for row in reader:
            try:
                people[row["person_id"]]["movies"].add(row["movie_id"])
                movies[row["movie_id"]]["stars"].add(row["person_id"])
            except KeyError:
                pass
def main():
    if len(sys.argv) > 2:
        sys.exit("Usage: python degrees.py [directory]")
    directory = sys.argv[1] if len(sys.argv) == 2 else "large"
    print("Loading data...")
    load_data(directory)
    print("Data loaded.")
    source = person_id_for_name(input("Name: "))
    if source is None:
        sys.exit("Person not found.")
    target = person_id_for_name(input("Name: "))
    if target is None:
        sys.exit("Person not found.")
    path = shortest_path(source, target)
    if path is None:
        print("Not connected.")
    else:
        degrees = len(path)
        print(f"{degrees} degrees of separation.")
        path = [(None, source)] + path
        for i in range(degrees):
            person1 = people[path[i][1]]["name"]
            person2 = people[path[i + 1][1]]["name"]
            movie = movies[path[i + 1][0]]["title"]
            print(f"{i + 1}: {person1} and {person2} starred in {movie}")
def shortest_path(source, target):
    num_explored = 0
    start = Node(source, None, None)
    frontier = QueueFrontier()
    frontier.add(start)
    explored = set()
    while True:
        if frontier.empty():
            return None
        node = frontier.remove()
        num_explored += 1
        if node.state == target:
            solution = []
            while node.parent is not None:
                solution.append((node.action, node.state))
                node = node.parent
            return sorted(solution)
        explored.add(node.state)
        for action, state in neighbors_for_person(node.state):
            if not frontier.contains_state(state) and state not in explored:
                child = Node(state=state, parent=node, action=action)
                frontier.add(child)
def person_id_for_name(name):
    person_ids = list(names.get(name.lower(), set()))
    if len(person_ids) == 0:
        raise ValueError("Person not found.")
    return person_ids[0]
def neighbors_for_person(person_id):
    movie_ids = people[person_id]["movies"]
    neighbors = set()
    for movie_id in movie_ids:
        for person_id in movies[movie_id]["stars"]:
            neighbors.add((movie_id, person_id))
    return neighbors
if __name__ == "__main__":
    main()