class Node:
    def __init__(self, data, next_node=None, prev_node=None):
        self.data = data
        self.next_node = next_node
        self.prev_node = prev_node


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def push_back(self, data):
        if self.head is None:
            self.head = Node(data)
            self.tail = self.head
            return self.head
        
        # x <-> y <-> None
        temp = Node(data, None, self.tail)
        self.tail.next_node = temp
        self.tail = temp
        return self.head

    def push_front(self, data):
        if self.head is None:
            self.head = Node(data)
            self.tail = self.head
        else:
            temp = Node(data, self.head)
            self.head.prev_node = temp
            self.head = temp
        return self.head

    def pop_front(self):
        if self.head is None:
            return -1

        # a <-> b <-> c <-> d <-> None
        temp = self.head
        self.head = self.head.next_node
        if self.head is not None:
            self.head.prev_node = None
        else:
            self.tail = None
        value = temp.data
        del temp  # Automatically handled by Python's garbage collector
        return value

    def pop(self):
        if self.head is None:
            return -1

        if self.head.next_node is None:
            val = self.head.data
            self.head = None
            self.tail = None
            return val
        
        # a <-> b <-> c <-> d <-> None
        temp = self.tail
        self.tail = self.tail.prev_node
        if self.tail is not None:
            self.tail.next_node = None
        else:
            self.head = None
        value = temp.data
        del temp
        return value

    def pop_at(self, position):
        if self.head is None:
            return -1

        # a <-> b <-> c <-> d <-> None
        count = 1
        temp = self.head
        while temp is not None and count < position:
            temp = temp.next_node
            count += 1

        if temp is None:
            return -1
        
        back_node = temp.prev_node
        front_node = temp.next_node
        val = temp.data

        if front_node is not None and back_node is not None:
            back_node.next_node = front_node
            front_node.prev_node = back_node
        elif front_node is None and back_node is None:
            self.head = None
            self.tail = None
        elif back_node is None:
            # We're at the head
            self.pop_front()
        else:
            # We're at the tail
            self.pop()

        del temp
        return val

    def insert_value(self, value, position):
        if position == 1:
            self.push_front(value)
            return

        # a <-> b <-> c <-> d <-> None
        count = 1
        temp = self.head
        while temp is not None and count < position:
            temp = temp.next_node
            count += 1

        if temp is None:
            if count == position:
                self.push_back(value)
            return
        
        back_node = temp.prev_node
        new_node = Node(value, temp, back_node)
        back_node.next_node = new_node
        temp.prev_node = new_node
