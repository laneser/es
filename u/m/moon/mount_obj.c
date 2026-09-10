// This is the mount object, inherited by monsters can be mounted.
// By Ruby@ES 1995-6-18

#include <mudlib.h>
inherit OBJECT;
int hit1(string arg);
void create()     
{
        if (clonep(this_object())) {
                set_default_ob("/std/mount_obj");
                return ;
        }
        set_name( "wooden horse", "小木馬" );
        set("short", "小木馬");
        set("long", "這是一匹木馬");
        set( "unit", "匹" );
        set("weight", 0);
        set("prevent_drop",1);
        set("prevent_insert",1);
}

void init()
{
        add_action( "do_dismount", "dismount" );
        add_action( "do_hit","hit");
}

int do_dismount()
{
        return call_other("/adm/daemons/mount","dismount",this_object(),this_player());
}

int scare_me()
{
        return "/adm/daemons/mount"->scare_me(this_object());
}
int do_hit(string arg)
{
   if(this_object()->query("name")=="chocobo" ||
      this_object()->query("name")=="black chocobo") return hit1(arg);
   return 0;
}

int hit1(string arg)
{
   object owner, target,me;
   int rid,deb,dod,dam;

   owner = environment(this_object());
   me=this_object();

   if( !living(owner) ) 
        return notify_fail("它不聽你的指揮。\n");
   if( !arg ) return notify_fail("你想撞誰？\n");
   if( !target = present(arg,environment(owner)) )
        return notify_fail("這裡沒有那種東西。\n");
   if( arg == (string)owner->query("name") )
        return notify_fail("撞自己？你瘋啦？\n");
   if( !living(target) )
        return notify_fail("你的坐騎用力的撞了"
                        +target->query("c_name")+"但是什麼事也沒發生。\n");
   if( !visible(target,owner) )
        return notify_fail("你想撞誰？\n");
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
   if( owner->query_skill("riding")/2 +
        random( owner->query_skill("riding")/2)
      < ( int )target->query_skill("dodge")  ) {

        tell_object( owner,
            "\n你命令"+me->query("c_name")+"向對方撞去, 但是敵人閃過了!\n\n" );
        tell_object( target,
             "\n"+me->query("c_name")+"向你撞來, 但是你閃過了!\n\n" );
        tell_room( owner,
            owner->query("c_name")+"騎著"+me->query("c_name")
             +"撞向"+target->query("c_name")+"\n\n",
        ({ owner,target }) );
        owner->add("talk_points", -50);
        target->kill_ob(owner);
        owner->kill_ob(target);
        return 1;
   }
   else {
      if(me->query("name")=="black chocobo")
      {
         rid = (int)owner->query_skill("riding");
         deb = (int)target->query("defense_bonus");
         dod = (int)target->query_skill("dodge");
         dam = rid/2 - deb/5 -random(dod)/5;
         tell_object( owner,
         "\n你命令黑色陸行鳥向對方撞去, 敵人摔倒在地, 似乎受到巨大的傷害!\n\n" );
         tell_object( target,
          "\n黑色陸行鳥向你撞來, 你摔倒在地, 似乎受到巨大的傷害!\n\n" );

         target->add("hit_points",-dam);
         owner->add("talk_points",-20);
       }
      else
       {
         tell_object( owner,
            "\n你命令"+me->query("c_name")+"向對方撞去, 敵人摔倒在地上了!\n\n" );
         tell_object( target,
            "\n"+me->query("c_name")+"向你撞來, 你摔倒在地上了!\n\n" );
         tell_room( owner,
            owner->query("c_name")+"騎著"+me->query("c_name")+
            "撞向"+target->query("c_name")+"\n\n",
         ({ owner,target }) );
        }
        owner->add("talk_points",-100);
        target->kill_ob(owner);
        owner->kill_ob(target);
        target->block_attack(3);
        target->set_temp("msg_stop_attack",
            "( 你現在摔倒在地，無法攻擊！ )\n" );
        return 1;
   }
   return 1;
}
