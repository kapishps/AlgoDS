
def main():
    t = int(raw_input())
    while(t > 0):
        t -= 1
        n,k = map(int, raw_input().split())

        if k == 1:
            if n%2 == 0:
                print("Bob")
            else:
                print("Alice")
            continue

        powk = [1]

        for i in range(1,63):
            powk.append(powk[i-1]*k)
            if powk[i] > 1e18:
                break

        c = 2
        while n >= 0:
            n -= powk[c/2]
            c += 1

        if c%2 == 0:
            print("Alice")
        else:
            print("Bob")


if __name__ == '__main__':
    main()