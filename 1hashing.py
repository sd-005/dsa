class HashTable:
    def __init__(self):
        self.m = int(input("Enter the size of hashtable: "))
        self.hashtable = [None] * self.m
        self.elecount = 0
        self.comparison = 0
        print(self.hashtable)

    def hashfunction(self, key):
        return key % self.m

    def isfull(self):
        return self.elecount == self.m

    def insertvialinear(self, key, data):
        if self.isfull():
            print("Table is full")
            return False
        index = self.hashfunction(key)
        if self.hashtable[index] is None:
            self.hashtable[index] = [key, data]
            self.elecount += 1
            print("Element inserted at", index)
            print(self.hashtable)
        else:
            print("Collision occurred! Applying linear probing...")
            self.insertbylinearprob(key, data)

    def insertbylinearprob(self, key, data):
        index = self.hashfunction(key)
        compare = 0
        while self.hashtable[index] is not None:
            index = (index + 1) % self.m
            compare += 1
        self.hashtable[index] = [key, data]
        self.elecount += 1
        print("Data inserted at", index)
        print(self.hashtable)
        print("Number of comparisons =", compare)

    def searchbylinearprob(self, key, data):
        index = self.hashfunction(key)
        start = index
        while self.hashtable[index] is not None:
            if self.hashtable[index] == [key, data]:
                return index
            index = (index + 1) % self.m
            if index == start:
                break
        return None

    def insertviaquadratic(self, key, data):
        if self.isfull():
            print("Table is full")
            return False
        index = self.hashfunction(key)
        if self.hashtable[index] is None:
            self.hashtable[index] = [key, data]
            self.elecount += 1
            print("Element inserted at", index)
            print(self.hashtable)
        else:
            print("Collision occurred! Applying quadratic probing...")
            self.insertbyquadraticprob(key, data)

    def insertbyquadraticprob(self, key, data):
        index = self.hashfunction(key)
        compare = 0
        i = 1
        while self.hashtable[index] is not None:
            index = (index + i * i) % self.m
            compare += 1
            i += 1
        self.hashtable[index] = [key, data]
        self.elecount += 1
        print("Data inserted at", index)
        print(self.hashtable)
        print("Number of comparisons =", compare)

    def searchbyquadraticprob(self, key, data):
        index = self.hashfunction(key)
        i = 1
        start = index
        while self.hashtable[index] is not None:
            if self.hashtable[index] == [key, data]:
                return index
            index = (index + i * i) % self.m
            if index == start:
                break
            i += 1
        return None


def menu():
    obj = HashTable()  # One object only for both linear and quadratic
    ch = 0
    while ch != 3:
        print("\n******** MAIN MENU ********")
        print("1. Linear Probing")
        print("2. Quadratic Probing")
        print("3. Exit")
        ch = int(input("Enter your choice: "))

        if ch == 1:
            ch2 = 0
            while ch2 != 3:
                print("\n--- Linear Probing ---")
                print("1. Insert")
                print("2. Search")
                print("3. Back to Main Menu")
                ch2 = int(input("Enter your choice: "))
                if ch2 == 1:
                    a = int(input("Enter phone number (key): "))
                    b = input("Enter name (data): ")
                    obj.insertvialinear(a, b)
                elif ch2 == 2:
                    k = int(input("Enter key to search: "))
                    b = input("Enter name: ")
                    f = obj.searchbylinearprob(k, b)
                    if f is None:
                        print("Key not found")
                    else:
                        print("Key found at index", f)

        elif ch == 2:
            ch2 = 0
            while ch2 != 3:
                print("\n--- Quadratic Probing ---")
                print("1. Insert")
                print("2. Search")
                print("3. Back to Main Menu")
                ch2 = int(input("Enter your choice: "))
                if ch2 == 1:
                    a = int(input("Enter phone number (key): "))
                    b = input("Enter name (data): ")
                    obj.insertviaquadratic(a, b)
                elif ch2 == 2:
                    k = int(input("Enter key to search: "))
                    b = input("Enter name: ")
                    f = obj.searchbyquadraticprob(k, b)
                    if f is None:
                        print("Key not found")
                    else:
                        print("Key found at index", f)


# ✅ Call only once
menu()





















'''In hashing, the best case time complexity for insertion, search, and deletion operations is O(1). This happens when the hash function distributes keys uniformly and there are no collisions.

The average case time complexity is also O(1) when a good hash function is used and the load factor (number of elements divided by the table size) remains low.

However, in the worst case, time complexity can degrade to O(n). This occurs when many collisions happen and a poor collision resolution strategy (like probing through many elements) is used, or the hash table becomes nearly full.

The space complexity of a hash table is O(n), where n is the number of elements or slots in the table. This space is used to store keys, values, and manage probing sequences (in open addressing methods like linear or quadratic probing).

💡 Applications of Hashing
Hashing is used in a wide variety of real-world and computer science applications, including:

Hash tables and dictionaries: For storing and accessing key-value pairs efficiently.

Password storage: Passwords are stored in hashed format to enhance security.

Symbol tables: Used by compilers and interpreters to keep track of variable and function names.

Caching systems: Hashing is used in systems like DNS caching and web caching to retrieve data faster.

Database indexing: Hashing provides quick lookup for records in large datasets.'''
