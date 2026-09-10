#include <mudlib.h>

inherit MONSTER;

void create ()
{
       ::create();
       set_level(13);
       set_name( "silver mollusk", "銀線蛞蝓");
       add( "id", ({ "mollusk" }) );
       set_short( "銀線蛞蝓");
       set("unit","只");
       set_long(@LONG
一隻碩大無朋的陸生蛞蝓。兩道亮銀線由頭部中心開始平行的劃過略帶粉紅而透明的
軀幹一直到尾部，爬過的地方都覆蓋上一條似由冰霜結成的白色粉狀痕跡，看它悠閒
的在你面前爬來爬去，讓你忍不住就想做弄它一番。
LONG    );
       set_skill("dodge",90);
       set_natural_weapon(45,5,10);
       set_natural_armor(10,40);
       set_c_verbs(({
         "%s緩緩的靠向%s",
         "%s黏住了%s",
         "%s貼上了%s",
         "%s吐出透明的分泌物沾住了%s",
         "%s爬過%s",
         }));
       set_c_limbs(({"腹部","頭部","尾部"}));
}
