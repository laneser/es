#include "../iigima.h"

inherit MONSTER ;
void create ()
{
        ::create();
        set_level(6);
        set_name("Teeder","女祭司蒂德" );
        add ("id", ({"drow", "teeder" }) );
        set_short( "Teeder","女祭司蒂德" );
        set("unit","位");
        set_long(
@C_LONG
這位看來纖弱的美麗女子好像受到了相當程度的驚嚇，看她又髒又餓
地捲曲著哭泣，你還不快救她？
C_LONG
        );
        set_perm_stat("str", 6);
        set_perm_stat("int", 16);
        set_perm_stat("kar", 12);
        set ("natural_weapon_class1", 10);
        set ("natural_min_damage1", 9);
        set("natural_max_damage1",13);
        set ("natural_armor_class", 15);
         set("inquiry",([
             "help" : ({
             "烤雞，能不能讓我吃烤雞～～ \n"})
               ]));
        set("chat_chance",15);
        set("chat_output",({
            "蒂德說道：好餓，能不能幫幫(help)我．．． \n",
            "蒂德揉揉她的眼睛，不停的啜泣．．． \n"}));
    set( "special_defense", ([
        "all":15,"fire":-10,"cold":-10,"evil":30,"divine":-30,"none":5 ]) );
        set ("gender", "female");
        set("wealth/copper",3000);
   set("weight" , 300 );
        set ("race", "drow");
        equip_armor(ARM"feet");
}
int accept_item(object me, object item)
{
   string name;
   object ob;

   name=(string)item->query("name");
   if (!name || (name!="chicken"))
     return 1;
write("\n你看到蒂德三兩下就把烤雞吃掉了，好像饑民般的模樣好不可憐\n");
write("\n蒂德說道：謝謝你～～救我離開這裡，前面有個很恐怖的怪物～\n");
write("\n你等等喔～我拿個東西給你喔～～\n");
write("\n....\n");
write("\n...\n");
write("\n...\n");
write("\n..\n");
write("\n..\n");
write("\n\n");
   item->remove();
   if (!this_object()->query("wine")) {
     write("蒂德說道：這瓶術酒是村長給我的，我現在給你，希望對你有用。\n");
     ob=new(OBJ"wine");
     ob->move(this_player());
     set("wine",2);
   }
   else
  write("\n蒂德說道：歐．．．有人拿走我的術酒了～不能給你了～～\n");
   return 1;
}
