import random
import matplotlib.pyplot as plt

def main():
    tosses = 1000
    number_of_tosses = [0]
    head_count = 0
    tail_count = 0
    heads = [0]
    tails = [0]

    for i in range(1, tosses + 1):
        choice = random.choice([0, 1])
        number_of_tosses.append(i)

        if choice == 1:
            head_count += 1
            heads.append(100 * (head_count / i))
            tails.append(100 * (tail_count / i))
        else:
            tail_count += 1
            heads.append(100 * (head_count / i))
            tails.append(100 * (tail_count / i))

    plt.figure(figsize=(6.0, 4.0))
    plt.plot(number_of_tosses, heads, tails)
    plt.ylabel("Numero de cara ou coroa")
    plt.xlabel("Jogadas")
    plt.show()



if __name__ == "__main__":
    main()