#pragma once
#include "action.h"
#include "field.h"

#define CHAR_NAME_LEN			16
#define ITEM_NAME_LEN			28
#define ITEM_NAME2_LEN			16
#define ITEM_MEMO_LEN			84
#define CHAR_FREENAME_LEN		32
#define MAX_PET					5
#define MAX_MAXHAVEITEM	15
#define MAX_ITEMSTART CHAR_EQUIPPLACENUM
#define MAX_ITEM (MAX_ITEMSTART+MAX_MAXHAVEITEM*3)

typedef enum
{
	CHAR_HEAD,
	CHAR_BODY,
	CHAR_ARM,
	CHAR_DECORATION1,
	CHAR_DECORATION2,

#ifdef _ITEM_EQUITSPACE
	CHAR_EQBELT,
	CHAR_EQSHIELD,
	CHAR_EQSHOES,
#endif

#ifdef _EQUIT_NEWGLOVE
	CHAR_EQGLOVE,
#endif
	CHAR_EQUIPPLACENUM,
#ifdef _PET_ITEM
	PET_HEAD = 0,	// 头
	PET_WING,		// 翼
	PET_TOOTH,		// 牙
	PET_PLATE,		// 身体
	PET_BACK,		// 背
	PET_CLAW,		// 爪
	PET_FOOT,		// 脚(鳍)
	PET_EQUIPNUM
#endif
}CHAR_EquipPlace;

typedef struct
{
	int color;						// 䦶?
	int graNo;						// ???
	int level;						// ???????
#ifdef _ITEM_PILENUMS
	int pile;
#endif
#ifdef _ALCHEMIST //#ifdef _ITEMSET7_TXT
	char alch[4 + 200];
#endif
	short useFlag;					// ????
	short field;					// ?????
	short target;					// 
	short deadTargetFlag;			// ??????????
	short sendFlag;					// ??????????
	char name[ITEM_NAME_LEN * 2 + 1];		// ????䦶
	char name2[ITEM_NAME2_LEN * 2 + 1];	// ????䦶?
	char memo[ITEM_MEMO_LEN * 2 + 1];		// ??
	char damage[20];
#ifdef _PET_ITEM
	char type;
#endif
#ifdef _ITEM_JIGSAW
	char jigsaw[50];
#endif
#ifdef _NPC_ITEMUP
	int itemup;
#endif
#ifdef _ITEM_COUNTDOWN
	int counttime;
#endif
#ifdef _MAGIC_ITEM_
	int 道具类型;
#endif
} ITEM;

typedef struct
{
	int graNo;
	int faceGraNo;
	int id;
	int dir;
	int hp, maxHp;
	int mp, maxMp;
	int vital;
	int str, tgh, dex;
	int exp, maxExp;
	int level;
	int atk, def;
	int quick, charm, luck;
	int earth, water, fire, wind;
	int gold;
#ifdef _NEW_MANOR_LAW
	int fame;
#endif
	int titleNo;
	int dp;
	char name[CHAR_NAME_LEN + 1];
	char freeName[CHAR_FREENAME_LEN + 1];
	short nameColor;
#ifdef _ANGEL_SUMMON
	unsigned status;
#else
	unsigned short status;
#endif
	unsigned short etcFlag;
	short battlePetNo;
	short selectPetNo[MAX_PET];
	short mailPetNo;
#ifdef _STANDBYPET
	short standbyPet;
#endif
	int battleNo;
	short sideNo;
	short helpMode;
	ITEM item[MAX_ITEM];
	ACTION* ptAct;
	int pcNameColor;
	short transmigration;
	char chusheng[61];
	char familyName[CHAR_NAME_LEN + 1];
	int familyleader;
	int channel;
	int quickChannel;
	int personal_bankgold;
	int ridePetNo;//宠物形像
	int learnride;
	unsigned int lowsride;
	char ridePetName[CHAR_FREENAME_LEN + 1];
	int ridePetLevel;
	int familySprite;
	int baseGraNo;
	ITEM itempool[MAX_ITEM];
	int big4fm;
	int trade_confirm;         // 1 -> 初始值
							   // 2 -> 慬我方按下确定键
							   // 3 -> 仅对方按下确定键
							   // 4 -> 双方皆按下确定键

#ifdef _CHAR_PROFESSION			// WON ADD 人物职业
	int profession_class;
	int profession_level;
	//	int profession_exp;
	int profession_skill_point;
	char profession_class_name[32];
#endif	
#ifdef _ALLDOMAN // (不可开) Syu ADD 排行榜NPC
	int herofloor;
#endif

#ifdef _GM_IDENTIFY		// Rog ADD GM识别
	char gm_name[GM_NAME_LEN + 1];
#endif

#ifdef _FRIENDCHANNEL  // ROG ADD 好友频道
	char  chatRoomNum[4];
#endif
#ifdef _STREET_VENDOR
	int iOnStreetVendor;		// 摆摊模式
#endif
	int skywalker; // GM天行者??
#ifdef _MOVE_SCREEN
	BOOL	bMoveScreenMode;	// 移动荧幕模式
	BOOL	bCanUseMouse;		// 是否可以使用滑鼠移动
	int		iDestX;				// 目标点 X 座标
	int		iDestY;				// 目标点 Y 座标
#endif
#ifdef _THEATER
	int		iTheaterMode;		// 剧场模式
	int		iSceneryNumber;		// 记录剧院背景图号
	ACTION* pActNPC[5];		// 记录剧场中临时产生出来的NPC
#endif
#ifdef _NPC_DANCE
	int     iDanceMode;			// 动一动模式
#endif
#ifdef _EVIL_KILL
	int     newfame; // 讨伐魔军积分
	short   ftype;
#endif

	int debugmode;
#ifdef _SFUMATO
	int sfumato;		// 二次渲染图层色彩
#endif
#ifdef _NEW_ITEM_
	int 道具栏状态;
#endif
#ifdef _CHARSIGNADY_NO_
	int 签到标记;
#endif
#ifdef _MAGIC_ITEM_
	int 法宝道具状态;
	int 道具光环效果;
#endif
} PC;

extern PC pc;
void setPcDir(int dir);