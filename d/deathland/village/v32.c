
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The squire of the dwarf village","矮人村落的廣場");
    set_long(@Long
Long
,@CLong
你目前位於矮人的村莊的大廣場上,這裡有著非常和平安詳的氣氛,矮人們經常在此地
遊玩及嬉戲.北邊有一個很大的水塘(pool),是矮人飲用水的來源 ,在水塘的中央有一個飄
浮的房子(house),你不能想像為何它能浮在空中而不掉下來.在水塘的旁邊有一個標誌(si
gn),上面似乎寫著一段文字.
CLong
    );
    set("c_item_desc",([
        "pool":"一個大水塘,由於矮人的飲用水取於此地,所以此水塘禁止游泳.\n",
        "house":"一間飄浮的房子,它有著奇怪的力量,當你注視著它的時候,你發現有一\n"
                "奇異的光線從裡面射了出來.\n",
        "sign":"\nOSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSO\n"
               "O              飄扶之屋,閒人勿進                        O\n"
               "O              回答(answer)密語,請君入甕                O\n" 
               "O              ...........長老 安洛(Annow)              O\n"
               "OSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSCSO\n"
                ]) ); 
    set("exits",([
                "west":Deathland"/village/v22",
                "east":Deathland"/village/v42",
                "south":Deathland"/village/v31",
             ]));
    ::reset();
}

void init()
{
     add_action("to_answer","answer");
}

int to_answer(string str)
{
    if (!str ||str!="intelligence")
    return notify_fail(
           "房屋中傳來一陣笑聲,說:愚蠢的人愚蠢的答案.\n");
    else
           write("一陣柔和的光線把你傳送至飛天小屋內.\n");
           this_player()->set_explore("deathland#26");
           this_player()->move_player(Deathland"/village/v33",({
           "一陣光束籠罩著%s,然後他就消失了.\n",
           "%s被送到這裡.\n"}),"" );       
           return 1;
}  
   
