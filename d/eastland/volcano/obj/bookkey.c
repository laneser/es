#include "../oldcat.h"

inherit OBJECT;

void create()
{
        set_name("stone key", "藍寶石鑰匙");
        set_short("藍寶石鑰匙");
        set_long( @LONG
    一支由漂亮藍寶石打製成的鑰匙。你可以用它直接  < insert 某地方 > 來開
啟特定的東西。
LONG    );
        set( "unit", "支" );
        set( "weight", 20 );
        set( "value", ({ 50,"silver"}) );
        set("no_sale",1);
}

void init()
{
  add_action("do_unlock", "insert");
}

int do_unlock(string arg)
{
  object here,book;
  
  if (arg!="wall_hole")
    return notify_fail("你試了半天，一點結果也沒有。\n");
  if (!this_player()->query_temp("can_insert_key"))
         return 0;
  here=environment(this_player());
  if (here->query("wall_box_for_mar_short"))
    if (present("wraith elder",here))
      return 
        notify_fail("你發現矮靈族長老正惡狠狠地盯著你，只好趕緊落荒而逃。\n");
    else   
      if (here->query("have_book")) {
        tell_object(this_player(),@LONG
你把藍寶石鑰匙插進牆上的暗洞，颼的一聲，鑰匙被吸了進去，並彈出一本小冊
子。你順手就把小冊子接了起來。
LONG  );
        here->set("have_book",0);
        seteuid(getuid());
        book=new(OOBJ"sword_book1.c");
        book->move(this_player());
        this_object()->remove();
        return 1;
      }
      else {
        tell_object(this_player(),
          "你把藍寶石鑰匙插進牆上的暗洞，可是鑰匙又彈了出來。\n"
          );
        return 1;     
      }
  return 0;      
}
