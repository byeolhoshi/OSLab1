#include <stdio.h>

#include "list.h"
#include <assert.h>

void init_test_list(list_t* l) {
  list_add_to_back(l, 3);
  list_add_to_back(l, 10);
  list_add_to_back(l, 15);
}

int main() {
  printf("Tests for linked list implementation\n");

  printf("Test one \n");
  list_t* t_one = list_alloc();
  init_test_list(t_one);
  list_print(t_one);
  assert(3 == list_length(t_one));
  
  list_remove_from_back(t_one);
  list_print(t_one);
  assert(2 == list_length(t_one));
  list_free(t_one);
  printf("Test one pass \n");
  
  printf("Test two \n");
  list_t* t_two = list_alloc();
  init_test_list(t_two);
  list_add_to_front(t_two, 1);
  list_print(t_two);
  assert(4 == list_length(t_two));
  
  list_remove_from_front(t_two);
  list_print(t_two);
  assert(3 == list_length(t_two));
  list_free(t_two);
  printf("Test two pass \n");
  
  printf("Test three \n");
  list_t* t_three = list_alloc();
  init_test_list(t_three);
  list_add_at_index(t_three, 20, 1);
  list_print(t_three);
  assert(4 == list_length(t_three));
  
  list_remove_at_index(t_three, -10);
  list_remove_at_index(t_three, 10);
  list_remove_at_index(t_three, 1);
  list_print(t_three);
  assert(3 == list_length(t_three));
  list_free(t_three);
  printf("Test three pass \n");
  
  printf("Test four \n");
  list_t* t_four = list_alloc();
  init_test_list(t_four);
  assert(1 == list_is_in(t_four, 15));
  assert(0 == list_is_in(t_four, 30));
  list_free(t_four);
  printf("Test four pass \n");
  
  printf("Test five \n");
  list_t* t_five = list_alloc();
  init_test_list(t_five);
  assert(10 == list_get_elem_at(t_five, 1));
  assert(0 == list_get_elem_at(t_five, 10));
  assert(0 == list_get_elem_at(t_five, -1));
  list_free(t_five);
  printf("Test five pass \n");
  
  printf("Test six run.\n");
  list_t* t_six = list_alloc();
  init_test_list(t_six);
  assert(1 == list_get_index_of(t_six, 10));
  assert(-1 == list_get_index_of(t_six, 30));
  list_free(t_six);
  printf("Test six pass \n");
  return 0;
}