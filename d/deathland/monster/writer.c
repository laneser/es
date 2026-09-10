
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "Dwarf poet", "矮人詩人" );
	add ("id", ({ "poet","dwarf" }) );
	set_short( "Dwarf writer", "矮人詩人" );
	set_long(@DESC
一個矮人詩人,她正在尋找寫作的靈感(afflatus)而散步在小路上,為了尋找
靈感她已經好幾天沒有睡覺了.
DESC
     );
    set( "alignment", -100 );
    set( "gender", "female" );
    set( "race", "dwarf" );
    set( "unit", "個" );
	set_perm_stat( "str", 7 );
	set ("wealth", ([ "silver": 200 ]) );
	set_natural_weapon(4,2,6);
	set_natural_armor(26,0);
    set ("weight", 300);
    set ("chat_chance", 25);
    set ("chat_output", ({
            "這作家說:可能一個好的作品需要一個好的靈感,但是那裡去找尋靈感呢?\n",
	    }) );
	set ( "inquiry",([
	      "afflatus":"@@ask_afflatus",
	      "muse":"@@ask_muse",
	      "queen":"@@ask_queen",
	      ]) );
	wield_weapon(Weapon"/dagger03");
    equip_armor(Armour"/cloth04");
}

void ask_afflatus(object who)
{
     who->set_explore("deathland#38");
     tell_object(who,
	"如果有傳說中謬思(Muse)泉的泉水的話,或者能幫我找回我的靈感.\n");  
     return;
}

void ask_muse(object who)
{
     tell_object(who,@MSG1
一個詩人之泉,據說正確的位置是在於死亡大地的最深處,但是
詳細的位置沒有幾個人知道,
對了,或許安洛長老知道,他是個很有智慧的人
MSG1
                 );
}

void ask_queen(object who)
{
     tell_object(who,"可憐的皇后, 全國的人民都為了她在擔心著\n");
}
