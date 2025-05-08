'''
To create ADT that implement the "set" concept.
    a. Add (new Element) - Place a value into the set , 
    b. Remove (element) Remove the value
    c. Contains (element) Return true if element is in collection, 
    d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection, 
    e. Intersection of two sets , 
    f. Union of two sets, 
    g. Difference between two sets, 
    h. Subset
'''

class SetADT :
    def __init__(self) :
        self.data = []
    
    def add(self, element) :
        if element not in self.data :
            self.data.append(element)
        return self.data
    
    def delete(self,element) :
        if element in self.data :
            self.data.remove(element)
        else :
            print(f"{element} not found in the set.")
        return self.data
    
    def contains(self, element) :
        if element in self.data :
            return True
        else :
            return False
    
    def size(self) :
        return len(self.data)
    
    def iterator(self) :
        return iter(self.data)
    
    def intersection(self, other_set) :
        result = []
        for item in self.data :
            if item in other_set.data:
                result.append(item)
        return result
    
    def union(self, other_set) :
        result = []
        for item in other_set.data :
            if item not in result :
                result.append(item)
        
        for item in self.data :
            if item not in result :
                result.append(item)
        return result
    
    def difference(self , other_set) :
        result = []
        for item in self.data :
            if item not in other_set.data :
                result.append(item)
        return result
    
    def is_subset(self, other_set) :
        for item in other_set.data :
            if item not in self.data :
                return False
        return True
    
def main() :
    obj1 = SetADT()

    while(True) :
        print("\n1.Add new Element.")
        print("2.Remove element.")
        print("3.Find element.")
        print("4.Get size.")
        print("5.Intersection of two sets.")
        print("6.Union of two sets.")
        print("7.Difference of two sets.")
        print("8.Subset of a set.")
        print("9.Exit")
        choice = int(input("Select a valid choice : "))

        if(choice == 1) :
            x = int(input("\nEnter element to add : "))
            print(obj1.add(x))
        
        elif(choice == 2) :
            x = int(input("\nEnter element to delete : "))
            print(obj1.delete(x))
        
        elif(choice == 3) :
            x = int(input("\nEnter element to search in Set 1 : "))
            flag = obj1.contains(x)
            if( flag == True) :
                print("\nElement found in Set 1:)")
            else :
                print("\nElement not found in Set 1..!!")
        
        elif(choice == 4) :
            print("Size of Set 1 : ",obj1.size())
        
        elif(choice == 5) :
            n = int(input("\nEnter number of elements for set 2 : "))
            obj2 = SetADT()
            for i in range(n) :
                x = int(input("Enter element : "))
                obj2.add(x)
            print("Set 2 created.")

            print("Intersection:",obj1.intersection(obj2))
        
        elif(choice == 6) :
            n = int(input("\nEnter number of elements for set 2 : "))
            obj2 = SetADT()
            for i in range(n) :
                x = int(input("Enter element : "))
                obj2.add(x)
            print("Set 2 created.")

            print("Union:",obj1.union(obj2))
        
        elif(choice == 7) :
            n = int(input("\nEnter number of elements for set 2 : "))
            obj2 = SetADT()
            for i in range(n) :
                x = int(input("Enter element : "))
                obj2.add(x)
            print("Set 2 created.")

            print("Difference:",obj1.difference(obj2))
        
        elif(choice == 8) :
            n = int(input("\nEnter number of elements for set 2 : "))
            obj2 = SetADT()
            for i in range(n) :
                x = int(input("Enter element : "))
                obj2.add(x)
            print("Set 2 created.")

            print("Subet :",obj1.is_subset(obj2))
        
        elif(choice == 9) :
            print("\nProgram exited successfully... :)")
            break
        else :
            print("\nEntered Invalid option !!!!")
        

main()
