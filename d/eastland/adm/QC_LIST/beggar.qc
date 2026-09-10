
                      『薪膽村』區域簡介(僅就目前已完成做描述)

                      作者：Dony

I.歷史背景：

        大約在二百八十年前,中原江湖上各大幫派林立;多餘萬人的大幫會少說
    有二、三百個;小如一、兩百人的小派門更是不下千個,一時風雲湧起襲捲著
    武林的每一個角落。
        然而, 學過經濟學的人都知道,在這塊有限的土地資源之下,一旦幫派多
    了起來相對的能分配給眾人的區域就少了起來。 更由於人類的惡根性---『
    深信著暴力就能夠解決一切』的支使之下, 凡是有地盤之爭或者彼此理念不
    同或者其它的芝麻小事都能使人大動幹伐。若是單純兩派之鬥還好,就是有那
    些想趁火打劫,想從中分一杯羹的, 往往引得一派的覆亡累至滿門於一夜之間
    悉數消失殆盡。不過總是有人會看不慣因而從中加以調停,調停的結果雖然表
    面上能使之罷鬥,但彼此總還會有或多或少的隙縫存在, 甚至有那些不甘於調
    停結果的,往往呼朋引伴其結果是引來更大的鬥爭。這時, 就有些屬於『較大
    』的門派倡議大家選一個武林盟主來領導眾人, 頗得江湖中人的支持。但是,
    人人為爭那一個盟主席位更是打的頭破血流,引來的卻是另一場更大的血腥。
    出乎意料的是,武林盟主卻能夠帶來江湖上數十年的安寧, 想必是人類天生的
    努役性驅使吧!數十年之後,武學日式衰微,江湖上再也找不到一個足以擔當武
    林盟主之位的人,於是,干戈大起,引發了一場更大的浩劫。   
        這時正值異族入侵,朝廷正苦於無法把整個中原勢力納入統治之中, 更樂
    於那些武人自相殘殺,但為保千秋大業, 把整個幫會勢力給連根拔起是免不了
    的。於是,朝廷計劃籌謀,正當佈置好了所有準備,但恰逢武林盟主相安後的數
    十年,卻告作廢。無奈數十年之後,武林自鬥並且給了朝廷一個最大的機會,朝
    廷也知道這個良機一蹤即失,遂派遺鷹門爪牙逐一剷除各大幫派。出手不外乎
    是威脅利誘,如有順從歸順那是最好不過,不服就連根給拔起, 手段極其狠毒,
    僅僅幾個月之間,各大幫派已十之去九,這時武林像一盤散沙,又有那一個派門
    抵擋得了呢?
        位天下第一大幫的丐幫在面臨朝廷這波的攻擊之下,不免也有些狠狽, 更
    何況在異族還未入侵之前,丐幫處處在反著;入關之後,丐幫又到處滋擾生事,
    種種舉動早已被朝廷視為眼中釘,背後的芒刺。丐幫在朝廷的一場決戰裡,自八
    袋弟子已上,悉部陣亡,所幸一名七袋見得快,得以保住幫中重要的物事,更憂於
    朝廷防不勝防的攻勢,無奈只好退居到一處隱密之處,俟機復幫, 並把所在之地
    命名為『薪膽村』取'臥薪嚐膽'之意....... 
                                                            前事完           

                               ps 沒想到我還真會掰

II.商店：
       
       I). 買賣 eq ( /u/d/dony/beggar/store.c)
       II).藥鋪    ( /u/d/dony/beggar/hospital1.c)
       III).賭坊   ( /u/d/dony/beggar/game_room.c)
      
III.任務概要：

       I). 幫忙幫主找回打狗棒



IV.怪物 : /u/d/dony/monster

   怪物名稱    檔名    等級 AC/DB  WC  傷害範圍  武器裝備    特殊能力    

丐幫幫主 喬峰 master.c  19  56/83  115  51/73    束雲戒指    1.解 quest 
                                                 束雲頭帶    2.打落別人
                                                 束雲腰帶      武器
                                                 束雲白袍    3.火系傷害 

囚犯 不知名  prisoner.c 19  55/57  104  41/62    阿修羅之戒  1.block_command
         ( ch_prisoner.c  19  70/70  125  46/82 )            2.讓人混亂
                                                          (  3.火系攻擊
                                                             4.冰系攻擊
                                                             5.讓人遲緩 )
                                                    
祠堂老院長 old_garden.c 19  80/0   70   30/55    破掃帚      1.解 quest
                                                 元氣玉      2.反彈攻擊

江湖術士 神算小瓜 
           soothsayer.c 19  76/55  94  37/62    誅仙劍      1.summon mob
                                                風火雷電七星袍 

陷仙劍[發狂狀態] kill1.c 19 110/50 75  36/72

絕仙劍[發狂狀態] kill2.c 19 110/50 75  36/72 

戮仙劍[發狂狀態] kill3.c 19 110/50 75  36/72
                               
畫中仙          spirit.c 19 68/67  96  30/76    絕龍牌
                                   70  27/73    冰魄銀針 
                                                打神鞭

東瀛武士 黑月 fighter.c 18  45/34  72  45/48    螺旋刃      1.解 quest
                                                 黑色緊身衣  2.邪惡系傷
                                                               害
                                                             3.一般的特
                                                               殊攻擊

一代神醫 小雪子 uki.c   17  55/58  84   28/43    小小銀針    1.解 quest
                                                 醫者護符    2.瞄 weakest      
                                                 醫者之袍         critical
                                                                  vascular    
                                          ps #2 12/6 改 aim
                                                                    
巧匠 馮阿三 blackmaster.c 17 63/50 70   40/58    倚天劍      1.解 quest
                                                 火雲護臂    2.書生解完 
                                                 冰晶盾        quest 後
                                                               給聚劍術

謎樣劍客 風飛雪         17  48/71  81   30/50    七星劍      1.冰系傷害  
        occult_swordman.c                        至陽頭帶    2.神聖傷害
                                                 元陰鬥蓬    3.邪惡系傷害  
                                                 陷阱

執法長老 白世鏡         17  52/55  57   21/36    判官筆      1.解 quest 
        law_master.c               53   21/36    判官筆
                                                 白綸巾 

天山二老 天鷺 couple1.c 17  45/42  59   26/47    黑披風      1.解 quest
                                                             2.毒系傷害
                                                             3.和天鳩一
                                                               同攻擊敵人

監牢守衛 jail_guard.c   17  85/34  65   32/40    竹棒       
 
全副幫主的女兒 月讀     16  62/56  64   30/48    七寶金幢    1.解 quest
        unary.c                                  七彩雲衣    2.會 forget 
                                                 七彩雲靴    3.aim weakest
                                                 七彩雲套

項長老  gonfu_master.c  16  30/23  50   24/45    竹棒        1.解 quest
                                                 鳩衣        2.會 block 人
                                                             3.打落武器

祠堂執事僧 enforcer.c   16  70/18  30   18/33    執事者之袍
                                                 破掃帚
                   
大笨驢     donkey.c     16  79/40  53   41/66                1.騎士可以騎 
                                                             2.會保護主人

天山二老 天鳩 couple2.c 15  40/20  49   18/36    黑披風      1.會 block 人
                                                             2.和天鷺一同
                                                               攻擊敵人

太行山沖霄洞 譚公
         tan_male.c     15  40/46  59   26/47    沖霄雲戒    1.會 healing
                                                 小盒子        group
                                                             2.和譚婆一同
                                                               攻擊敵人  
    
太行山沖霄洞 譚婆
         tan_female.c   15  40/46  59   26/47    沖霄雲戒    1.一般特殊攻
                                                 小盒子        擊
                                                             2.和譚公一同
                                                               攻擊敵人 

趙錢孫   chau.c         15  80/59  65   24/39    暖衣        1.招喚 donkey
                                                               攻擊   

丐幫 七袋弟子 seventh.c 14  75/40  48   19/26    

丐幫 六袋弟子 sixth.c   13  50/35  46   14/24       

 
小侍童        servant.c 12  55/20  25   16/23    骨刀

丐幫 五袋弟子 fifth.c   11  45/10  28   14/21 

莊稼漢 阿土仔 ahtu.c    7   55/20  26   11/23                1.exp 1150

丐幫 二袋弟子 second.c  7   15/10  24   11/19

大公雞   big_chicken.c  6   30/0   4    1/4

甲蟲          beetle.c  5   5/1    9    3/7

母公雞 mother_chicken.c 4   10/0   3    1/3

小公雞 little_chicken.c 2   5/0    3    1/3

全冠清         chan.c   1   5/2    3    1/3                   1.解 quest
                                                              2.healing 
                                                                himself       

倒在桌上的醉漢 chan_master.c                                  1.解 quest
                                                              2.cant attack

帳房 霍先生   keeper.c                                        1.解 quest
                                                              2.cant attack 


V.武器： /u/d/dony/weapon

武器名稱    檔案名稱      武器類別     WC   傷害範圍     特殊攻擊

小小銀針    needle.c      dagger       45    23/36       divine
風月魔刀    evil_glaive.c longblade    45    30/50       evil
七寶金幢    seven_blunt.c blunt        35    15/38       divine
名刀 七星劍 seven_sword.c shortblade   40  int/(int+10)  sleet
誅仙劍 god_killed_sword4.c shortblade  42    27/47
陷仙劍      kill1.c       longblade    47    27/50       bleeding
                                                         block 4
絕仙劍      kill2.c       longblade    45    27/50       bleeding
                                                         sleet
戮仙劍      kill3.c       longblade    48    27/50       bleeding
冰魄銀針    ice_needle.c  dagger       40    25/40       anatomlogy 10
打神鞭   flog_god_whip.c  whip         40    25/40       divine
倚天劍      sky_sword.c   longblade    35    20/40       sleet
螺旋刃      katana.c      longblade    35    20/35       bleeding
靈氣劍     spirit_sword.c longblade    25    18/28       隔一段時間會不見 
骨刀        blade.c       longblade    15    13/18       bleeding
判官筆      pen.c         thrusting    37    20/35     
竹棒        blunt.c       blunt        20    12/20
破掃帚      broom.c       blunt        30    15/30



VI.防具： /u/d/dony/armor

防具名稱     檔案名稱      型態     質料      AC/DB     特殊效果

束雲白袍   wind_cloth.c    body     cloth     32/9      fire:-20
                                                        cold:10
束雲頭帶   wind_helmet.c   head     cloth     7/3       
束雲戒指   wind_ring.c     finger   element   0/8
束雲腰帶   wind_belt.c     legs     cloth     7/3
阿修之戒   fighter_ring.c  finger   cloth     0/7       evil:5  
          (fighter_ring1.c)                  (0/10)     evil:10 
鳩衣       broken_cloth.c  body     cloth     10/3      fire:-10
暖衣       chau_cloth.c    body     cloth     15/4      fire:5
                                                        cold:5
絕龍牌     dragon_shield   shield   cloth     8/7
黑披風     couple_cloak.c  cloak    leather   5/2       poison:10
執事者之袍 enforcer_robe.c body     cloth     10/3    
火雲護臂   fire_armband.c  arms     element   1/5
元陰鬥蓬   fun_cloak.c     cloak    cloth     4/9       cold:5
至陽頭帶   fun_turban.c    head     cloth     4/5       fire:5
黑色緊身衣 japan_cloth.c   body     thief     15/9      evil:15
                                                        divine:-20
冰晶盾     orb_shield.c    shield   element   2/10      light 
風火雷電七星袍
       soothsayer_cloth.c  body     cloth     36/10     all:10
破馬鞍     saddle.c        saddle   leather   3/1
七彩雲靴   seven_boots.c   feet     leather   1/5
七彩雲衣   seven_cloth.c   body     cloth     26/7
七彩雲套   seven_gloves.c  hands    cloth     0/4       pie:-2
                                                        int:2
                                                        con:-2
                                                        str:-1
沖霄雲指   tan_ring.c      finger   element   0/6
白綸巾     turban.c        head     cloth     7/5       fire:-10
醫者護符   uki_amulet.c    misc     element   0/8       
醫者之袍   uki_cloth.c     body     healer    15/10     fire:-10
                                                        poison:15
                                                        acid:10

                           
VII.其他物品：/u/d/dony/item
  
       物品名稱       檔名            用途
 
       舍利子       ball.c            加全部 skill 5% , 要花 fp 80 或 int 100
       復元術       heal_spell.c      可以恢復部分的狀態
       舒跑五十     super_supra.c     加 ap 500
       小盒子       box.c             可以當 bag 用
       家書         chan_letter.c     quest 用
       打狗棒       dog_blunt.c       quest 用
       銅鑰匙       key.c             開 room jail1.c 用
       信件         letter.c          quest 用
       元氣玉       life_ball.c       『血庫』,請看 life_ball.c 的內容
       手論         password.c        quest 用
    天山九轉熊蛇丸  pill.c            quest 用
       聚劍術       spell.c           可以 clone 靈氣劍 (給書生用) 
       六陽正氣丹   sun_pill.c        quest 用
       治傷靈藥     tan_plaster.c     和 plaster 一樣,只不過一次恢復 8 hp
       陷阱材料     trap.c            可以使玩家 blockcommand 2 分鐘       

