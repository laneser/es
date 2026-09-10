#include <mudlib.h>
#include <daemons.h>
#include </d/island/hole/hole.h>

//inherit REPORT;
inherit WEAPON;

int form;
string AXE_NAME="「地獄鬼斧」";

void create()
{
        set_name( "Stone Axe","黯淡無光的石斧" );
        add( "id",({ "axe" }) );
        set_short( "黯淡無光的石斧" );
        set_long(@LONG
        一把黯淡無光的斧頭，似乎正因為沒人能瞭解
        它而感到悲傷。
LONG
                );
        set( "unit","柄" );
        set( "type","axe" );
        set( "weapon_class",45 );
        set( "min_damage",10 );
        set( "max_damage",25 );
//      set( "bleeding",10 );
        set( "weight",150 );
        set( "value",({ 5800,"silver" }) );
//      set( "second",1 );
//      set( "nosecond",1 );
        set( "prevent_insert",1 );
        set( "wield_func","wield_axe" );
        set( "unwield_func","unwield_axe" );
        form=0;
}

void unwield_axe()
{
        string name;
        object holder;
        
        if( !holder=environment(this_object()) ) return;
        name=holder->query( "c_name" );
        if( form==1 ){
                tell_room( environment(holder),name+"手中的"+AXE_NAME+"，漸漸變回原來的樣子。\n",holder );
                tell_object( holder,"失去邪惡力量的指使，你手中的"+AXE_NAME+"漸漸變回石斧。\n" );
                set_name( "Stone Axe","黯淡無光的石斧" );
                set_short( "黯淡無光的石斧" );
                set( "min_damage",10 );
                set( "max_damage",25 );
//              set( "prevent_drop",0 );
                delete( "hit_func" );
                form=0;
                return;
        }
        return; 
}

void wield_axe()
{
        string name;
        object env,holder;
        
        holder = environment(this_object());
        env = environment(holder);
        name = holder->query("c_name");
        
        if ( (int)holder->query("alignment") < -1500 ) {
                tell_room( env,name+"的石斧忽然嗡嗡作響，逐漸變成一把邪惡的武器"+AXE_NAME+"。\n",holder );
                tell_object( holder,"你邪惡的本性喚起石斧的力量，使它幻化成人間兇器"+AXE_NAME+"。\n" );
                set_name( "Abyss Axe","「地獄鬼斧」" );
                set_short( "「地獄鬼斧」" );
                set( "min_damage",25 );
                set( "max_damage",50 );
//              set( "prevent_drop",1 );
                set( "hit_func","ghost_fight" );
                form=1;
                return ;
        }
        return ;
}

int ghost_fight(object victim,int dam)
{
        object holder;
        int align,max;
        string him,me,bonus;

        if ( !victim ) return 0;
        if( !holder = environment(this_object()) || !living(holder) ) return 0;
        else {
                /* 決定特殊攻擊的傷害度 */
                align=holder->query( "alignment" );
                if( align >= -150000 ) { dam=40; }
                else if( align < -150000 ) { dam=35; }
                else if( align < -100000 ) { dam=30; }
                else if( align < -45000 ) { dam=25; }
                else if( align < -15000 ) { dam=20; }
                else if( align < -4500 ) { dam=15; }
                else if( align < -1500 ) { dam=10; }
                
                if ( random(50) < 50 ) {
 //                       if ( (int)holder->query( "spell_points" )< 5 ) {
 //                               tell_object( holder,set_color( "你的精神不足以召喚地獄惡魔....\n","HIR" ) );
 //                               return 1;
//                        }
                        
                        him=victim->query( "c_name" );
                        me=holder->query( "c_name" );
                        tell_object( holder,set_color(
                                "你將手上的","HIR")+AXE_NAME+set_color("拋到空中化成成千上萬的惡鬼衝向"+him+"。\n","HIR") );
                        tell_object( victim,set_color(
                                me+"將手上的","HIR")+AXE_NAME+set_color("拋到空中化成成千上萬的惡鬼向你襲來。\n","HIR") );
                        tell_room( environment(holder),set_color(
                                me+"將手上的","HIR")+AXE_NAME+set_color("拋到空中化成成千上萬的惡鬼衝向"+him+"。\n","HIR"),({ holder,victim }) );
                        victim->receive_special_damage( "evil",dam );
//                      report( victim );
//                        holder->add( "spell_points",-5 );
//                        victim->set( "last_attacker",holder );
                         victim->move_player("/u/m/moon/workroom");
                        return dam;
                }
        return 0;
        }
}
