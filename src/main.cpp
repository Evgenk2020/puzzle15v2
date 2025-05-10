#include "../include/data_gen.h"
#include "../include/keys.h"
#include "../include/m_swap.h"
#include "../include/print.h"

void gaming();

int main()
{
  gaming();
  return 0;
}

void gaming()
{
  keyboard_set keyboards;
  game puzzle(game_data());
  print game_field_show;

  game_field_show.set_board(puzzle.get_board());

  std::string select;
  while (true)
  {
    system("clear");
    game_field_show.print_head();
    game_field_show.get_board();
    
    if (puzzle.is_solved())
    {
      game_field_show.game_over();
      exit(0);
    }

    else
    {
      game_field_show.print_score(puzzle.get_score());
    }

    select = keyboards.get_keyboard_manage_key();

    if (select == "esc")
    {
      exit(0);
    }

    if (select == "F1")
    {
      gaming();
    }

    else
    {
      puzzle.swapping(select);
      game_field_show.set_board(puzzle.get_board());
    }
  }
}