#include <mudlib.h>
#include "/u/s/smore/hawk.h"
inherit MONSTER;

void create ()
{
        ::create();
        set_level(7);
        set_name("Hawkman Flamen","鳥人族祭司");
        add("id",({"","hawkman","flamen"}) );
        set_short("鳥人族祭司");
        set_long(@C_LONG
你看到一個在祭檀上誠心祈導的老頭子，大概是鳥人族的祭司吧。你覺得他在
這邊說不定已經好久好久了，應該知道一些祭壇的故事(story)吧。
C_LONG
        );
        set("alignment",300);
        set( "gender", "male" );
        set( "race", "hawkman");
        set( "unit", "位" );
        set_perm_stat( "dex",5);
        set_perm_stat( "int",12);
        set_perm_stat( "karma",3);
        set_natural_weapon(12,10,20);
        set_natural_armor(25,10);
        set("inquiry",([
                "story":"@@ask_story",
                        ]) );
        set("aim_difficulty",(["critical":30, "vascular":30]) );
}


int ask_story()
{
        tell_object(this_player(),@LONG
鳥人族祭司對你說：
　　祭壇底下就是每年舉行武鬥大會的地方，參加比武的勇士們在這兒接受神的祝
福。不過最近裘拉根在武鬥場養了許許多多從黑暗世界來的怪物，真不知道他在想
些什麼，長老和阿道夫要是不採取一些行動，神明一定會發怒的。
LONG
        );

        return 1;
}
