import random, csv, sys



def generate_numbers(n_num, n_col):
    with open('csv/test_linked_list.csv', 'w', newline='') as file:
        writer = csv.writer(file, delimiter=';')

        headers = [f"column{i + 1}" for i in range(n_col)]
        writer.writerow(headers)

        for _ in range(n_num):
            row = [random.randint(0, 2**64 - 1) for _ in range(n_col)]  # Générer une ligne de nombres
            writer.writerow(row)



if __name__ == "__main__":
    generate_numbers(int(sys.argv[1]), int(sys.argv[2]))