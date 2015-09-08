#ifndef OPTIONS_H
#define OPTIONS_H

#include "enums.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <iostream>
#include <string.h>

const struct option long_options[] = {
  { "help", 0, NULL, 'h' },
  { "file", 1, NULL, 'f' },
  { "ievent", 1, NULL, 'i' },
  { "nevent", 1, NULL, 'n' },
  { "tail", 1, NULL, 't' },
  { "meson", 1, NULL, 'm'},
  { "barrel", 0, NULL, 'b'},
  { NULL, 0, NULL, 0 } /* Required at end of array. */
};

class options {
 public:
  options(int argc, char *argv[]);
  ~options();

  int get_ievent() {return ievent;};
  int get_nevent() {return nevent;};
  Meson get_meson() {return meson;};
  std::string get_tail() {return tail;};
  std::string get_file() {return file;};
  bool get_barrel() {return barrel;};

 private:
  void print_usage(FILE* stream, int exit_code);
  void doit();

  std::string program_name;
  int next_option;
  std::string short_options;

  std::string file;
  int ievent;
  int nevent;
  std::string tail;
  Meson meson;
  bool barrel;

  int argc_;
  char **argv_;
};

#endif
