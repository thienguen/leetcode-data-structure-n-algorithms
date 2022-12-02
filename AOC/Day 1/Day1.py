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

@timed
def main():
    INPUT = open('in1.txt').read()
        
    INPUT = [list(map(int, x.split())) for x in INPUT.split("\n\n")]
    SORTING = sorted(map(sum, INPUT))

    # print with a new line each time
    for x in enumerate(INPUT):
        print(x)

    # Actual result
    print("\nPart 1: " + str(SORTING[-1]))
    print("Part 2: " + str(SORTING[-3:]) + " = " + str(sum(SORTING[-3:])))

if __name__ == "__main__":
    main()
