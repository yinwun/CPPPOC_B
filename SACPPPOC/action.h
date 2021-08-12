#pragma once

#include <Windows.h>

struct action {
	struct 	action* pPrev, * pNext;			//上一个及下一个action指标
	void 	(*func)(struct action*);	//action所执行的function的指标
	void* pYobi;							//备用的struct指标
	void* pOther;						//其它用途struct指标
	UCHAR 	prio;							//action处理时的优先顺序
	UCHAR 	dispPrio;						//秀图时的优先顺序	
	int 	x, y;							//图的座标
	int		hitDispNo;						//是否命中目标编号
	BOOL	deathFlag;						//此action是否死亡旗标	
	int 	dx, dy;							//秀图座标位移量
	int 	dir;							//方向
	int 	delta;  						//合成向量

	char 	name[29];						//名字
	char 	freeName[33];					//free name
	int 	hp;
#ifdef _PET_ITEM
	int		iOldHp;
#endif
	int 	maxHp;
	int 	mp;
	int 	maxMp;
	int 	level;
	int 	status;
	int 	itemNameColor;					/* ?????䦶? */
	int		charNameColor;					// ????????????䦶?

	int		bmpNo;							//图号
	int		bmpNo_bak;							//备份图号
	int		atr;							//属性
	int		state;							//状态
	int		actNo;							//行动编号
	int		damage;

	int		gx, gy;							//在目前的地图上的座标
	int		nextGx, nextGy;					//下一个座标
	int		bufGx[10], bufGy[10];			//从目前座标到下一个座标之间座标的buffer
	short	bufCount;						//设定目前要走到那一个座标
	short	walkFlag;						// ??????????????????????
	float	mx, my;							//地图座标
	float	vx, vy;							// ??

//属性
	short 	earth;							// 佋 
	short 	water;							// ? 
	short 	fire;							// ? 
	short 	wind;							// ? 
//rader使用
	int		dirCnt;							// ???????
//gemini使用
	int		spd;							//移动的速度(0~63)( ?????? )
	int		crs;							//方向(0~31)(正上方为0,顺时钟方向) ?( ???? )( ?????? )
	int		h_mini;							// ??
	int		v_mini;							// ?
//pattern使用
	int		anim_chr_no;					//人物的编号(anim_tbl.h的编号)
	int		anim_chr_no_bak;				//上一次的人物编号
	int		anim_no;						//人物的动作编号
	int		anim_no_bak;					//上一次的人物编号
	int		anim_ang;						//动作的方向(0~7)(下0)
	int		anim_ang_bak;					//上一次的方向
	int		anim_cnt;						//第几张frame
	int		anim_frame_cnt;					//这张frame停留时间
	int		anim_x;							//X座标(Sprbin+Adrnbin)
	int		anim_y;							//Y座标(Sprbin+Adrnbin)
	int		anim_hit;						// ???
	// shan add +1
	char    fmname[33];			            // 家族名称
	// Robin 0728 ride Pet
	int		onRide;
	char	petName[16 + 1];
	int		petLevel;
	int		petHp;
	int		petMaxHp;
	int		petDamage;
	int		petFall;
#ifdef _MIND_ICON
	unsigned int sMindIcon;
#endif
#ifdef _SHOWFAMILYBADGE_
	unsigned int sFamilyIcon;
#endif
#ifdef FAMILY_MANOR_
	unsigned int mFamilyIcon;
#endif
#ifdef _CHAR_MANOR_
	unsigned int mManorIcon;
#endif
#ifdef _CHARTITLE_STR_
	TITLE_STR TitleText;
#endif
#ifdef _CHARTITLE_
	unsigned int TitleIcon;
#endif
#ifdef _NPC_EVENT_NOTICE
	int noticeNo;
#endif

#ifdef _SKILL_ROAR  
	int		petRoar;		//大吼(克年兽)
#endif 
#ifdef _SKILL_SELFEXPLODE //自爆
	int		petSelfExplode;
#endif 
#ifdef _MAGIC_DEEPPOISION   //剧毒
	int		petDeepPoision;
#endif 

#ifdef _CHAR_PROFESSION			// WON ADD 人物职业
	int		profession_class;
#endif
	//#ifdef _BATTLESKILL				// (不可开) Syu ADD 战斗技能介面
	int		warrioreffect;
	//#endif
#ifdef _GM_IDENTIFY		// Rog ADD GM识别
	char gm_name[33];
#endif
#ifdef _STREET_VENDOR
	char szStreetVendorTitle[64];
#endif
#ifdef _NPC_PICTURE
	int picture;
	int picturetemp;
#endif
#ifdef _PETSKILL_RIDE
	int saveride;
#endif
#ifdef _MOUSE_DBL_CLICK
	int index;	// 禁断!! Server中的charaindex
#endif

#ifdef _SFUMATO
	int sfumato;		// 二次渲染图层色彩
#endif
};

typedef struct action ACTION;