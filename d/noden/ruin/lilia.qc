魔族帝國遺蹟

	作者 Lilia (athena@cs.nthu.edu.tw)


I. 故事背景與寫作計畫

	古代魔族建造了一個龐大的帝國，帝國後來無端地由地面消失，使得文
    明從零開始。文明消失的原因是因為帝國兩大法師大對決，引發一場空前的
    災難，而當初祭司希達曾嘗試消弭這個兩虎相爭的局面，但是並沒有成功。

	玩家就是後知後覺的勇者，要取得七個封印打開通往異次元世界的通道
    去見魔族的真神女王 (:p) 得到神奇的力量，當然解救是來不及啦，人都死
    了幾千年了。不過自己得到些好處也是不錯的 :)

	原始的計畫和任務線設計放在 README 以及  quest 這兩個檔案裡，由
    於實際製作的困難，可能會只做給醫生公會玩家的獎賞。當然技能要由各公
    會的 arch 認定是否可以加入 :p 任務線以這個檔案所描述的為準，原始的
    設計有點過於理想化 :p

	這個 quest 基本設定是  10 級以上的玩家可以不費吹灰之力完成，不
    過我好像有點樂觀，目前測試的結果一致認為這個題目太困苦了，所以請各
    位 arch 高抬貴手對 QC 睜隻眼閉隻眼吧呵呵 *smirk*


II. 任務線設計 (房間存放目錄 /u/l/lilia/ruin/room)

	由封印之廳 (sealroom.c) 進入遺蹟入口，走過水道扳杆迷宮 (en*.c)
    到達帳蓬 (camp.c)，取得魔法字典和密語進入羅斯托麗城 (rose*.c)。路
    上的出口均通向諾頓大陸遠風鎮外的小河 (11,6.noden.c)。

	羅斯托麗城內有大圖書館 (lib*.c) 及波塔祭壇 (altar.c)，解開大圖
    書館大廳 (lib0.c) 內的接水管謎題可以進入秘室 (lib8.c) 得到納突尼之
    印。進秘室的提示寫在牆上。取得第一印後以後可以直接進入羅斯托麗城外
    的小徑，不必再走水道迷宮。 

	接下來到波塔祭壇傳送到米拉瓦神殿 (min*.c)，回答大祭司的謎語或是
    將大祭司幹掉可以進入神殿內廳。按下藍紅黃三鈕可以通過氣盾牆，取得巴
    拉斯之印後 pray 即可回羅斯托麗城。 (暗示在風神布萊 bry 三個字上)

	到羅斯托麗城的廢墟里找到秘門，把巴拉斯印畫在門上，就可以打開秘
    門到依達波第亞城 (eda*.c) 廢墟去。進依達波第亞宮，按一下王座上的獨
    眼怪的眼睛會掉到放波西鳳印的房間裡，然後 pray 回羅斯托麗城 (輕鬆一
    下 :p)。

	再來到深淵去 (abyss*.c)，點完深淵上層的蠟燭之後，到六角形的中心
    去用自己的血啟動魔法陣到達冥府。回答黑天使的謎題，或是選擇把靈魂出
    賣給魔鬼就可以得到弗雷斯之印並回到羅斯托麗城或遠風鎮 *grin*

	再來進入空中花園 (g*.c)，走過死亡迷宮 (通過的提示是奉女王之聖名
    前進，也就是 ...)，就可以取得海地亞印。這一關比較簡單，但是容易死呵
    呵。

	接下來到溫柔鄉 (wenro*.c) 去，會見著石化的美女雕像 (維納斯) 及守
    護雕像的騎士卡謬。摘花供在雕像面前才可以親雕像，如果你堅持要把卡謬幹
    掉的話我也不反對，他和雷思差不多強，稍微遜一點。得到希特斯印。

	再來到魔術師塔 (tower*.c)，走完迷宮就可以拿到最後的封印，然後進
    卡榭布蘭卡宮 (p*.c) 見女王。Mission Accomplished。魔術師塔的迷宮以亂
    數決定出口，所以理論上每次 update room 之後出口的方位不同。

III. NPC (存放目錄 /u/l/lilia/ruin/monster)

1. 考古學家 達特紐斯 (deltazeus.c)
   no_attack npc

2. 大祭司 卡帕 (archbishop.c)
   str 25 int 30 dex 27 con 30 pie 20 kar 25 hp 1000 sp 2700
   aim_difficulty critical 100 weakest 100
   special_defense cold 90 fire 70 all 70 none 80
   spell heal 2 fireball 7
   skill dodge 70 
   法術施放機率 < 0.3
   裝備祭司袍、神聖匕首
   裝備後 ac 72 db 35 wc 95 dam 45-70

3. 地獄騎士 (deathknight.c)
   str 23 int 21 dex 23 con -- pie 21 kar 22 hp 5000 sp --
   skill dodge 100 longblade 100 parry 100
   killer
   裝備死神鐮刀
   裝備後 ac 80 db 50 wc 113 dam 35-65
   不死之身 (任務用 mob，目的是要給喜歡硬砍的玩家慘痛的教訓 *grin*)

4. 黑天使亞奇芬德 (archfiend.c)
   no_attack npc

5. 吟遊詩人紀羅斯 (bard.c)
   str 30 int 30 dex 20 con 25 pie 20 kar 20 hp 1200 sp --
   aim_difficulty critical 80 weakest 80
   special defense all 30 none 30 monk 20 scholar 20
   skill blunt 85 dodge 100
   裝備銀色長笛，白衣 (死亡大陸那件)
   裝備後 ac 40 db 42 wc 69 dam 35-65

6. 聖騎士卡謬 (carmue.c)
   str 30 int 20 dex 25 con 25 pie 30 kar 25 hp 2000 sp --
   aim_difficulty critical 80 weakest 80 vascular 80 ganglion 80
   special defense all 40 none 50
   skill longblade 100 dodge 100 parry 100
   裝備鎧魔劍
   裝備後 ac 157 db 53 wc 97 dam 35-70

7. 鬼魂 (ghost.c)
   no_attack npc

8. 聖騎士杰特 (jitter.c)
   str 30 int 20 dex 25 con 25 pie 30 kar 25 hp 2000 sp --
   aim_difficulty critical 80 weakest 80 vascular 80 ganglion 80
   special defense all 40 none 50
   skill jousting 100 dodge 100 parry 100 block 100
   裝備鎧魔槍
   裝備後 ac 157 db 56 wc 97 dam 35-70

9. 聖騎士亞姆羅列 (emerald.c)
   str 30 int 20 dex 25 con 25 pie 30 kar 25 hp 2000 sp 2000
   aim_difficulty critical 80 weakest 80 vascular 80 ganglion 80
   special defense all 40 none 50
   skill polearm 100 dodge 100 parry 100 longblade 100
   裝備眾神之怒、諸神的黃昏、鋼手套、鋼戰靴、鋼頭盔、鋼護膝、鋼戰甲、白色披風
   ( 除第一項外皆為 /d/noden 下已有之裝備 )
   裝備後 ac 154 db 33 wc1 60 dam 22-35 wc2 25 dam 8-16

10. 女王 (queen.c)
    no_attack npc


IV. 武器 (存放目錄 /u/l/lilia/ruin/weapon)

1. 鎧魔劍 (sword.c)
   wc 35 longblade dam 20-40 weight 250
   騎士專用，蜥蜴人不能用
   玩家使用時會幻化出一件鎧魔甲
   巫師及 npc 使用時會幻化出整套的鎧魔甲

2. 神聖匕首 (holy_dagger.c)
   wc 40 dagger dam 25-40 weight 30
   特攻機率 < 0.3
   特攻最大傷害 50，計算公式以雙方陣營值差除一千為準，持者陣營為負則反噬，
   反噬的傷害為 random(40)，每次特攻消耗 10 點 spell_points。
   
3. 死神鐮刀 (scythe.c)
   wc 42 longblade dam 25-45 weight 150 no_sale no_second
   玩家拿不到，如果拿到就是有 bug。

4. 銀色長笛 (flute.c)
   wc 35 blunt dam 10-25 weight 100
   特攻機率 < 0.4
   特攻種類 fire 傷害力 5

5. 鎧魔槍 (lance.c)
   wc 35 jousting dam 20-40 weight 250
   騎士專用
   玩家使用時會幻化出一件鎧魔甲
   巫師及 npc 使用時會幻化出整套的鎧魔甲

6. 眾神之怒 (polearm.c)
   wc 50 polearm dam 30-40 weight 245
   需與諸神之黃昏合用 (所以 .... 嘿嘿 .... 啦啦 ....)
   特攻機率目標 15 級以上 33% 9-15 級 40% 9 級以下 80%
   特攻種類 mental 傷害力 15 級以上 120 9-15 級 140 其他 250
   一般人用會折斷，折斷後
   wc 30 polearm dam 14-28


V. 護具 (存放目錄 /u/l/lilia/ruin/armor)

1. 鎧魔甲 (plate.c)
   ac 35 db 6 body 騎士公會專用

2. 鎧魔盔 (helm.c)
   ac 8 db 3 head 騎士公會專用

3. 鎧魔臂 (arms.c)
   ac 4 db 4 arms 騎士公會專用

4. 鎧魔手 (hands.c)
   ac 4 db 4 hands 騎士公會專用

5. 鎧魔襠 (leggings.c)
   ac 8 db 3 legs 騎士公會專用

6. 鎧魔鞋 (feet.c)
   ac 8 db 3 feet 騎士公會專用

7. 祭司袍 (bishop_robe.c)
   ac 22 db 5 body 醫生公會專用 weight 80 value 2000 silver

8. 鎧魔盾 (shield.c)
   ac 8 db 6 shield 騎士公會專用


VI. 其他物品 (存放目錄 /u/l/lilia/ruin/obj)

1. 魔法字典 (dictionary.c)
   任務必備用品，必須向達特紐斯討取。


VII. 獎賞技能 (存放目錄 /u/l/lilia/ruin/cmd)

1. 氣盾術 (_amass.c)
   sp -50 extra ac +10 db +(douin level)
   duration pie*3+50
   need skill: concentrate & douin


