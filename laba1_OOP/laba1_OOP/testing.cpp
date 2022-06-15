#include "testing.h"

void testing_the_list()
{
    std::cout << "Begin\n\n";
    creating_a_list();
    working_with_a_list();
    adding_and_removing_list_items();
    adding_one_list_to_another();
    testing_an_iterator_in_a_list();
    std::cout << "End\n";
}

void test_for_creating_an_empty_list()
{
    std::cout << "Test for creating an empty list\n";
    List<int> newlist;
    std::cout << "Test for creating an empty list PASSED\n\n";
}

void copy_constructor_test()
{
    std::cout << "Copy constructor test\n";
    List<int> lst{ 1, 2, 3 };
    List<int> lst2(lst);

    if (lst2.get_length() != 3 || lst2[0] != 1 || lst2[1] != 2 || lst2[2] != 3)
        std::cout << "Copy constructor test FAILED" << "\n\n";

    else
        std::cout << "Copy constructor test PASSED" << "\n\n";
}

void error_in_the_copy_constructor()
{
    std::cout << "Error in the copy constructor\n";
    List<int> lst;
    try {
        List<int> lst2(lst);
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void test_for_creating_a_list_via_initializer_list()
{
    std::cout << "Test for creating a list via initializer_list\n";
    List<int> lst{ 1, 3, 5 };
    if (lst.get_length() != 3 || lst[0] != 1 || lst[1] != 3 || lst[2] != 5)
        std::cout << "Test for creating a list via initializer_list FAILED" << "\n\n";

    else
        std::cout << "Test for creating a list via initializer_list PASSED" << "\n\n";
}

void error_in_creating_a_list_via_empty_initializer_list()
{
    std::cout << "Error in creating a list via empty initializer_list\n";
    try {
        List<int> lst{};
        std::cout << "The list has been created\n\n";
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void assignment_operator_test()
{
    std::cout << "Assignment operator test\n";
    List<int> lst{ 1, 2, 3 };
    List<int> lst2{ 3, 2, 1 };
    lst2 = lst;

    if (lst.get_length() != lst2.get_length() || lst[0] != lst2[0] || lst[1] != lst2[1] || lst[2] != lst2[2])
        std::cout << "Assignment operator test FAILED" << "\n\n";

    std::cout << "Assignment operator test PASSED" << "\n\n";
}

void error_in_assignment_operator_with_an_empty_list()
{
    std::cout << "Error in assignment operator\n";
    List<int> lst;
    List<int> lst2{ 1, 2 };
    try {
        lst2 = lst;
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void creating_a_list()
{
    test_for_creating_an_empty_list();
    copy_constructor_test();
    error_in_the_copy_constructor();
    test_for_creating_a_list_via_initializer_list();
    error_in_creating_a_list_via_empty_initializer_list();
    assignment_operator_test();
    error_in_assignment_operator_with_an_empty_list();
}

void test_for_the_size_of_a_non_empty_list()
{
    std::cout << "Test for the size of a non-empty list\n";
    List<int> lst{ 2, 4, 6, 8 };

    if (lst.get_length() != 4)
        std::cout << "Test for the size of a non-empty list FAILED" << "\n\n";

    else
        std::cout << "Test for the size of a non-empty list PASSED" << "\n\n";
}

void empty_list_size_test()
{
    std::cout << "Empty list size test\n";
    List<int> lst;
    if (lst.get_length() != 0)
        std::cout << "Empty list size test FAILED" << "\n\n";

    else
        std::cout << "Empty list size test PASSED" << "\n\n";
}

void test_for_changing_a_list_item_by_index()
{
    std::cout << "Test for changing a list item by index\n";
    int elem = 2;
    List<int> lst{ 1, 100, 3 };
    lst.set_elem(1, elem);

    if (lst[1] != 2)
        std::cout << "Test for changing a list item by index FAILED" << "\n\n";

    else
        std::cout << "Test for changing a list item by index PASSED" << "\n\n";
}

void error_changing_an_item_with_an_empty_list()
{
    std::cout << "Error changing an item with an empty list\n";
    int elem = 0;
    List<int> lst;
    try {
        lst.set_elem(2, elem);
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void error_changing_an_element_when_going_beyond_the_size_of_the_list()
{
    std::cout << "Error changing an element when going beyond the size of the list\n";
    int elem = 0;
    List<int> lst{ 1, 2, 3 };
    try {
        lst.set_elem(4, elem);
    }
    catch (const char* msg) {
        std::cout <<"Test FAILED" << msg << "\n\n";
    }
}

void test_for_getting_a_list_item()
{
    std::cout << "Test for getting a list item\n";
    List<int> lst{ 1, 2, 3 };

    if (lst.get_elem(2) != 3)
        std::cout << "Test for getting a list item FAILED" << "\n\n";

    else
        std::cout << "Test for getting a list item PASSED" << "\n\n";
}

void error_getting_an_empty_list_item()
{
    std::cout << "Error getting an empty list item\n";
    List<int> lst;
    try {
        lst.get_elem(2);
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void error_receiving_an_item_when_exiting_the_list()
{
    std::cout << "Error receiving an item when exiting the list\n";
    List<int> lst{ 1, 2, 3 };
    try {
        lst.get_elem(4);
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void list_sorting_test()
{
    std::cout << "List sorting test\n";
    List<int> lst{ 3, 5, 1 };
    lst.sort(comp);

    if (lst[0] != 1 || lst[1] != 3 || lst[2] != 5)
        std::cout << "List sorting test FAILED" << "\n\n";

    else
        std::cout << "List sorting test PASSED" << "\n\n";
}

void error_on_sorting_the_list()
{
    std::cout << "Error on sorting the list\n";
    List<int> lst;
    try {
        lst.sort(comp);
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void test_for_the_entry_of_an_item_in_the_list()
{
    std::cout << "Test for the entry of an item in the list\n";
    int elem1 = 3;
    List<int> lst{ 1, 3, 5, 7 };

    if (lst.get_index(elem1) != 1)
        std::cout << "Test for the entry of an item in the list FAILED" << "\n\n";

    else
        std::cout << "Test for the entry of an item in the list PASSED" << "\n";
}

void error_test_for_the_entry_of_an_item_in_the_list()
{
    std::cout << "Test for the entry of an item in the list\n";
    int elem1 = 4;
    List<int> lst{ 1, 3, 5, 7 };

    if (lst.get_index(elem1) != -1)
        std::cout << "Test for the entry of an item in the list FAILED" << "\n\n";

    else
        std::cout << "Test for the entry of an item in the list PASSED" << "\n";
}

void error_getting_an_item_if_the_list_is_empty()
{
    std::cout << "Error getting an item if the list is empty\n";
    int elem = 1;
    List<int> lst;
    try {
        lst.get_index(elem);
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void test_creating_an_array_based_on_a_list()
{
    std::cout << "Test creating an array based on a list\n";
    List<int> lst{ 9, 8, 7 };
    int* arr = lst.to_array();

    if (arr[0] != 9 || arr[1] != 8 || arr[2] != 7)
        std::cout << "Test creating an array based on a list FAILED" << "\n\n";

    else
        std::cout << "Test creating an array based on a list PASSED" << "\n\n";
}

void error_creating_an_array_based_on_an_empty_list()
{
    std::cout << "Error creating an array based on an empty list\n";
    List<int> lst;
    try {
        lst.to_array();
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void element_access_operator_test()
{
    std::cout << "Element access operator test\n";
    List<int> lst{ 2, 4, 6 ,8 };

    if (lst[3] != 8)
        std::cout << "Element access operator test FAILED" << "\n\n";

    else
        std::cout << "Element access operator test PASSED" << "\n\n";
}

void error_on_the_access_operator_for_an_empty_list_item()
{
    std::cout << "Error on the access operator for an empty list item\n";
    List<int> lst;
    try {
        lst[3];
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void error_on_the_access_operator_for_an_item_outside_the_list()
{
    std::cout << "Error on the access operator for an item outside the list\n";
    List<int> lst{ 8, 6, 4, 2 };
    try {
        lst[5];
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void test_for_the_output_operator()
{
    std::cout << "Test for the output operator\n";
    List<int> lst{ 10, 20, 30 , 40, 50 };
    std::cout << lst << "\n\n";
}

void error_on_the_empty_list_output_operator()
{
    std::cout << "Error on the empty list output operator\n";
    List<int> lst;
    try {
        std::cout << lst;
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void test_to_clear_the_list()
{
    std::cout << "Test to clear the list\n";
    List<int> lst{ 1, 2, 3, 4 };
    std::cout << lst << "\n";
    std::cout << "Clearing...\n";
    lst.clear();
    try {
        std::cout << lst;
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void working_with_a_list()
{
    test_for_the_size_of_a_non_empty_list();
    empty_list_size_test();
    test_for_changing_a_list_item_by_index();
    error_changing_an_item_with_an_empty_list(); 
    error_changing_an_element_when_going_beyond_the_size_of_the_list();
    test_for_getting_a_list_item();
    error_getting_an_empty_list_item();
    error_receiving_an_item_when_exiting_the_list();
    list_sorting_test();
    error_on_sorting_the_list();
    test_for_the_entry_of_an_item_in_the_list();
    error_test_for_the_entry_of_an_item_in_the_list();
    error_getting_an_item_if_the_list_is_empty();
    test_creating_an_array_based_on_a_list();
    error_creating_an_array_based_on_an_empty_list();
    element_access_operator_test();
    error_on_the_access_operator_for_an_empty_list_item();
    error_on_the_access_operator_for_an_item_outside_the_list();
    test_for_the_output_operator();
    error_on_the_empty_list_output_operator();
    test_to_clear_the_list();
}

void test_for_adding_an_item_to_the_end_of_the_list()
{
    std::cout << "Test for adding an item to the end of the list\n";
    List<int> lst{ 1, 2, 3 };
    int elem = 4;
    lst.add(elem);

    if (lst[3] != 4)
        std::cout << "Test for adding an item to the end of the list FAILED" << "\n\n";

    else
        std::cout << "Test for adding an item to the end of the list PASSED" << "\n\n";
}

void test_for_adding_a_list_of_items_to_the_end_of_the_list()
{
    std::cout << "Test for adding a list of items to the end of the list\n";
    List<int> lst{ 1, 2 };
    List<int> lst2{ 4, 5 };
    lst.add_range(lst2);

    if (lst.get_length() != 4 || lst[0] != 1 || lst[1] != 2 || lst[2] != 4 || lst[3] != 5)
        std::cout << "Test for adding a list of items to the end of the list FAILED" << "\n\n";

    else
        std::cout << "Test for adding a list of items to the end of the list PASSED" << "\n\n";
}

void error_on_adding_a_list_of_items_to_the_end_of_the_list()
{
    std::cout << "Error on adding a list of items to the end of the list\n";
    List<int> lst{ 1, 2, 3 };
    List<int> lst2;
    try {
        lst.add_range(lst2);
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void test_for_adding_an_array_of_elements_to_the_end_of_the_list()
{
    std::cout << "Test for adding an array of elements to the end of the list\n";
    List<int> lst{ 1, 2 };
    int arr[2] = { 3, 4 };
    lst.add_range(arr, 2);

    if (lst.get_length() != 4 || lst[0] != 1 || lst[1] != 2 || lst[2] != 3 || lst[3] != 4)
        std::cout << "Test for adding an array of elements to the end of the list FAILED" << "\n\n";

    else
        std::cout << "Test for adding an array of elements to the end of the list PASSED" << "\n\n";
}

void error_when_adding_an_array_of_elements_to_the_end_of_the_list()
{
    std::cout << "Error when adding an array of elements to the end of the list\n";
    List<int> lst{ 1, 2 };
    int* arr = NULL;
    try {
        lst.add_range(arr, 0);
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void test_for_removing_an_item_from_the_list_by_index()
{
    std::cout << "Test for removing an item from the list by index\n";
    List<int> lst{ 12, 13, 14 };
    lst.remove_elem(2);

    if (lst.get_length() != 2)
        std::cout << "Test for removing an item from the list by index FAILED" << "\n\n";

    else
        std::cout << "Test for removing an item from the list by index PASSED" << "\n\n";
}

void error_on_deleting_an_item_from_an_empty_list_by_index()
{
    std::cout << "Error on deleting an item from an empty list by index\n";
    List<int> lst;
    try {
        lst.remove_elem(3);
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void error_on_deleting_an_item_from_the_list_by_index_outside_the_list()
{
    std::cout << "Error on deleting an item from the list by index outside the list\n";
    List<int> lst{ 1, 2 };
    try {
        lst.remove_elem(3);
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void adding_and_removing_list_items()
{

    test_for_adding_an_item_to_the_end_of_the_list();
    test_for_adding_a_list_of_items_to_the_end_of_the_list();
    error_on_adding_a_list_of_items_to_the_end_of_the_list();
    test_for_adding_an_array_of_elements_to_the_end_of_the_list();
    error_when_adding_an_array_of_elements_to_the_end_of_the_list();
    test_for_removing_an_item_from_the_list_by_index();
    error_on_deleting_an_item_from_an_empty_list_by_index();
    error_on_deleting_an_item_from_the_list_by_index_outside_the_list();
}

void test_combining_one_list_with_another()
{
    std::cout << "Test combining one list with another\n";
    List<int> lst1{ 1, 2 };
    List<int> lst2{ 4, 5 };
    List<int> lst3;
    lst3 = lst1.combine(lst2);

    if (lst3.get_length() != 4 || lst3[0] != 1 || lst3[1] != 2 || lst3[2] != 4 || lst3[3] != 5)
        std::cout << "Test combining one list with another FAILED" << "\n\n";

    else
        std::cout << "Test combining one list with another PASSED" << "\n\n";
}

void error_combining_one_list_with_another_empty_one()
{
    std::cout << "Error combining one list with another empty one\n";
    List<int> lst1{ 1, 2, 3 };
    List<int> lst2;
    try {
        List<int> lst3;
         lst3 = lst1.combine(lst2);
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void addition_operator_test()
{
    std::cout << "Addition operator test\n";
    List<int> lst1{ 1, 2 };
    List<int> lst2{ 4, 5 };
    List<int>lst3;
    lst3  = lst1 + lst2;

    if (lst3.get_length() != 4 || lst3[0] != 1 || lst3[1] != 2 || lst3[2] != 4 || lst3[3] != 5)
        std::cout << "Addition operator test FAILED" << "\n\n";

    else
        std::cout << "Addition operator test PASSED" << "\n\n";
}

void addition_operator_error_with_an_empty_list()
{
    std::cout << "Addition operator error with an empty list\n";
    List<int> lst1{ 1, 2, 3 };
    List<int> lst2;
    try {
        List<int> lst3;
        lst3 = lst1 + lst2;
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void test_of_the_operator_of_adding_to_the_list_of_another_list()
{
    std::cout << "Test of the operator of adding to the list of another list\n";
    List<int> lst1{ 1, 2 };
    List<int> lst2{ 4, 5 };
    lst1 += lst2;

    if (lst1.get_length() != 4 || lst1[0] != 1 || lst1[1] != 2 || lst1[2] != 4 || lst1[3] != 5)
        std::cout << "Test of the operator of adding to the list of another list FAILED" << "\n\n";

    else
        std::cout << "Test of the operator of adding to the list of another list PASSED" << "\n\n";
}

void error_of_the_operator_adding_another_empty_list_to_the_list()
{
    std::cout << "Error of the operator adding another empty list to the list\n";
    List<int> lst1{ 1, 2, 3 };
    List<int> lst2;
    try {
        lst1 += lst2;
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void adding_one_list_to_another()
{
    test_combining_one_list_with_another();
    error_combining_one_list_with_another_empty_one();
    addition_operator_test();
    addition_operator_error_with_an_empty_list();
    test_of_the_operator_of_adding_to_the_list_of_another_list();
    error_of_the_operator_adding_another_empty_list_to_the_list();
}

void test_creating_an_iterator_on_an_empty_list()
{
    std::cout << "Test creating an iterator on an empty list\n";
    List<int> lst;
    try {
        Iterator<int> iter = lst.iterator_begin();
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void put_the_iterator_at_the_beginning()
{
    std::cout << "Put the iterator at the beginning\n";
    List<int> lst{ 1, 2, 3 };
    Iterator<int> iter = lst.iterator_begin();

    if (iter.value() != 1)
        std::cout << "Put the iterator at the beginning FAILED" << "\n\n";

    else
        std::cout << "Put the iterator at the beginning PASSED" << "\n\n";
}

void put_the_iterator_at_the_end()
{
    std::cout << "Put the iterator at the end\n";
    List<int> lst{ 1, 2, 3 };
    Iterator<int> iter = lst.iterator_end();

    if (iter.value() != 3)
        std::cout << "Put the iterator at the end FAILED" << "\n\n";

    else
        std::cout << "Put the iterator at the end PASSED" << "\n\n";
}

void test_rearrange_the_iterator_to_the_next_element()
{
    std::cout << "Test rearrange the iterator to the next element\n";
    List<int> lst{ 1, 2, 3 };
    Iterator<int> iter = lst.iterator_begin();
    iter.next();

    if (iter.value() != 2)
        std::cout << "Test rearrange the iterator to the next element FAILED" << "\n\n";

    else
        std::cout << "Test rearrange the iterator to the next element PASSED" << "\n\n";
}

void error_rearrange_iterator_to_the_next_element()
{
    std::cout << "Error rearrange iterator to the next element";
    List<int> lst{ 1, 2, 3 };
    Iterator<int> iter = lst.iterator_end();
    try {
        iter.next();
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void test_of_getting_the_iterator_value()
{
    std::cout << "Test of getting the iterator value\n";
    List<int> lst{ 1, 2, 3 };
    Iterator<int> iter = lst.iterator_begin();
    iter.next();
    if (iter.value() != 2)
        std::cout << "Test of getting the iterator value FAILED" << "\n\n";

    else
        std::cout << "Test of getting the iterator value PASSED" << "\n\n";
}

void test_whether_the_iterator_points_to_the_element_behind_the_last_one()
{
    std::cout << "Test whether the iterator points to the element behind the last one\n";
    List<int> lst{ 1, 2, 3 };
    Iterator<int> iter = lst.iterator_end();
    if (iter.is_end())
        std::cout << "The end\n\n";
    else
        std::cout << "Not the end\n\n";
}

void prefix_increment_operator_test()
{
    std::cout << "Prefix increment operator test\n";
    List<int> lst{ 1, 2, 3 };
    Iterator<int> iter = lst.iterator_begin();
    ++iter;

    if (iter.value() != 2)
        std::cout << "Prefix increment operator test FAILED" << "\n\n";

    else
        std::cout << "Prefix increment operator test PASSED" << "\n\n";
}

void error_prefix_increment_operator()
{
    std::cout << "Error prefix increment operator\n";
    List<int> lst{ 1, 2, 3 };
    Iterator<int> iter = lst.iterator_end();
    try {
        ++iter;
    }
    catch (const char* msg) {
        std::cout << "test FAILED" << msg << "\n\n";
    }
}

void dereference_operator_test()
{
    std::cout << "Dereference operator test\n";
    List<int> lst{ 1, 2, 3 };
    Iterator<int> iter = lst.iterator_begin();
    ++iter;

    if (*iter != 2)
        std::cout << "Dereference operator test FAILED" << "\n\n";

    else
        std::cout << "Dereference operator test PASSED" << "\n\n";
}

void comparison_operator_test_for_equality()
{
    std::cout << "Comparison operator test for equality\n";
    List<int> lst{ 1, 2, 3 };
    Iterator<int> iter1 = lst.iterator_begin();
    Iterator<int> iter2 = lst.iterator_begin();
    if (iter1 == iter2)
        std::cout << "Comparison operator test for equality PASSED" << "\n\n";
    else
        std::cout << "Comparison operator test for equality FAILED" << "\n\n";
}

void comparison_operator_test_for_inequality()
{
    std::cout << "Comparison operator test for inequality\n";
    List<int> lst{ 1, 2, 3 };
    Iterator<int> iter1 = lst.iterator_begin();
    Iterator<int> iter2 = lst.iterator_end();
    if (iter1 != iter2)
        std::cout << "Comparison operator test for inequality PASSED" << "\n\n";
    else
        std::cout << "Comparison operator test for inequality FAILED" << "\n\n";
}

void testing_an_iterator_in_a_list()
{
    test_creating_an_iterator_on_an_empty_list();
    put_the_iterator_at_the_beginning();
    put_the_iterator_at_the_end();
    test_rearrange_the_iterator_to_the_next_element();
    error_rearrange_iterator_to_the_next_element();
    test_of_getting_the_iterator_value();
    test_whether_the_iterator_points_to_the_element_behind_the_last_one();
    prefix_increment_operator_test();
    error_prefix_increment_operator();
    dereference_operator_test();
    comparison_operator_test_for_equality();
    comparison_operator_test_for_inequality();
}
