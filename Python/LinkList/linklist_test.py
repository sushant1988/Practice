import unittest
from linklist import LinkList

class LinkListTest(unittest.TestCase):
  def setUp(self) -> LinkList:
    return LinkList()

  def test_fn_insert_at_front(self):
    link: LinkList = self.setUp()
    items: list = [2, 3, 4]

    for x in items:
      link.insert_at_front(x)

    lst: list = link.to_list()
    self.assertEqual(len(lst), len(items))
    self.assertEqual(lst, items[::-1])

  def test_fn_insert_at_rear(self):
    link: LinkList = self.setUp()
    items: list = [2, 3, 4]

    for x in items:
      link.insert_at_rear(x)

    lst: list = LinkList.to_list(link) # test class method
    self.assertEqual(len(lst), len(items))
    self.assertEqual(lst, items)

  def test_fn_mth_from_last(self):
    link: LinkList = self.setUp()
    items: list = [1, 2, 3, 4, 5, 6]

    for x in items:
      link.insert_at_rear(x)

    self.assertEqual(link.find_mth_from_last_element(3), 4)
    self.assertEqual(link.find_mth_from_last_element(2), 5)
    self.assertEqual(link.find_mth_from_last_element(6), 1)
    self.assertEqual(link.find_mth_from_last_element(7), None)

  def test_fn_recursive_linklist(self):
    link: LinkList = self.setUp()
    items: list = [1, 2, 3, 4, 5, 6]

    for x in items:
      link.insert_at_front(x)

    hd = LinkList.reverse_recursive_linklist(link.head)
    lst = []
    while(hd is not None):
      lst.append(hd.data)
      hd = hd.next

    self.assertEqual(len(lst), len(items))
    self.assertEqual(lst, items)

  def test_fn_iterative_linklist(self):
    link: LinkList = self.setUp()
    items: list = [1, 2, 3, 4, 5, 6]

    for x in items:
      link.insert_at_front(x)

    link.reverse_iterative_linklist()
    lst: list = link.to_list()
    self.assertEqual(len(lst), len(items))
    self.assertEqual(lst, items)

if __name__ == '__main__':
  unittest.main()