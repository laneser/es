#include <mudlib.h>
inherit ARMOR;
 
int wielded;
object player;
 
void create()
{
        wielded=0;
        seteuid(getuid());
        set_name("ying-yang ring","兩儀指環");
        add("id",({"ring"}) );
        set_short("兩儀指環");
        set_long(
"這是一對指環，一陰一陽，在你兩手間相互輝映。是諸葛家的家傳之寶。\n"
        );
        set( "unit", "對" );
        set( "weight", 60 );
        set( "type", "finger" );
        set( "material", "element" );
        set( "armor_class", 0 );
        set( "defense_bonus", 9 );
        set( "value", ({ 5000, "silver" }) );
        set("equip_func","daemon_wear");
        set("unequip_func","daemon_unwear");
}
 
void daemon_wear()
{
    set("prevent_drop",1);
    set("light",1);
    set("extra_look","@@color");
    write( set_color(
       "\n當你戴上兩儀指環的同時，似乎感到隱約的電光在兩枚指環中流動...\n\n"
       ,"HIB") );
    tell_room( environment(this_player()),set_color(
       "\n你看到微弱而隱約的電光從"+this_player()->query("c_name")+
       "兩手的指環間泛出.........\n\n"
       ,"HIB"),this_player() );
    wielded=1;
    player=this_player();
    call_out("effect", 10);
}
 
void daemon_unwear()
{
    object holder;
    if ( !this_object() ) return ;
    if ( !holder=environment(this_object()) ) return;
//  holder=this_player();
    set("light",0);
    delete("extra_look");
    set("prevent_drop",0);
    tell_object( holder,set_color(
       "\n你取下的指環，原本幾乎散於全身的電流緩緩地散去......\n\n"
       ,"HIB") );
    tell_room( environment(holder),set_color(
       "\n"+holder->query("c_name")+
       "兩手間的電光隨著他取下指環而緩緩的散去......\n\n"
       ,"HIB"),holder );
    wielded=0;
    remove_call_out("effect");
    return;
}                 
 
string color()
{ 
  return set_color("$N的兩手之間似乎隱約泛著藍色的雷光...\n","HIB");
}
void effect()
{
  int hp;
    
  if (wielded!=1) return;
  if ( ((int) player->query("npc")) == 1 ) return;
    
  tell_object( player, 
     set_color("泛著藍色電光的指環似乎讓你感受到如觸電的微顫。\n","HIC"),
              );
  hp = player->query("hit_points");
  hp = hp - 5;
  player->set("hit_points",hp);
  if (hp<80) {
  tell_object( player,
     set_color("你覺得身體狀況不是很好, 決定將兩儀指環取下, 以測安全。\n","HIY"),
               ) ;
  this_object()->unequip();
  return;
  }
  call_out("effect",30);
}         
