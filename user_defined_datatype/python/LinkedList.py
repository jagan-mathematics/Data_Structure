class Node:
    def __init__(self, data, next_node=None):
        self.data = data
        self.next_node = next_node


class LinkedList:
    def __init__(self):
        self.head = None

    def push_back(self, data):
        if self.head is None:
            self.head = Node(data)
            return self.head

        if self.head.next_node is None:
            self.head.next_node = Node(data)
            return self.head

        temp = self.head
        while temp.next_node is not None:
            if temp.next_node.next_node is None:
                temp.next_node.next_node = Node(data)
                break
            temp = temp.next_node
        return self.head

    def push_front(self, data):
        if self.head is None:
            self.head = Node(data)
        else:
            self.head = Node(data, self.head)
        return self.head

    def insert_value(self, data, position):
        if self.head is None:
            if position == 1:
                self.head = Node(data)
            else:
                return
        if position == 1:
            self.push_front(data)
            return

        count = 0
        temp = self.head
        while temp.next_node is not None:
            count += 1
            if count == position - 1:
                temp.next_node = Node(data, temp.next_node)
                break
            temp = temp.next_node

    def pop(self):
        if self.head is None:
            return -1

        if self.head.next_node is None:
            value = self.head.data
            self.head = None
            return value

        current_node = self.head
        while current_node.next_node is not None:
            if current_node.next_node.next_node is None:
                temp = current_node.next_node
                current_node.next_node = None
                return temp.data
            current_node = current_node.next_node
        return -1

    def pop_front(self):
        if self.head is None:
            return -1

        temp = self.head
        self.head = self.head.next_node
        return temp.data

    def pop_data(self, data):
        if self.head is None:
            return

        if self.head.data == data:
            temp = self.head
            self.head = self.head.next_node
            return

        current_node = self.head
        while current_node.next_node is not None:
            if current_node.next_node.data == data:
                current_node.next_node = current_node.next_node.next_node
                break
            current_node = current_node.next_node
