
def node_num(path):
    num = 1
    x = 1000000007
    for fork in path:
        if num % 2 == 0:
            # print("even")
            if fork == 'l':
                num = (2 * num - 1)%x
                # print("2x-1")
            elif fork == 'r':
                num = (2 * num + 1)%x
                # print("2x+1")
        else:
            # print("odd")
            if fork == 'l': 
                num = (2 * num)%x
                # print("2x")
            elif fork == 'r':
                num = (2 * num + 2)%x
                # print("2x+2")
    return num % x


def runner():
    cases = int(raw_input())
    paths = []
    for i in range(0, cases):
        print(node_num(raw_input()))
runner()