#include <mudlib.h>
#include "../legend.h"
inherit ROOM;

int be_knock=0;
void create()
{
    ::create();
    set_short( "山腰" );
    set_long(@C_LONG
你現在正走在一條山路上。路旁長滿了一些不知名的白色花朵，聞起來有點淡
淡的香氣。在花朵上有幾隻蝴蝶翩翩地飛舞著，盡情地吸吮著花蜜；花叢裡還有蚱
蜢跳來跳去，一副不怕人的樣子，路旁樹上的鳥兒正呼朋引伴地高歌，似乎很快樂
的樣子。或許，你該放下手邊的工作，投入大自然的懷抱裡，誠所謂「休息是為了
走更長的路」。在旁邊有一顆樹，樹身上一條條的痕跡似乎是動物的爪子留下來的
。
C_LONG
    );
    set( "light",1);
    set( "exit_suppress", ({
      "nwu","sd" }) );
    set( "exits", ([
     "southdown":LAKE"mountain8",
            "sd":LAKE"mountain8", 
     "northwestup":LAKE"mountain6",
            "nwu":LAKE"mountain6" 
    ]) );
    set( "c_item_desc", ([
      "tree" : @C_LONG
一棵斑白的樹木，長得還算茂盛，樹幹周圍是一條條的痕跡。樹上有個不小的
洞，那似乎是動物的巢穴，或許你敲一敲(knock) ，說不定會有什麼從裡面掉
下來也說不定。
C_LONG
    ]) );
    set("objects",([
     "cat#1":LMONSTER"cat",
     "cat#2":LMONSTER"cat",
    ]) );
    reset();
}
void init()
{
    add_action("do_knock","knock");
}
int do_knock(string arg)
{
   object ball;
   if ( present("wild cat",this_object()) ) return 0;
   if (!arg || arg!="tree") return 0;
   if ( be_knock ) return 0;
   tell_object(this_player(),"你用力地敲這顆樹幹，從上面的洞裡掉下一顆珠子。\n");
   ball=new(LITEM"sea_ball");
   ball->move(this_object());      
   be_knock=1;
   call_out("back",300);
   return 1;
}
void back()
{
  be_knock=0;
} 
void reset()
{
   be_knock=0;
   ::reset();
}