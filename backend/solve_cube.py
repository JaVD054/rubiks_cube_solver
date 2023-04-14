import kociemba


def format_solution(solution):
    solution = solution.replace("U'", 'u')
    solution = solution.replace("D'", 'd')
    solution = solution.replace("F'", 'f')
    solution = solution.replace("B'", 'b')
    solution = solution.replace("R'", 'r')
    solution = solution.replace("L'", 'l')
    solution = solution.replace("U2", 'u u')
    solution = solution.replace("D2", 'd d')
    solution = solution.replace("F2", 'f f')
    solution = solution.replace("B2", 'b b')
    solution = solution.replace("R2", 'r r')
    solution = solution.replace("L2", 'l l')
    solution = solution.replace(" ", '')
    return solution

def solve(cubestring):
    return format_solution(kociemba.solve(cubestring)).encode()
