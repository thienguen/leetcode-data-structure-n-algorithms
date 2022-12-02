import time

def timed(method):
    def wrapper_method(*arg, **kw):
        t = time.time()
        ret = method(*arg, **kw)
        print(
            "Method "
            + method.__name__
            + " took : "
            + "{:2.5f}".format(time.time() - t)
            + " sec"
        )
        return ret

    return wrapper_method

def playerChoiceToLose(computer, player):
    """
    X is 0 --> Lose
    Computer: 
    0 --> A, to lose we chose 2 --> Z
    1 --> B, to lose we chose 0 --> X
    2 --> C, to lose we chose 1 --> Y
    """
    if player == 0:  
        return (computer - 1) % 3
    """
    Z is 2 --> Win
    Computer:
    0 --> A, to win we chose 1 --> Y
    1 --> B, to win we chose 2 --> Z
    2 --> C, to win we chose 0 --> X
    """
    if player == 2:  
        return (computer + 1) % 3
    
    # Y is 1 --> Draw
    return computer


def result(computer, player):
    # X == A ; Y == B ; Z == C
    if computer == player:  
        return 3
    
    # X > C ; Y > A ; Z > B
    if (computer + 1) % 3 == player:  
        return 6
    
    # X < B ; Y < C ; Z < A
    return 0

# Rock Paper Scissors
RPS = {
    "A": 0,
    "B": 1,
    "C": 2,
    "X": 0,
    "Y": 1,
    "Z": 2,
}

scores = [1, 2, 3]

@timed
def main():
    score1 = 0
    score2 = 0
    
    with open("in2.txt") as file:
        for line in file:
            # Part 1
            computer, player = RPS[line[0]], RPS[line[2]]
            score1 += scores[player] + result(computer, player)

            # Part 2
            player = playerChoiceToLose(computer, player)
            score2 += scores[player] + result(computer, player)

    print(f"Total score Day2.py:  PART 1:  {score1}")
    print(f"Total score Day2.py:  PART 2:  {score2}")

if __name__ == "__main__":
    main()