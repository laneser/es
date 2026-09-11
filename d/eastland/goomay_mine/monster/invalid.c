#include "../zeus.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(7);
        set_name( "invalid", "病人" );
        add("id",({"invalid"}));
        set_short( "病人");
        set("unit","位");
        set_long( @LONG
這是一位全身包滿繃帶的人，躺在病床上有點無聊地看著天花板，也許他在
期待著有人來陪他講講話，他應該會告訴你他的傷(hurt)是怎麼來的
LONG
        );
        set_perm_stat("str",12 );
        set_natural_weapon(12, 6, 12);
        set_natural_armor( 40, 20 );
        set ("gender", "male");
        set ("race", "dwarf");
        set_c_verbs(({"%s用他的柺杖向%s打去","%s用他的腳向%s踢去","%s用他的拳頭向%s攻擊"}));
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        wield_weapon( ZOBJ"/stick" );

        set("inquiry",([
        "detonation":"@@ask_detonation", 
        "hurt": 
                "這身傷是在那次大爆炸中被燒傷的．\n"
      ]));
}
int ask_detonation()
{
tell_object(this_player(),
@AA
病人道：說起來也很莫名奇妙，那一天我剛好要送東西給工頭，遠遠
地只瞧見工頭不知道點燃了什麼東東，往身後一丟 (throw)結果轟一
聲！醒來時就躺在這裡了．
　　至於那東東，你可以四處找找，因為我也看到他也是隨手拿來的
．希望你能找到真相！
AA
);
this_player()->set_temp("get/paper_torch",1);
}