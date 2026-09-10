// org.h
// The defined variables for organization .

#define GUILD_PREFIX           "/d/"

#define LOW_ORG_EXP             1000000  //加入組織的最小經驗
#define LOW_ORG_QUEST		260	//加入組織的最少任務點數
#define LEVEL_UP_QUEST		30	//每升一級所需的任務點數
#define LOW_ORG_EXPLORE		600	//加入組織的最少平均冒險度=60%
#define LEVEL_UP_EXPLORE	50	//每升一級所需的冒險度=5%
#define LEVEL_UP_SKILL		10	//每升一級能訓練的skills等級
#define MAX_ORG_LEVEL		10	//組織的最大等級

#define CLASS_NAMES ({ "adventurer","knight","mage","healer",\
        "monk", "scholar", "thief",})
#define GUILD_FILES ({ "/d/adventurer/adventurer", "/d/knight/knight",\
        "/d/mage/mage", "/d/healer/healer", "/d/monk/monk", "/d/scholar/scholar",\
        "/d/thief/thief",})

#define GUILD_DIR(x)           (GUILD_PREFIX + (x))
#define GUILD_MASTER(x)        (GUILD_PREFIX + (x) +"/" + (x))

// The defined variables for social guilds.
#define MAX_SOCIAL_GUILDS      4

#define SOCIAL_GUILD_PREFIX    "/d/std/social_guilds/"

#define SOCIAL_GUILD_MASTER(x) (SOCIAL_GUILD_PREFIX + (x))
