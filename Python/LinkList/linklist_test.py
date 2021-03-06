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

        lst: list = link.return_list()
        self.assertEqual(len(lst), len(items))
        self.assertEqual(lst, items[::-1])

    def test_fn_insert_at_rear(self):
        link: LinkList = self.setUp()
        items: list = [2, 3, 4]

        for x in items:
          link.insert_at_rear(x)

        lst: list = link.return_list()
        self.assertEqual(len(lst), len(items))
        self.assertEqual(lst, items)

if __name__ == '__main__':
    unittest.main()