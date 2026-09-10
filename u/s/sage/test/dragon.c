//back_dragon.c

#include <mudlib.h>
inherit MONSTER;
inherit MOUNT;

void create ()
{
        ::create();
        seteuid( getuid() );
   set_level(19);
   set_name( "back dragon", "黑龍" );
        add ("id", ({ "bird", "dragon", }) );
   set_short( "黑龍" );
        set_long( @C_LONG
    傳說中邪惡的神靈，只要它出現，大地將變的戰火連篇，人世間將永遠得
不到安寧，除非是勇者出現，否則這種情況將持續下去。它正用邪惡的眼睛看
著你，不斷地向你嘿嘿冷笑。
C_LONG
        );
   set( "alignment", 1000 );
    set( "unit", "條" );
   set_perm_stat( "dex", 30 );
   set_perm_stat( "str", 30 );
   set_perm_stat( "int", 30 );
   set_perm_stat( "con", 30 );
   set_perm_stat( "piety", 30 );
   set_perm_stat( "karma", 30 );
   set_natural_weapon( 100, 50, 88 );
   set_natural_armor( 100, 60 );
   setenv( "C_MIN", "一隻$N在天空中一閃而過。");
        setenv( "C_MOUT", "$N閃電般地向$D飛去。");
        set ("special_defense",
            ([ "all" : 30 ]) );
        set ("wimpy", 100);
        set_skill( "dodge" ,100);
        set ("moving", 1);
        set ("speed", 20);
   set( "mountable", 0 );
   set( "max_load", 2200 );
   set( "c_extra_look", "$N正坐在一條黑龍。\n");
    set ("weight", 900);
   set( "exp_reward", 3333 );
    set ("time_to_heal", 5);
    set_c_verbs( ({ "%s撞到%s身上", "%s一腳踢在%s臉上", "%s一爪抓到%s",
                    "%s用大嘴咬%s", }) );
    set_c_limbs( ({ "龍身", "龍角", "龍嘴", "龍腳", "龍尾", "龍爪", }) );
    set( "c_death_msg", "%s說: 你們會後悔的:( .... 然後就死了。\n" );
}

void init()
{
   npc::init();
   mount::init();
   add_action( "hit_enemy", "hit" );
}

int accept_item(object who,object item)
{
   object obj;
   obj = new( "/d/noden/moyada/obj/saliva" );

        tell_room( environment(),
             "黑龍狂叫一聲: 傲....\n"
             "黑龍把"+item->query("c_name")+"一口吃掉!?\n" );
        item->remove();
        if( this_object()->query("mountable") ) {
            if( random(60)>1 ) return 0;
            tell_room( environment(),
            "黑龍滴下了一灘口水, 真髒啊!\n" );
            obj->move(environment(this_object()));
            return 1;
        }
        else {
            tell_object( who, "你現在可以騎黑龍了!\n" );
            set( "mountable", 1 );
            return 1;
        }
        return 1;
}

int catch_huntee( object who )
{
    tell_room( environment(this_object()),
       "黑龍狂叫一聲: 又是你這殺人魔王，看招!\n"
      ,  ({ this_object(), who }) );
    tell_object( who, "黑龍狂叫一聲: 又是你這殺人魔王，看招!\n" );
    return 1;
}

int hit_enemy(string arg)
{
   object owner, target;

   owner = environment(this_object());

   if( !living(owner) )
        return notify_fail("黑龍不聽你的指揮。\n");
   if( !arg ) return notify_fail("你想咬誰？\n");
   if( !target = present(arg,environment(owner)) )
        return notify_fail("這裡沒有那種東西。\n");
   if( arg == (string)owner->query("name") )
        return notify_fail("咬自己？你瘋啦？\n");
   if( !living(target) )
        return notify_fail("黑龍張開大嘴用力的咬了"
                        +target->query("c_name")+"但是什麼事也沒發生。\n");
   if( !visible(target,owner) )
        return notify_fail("你想咬誰？\n");
   if( !owner->query_vision() )
        return notify_fail("這裡一片漆黑 ! 你什麼也看不到 !!\n");
   if ( target->query("no_attack") )
        return notify_fail("這傢伙－不能殺。\n");
   if( userp(target) && (int)target->query_level()< 5 )
        return notify_fail("你不能 PK 他 !!\n");
   if( "berserk" == (string)owner->query("tactic") )
        return notify_fail("你必須換另一種戰術。\n");
   if( "melee" == (string)owner->query("tactic") )
        return notify_fail("你必須換另一種戰術。\n");
   if( "assault" == (string)owner->query("tactic") )
        return notify_fail("你必須換另一種戰術。\n");
   if( (int)owner->query("talk_points")<100 )
        return notify_fail("你的交談能力太低了!\n" );
   if( target->query_temp("dodge_hit2") ) {
        tell_object( owner,
            "\n你命令黑龍向對方咬去, 但是敵人閃過了!\n\n" );
        tell_object( target,
             "\n黑龍向你咬來, 但是你閃過了!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"騎著黑龍咬向"+target->query("c_name")+"\n\n",
        ({ owner,target }) );
        owner->add("talk_points", -50);
        target->kill_ob(owner);
        owner->kill_ob(target);
        return 1;
   }
   else {
        tell_object( owner,
            "\n你命令黑龍向對方的腿部咬去, 敵人被咬去了一塊肉!\n\n" );
        tell_object( target,
            "\n黑龍向你腿部咬來, 你被咬地鮮血淋漓，摔倒在地上了!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"騎著黑龍咬向"+target->query("c_name")+"腿部\n\n",
        ({ owner,target }) );
        owner->add("talk_points",-100);
        target->kill_ob(owner);
        owner->kill_ob(target);
        target->block_attack(3);
        target->set_temp("msg_stop_attack",
            "( 你腿部受傷，無法攻擊！ )\n" );
        target->set_temp("dodge_hit2",1);
        return 1;
   }
   return 1;
}
//back_dragon.c

#include <mudlib.h>
inherit MONSTER;
inherit MOUNT;

void create ()
{
        ::create();
        seteuid( getuid() );
   set_level(19);
   set_name( "back dragon", "黑龍" );
        add ("id", ({ "bird", "dragon", }) );
   set_short( "黑龍" );
        set_long( @C_LONG
    傳說中邪惡的神靈，只要它出現，大地將變的戰火連篇，人世間將永遠得
不到安寧，除非是勇者出現，否則這種情況將持續下去。它正用邪惡的眼睛看
著你，不斷地向你嘿嘿冷笑。
C_LONG
        );
   set( "alignment", 1000 );
    set( "unit", "條" );
   set_perm_stat( "dex", 30 );
   set_perm_stat( "str", 30 );
   set_perm_stat( "int", 30 );
   set_perm_stat( "con", 30 );
   set_perm_stat( "piety", 30 );
   set_perm_stat( "karma", 30 );
   set_natural_weapon( 100, 50, 88 );
   set_natural_armor( 100, 60 );
   setenv( "C_MIN", "一隻$N在天空中一閃而過。");
        setenv( "C_MOUT", "$N閃電般地向$D飛去。");
        set ("special_defense",
            ([ "all" : 30 ]) );
        set ("wimpy", 100);
        set_skill( "dodge" ,100);
        set ("moving", 1);
        set ("speed", 20);
   set( "mountable", 0 );
   set( "max_load", 2200 );
   set( "c_extra_look", "$N正坐在一條黑龍。\n");
    set ("weight", 900);
   set( "exp_reward", 3333 );
    set ("time_to_heal", 5);
    set_c_verbs( ({ "%s撞到%s身上", "%s一腳踢在%s臉上", "%s一爪抓到%s",
                    "%s用大嘴咬%s", }) );
    set_c_limbs( ({ "龍身", "龍角", "龍嘴", "龍腳", "龍尾", "龍爪", }) );
    set( "c_death_msg", "%s說: 你們會後悔的:( .... 然後就死了。\n" );
}

void init()
{
   npc::init();
   mount::init();
   add_action( "hit_enemy", "hit" );
}

int accept_item(object who,object item)
{
   object obj;
   obj = new( "/d/noden/moyada/obj/saliva" );

        tell_room( environment(),
             "黑龍狂叫一聲: 傲....\n"
             "黑龍把"+item->query("c_name")+"一口吃掉!?\n" );
        item->remove();
        if( this_object()->query("mountable") ) {
            if( random(60)>1 ) return 0;
            tell_room( environment(),
            "黑龍滴下了一灘口水, 真髒啊!\n" );
            obj->move(environment(this_object()));
            return 1;
        }
        else {
            tell_object( who, "你現在可以騎黑龍了!\n" );
            set( "mountable", 1 );
            return 1;
        }
        return 1;
}

int catch_huntee( object who )
{
    tell_room( environment(this_object()),
       "黑龍狂叫一聲: 又是你這殺人魔王，看招!\n"
      ,  ({ this_object(), who }) );
    tell_object( who, "黑龍狂叫一聲: 又是你這殺人魔王，看招!\n" );
    return 1;
}

int hit_enemy(string arg)
{
   object owner, target;

   owner = environment(this_object());

   if( !living(owner) )
        return notify_fail("黑龍不聽你的指揮。\n");
   if( !arg ) return notify_fail("你想咬誰？\n");
   if( !target = present(arg,environment(owner)) )
        return notify_fail("這裡沒有那種東西。\n");
   if( arg == (string)owner->query("name") )
        return notify_fail("咬自己？你瘋啦？\n");
   if( !living(target) )
        return notify_fail("黑龍張開大嘴用力的咬了"
                        +target->query("c_name")+"但是什麼事也沒發生。\n");
   if( !visible(target,owner) )
        return notify_fail("你想咬誰？\n");
   if( !owner->query_vision() )
        return notify_fail("這裡一片漆黑 ! 你什麼也看不到 !!\n");
   if ( target->query("no_attack") )
        return notify_fail("這傢伙－不能殺。\n");
   if( userp(target) && (int)target->query_level()< 5 )
        return notify_fail("你不能 PK 他 !!\n");
   if( "berserk" == (string)owner->query("tactic") )
        return notify_fail("你必須換另一種戰術。\n");
   if( "melee" == (string)owner->query("tactic") )
        return notify_fail("你必須換另一種戰術。\n");
   if( "assault" == (string)owner->query("tactic") )
        return notify_fail("你必須換另一種戰術。\n");
   if( (int)owner->query("talk_points")<100 )
        return notify_fail("你的交談能力太低了!\n" );
   if( target->query_temp("dodge_hit2") ) {
        tell_object( owner,
            "\n你命令黑龍向對方咬去, 但是敵人閃過了!\n\n" );
        tell_object( target,
             "\n黑龍向你咬來, 但是你閃過了!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"騎著黑龍咬向"+target->query("c_name")+"\n\n",
        ({ owner,target }) );
        owner->add("talk_points", -50);
        target->kill_ob(owner);
        owner->kill_ob(target);
        return 1;
   }
   else {
        tell_object( owner,
            "\n你命令黑龍向對方的腿部咬去, 敵人被咬去了一塊肉!\n\n" );
        tell_object( target,
            "\n黑龍向你腿部咬來, 你被咬地鮮血淋漓，摔倒在地上了!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"騎著黑龍咬向"+target->query("c_name")+"腿部\n\n",
        ({ owner,target }) );
        owner->add("talk_points",-100);
        target->kill_ob(owner);
        owner->kill_ob(target);
        target->block_attack(3);
        target->set_temp("msg_stop_attack",
            "( 你腿部受傷，無法攻擊！ )\n" );
        target->set_temp("dodge_hit2",1);
        return 1;
   }
   return 1;
}
