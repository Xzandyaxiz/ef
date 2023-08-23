cmake_minimum_required(VERSION 3.0)
project(ef)

add_executable(ef
  src/ef_parser.c
  src/main.c)

target_link_libraries(ef
  PRIVATE ncurses)
