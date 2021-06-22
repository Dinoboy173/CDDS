#include "pch.h"
#include "CppUnitTest.h"

#include "../AIE_Collections/LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<int ID>
class MockListItemDeleteCount
{
public:

	MockListItemDeleteCount()
	{
		counter++;
	}

	MockListItemDeleteCount(const MockListItemDeleteCount& copy)
	{
		counter++;
	}

	~MockListItemDeleteCount()
	{
		counter--;
	}

	static int counter;

};

template<int ID>
int MockListItemDeleteCount<ID>::counter = 0;

namespace AIEUnitTests
{
	TEST_CLASS(AIELinkedListTest)
	{
	public:
		
		TEST_METHOD(Can_Create_Empty_List)
		{
			LinkedList<int> list;

			Assert::IsNull(list.FirstNode());
			Assert::IsNull(list.LastNode());

			Assert::IsTrue(list.IsEmpty());

			Assert::IsTrue(list.begin() == list.end());

			Assert::IsTrue(list.Count() == 0);
		}

		TEST_METHOD(Can_Create_List_With_Initialiser_List)
		{
            LinkedList<int> list = { 10, 20, 30, 40 };
            
            Assert::IsNotNull(list.FirstNode());
            Assert::IsNotNull(list.LastNode());
            
            Assert::AreEqual(list.FirstNode()->value, 10);
            Assert::AreEqual(list.LastNode()->value, 40);
            
            Assert::IsFalse(list.IsEmpty());
			
			int arr[5] = { 10, 20, 30, 40 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
				Assert::AreEqual(*iter, arr[index]);
                index++;
            }

			Assert::IsTrue(list.Count() == 4u);
		}

		TEST_METHOD(PushBack_List)
		{
			LinkedList<int> list = { 10, 20, 30 };

			list.PushBack(40);

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 40);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 4u);
		}

		TEST_METHOD(PushFront_List)
		{
			LinkedList<int> list = { 20, 30, 40 };

			list.PushFront(10);

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 40);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 4u);
		}

		TEST_METHOD(PopBack_List)
		{
			LinkedList<int> list = { 10, 20, 30, 40 };

			list.PopBack();

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 30);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 3u);
		}

		TEST_METHOD(PopFront_List)
		{
			LinkedList<int> list = { 10, 20, 30, 40 };

			list.PopFront();

			Assert::AreEqual(list.FirstNode()->value, 20);
			Assert::AreEqual(list.LastNode()->value, 40);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 3u);
		}

		TEST_METHOD(Clear_List)
		{
			LinkedList<int> list = { 10, 20, 30, 40 };

			list.Clear();

			Assert::IsNull(list.FirstNode());
			Assert::IsNull(list.LastNode());

			Assert::IsTrue(list.IsEmpty());

			Assert::IsTrue(list.begin() == list.end());

			Assert::IsTrue(list.Count() == 0);
		}

		TEST_METHOD(Remove_From_List)
		{
			LinkedList<int> list = { 10, 20, 30, 40 };

			for (auto iter = list.begin(); iter != list.end();)
			{
				if (*iter == 30)
					iter = list.Remove(iter);
				else
					iter++;
			}

			for (auto iter = list.begin(); iter != list.end(); iter++)
			{
				Assert::AreNotEqual(iter.node->value, 30);
			}

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 40);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 3u);
		}
		
		TEST_METHOD(Remove_From_List_Multiple)
		{
			LinkedList<int> list = { 20, 10, 20, 30, 20 };

			for (auto iter = list.begin(); iter != list.end();)
			{
				if (*iter == 20)
					iter = list.Remove(iter);
				else
					iter++;
			}

			for (auto iter = list.begin(); iter != list.end(); iter++)
			{
				Assert::AreNotEqual(iter.node->value, 20);
			}

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 30);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 2u);
		}

		TEST_METHOD(Insert_Into_List)
		{
			LinkedList<int> list = { 10, 20, 30, 40 };

			auto iter1 = std::find(list.begin(), list.end(), 30);

			list.Insert(iter1, 35);

			auto iter2 = std::find(list.begin(), list.end(), 35);

			Assert::AreEqual(iter2.node->value, 35);

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 40);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 5u);
		}

		TEST_METHOD(Sort_Unsorted_List)
		{
			LinkedList<int> list = { 30, 40, 10, 20 };

			list.Sort();

			for (auto iter = list.begin().Next(); iter != list.end(); iter++)
			{
				Assert::IsTrue(iter.node->prev->value < iter.node->value);
			}

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 40);
		}
		TEST_METHOD(List_Items_Are_Deleted)
		{
			const int ID = 9786532;
			{
				LinkedList<MockListItemDeleteCount<ID>> list;

				list.PushBack(MockListItemDeleteCount<ID>());
				list.PushBack(MockListItemDeleteCount<ID>());
				list.PushBack(MockListItemDeleteCount<ID>());

				Assert::AreEqual(MockListItemDeleteCount<ID>::counter, 3);

				list.PopBack();
				Assert::AreEqual(MockListItemDeleteCount<ID>::counter, 2);

				list.Clear();
				Assert::AreEqual(MockListItemDeleteCount<ID>::counter, 0);

				list.PushBack(MockListItemDeleteCount<ID>());
				list.PushBack(MockListItemDeleteCount<ID>());
				list.PushBack(MockListItemDeleteCount<ID>());

				Assert::AreEqual(MockListItemDeleteCount<ID>::counter, 3);
			}

			Assert::AreEqual(MockListItemDeleteCount<ID>::counter, 0);

		}
	};
}
