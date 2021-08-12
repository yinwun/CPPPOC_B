#pragma once

#include <Windows.h>

struct action {
	struct 	action* pPrev, * pNext;			//��һ������һ��actionָ��
	void 	(*func)(struct action*);	//action��ִ�е�function��ָ��
	void* pYobi;							//���õ�structָ��
	void* pOther;						//������;structָ��
	UCHAR 	prio;							//action����ʱ������˳��
	UCHAR 	dispPrio;						//��ͼʱ������˳��	
	int 	x, y;							//ͼ������
	int		hitDispNo;						//�Ƿ�����Ŀ����
	BOOL	deathFlag;						//��action�Ƿ��������	
	int 	dx, dy;							//��ͼ����λ����
	int 	dir;							//����
	int 	delta;  						//�ϳ�����

	char 	name[29];						//����
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
	int 	itemNameColor;					/* ?????���q?�� */
	int		charNameColor;					// ??????����??????���q?��

	int		bmpNo;							//ͼ��
	int		bmpNo_bak;							//����ͼ��
	int		atr;							//����
	int		state;							//״̬
	int		actNo;							//�ж����
	int		damage;

	int		gx, gy;							//��Ŀǰ�ĵ�ͼ�ϵ�����
	int		nextGx, nextGy;					//��һ������
	int		bufGx[10], bufGy[10];			//��Ŀǰ���굽��һ������֮�������buffer
	short	bufCount;						//�趨ĿǰҪ�ߵ���һ������
	short	walkFlag;						// ��????????????��?�v?????????
	float	mx, my;							//��ͼ����
	float	vx, vy;							// ?�h?��

//����
	short 	earth;							// �� �N��
	short 	water;							// ? �N��
	short 	fire;							// ? �N��
	short 	wind;							// ? �N��
//raderʹ��
	int		dirCnt;							// ��?��??????
//geminiʹ��
	int		spd;							//�ƶ����ٶ�(0~63)( ?????? )
	int		crs;							//����(0~31)(���Ϸ�Ϊ0,˳ʱ�ӷ���) ��?( ???? )( ��?????? )
	int		h_mini;							// ��?��?
	int		v_mini;							// ��?����
//patternʹ��
	int		anim_chr_no;					//����ı��(anim_tbl.h�ı��)
	int		anim_chr_no_bak;				//��һ�ε�������
	int		anim_no;						//����Ķ������
	int		anim_no_bak;					//��һ�ε�������
	int		anim_ang;						//�����ķ���(0~7)(��0)
	int		anim_ang_bak;					//��һ�εķ���
	int		anim_cnt;						//�ڼ���frame
	int		anim_frame_cnt;					//����frameͣ��ʱ��
	int		anim_x;							//X����(Sprbin+Adrnbin)
	int		anim_y;							//Y����(Sprbin+Adrnbin)
	int		anim_hit;						// ???�R�e
	// shan add +1
	char    fmname[33];			            // ��������
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
	int		petRoar;		//���(������)
#endif 
#ifdef _SKILL_SELFEXPLODE //�Ա�
	int		petSelfExplode;
#endif 
#ifdef _MAGIC_DEEPPOISION   //�綾
	int		petDeepPoision;
#endif 

#ifdef _CHAR_PROFESSION			// WON ADD ����ְҵ
	int		profession_class;
#endif
	//#ifdef _BATTLESKILL				// (���ɿ�) Syu ADD ս�����ܽ���
	int		warrioreffect;
	//#endif
#ifdef _GM_IDENTIFY		// Rog ADD GMʶ��
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
	int index;	// ����!! Server�е�charaindex
#endif

#ifdef _SFUMATO
	int sfumato;		// ������Ⱦͼ��ɫ��
#endif
};

typedef struct action ACTION;