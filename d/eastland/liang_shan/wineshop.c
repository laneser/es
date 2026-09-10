#include "takeda.h"
#include <money.h>

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "梁山酒店" );
        set_long(@LONG
這裡是梁山泊最大的酒樓，山寨內的山賊和跑單幫買黑貨的商人，經
常聚在這裡享受孫二孃的美食以慰勞自己，順便交換旅行的經歷，幾名店
小二忙進忙出的顯得十分熱鬧，一陣陣的酒香，肉香撲鼻而來，你不禁覺
得飢腸轆轆，食指大動，低聲向老闆詢問價錢(menu)。
LONG
        );
        
        set( "exits", ([ 
        	"east"  : TROOM"path2" ,
        ]) );
        
        set( "objects", ([
                "owner" : TMONSTER"zhan1",
                "owner_wife" : TMONSTER"sun1",
                "guest" : TMONSTER"traveller"
        ]) );
        reset();
}
int clean_up() { return 0; }
