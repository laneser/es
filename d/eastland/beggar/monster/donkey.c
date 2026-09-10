#include "../dony.h"
inherit MONSTER;
inherit MOUNT;
 
void create()
{
        ::create();
        set_level(16);
        set_name( "donkey", "大笨驢" );
        add( "id", ({ "donkey" }) );
        set_short( "大笨驢" );
        set_long(@C_LONG
這是一頭年紀蠻大的大笨驢。它的一支眼睛已經瞎掉了,嘴巴裡面也只剩下幾顆稀
稀疏疏的牙齒, 走起路來搖搖擺擺尾巴一甩一甩的,嚇!尾巴還會卷三個彎兒呢!如
果你不怕難為情,還可以騎著 ( mount ) 它到處去看看,不過小心它看到美女可會
『蹄蹄蹄』的叫著呢。 
C_LONG
        );        
        set( "unit", "匹" );
        set( "race", "monster");
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "int", 15 );
        set_perm_stat( "con", 25 );
        set_perm_stat( "kar", 25 );
        set_natural_weapon( 45,40,60 );
        set_natural_armor( 76,39 );
        set_skill("dodge",60);
        set( "alignment", 0 );
        set( "extra_look","$N正騎著一頭大笨驢上，看起來好糗喔。\n");
        set( "mountable", 1);
        set( "max_load", 2500 );
        set_c_limbs( ({ "頭部", "身體", "後腿", "尾巴" }) );
        set_c_verbs( ({ "%s抬起後腿, 往%s一踢", 
                        "%s的尾巴往%s一卷",
                        "%s用牙齒往%s一咬"}) );
        equip_armor(DARMOR"saddle");
}
void relay_message(string class, string msg)
{
  
     string who, str;
     object player;
          
     ::relay_message(class, msg);
     if( sscanf( msg, "%s(%s)走了過來。", str,who )==2 ) {
        if( !player = find_player(lower_case(who)) ) return;
        if( (string)player->query("gender")=="female"){  
            tell_object(player,
               "大笨驢用色色的眼光盯著你瞧,發出『蹄蹄蹄』的叫聲!!\n");                 
            tell_room(environment(this_object()),
               "大笨驢發出『蹄蹄蹄』叫聲,你往四周一看,哇!原來是有"+
               player->query("c_name")+"這個美女走了過來!!\n",player);
        }
     }
}
void init()
{
    mount::init();
}
