from queue import Queue

class Animal:
    def __init__(self):
        """
        Initializes the Animal class with two empty queues for dogs and cats and an order number counter.
        """
        self.dog, self.cat, self.order = Queue(), Queue(), 1

    def enque(self, a: str) -> int:
        """
        Enqueues a new animal (dog or cat) to the appropriate queue and returns the order number of the added animal.

        Args:
            a (str): A string indicating the type of animal to add ("dog" or "cat").

        Returns:
            int: The order number of the added animal.
        """
        queue = self.dog if a == "dog" else self.cat
        queue.put(self.order)
        self.order += 1
        return self.order - 1

    def dequeAny(self) -> int:
        """
        Dequeues the oldest animal (either a dog or a cat) from the queue and returns the order number of the dequeued animal.

        Returns:
            int: The order number of the dequeued animal.
        """
        if self.dog.empty(): return self.cat.get()
        if self.cat.empty(): return self.dog.get()
        return self.cat.get() if self.dog.queue[0] > self.cat.queue[0] else self.dog.get()

    def dequeDog(self) -> int:
        """
        Dequeues the oldest dog from the queue and returns the order number of the dequeued dog.

        Returns:
            int: The order number of the dequeued dog.

        Raises:
            SystemExit: If there are no dogs in the queue.
        """
        if self.dog.empty():
            print("There is no more dogs!")
            exit(0)
        return self.dog.get()

    def dequeCat(self) -> int:
        """
        Dequeues the oldest cat from the queue and returns the order number of the dequeued cat.

        Returns:
            int: The order number of the dequeued cat.

        Raises:
            SystemExit: If there are no cats in the queue.
        """
        if self.cat.empty():
            print("There is no more cats!")
            exit(0)
        return self.cat.get()

class AnimalShelter(Animal):
    def size(self) -> int:
        """
        Returns the number of animals in the queue.

        Returns:
            int: The total number of animals in the queue.
        """
        return self.dog.qsize() + self.cat.qsize()


def main():
    """
    Demonstrates the functionality of the AnimalShelter class.
    """
    animal_shelter = AnimalShelter()
    animal_shelter.enque("cat")
    animal_shelter.enque("dog")
    animal_shelter.enque("cat")
    animal_shelter.enque("dog")
    print(animal_shelter.dequeDog()) # prints 2
    print(animal_shelter.dequeCat()) # prints 1
    print(animal_shelter.dequeAny()) # prints 3

if __name__ == "__main__":
    main()