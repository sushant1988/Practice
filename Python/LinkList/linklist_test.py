import unittest
from linklist import LinkList

class LinkListTest(unittest.TestCase):
  def setUp(self) -> LinkList:
    return LinkList()

  def create_linklist_from_list(self, lst: list, add_front: bool):
    link: LinkList = self.setUp()
    if add_front:
      for z in lst: link.insert_at_front(z)
    else:
      for z in lst: link.insert_at_rear(z)

    return link

  def test_fn_insert_at_front(self):
    items: list = [2, 3, 4]
    link = self.create_linklist_from_list(items, True)

    lst: list = link.to_list()
    self.assertEqual(len(lst), len(items))
    self.assertEqual(lst, items[::-1])

  def test_fn_insert_at_rear(self):
    items: list = [2, 3, 4]
    link = self.create_linklist_from_list(items, False)

    lst: list = LinkList.to_list(link) # test class method
    self.assertEqual(len(lst), len(items))
    self.assertEqual(lst, items)

  def test_fn_mth_from_last(self):
    items: list = [1, 2, 3, 4, 5, 6]
    link = self.create_linklist_from_list(items, False)

    self.assertEqual(link.find_mth_from_last_element(3), 4)
    self.assertEqual(link.find_mth_from_last_element(2), 5)
    self.assertEqual(link.find_mth_from_last_element(6), 1)
    self.assertEqual(link.find_mth_from_last_element(7), None)

  def test_fn_recursive_linklist(self):
    items: list = [1, 2, 3, 4, 5, 6]
    link = self.create_linklist_from_list(items, True)

    hd = LinkList.reverse_recursive_linklist(link.head)
    lst = []
    while(hd is not None):
      lst.append(hd.data)
      hd = hd.next

    self.assertEqual(len(lst), len(items))
    self.assertEqual(lst, items)

  def test_fn_iterative_linklist(self):
    items: list = [1, 2, 3, 4, 5, 6]
    link = self.create_linklist_from_list(items, True)

    link.reverse_iterative_linklist()
    lst: list = link.to_list()
    self.assertEqual(len(lst), len(items))
    self.assertEqual(lst, items)

  def test_fn_is_circular_list(self):
    items: list = [1, 2, 3, 4, 5, 6]
    link = self.create_linklist_from_list(items, True)

    self.assertEqual(link.is_circular_list(), False)
    link.rear.next = link.head
    self.assertEqual(link.is_circular_list(), True)

  def test_fn_partition_linklist(self):
    items: list = [3, 5, 1, 9, 6, 2, 10, 7, 4]
    link = self.create_linklist_from_list(items, False)

    link.partition_linklist(5)
    lst: list = link.to_list()
    self.assertEqual(lst, [4, 2, 1, 3, 5, 9, 6, 10, 7])

  def test_fn_is_palindrom_linklist(self):
    items1: list = [1, 2, 3, 2, 1]
    link1: LinkList = self.create_linklist_from_list(items1, False)

    items2: list = [1, 2, 2, 1]
    link2: LinkList = self.create_linklist_from_list(items2, False)

    items3: list = [1, 2, 1, 3]
    link3: LinkList = self.create_linklist_from_list(items3, False)

    self.assertEqual(link1.is_palindrome(), True)
    self.assertEqual(link2.is_palindrome(), True)
    self.assertEqual(link3.is_palindrome(), False)
    pass

  def test_fn_find_intersection(self):
    items1: list = [10, 11, 13, 4, 5, 6, 7, 8, 9]
    link1: LinkList = self.create_linklist_from_list(items1, False)

    items2: list = [1, 2, 3]
    link2: LinkList = self.create_linklist_from_list(items2, False)

    target_link = link1.find(5)
    link2.rear.next = target_link
    self.assertEqual(LinkList.find_intersection(link1, link2), target_link)

    target_link = link1.find(8)
    link2.rear.next = target_link
    self.assertEqual(LinkList.find_intersection(link1, link2), target_link)

    target_link = link1.find(3)
    link2.rear.next = target_link
    self.assertEqual(LinkList.find_intersection(link1, link2), target_link)

  def test_fn_add_linklist(self):
    items1: list = [2, 4, 5, 7]
    link1: LinkList = self.create_linklist_from_list(items1, False)
    items2: list = [1, 2, 3]
    link2: LinkList = self.create_linklist_from_list(items2, False)

    link3: LinkList = LinkList.add_two_linklist(link1, link2)
    self.assertEqual(link3.to_list(), [2, 5, 8, 0])

  def test_fn_add_linklist_variable(self):
    # differen in length 1
    items1: list = [2, 4, 5, 7]
    link1: LinkList = self.create_linklist_from_list(items1, False)
    items2: list = [1, 2, 3]
    link2: LinkList = self.create_linklist_from_list(items2, False)

    link_node1: LinkListNode = LinkList.add_two_linklist_variable(link1, link2)
    self.assertEqual(link_node1.to_list(), [2, 5, 8, 0])

    # difference in length 3
    items3: list = [9, 9, 8, 5]
    link3: LinkList = self.create_linklist_from_list(items3, False)
    items4: list = [1, 5]
    link4: LinkList = self.create_linklist_from_list(items4, False)

    link_node2: LinkListNode = LinkList.add_two_linklist_variable(link3, link4)
    self.assertEqual(link_node2.to_list(), [1, 0, 0, 0, 0])

if __name__ == '__main__':
  unittest.main()