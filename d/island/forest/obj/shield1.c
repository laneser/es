#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Hawk Shield","光鷹盾");
    add("id",({"shield"}));
    set_short("光鷹盾");
    set_long(@LONG
這是樹雷王家高尚血統的證明。唯有擁有魔法者，才能擁有這偉大神聖
的力量。由於這份力量必須用強大的魔法力量才能支配，所以並不是一
般人所能隨意支配的。
LONG
            );
    set("unit","面");
    set("no_clean",1) ; 
    set("type","shield");
    set("material","element");
    set("armor_class",6);
    set("defense_bonus",1);
    set("special_defense",(["all":10,"none":0]) );
    set("weight",100);
    set("no_sale",1);
    set("value",({1500,"silver"}) );
    set("equip_func","daemon_wear");
    set("unequip_func","daemon_unwear");
}



void daemon_wear()
{
    if( (string)this_player()->query("race")=="daemon" ||
        (string)this_player()->query("class")=="mage"  ||
        (string)this_player()->query("class")=="healer"   ) {
      if( (int)this_player()->query_level() < 13){
        tell_object( this_player(),
        "你的魔力太小，不足以使盾將光翼伸展出來....\n");
        }
        else{
    set("prevent_drop",1);
    set("armor_class",8);
    set("defense_bonus",4);
    set("light",1);
    set("extra_look","@@color");
    set("special_defense",(["all":50,"none":30]) );
    write( set_color(
       "\n光鷹盾呼應著你的魔力，逐漸伸展出三片巨大的光翼攏罩在你的前方...\n\n"
       ,"HIW") );
    tell_room( environment(this_player()),set_color(
       "\n光鷹盾緩緩的在"+this_player()->query("c_name")+
       "的身前伸展出三片巨大的光翼.........\n\n"
       ,"HIW"),this_player() );
    set_name("Hawk Wind","光鷹翼");
    set_short("光鷹翼");
        }
    return;
    } 
    return;
}

void daemon_unwear()
{
	object holder;
	if ( !this_object() ) return ;
	if ( !holder=environment(this_object()) ) return;
//    holder=this_player();
    if( (int)holder->query_level() >= 13){
    set("armor_class",6);
    set("defense_bonus",1);
    set("light",0);
    delete("extra_look");
    set("prevent_drop",0);
    if( (string)holder->query("race")=="daemon"  ||
        (string)holder->query("class")=="mage"  ||
        (string)holder->query("class")=="healer" ) {
    tell_object( holder,set_color(
       "\n你脫手後，三片巨大的光翼緩緩的散去，恢復成平凡的光鷹盾...\n\n"
       ,"HIW") );
    tell_room( environment(holder),set_color(
       "\n"+holder->query("c_name")+
       "身前的三片光翼緩緩的散去，恢復成平凡的盾...\n\n"
       ,"HIW"),holder );
    };
    set_name("Hawk Shield","光鷹盾");
    set_short("光鷹盾"); 
    return;
    }
    else return;
}                 

string color()
{ 
  return set_color("$N的身前攏罩著三片巨大而明亮的光翼，看起來英挺極了...\n","HIW");
}
