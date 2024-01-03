def edge(w1, w2):
    return sum([1 for i in range(len(w1)) if w2[i] == w1[i]]) == 2 or sorted(w1) == sorted(w2)

if __name__ == "__main__":
    vertices = ["now", "won", "eon", "own", "ton", "not", "tow", "cow", "cot", "con"]
    for v1 in vertices:
        for v2 in vertices:
            if edge(v1, v2):
                print(f"{v1} and {v2} are connected")
