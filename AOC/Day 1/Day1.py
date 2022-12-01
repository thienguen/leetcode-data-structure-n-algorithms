def main():
    INPUT = open('in1.txt').read()
    
    # - INPUT.split("\n\n") splits INPUT into a list of strings, 
    # --> each string separated by two newlines
    # - list(map(int, x.split())) converts each string into a list of integers, 
    # --> where each integer is a number in the string
    # - INPUT = [list(map(int, x.split())) for x in INPUT.split("\n\n")] 
    # --> is a list comprehension that converts each string into a list of integers and adds it to INPUT """
    
    INPUT = [list(map(int, x.split())) for x in INPUT.split("\n\n")]
    
    # print with a new line each time
    SORTED = sorted(map(sum, INPUT))
    
    print(INPUT, SORTED, sep="\n\n")

    print("Part 1: " + str(SORTED[-1]))
    print("Part 2: " + str(SORTED[-3:]) + " = " + str(sum(SORTED[-3:])))

if __name__ == "__main__":
    main()