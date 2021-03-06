class LinkListNode:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkList:
    def __init__(self):
        self.head = None
        self.rear = None

    def insert_at_front(self, data):
        new_node = LinkListNode(data)
        if self.head is None:
            self.head = new_node
            self.rear = self.head
        else:
            new_node.next = self.head
            self.head = new_node

    def insert_at_rear(self, data):
        new_node = LinkListNode(data)
        if self.rear is None:
            self.head = self.rear = new_node
        else:
            self.rear.next = new_node
            self.rear = new_node

    def traverse_linklist(self):
        temp = self.head
        while(temp is not None):
            print(temp.data)
            temp = temp.next

    def find(self, data):
        temp = self.head
        while(temp is not None and temp.data != data):
            temp = temp.next

        return temp

    def return_list(self):
      temp = self.head
      lst = []
      while(temp is not None):
        lst.append(temp.data)
        temp = temp.next

      return lst


