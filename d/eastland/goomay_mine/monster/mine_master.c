
#include <../zeus.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(19);
        set_name( "Master", "段老大" );
        add ("id",({ "master"}));
        set_short( "a master of mine","礦坑主人－段老大");
        set("unit","位");
        set_long(@C_LONG
他就是有當今天下第一鑄劍師的劍廬主人段鐵的大哥，他主掌著段家鑄劍
業的命脈**礦坑**由於他精深的功夫，以及過人的頭腦才得以將這片人人
眼紅的礦區保存下來．
C_LONG
);
        set ("gender", "male");
        set ("race", "dwarf");
        set_natural_armor( 70, 20 );
        set_natural_weapon( 40, 20, 40 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 30 );
        set_perm_stat( "dex", 30 );
        set_skill( "axe", 90 );
        set_skill( "parry", 80 );
        set( "tactic","berserk");
        set( "hit_points", 1200 );
        set( "max_hp", 1200 );
        set( "special_defense", ([ "cold": 40 ]) );
	set( "wealth/gold",100);
	wield_weapon(ZOBJ"/tang_axe");
	equip_armor(ZOBJ"/black_armband");
	equip_armor(ZOBJ"/black_boots");
	equip_armor(ZOBJ"/king_robe");
	equip_armor(ZOBJ"/diamond_ring");
	set("inquiry",([
	"magic magnetite":"@@ask_magic_metal",
	"troll" :
"唉！鋼鐵巨人原本是我請來保護魔法磁鐵礦，可是他見寶物\n"
"就起了歹心現在將鐵礦霸佔住不讓任何人拿走，只要你能把它取到手就可\n"
"以交給段鐵幫你鑄出一把絕世武器！\n" 
]));
}
void ask_magic_metal()
{ 
    tell_object(this_player(),
@ASK

天下奇寶，有德者居之．只要你能打敗我，就有希望殺死巨人取得寶物！
如果你打不贏我就不要去巨人那裡送死！來吧！

ASK
);
     kill_ob(this_player());
     this_player()->set_temp("ask#metal",1);
}
     
void die()
{      object ob,who;
      who=query_current_attacker();
  if(who->query_temp("ask#metal")){ 
tell_room(environment(this_object()),
"\n不錯！你贏了！希望你能找到巨人的弱點，並且殺死他他拿到魔法磁鐵礦，\n"
"做出一把天下無敵的神兵利器．這些裝備留給你希望對你有所幫助，我必須\n"
"去閉關療傷了．把拉桿拉動就可以消掉礦坑內的機關了．\n\n",
this_object()  );
 set("alt_corpse",ZMOB"/mine_master");
  ob=present("master");
   ob->remove();
::die(1);
}else{
::die(1);
}
}