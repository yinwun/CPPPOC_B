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
	PET_HEAD = 0,	// ͷ
	PET_WING,		// ��
	PET_TOOTH,		// ��
	PET_PLATE,		// ����
	PET_BACK,		// ��
	PET_CLAW,		// צ
	PET_FOOT,		// ��(��)
	PET_EQUIPNUM
#endif
}CHAR_EquipPlace;

typedef struct
{
	int color;						// ���q?��
	int graNo;						// ??�k?
	int level;						// ???????
#ifdef _ITEM_PILENUMS
	int pile;
#endif
#ifdef _ALCHEMIST //#ifdef _ITEMSET7_TXT
	char alch[4 + 200];
#endif
	short useFlag;					// ��????
	short field;					// ��????��?
	short target;					// �n��
	short deadTargetFlag;			// ???????�n��???
	short sendFlag;					// ????????��?�u?
	char name[ITEM_NAME_LEN * 2 + 1];		// ????��
	char name2[ITEM_NAME2_LEN * 2 + 1];	// ????��?
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
	int ��������;
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
	int ridePetNo;//��������
	int learnride;
	unsigned int lowsride;
	char ridePetName[CHAR_FREENAME_LEN + 1];
	int ridePetLevel;
	int familySprite;
	int baseGraNo;
	ITEM itempool[MAX_ITEM];
	int big4fm;
	int trade_confirm;         // 1 -> ��ʼֵ
							   // 2 -> �[�ҷ�����ȷ����
							   // 3 -> ���Է�����ȷ����
							   // 4 -> ˫���԰���ȷ����

#ifdef _CHAR_PROFESSION			// WON ADD ����ְҵ
	int profession_class;
	int profession_level;
	//	int profession_exp;
	int profession_skill_point;
	char profession_class_name[32];
#endif	
#ifdef _ALLDOMAN // (���ɿ�) Syu ADD ���а�NPC
	int herofloor;
#endif

#ifdef _GM_IDENTIFY		// Rog ADD GMʶ��
	char gm_name[GM_NAME_LEN + 1];
#endif

#ifdef _FRIENDCHANNEL  // ROG ADD ����Ƶ��
	char  chatRoomNum[4];
#endif
#ifdef _STREET_VENDOR
	int iOnStreetVendor;		// ��̯ģʽ
#endif
	int skywalker; // GM������??
#ifdef _MOVE_SCREEN
	BOOL	bMoveScreenMode;	// �ƶ�ӫĻģʽ
	BOOL	bCanUseMouse;		// �Ƿ����ʹ�û����ƶ�
	int		iDestX;				// Ŀ��� X ����
	int		iDestY;				// Ŀ��� Y ����
#endif
#ifdef _THEATER
	int		iTheaterMode;		// �糡ģʽ
	int		iSceneryNumber;		// ��¼��Ժ����ͼ��
	ACTION* pActNPC[5];		// ��¼�糡����ʱ����������NPC
#endif
#ifdef _NPC_DANCE
	int     iDanceMode;			// ��һ��ģʽ
#endif
#ifdef _EVIL_KILL
	int     newfame; // �ַ�ħ������
	short   ftype;
#endif

	int debugmode;
#ifdef _SFUMATO
	int sfumato;		// ������Ⱦͼ��ɫ��
#endif
#ifdef _NEW_ITEM_
	int ������״̬;
#endif
#ifdef _CHARSIGNADY_NO_
	int ǩ�����;
#endif
#ifdef _MAGIC_ITEM_
	int ��������״̬;
	int ���߹⻷Ч��;
#endif
} PC;

extern PC pc;
void setPcDir(int dir);