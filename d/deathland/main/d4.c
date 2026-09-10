
#include "../echobomber.h"
inherit "/std/room/waterroom";

int can_enter;
void create()
{
   ::create(); 
   set("light",1);
   set("short","碼頭的水底");

   set("long","@@c_long");
   set("item_desc",([
    "stones":"石頭上的青苔有磨損的痕跡,你可以試著移動它\n",
    "fish":"一群奇奇怪怪的魚,似乎只有這個地方才會出現.\n"
     ]) );
   set("exits",([
              "up":Deathland"/main/d1",
              "down":Deathland"/main/d5"
             ]));

reset();
}
void init()
{
  add_action("to_move_stone","move");
  add_action("to_enter_hole","enter");
}

int to_move_stone(string str)
{
   if (!str||str=="")
     return 0;
   if (str=="stones"|| str=="stone") {
       write("你用了很大的力氣去移動石頭,漸漸地一個洞出現在你的眼前\n");

     can_enter=1;
     add( "item_desc",([
          "hole":"一個奇怪的洞,不能確定它通往何處.\n"
              ]) );
    this_player()->set_explore( "deathland#1" );
    return 1;
    }
}

int to_enter_hole(string str)
{
    if ( can_enter==0 ) return 0;
    if (!str||str!="hole") {
      write("進入甚麼地方 ?\n"); 
      return 1;
      }
    write("你小心翼翼地遊進洞穴\n");
    say("當你看到"+this_player()->query("c_name")+
         "遊進洞中,石頭再度地把洞口蓋住\n");
    this_player()->move_player(Deathland"/main/d6",
    ({"%s swim to hole,then the stone close the hole\n","當你看到%s遊進洞中後,石頭再度地把洞口蓋住\n" ,
      "%s swim from outside.\n","%s從外面遊了進來.\n"}),"");
    can_enter=0;
    return 1;
}

void reset()
{
   ::reset();
   can_enter=0;
   
}

string c_long()
{
    string longlook;

    longlook="微弱的光線從海面照射下來,你能看到一些魚(fish)在這裡游來游去.\n";
    switch( can_enter ) {         
         case 0:
           longlook+="仔細一看北方的岩石(stones)似乎常常有人搬動的樣子.\n";
           break;
         case 1:
           longlook+="仔細一看北方的岩石(stones)似乎已被人搬開了,有一個洞穴\n"
                     "出現在你的面前.\n";
           break; 
          }
    return longlook;       
}

