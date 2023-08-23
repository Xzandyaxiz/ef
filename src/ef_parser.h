#ifndef ef_parser
  #define ef_parser

  typedef enum
  { a_move, i_set
  } mode_e;

  typedef struct
  {
    mode_e mode;
    int value;
  } instr_t;

  void load_next_instr(
      char *source);

#endif // ef_parser
