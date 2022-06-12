
#include "list.h"

void testing_the_list();

void test_for_creating_an_empty_list();
void copy_constructor_test();
void error_in_the_copy_constructor();
void test_for_creating_a_list_via_initializer_list();
void error_in_creating_a_list_via_empty_initializer_list();
void assignment_operator_test();
void error_in_assignment_operator_with_an_empty_list();
void creating_a_list();

void test_for_the_size_of_a_non_empty_list();
void empty_list_size_test();
void test_for_changing_a_list_item_by_index();
void error_changing_an_item_with_an_empty_list();
void error_changing_an_element_when_going_beyond_the_size_of_the_list();
void test_for_getting_a_list_item();
void error_getting_an_empty_list_item();
void error_receiving_an_item_when_exiting_the_list();
void list_sorting_test();
void error_on_sorting_the_list();
void test_for_the_entry_of_an_item_in_the_list();
void error_getting_an_item_if_the_list_is_empty();
void test_creating_an_array_based_on_a_list();
void error_creating_an_array_based_on_an_empty_list();
void element_access_operator_test();
void error_on_the_access_operator_for_an_empty_list_item();
void error_on_the_access_operator_for_an_item_outside_the_list();
void test_for_the_output_operator();
void error_on_the_empty_list_output_operator();
void test_to_clear_the_list();
void working_with_a_list();

void test_for_adding_an_item_to_the_end_of_the_list();
void test_for_adding_a_list_of_items_to_the_end_of_the_list();
void error_on_adding_a_list_of_items_to_the_end_of_the_list();
void test_for_adding_an_array_of_elements_to_the_end_of_the_list();
void error_when_adding_an_array_of_elements_to_the_end_of_the_list();
void test_for_removing_an_item_from_the_list_by_index();
void error_on_deleting_an_item_from_an_empty_list_by_index();
void error_on_deleting_an_item_from_the_list_by_index_outside_the_list();
void adding_and_removing_list_items();

void test_combining_one_list_with_another();
void error_combining_one_list_with_another_empty_one();
void addition_operator_test();
void addition_operator_error_with_an_empty_list();
void test_of_the_operator_of_adding_to_the_list_of_another_list();
void error_of_the_operator_adding_another_empty_list_to_the_list();
void adding_one_list_to_another();

void test_creating_an_iterator_on_an_empty_list();
void put_the_iterator_at_the_beginning();
void put_the_iterator_at_the_end();
void test_rearrange_the_iterator_to_the_next_element();
void error_rearrange_iterator_to_the_next_element();
void test_of_getting_the_iterator_value();
void test_whether_the_iterator_points_to_the_element_behind_the_last_one();
void prefix_increment_operator_test();
void error_prefix_increment_operator();
void dereference_operator_test();
void comparison_operator_test_for_equality();
void comparison_operator_test_for_inequality();
void testing_an_iterator_in_a_list();
