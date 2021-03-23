#ifndef BOARD
#define BOARD
#include "Direction.hpp"
#include <string>

namespace ariel{
   class Board
   {
   private:
       /* data */
   public:
       Board(/* args */);
       ~Board();
       void post(unsigned int x,unsigned int y,Direction d,std::string s);
       std::string read(unsigned int x,unsigned int y,Direction d,unsigned int num);
       void show();
   };
   
   
   


}
#endif