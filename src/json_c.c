#include "json_c.h"
#include <stdio.h>
#include <json-c/json.h>

json_object *json;
void json_c_createObj_convToString(){
  json = json_object_new_object();  //create json object
  json_object_object_add(json, "title",\
        json_object_new_string("testies")); //add "title" : "testies"
  json_object_object_add(json, "body", json_object_new_string("testies ... testies ... 1,2,3"));
  json_object_object_add(json, "userId", json_object_new_int(133));
  printf("%s\n",json_object_to_json_string(json));
}
