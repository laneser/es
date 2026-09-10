#include <mudlib.h>
int mistake = 0;
inherit MONSTER;

void create()
{
        object ob1, ob2, ob3, ob4;

        ::create();
        set_level(16);
        set_name("Juraken", "裘拉根");
        add( "id", ({"pontiff"}) );
        set_short("錫卡拉教大祭司 裘拉根");
        set_long(@CLONG
這個叫做裘拉根的人長得很高，一臉精悍神色，他的臉上從鼻子到耳朵有一
道很可怕的傷痕。當你和他的目光相遇的時候，一股莫名的寒意使你清楚的
瞭解到: 這傢伙是個不簡單的人物。
CLONG
        );
        set( "gender", "male" );
        set( "race", "human" );
        set( "alignment", -1500 );
        set( "natural_armor_class", 30 );
        set( "natural_defense_bonus", 20 );
        set( "natural_weapon_class1", 10 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 10 );
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "int", 30 );
        set_skill( "blunt", 100 );
        set_skill( "dodge", 90 );

	ob1 = new( "/d/noden/hawk/weapon/crimson_scepter" );
        ob1->move( this_object() );
        wield_weapon( ob1 );

	ob2 = new( "/d/noden/hawk/armor/crimson_robe" );
        ob2->move( this_object() );
        equip_armor( ob2 );

	ob3 = new( "/d/noden/hawk/armor/crimson_amulet" );
        ob3->move( this_object() );
        equip_armor( ob3 );

	ob4 = new( "/d/noden/hawk/armor/crimson_ring" );
        ob4->move( this_object() );
        equip_armor( ob4 );

        set( "inquiry",([
                "potion" : "@@ask_potion",
                        ]) );
}

int ask_potion()
{
        if (this_player()->query_temp("smore_box") == 2 )
        {
                tell_object( this_player(),@LONG
裘拉根看到你手上的藥水，臉上一陣青一陣白，二話不說就衝了過來。
LONG
                );
        command("kill "+this_player()->query("name") );
        mistake = 1;
        }
        else
        {
                tell_object(this_player(),@LONG
裘拉根說：啥？你說啥？然後就轉過頭去不理你了。
LONG
                );

                return 1;
        }
        return 1;

}

void die()
{
        object killer;
        if (mistake)
        {
                tell_room(environment(this_object()),@LONG
裘拉根嘆了口氣，說到：
想不到我的計劃(plan)還是失敗了，罷了罷了。

然後就口吐鮮血，倒在地上一動也不動了。
LONG
                ,this_object() );
                killer = query("last_attacker");
                if ( killer->query_temp("smore_box") == 2)
                        killer->set_temp("smore_box",3) ;
        }
        ::die(1);
}


