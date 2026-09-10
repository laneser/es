// File: /d/eastland/haiwei/temple1.c

#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("道觀");
        set_long( @C_LONG_DESCRIPTION
這是一間道觀，其上供奉的是真武大帝，雖然不太大，但是十分乾淨，左側
有一個香爐，現今有幾許輕煙嫋嫋，看來此間道觀的信徒不少，右側有一個大箱
子(box)。
C_LONG_DESCRIPTION
        );
    set("objects",([
        "toaist":"/d/eastland/haiwei/monster/toaist"]));
        set( "light", 1 );
        set( "item_desc", ([ 
                "box" : "這是一個供俸箱\n"]) );
        set( "exits", ([ 
                "west" : "/d/eastland/haiwei/temple_square" ]) );
        reset();
}


void init()
{
        add_action( "do_put", "put" );
}

int do_put(string arg)
{
        string type;
        int num;
        object ob1;

        if( !arg || arg=="" || sscanf( arg, "%d %s",num, type)!=2 )
                return notify_fail( can_read_chinese()?
                        "放什麼？\n": "Put whom what?\n" );
        if( !this_player()->debit(type, num) ) return notify_fail( can_read_chinese()?
                "你沒有那麼多錢。\n": "You don't have that many coins.\n" );
    if (present("toaist",this_object())){
       this_player()->credit(type,-num);
       write(can_read_chinese()?
          "老道說：既然你已表達你的誠意，就給你一張收妖符吧。\n":
          "\n");
       ob1=new("/d/eastland/haiwei/obj/paper");
       ob1->move(this_object());
       return 0; 
      }  
}       
