                 謫仙島區域開放說明----odin

I.背景大綱:

    本島的背景是以三族合戰做基礎，各族的歷史及背景，都希望以
各說各話的方式來設定；東方的區域是由魔族飄移至此所開闊，南方
則是原住民的蜥蜴人族，西方則是由一群落難的人類武士在此建立的
城堡；位置則是接近東方大陸的一個島，與東方大陸的交通是由一道
稱為『遁甲之門』的傳送工具來運送，由於該島四周都是洶湧的暗潮
，無法以船隻航行來往，所以這個島長年以來彷佛披著神秘面紗似的
，一直與外界孤立。


II.任務概要:
   三族戰爭,發動方法:
            (1) 完成 tsunami 的任務三,可以得到原神一顆
            (2) 將原神給(give)聖騎士金身,金身將變回聖騎士,然後走下樓(
                聖騎士)
            (3) 若是完成tsunami的任務者，將得到一把創世神戟(一天一把)
            (3)在有和平碑處,乞求(beg Lizard Holy Knight),將發動戰爭
(關於戰爭用的npc,分別列在tsunami,ishige,mercury的QC檔中)


     
III.NPC 列表:(/o/open/odin/island/monster)
NAME    FILE_NAME  LV  AC/DB  WC/MAX/MIN  WEAPON  ARMOR      備註
一虛    e-shi      19  80/18  53/38/16    ------  流雲靴     .使用五種七十二絕
                                                  六祖袈裟    技(包括金剛不壞)
                                                             .提供有關戰爭訊息
                                                             .對玩家特難,所以
							      LV19

聖騎士  holy_knight 19 130/47 105/68/36   ------  鈦合金覆面 .與戰爭有關 
                              85/25/50            鈦合金護手 .難度特高,exp
                                                  鈦合金臂環  5000 
                                                  鈦合金鎧甲 .原則上,不希望被
                                                  鈦合金尾甲  殺,一次reboot一
                                                  鈦合金戰靴  只,被殺就沒戰爭!
                                                  藍寶石項鍊
                                                  藍寶石戒指

小販    vendor      19 90/30  95/68/26    ------  ---------- .可殺 *grin* 


稅官    taxman      18 100/40 80/21/73    ------  ---------- .會隱形,有wimpy
							      稅抽1/3
    
錢掌櫃  shopkeeper  12 35/15  24/22/14    ------  ---------- .原本不可殺,ask
                                                              thief後變身成lv
                                                              12的錢行次郎
                                                             .特殊攻擊:金錢鏢
                                                              成功:damage 18
                                                              失敗:victim得4 
                                                                   gold

蜥蜴獵人lizardman   9  26/13  29/29/15   蜥蜴短劍 蜥蜴人短甲 .帶個補獸袋

大白鯊  shark       18 78/30  80/67/31   -------  ---------- .會追人
  
章魚    octpus      14 62/30  62/34/18   -------  ---------- .特殊攻擊:捆人
                                                              damage:14+
                                                                random(20)

章魚    octpus1     10 45/19  44/23/10   -------  ---------- .特殊攻擊:捆人
							        damage:10+
								random(11)

櫻花鮭  salmon      10 50/20  27/23/12
                              15/18/8    -------  ---------

鬼魅烏鴉spec_crow   4  10/1   11/11/4    -------  ---------  .特殊攻擊:
							       codition:WEAK  

烏鴉    crow        2  10/4   6/8/4      -------  ---------

小魚    s_fish      5  25/8   16/12/6    -------  ---------


松鼠    squirrel    2  7/0    7/6/3      -------  ---------


巨龜    turtle      6  20/0   10/12/4    -------  ---------   .所有烏龜會相
                                                               互扶持....:)

老龜    turtle1     8  25/6   11/16/6    -------  ---------

小龜    turtle2     3  15/0   8/9/3      -------  ---------

壯年龜  turtle3     11 33/12  17/22/10   -------  ---------




IV.OBJ 列表:(/open/odin/island/obj)
NAME     FILE_NAME    TYPE  用途
補獸袋   bag          ----  普通袋子,比八寶帶差!

收據     bill         ----  quest 用,亂放東西會收到一張收據 ......*Grin*

百草丹   green_pill   ----  藥店賣的,與一般相同
 
小還丹   small_pill   ----  
    
大還丹   large_pill   ----

斷續膏   spicy_plater ----  

雲南白藥 white_plater ----

枇杷膏   paste        ----  恢復tp,100點

紀念碑   stone        ----  發動戰爭用,戰爭爆發stone將消失


V.WEAPON 列表:(/open/odin/island/weapon)

NAME        FILE_NAME  TYPE        WC/MAX/MIN   備註

創世神戟    jousting   jousting    45/25/55

蜥蜴人短劍  sword01    shortblade  15/19/8



VI.ARMOR 列表:(/open/odin/island/obj)
NAME       FILE_NAME  TYPE   MATERIAL    AC/DB  備註
流雲靴     boots01    feet   cloth       8/3
 
鈦合金戰靴 boots02    feet   light_metal 8/3

六祖袈裟   cloth01    body   cloth       32/5   special_defense:
						  fire,none : 20

蜥蜴人短甲 plate01    body   leather     11/3   

鈦合金鎧甲 plate02    body   light_metal 35/5

鈦合金覆面 helmet01   head   light_metal 8/3

藍寶石戒指 ring01     finger element      0/5

藍寶石項鍊 necklace01 misc   element      0/6

鈦合金尾甲 tail01     tail   light_metal  8/3

鈦合金盾   shield01   shield light_metal  8/5

鈦和金臂環 arm01      arms   light_metal  4/3

鈦合金護手 glove01    hands  light_metal  4/4

        
VII. 未完成部份

(A).地圖:

     野外的virtual_server,地圖

(B).戰爭的功勞:

     將會發與war_score,以score為依據發給適合的武器(個人用)

     請參考/open/odin/island/weapon/psword.c

     將會有一個鐵匠之類的npc發給武器
  

