#include "pch.h"
#include "CppUnitTest.h"

#include "../CodeDesignAndDataStructures/LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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

			Assert::IsNotNull(list.FirstNode());
			Assert::IsNotNull(list.LastNode());

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 40);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 4u);
		}

		TEST_METHOD(PushFront_List)
		{
			LinkedList<int> list = { 20, 30, 40 };

			list.PushFront(10);

			Assert::IsNotNull(list.FirstNode());
			Assert::IsNotNull(list.LastNode());

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 40);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 4u);
		}

		TEST_METHOD(PopBack_List)
		{
			LinkedList<int> list = { 10, 20, 30, 40 };

			list.PopBack();

			Assert::IsNotNull(list.FirstNode());
			Assert::IsNotNull(list.LastNode());

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 30);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 3u);
		}

		TEST_METHOD(PopFront_List)
		{
			LinkedList<int> list = { 10, 20, 30, 40 };

			list.PopFront();

			Assert::IsNotNull(list.FirstNode());
			Assert::IsNotNull(list.LastNode());

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

		TEST_METHOD(Remove_From_List_Middle)
		{
			LinkedList<int> list = { 10, 20, 30, 40 };

			for (auto iter = list.begin(); iter != list.end();)
			{

				if (*iter == 30)
					iter = list.Remove(iter);
				else
					iter++;
			}

			Assert::IsNotNull(list.FirstNode());
			Assert::IsNotNull(list.LastNode());

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 40);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 3u);
		}
		
		TEST_METHOD(Remove_From_List_End)
		{
			LinkedList<int> list = { 10, 20, 30, 40 };

			for (auto iter = list.begin(); iter != list.end();)
			{
				if (*iter == 40)
					iter = list.Remove(iter);
				else
					iter++;
			}

			Assert::IsNotNull(list.FirstNode());
			Assert::IsNotNull(list.LastNode());

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 30);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 3u);
		}
		
		TEST_METHOD(Remove_From_List_Start)
		{
			LinkedList<int> list = { 10, 20, 30, 40 };

			for (auto iter = list.begin(); iter != list.end();)
			{
				if (*iter == 10)
					iter = list.Remove(iter);
				else
					iter++;
			}

			Assert::IsNotNull(list.FirstNode());
			Assert::IsNotNull(list.LastNode());

			Assert::AreEqual(list.FirstNode()->value, 20);
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

			Assert::IsNotNull(list.FirstNode());
			Assert::IsNotNull(list.LastNode());

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 30);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 2u);
		}

		TEST_METHOD(Insert_Into_List)
		{
			LinkedList<int> list = { 10, 20, 30, 40 };

			auto iter = std::find(list.begin(), list.end(), 30);

			list.Insert(iter, 35);

			Assert::IsNotNull(list.FirstNode());
			Assert::IsNotNull(list.LastNode());

			Assert::AreEqual(list.FirstNode()->value, 10);
			Assert::AreEqual(list.LastNode()->value, 40);

			Assert::IsFalse(list.IsEmpty());

			Assert::IsTrue(list.Count() == 5u);
		}
	};
}
