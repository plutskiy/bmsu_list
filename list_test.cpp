#include <gtest/gtest.h>
#include <iostream>
#include "bmsu_list.h"

TEST(Constructor, Default) {
    bmstu::list<int> list;
    bmstu::list<int>::iterator it_b = list.begin();
    bmstu::list<int>::iterator it_e = list.end();

    ASSERT_EQ(list.size(), 0);
    ASSERT_TRUE(it_b == it_e);

    --it_b;
    --it_e;
    ASSERT_TRUE(it_b == it_e);
}

TEST(Constructor, IList) {
    bmstu::list<int> list({0, 1, 2, 3, 4});
    bmstu::list<int>::iterator it_b = list.begin();
    bmstu::list<int>::iterator it_e = list.end();

    ASSERT_EQ(list.size(), 5);
    for (int a = 0; it_b != it_e; ++it_b, ++a) {
        ASSERT_TRUE(*it_b == a);
        ASSERT_TRUE(list[a] == a);
    }

    --it_e;
    it_b = list.begin() - 1;
    for (int a = 4; it_b != it_e; --it_e, --a) {
        ASSERT_TRUE(*it_e == a);
        ASSERT_TRUE(list[a] == a);
    }
}

TEST(Constructor, Iterators) {
    bmstu::list<int> list_1({0, 1, 2, 3, 4});
    bmstu::list<int>::iterator it_b_1 = list_1.begin() + 1;
    bmstu::list<int>::iterator it_e_1 = list_1.end() - 1;


    bmstu::list<int> list_2(it_b_1, it_e_1);
    bmstu::list<int>::iterator it_b_2 = list_2.begin();
    bmstu::list<int>::iterator it_e_2 = list_2.end();

    ASSERT_EQ(list_1.size(), 5);
    ASSERT_EQ(list_2.size(), 3);
    for (int a = 1; it_b_2 != it_e_2; ++it_b_2, ++a) {
        ASSERT_TRUE(*it_b_2 == a);
        ASSERT_TRUE(list_2[a - 1] == a);
    }

    --it_e_2;
    it_b_2 = list_2.begin() - 1;
    for (int a = 3; it_b_2 != it_e_2; --it_e_2, --a) {
        ASSERT_TRUE(*it_e_2 == a);
        ASSERT_TRUE(list_2[a - 1] == a);
    }
}

TEST(Constructor, Copy) {
    bmstu::list<int> list_1({0, 1, 2, 3, 4});
    bmstu::list<int>::iterator it_b_1 = list_1.begin();
    bmstu::list<int>::iterator it_e_1 = list_1.end();

    bmstu::list<int> list_2(list_1);
    bmstu::list<int>::iterator it_b_2 = list_2.begin();
    bmstu::list<int>::iterator it_e_2 = list_2.end();

    ASSERT_EQ(list_1.size(), 5);
    ASSERT_EQ(list_2.size(), 5);
    for (int a = 0; it_b_2 != it_e_2; ++it_b_1, ++it_b_2, ++a) {
        ASSERT_TRUE(*it_b_1 == a);
        ASSERT_TRUE(*it_b_2 == a);
        ASSERT_TRUE(list_1[a] == list_2[a]);
    }

    --it_e_1;
    --it_e_2;
    it_b_1 = list_1.begin() - 1;
    it_b_2 = list_2.begin() - 1;
    for (int a = 4; it_b_2 != it_e_2; --it_e_1, --it_e_2, --a) {
        ASSERT_TRUE(*it_e_1 == a);
        ASSERT_TRUE(*it_e_2 == a);
        ASSERT_TRUE(list_1[a] == list_2[a]);
    }
}

TEST(Constructor, Move) {
    bmstu::list<int> list_1({0, 1, 2, 3, 4});
    bmstu::list<int> list_2(std::move(list_1));
    bmstu::list<int>::iterator it_b_2 = list_2.begin();
    bmstu::list<int>::iterator it_e_2 = list_2.end();

    ASSERT_EQ(list_1.size(), 0);
    ASSERT_EQ(list_2.size(), 5);
    for (int a = 0; it_b_2 != it_e_2; ++it_b_2, ++a) {
        ASSERT_TRUE(*it_b_2 == a);
        ASSERT_TRUE(list_2[a] == a);
    }
}

TEST(Method, push_back) {
    bmstu::list<int> list({0, 1, 2, 3, 4});

    list.push_back(5);

    bmstu::list<int>::iterator it_b = list.begin();
    bmstu::list<int>::iterator it_e = list.end();

    ASSERT_EQ(list.size(), 6);
    for (int a = 0; it_b != it_e; ++it_b, ++a) {
        ASSERT_TRUE(*it_b == a);
        ASSERT_TRUE(list[a] == a);
    }

    --it_e;
    it_b = list.begin() - 1;
    for (int a = 5; it_b != it_e; --it_e, --a) {
        ASSERT_TRUE(*it_e == a);
        ASSERT_TRUE(list[a] == a);
    }
}

TEST(Method, push_front) {
    bmstu::list<int> list({1, 2, 3, 4, 5});

    list.push_front(0);

    bmstu::list<int>::iterator it_b = list.begin();
    bmstu::list<int>::iterator it_e = list.end();

    ASSERT_EQ(list.size(), 6);
    for (int a = 0; it_b != it_e; ++it_b, ++a) {
        ASSERT_TRUE(*it_b == a);
        ASSERT_TRUE(list[a] == a);
    }

    --it_e;
    it_b = list.begin() - 1;
    for (int a = 5; it_b != it_e; --it_e, --a) {
        ASSERT_TRUE(*it_e == a);
        ASSERT_TRUE(list[a] == a);
    }
}

TEST(Method, clear) {
    bmstu::list<int> list({1, 2, 3, 4, 5});

    list.clear();

    bmstu::list<int>::iterator it_b = list.begin();
    bmstu::list<int>::iterator it_e = list.end();

    ASSERT_EQ(list.size(), 0);
    ASSERT_TRUE(it_b == it_e);

    --it_b;
    --it_e;
    ASSERT_TRUE(it_b == it_e);
}

TEST(Method, swap) {
    bmstu::list<int> list_1({0, 1, 2, 3, 4});
    bmstu::list<int> list_2({7, 8, 9});

    list_1.swap(list_2);

    bmstu::list<int>::iterator it_b_1 = list_1.begin();
    bmstu::list<int>::iterator it_e_1 = list_1.end();
    bmstu::list<int>::iterator it_b_2 = list_2.begin();
    bmstu::list<int>::iterator it_e_2 = list_2.end();

    ASSERT_EQ(list_1.size(), 3);
    ASSERT_EQ(list_2.size(), 5);

    for (int a = 7; it_b_1 != it_e_1; ++it_b_1, ++a) {
        ASSERT_TRUE(*it_b_1 == a);
        ASSERT_TRUE(list_1[a - 7] == a);
    }

    --it_e_1;
    it_b_1 = list_1.begin() - 1;
    for (int a = 9; it_b_1 != it_e_1; --it_e_1, --a) {
        ASSERT_TRUE(*it_e_1 == a);
        ASSERT_TRUE(list_1[a - 7] == a);
    }

    for (int a = 0; it_b_2 != it_e_2; ++it_b_2, ++a) {
        ASSERT_TRUE(*it_b_2 == a);
        ASSERT_TRUE(list_2[a] == a);
    }

    --it_e_2;
    it_b_2 = list_2.begin() - 1;
    for (int a = 4; it_b_2 != it_e_2; --it_e_2, --a) {
        ASSERT_TRUE(*it_e_2 == a);
        ASSERT_TRUE(list_2[a] == a);
    }
}

TEST(Operapor, Index) {
    bmstu::list<int> list({0, 1, 2, 0, 4});
    list[3] = 3;

    ASSERT_EQ(list.size(), 5);

    bmstu::list<int>::iterator it_b = list.begin();
    bmstu::list<int>::iterator it_e = list.end();
    for (int a = 0; it_b != it_e; ++it_b, ++a) {
        ASSERT_TRUE(*it_b == a);
        ASSERT_TRUE(list[a] == a);
    }

    --it_e;
    it_b = list.begin() - 1;
    for (int a = 4; it_b != it_e; --it_e, --a) {
        ASSERT_TRUE(*it_e == a);
        ASSERT_TRUE(list[a] == a);
    }


}

TEST(Operator, EQs) {
    bmstu::list<int> list_1({0, 1, 2, 3, 4, 5, 6});
    bmstu::list<int> list_2({0, 1, 2, 3, 4, 5, 6});
    bmstu::list<int> list_3({0, 1, 2, 3, 4, 5, 7});
    bmstu::list<int> list_4({1, 2, 3, 4, 5, 7, 8});
    bmstu::list<int> list_5({1, 1, 2, 3, 4, 5, 7});

    ASSERT_TRUE(list_1 == list_2);
    ASSERT_FALSE(list_1 == list_3);
    ASSERT_TRUE(list_1 != list_3);
    ASSERT_FALSE(list_1 != list_2);
    ASSERT_TRUE(list_1 < list_4);
    ASSERT_TRUE(list_4 > list_1);
    ASSERT_TRUE(list_1 <= list_5);
    ASSERT_TRUE(list_5 >= list_1);
}

TEST(Operator, LeftShift) {
    bmstu::list<int> list({0, 1, 2, 3, 4, 5, 6});
    std::stringstream ss;
    ss << list;
    ASSERT_STREQ(ss.str().c_str(), "{0, 1, 2, 3, 4, 5, 6}");
}

TEST(Method, insert) {
    bmstu::list<int> list({0, 1, 2, 4});
    bmstu::list<int>::iterator it = list.end();
    try{
        list.insert(it, 5);
    }
    catch (std::logic_error &err) {
        ASSERT_EQ(err.what(), std::string("You can't insert an element after end"));
    }
    it = it-2;
    list.insert(it, 3);
    bmstu::list<int>::iterator it_b = list.begin();
    bmstu::list<int>::iterator it_e = list.end();

    ASSERT_EQ(list.size(), 5);
    for (int a = 0; it_b != it_e; ++it_b, ++a) {
        ASSERT_TRUE(*it_b == a);
        ASSERT_TRUE(list[a] == a);
    }

    --it_e;
    it_b = list.begin() - 1;
    for (int a = 4; it_b != it_e; --it_e, --a) {
        ASSERT_TRUE(*it_e == a);
        ASSERT_TRUE(list[a] == a);
    }
}

TEST(sdsa, faf){
    bmstu::list<int> list1 {1,2,3,4,5,6,7,8,9};
    bmstu::list<int>::iterator it = list1.begin();
    bmstu::list<int>::iterator it2 = it + 2.2;
    
}